/*
 * ARAnetwlayer.cc
 *
 *  Created on: 30/01/2016
 *      Author: sushi
 */

#include <ARAmessages_m.h>
#include <ARAnetwlayer.h>
#include <BaseWorldUtility.h>
#include <cdefaultlist.h>
#include <cdisplaystring.h>
#include <cenvir.h>
#include <cmessage.h>
#include <cmodule.h>
#include <cobjectfactory.h>
#include <cpar.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <ctopology.h>
#include <cwatch.h>
#include <FindModule.h>
#include <INETDefs.h>
#include <regmacros.h>
#include <simtime.h>
#include <simutil.h>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <vector>

Define_Module(ARAnetwlayer);

/***********************************************************
 *                START OF THE MAIN METHODS                *
 **********************************************************/
void ARAnetwlayer::initialize(int stage){
    BaseNetwLayer::initialize(stage);

    if(stage == 0){
        topo = new cTopology("topo");
        std::vector<std::string> nedTypes;
        nedTypes.push_back(getParentModule()->getNedTypeName());
        topo->extractByNedTypeName(nedTypes);
        thisNode = topo->getNodeFor(getParentModule());

        isSinkNet = par("isSinkNet");
        isRecNet = par("isRecNet");
        table_size = par("table_size");

//        destination = topo->getNode(7)->getModuleId();
//        source_addr = topo->getNode(0)->getModuleId();

        /********* EVAPORATION *********/
        q = par("q");
        evaporation_time = par("evaporation_time");

        /********* TIME TO LIVE *********/
        //TTL = par ("TTL");
        ttl_discount = par("ttl_discount");
        ttl_time = par("ttl_time");
        bTTL = par("TTL");

        WATCH(destination);
        WATCH(source_addr);
        WATCH(sent);
        WATCH(fant);
        WATCH(bant);
        WATCH(received);
        WATCH(data);
        WATCH(index);
        WATCH(TTL);
        if(isSinkNet) WATCH(TTLF);
        WATCH(id_lastest_BANT[0]);
        WATCH(id_lastest_BANT[1]);
        WATCH(id_lastest_BANT[2]);
        WATCH(data_last_id);
        WATCH(route);
        WATCH(trying);

        world = FindModule<BaseWorldUtility*>::findGlobalModule();
        bt = FindModule<SimpleBattery*>::findGlobalModule();

    }else if(stage == 1){

//        ev << "OI : " <<  thisNode << "\n";
//        ev << "OI : " <<  topo->getNumNodes() << "\n";
//        ev << "OI : " <<  topo->getNode(0)->getModuleId() << "\n";
//        ev << "OI : " <<  getParentModule()->getId() << "\n";

        initialize_table(&routing_table,table_size);
        id_lastest_FANT[0] = 0;
        id_lastest_FANT[1] = 0;
        id_lastest_FANT[2] = 0;

        for(int i = 0; i < table_size; i ++){
            routing_table[i].pheromone_value = 0;
        }

        ttlf = new cMessage("ttlf");
        step_forward = new cMessage("step_forward");
        retry = new cMessage("retry");
        step_backward = new cMessage("step_backward");
        evaporation = new cMessage("evaporation");
        ttl = new cMessage("ttl");
        //refreshDisplay();

//        MIXIM_API BaseBattery::estimateResidualAbs();
//        SimpleBattery* bt;
//        BaseBattery *bt;
//        bt->estimateResidualAbs();
//        double teste = BaseBattery::estimateResidualAbs();
    }
}

void ARAnetwlayer::finish(){
    recordScalar("#sent",sent);
    recordScalar("#received",received);
    recordScalar("#data",data);
    recordScalar("#data_all",data_all);
    recordScalar("#data_error",data_error);
    recordScalar("#fant",fant);
    recordScalar("#bant",bant);
    EV << getFullPath() << "[ SENT ] : " << sent << "\n";
    EV << getFullPath() << "[ RECEIVED ] : " << received << "\n";
    EV << getFullPath() << "[ DATA ] : " << data << "\n";
    EV << getFullPath() << "[ ERROR ] : " << data_error << "\n";
    //int OwnedSize=this->defaultListSize();
    //EV << getFullPath() << "[ LIXO ] : " << OwnedSize << "\n";
}

ARAnetwlayer::~ARAnetwlayer(){

    cOwnedObject *Del=NULL;
    int OwnedSize=this->defaultListSize();
    for(int i=0;i<OwnedSize;i++){
        Del=this->defaultListGet(0);
        this->drop(Del);
        delete Del;
    }
}

void ARAnetwlayer::initialize_table(table **routing_table, int table_size){
    *routing_table = (table*) malloc (table_size*sizeof(table));
}

/*
 *  First step to start routing, is to create a FANT datagram and sent
 *  to neighbors in a broadcasting way.
 *  dtg is datagram abbreviation
 *  pheromone value is computed based on the number of hops
 */
void ARAnetwlayer::handleSelfMsg(cMessage *msg){

    if(msg == step_forward){
        FANT *dtg = new FANT("FANT_DTG",FANT_DTG);
        dtg->setDest_addr(destination);
        dtg->setPrevious_addr(getParentModule()->getId());
        dtg->setSource_addr(source_addr);
        dtg->setHops(dtg->getHops()+1);
        dtg->setId(id_last_FANT+1);
        dtg->setPheromone_value(1/dtg->getHops());
        id_last_FANT = dtg->getId();
        //index = 0;
        setDownControlInfo(dtg, LAddress::L2BROADCAST);
        sendDown(dtg);
        if(isSinkNet){
            TTLF = 100;
            if(ttlf->isScheduled()){
                cancelEvent(ttlf);
            }
            scheduleAt(simTime(),ttlf);
        }
        EV << "[ FANT SENT ] " << getParentModule()->getId() << "\n";
        sent++;

//        BaseBattery *bt;
//        double capacity = getParentModule()->getSubmodule("battery")->par("capacity");
//        ev << "TESTE: " << bt->estimateResidualAbs();
//        double nominal = getParentModule()->getSubmodule("SimpleBattery")->par("capacity");
//        ev << "TESTE: " << getParentModule()->getSubmodule("SimpleBattery");

        //refreshDisplay();
    }else if(msg == step_backward){
        print(routing_table);
        EV << "[ CREATING BANT ] ";
        BANT *dtg = new BANT("BANT_DTG",BANT_DTG);
        dtg->setDest_addr(routing_table[index].dest_addr);
        dtg->setNext_addr(routing_table[index].next_hop_backward);
        dtg->setPrevious_addr(getParentModule()->getId());
        dtg->setHops(dtg->getHops()+1);
        dtg->setPheromone_value(1/dtg->getHops());

        dtg->setId(id_last_BANT+1);
        id_last_BANT = dtg->getId();

        dtg->setSource_addr(getParentModule()->getId());
        routing_table[index].pheromone_value += dtg->getPheromone_value();
        setDownControlInfo(dtg, LAddress::L2BROADCAST);
        sendDown(dtg);
        //char text[32];
        //sprintf(text, "BANT (%i)", int(dtg->getNext_addr()));
        //getParentModule()->bubble(text);
        EV << "[ SEND BANT ] " << dtg->getNext_addr() << "\n";
        sent++;
        //refreshDisplay();
    }else if(msg == evaporation){
        handleEvaporation(routing_table);
    }else if(msg == retry){
        cMessage* teste = new cMessage();
        sendUp(teste);
    }else if(msg == ttl){
        handleTTL();
    }else if(msg == ttlf){
        handleTTLF();
    }else{
        EV << "OI: " << msg << "\n";
    }
}

void ARAnetwlayer::handleUpperMsg(cMessage *msg){
    if(msg->getKind() == DATA_PKT){
        handleDataPkt(static_cast<DATA*>(msg));
    }
}

void ARAnetwlayer::handleLowerMsg(cMessage *msg){

    ev << "TESTE RELATIVE: " << bt->estimateResidualRelative();
    ev << "\nTESTE ABS: " << bt->estimateResidualAbs() << endl;

    switch(msg->getKind()){
    case FANT_DTG:
        received++;
        fant++;
        //refreshDisplay();
        handleFantPkt(static_cast<FANT*>(msg));
        break;
    case BANT_DTG:
        received++;
        bant++;
        //refreshDisplay();
        handleBantPkt(static_cast<BANT*>(msg));
        break;
    case DATA_PKT:
        received++;
        data_all++;
        //refreshDisplay();
        handleDataPkt(static_cast<DATA*>(msg));
        break;
        /*case ROUTE_error:
        received++;
        //refreshDisplay();
        handleERROR(routing_table, static_cast<ROUTE_ERROR*>(msg));
        break;*/
    default:
        EV << "[ DROPING LOWER MSG ] " << msg << "\n";
        delete msg;
        break;
    }
}
/***********************************************************
 *                 END OF THE MAIN METHODS                 *
 **********************************************************/


/***********************************************************
 *               START OF THE AUXILIAR METHODS             *
 **********************************************************/
void ARAnetwlayer::refreshDisplay() const{
    char buf[40];
    sprintf(buf, "rcvd: %ld sent: %ld data: %ld", received, sent, data);
    getParentModule()->getDisplayString().setTagArg("t", 0, buf);
}

void ARAnetwlayer::print(table *routing_table){
    EV << "[ Actual Node ] : " << getParentModule()->getId();
    for(int i = 0; i <= index; i++){
        EV << "\n[ Table Number ] : " << i;
        EV << "\n[ Dest_addr ] : " << routing_table[i].dest_addr;
        EV << "\n[ Next_hop_backward ] : " << routing_table[i].next_hop_backward;
        EV << "\n[ Next_hop_forward ] : " << routing_table[i].next_hop_forward;
        EV << "\n[ Pheromone_value ] : " << routing_table[i].pheromone_value;
        EV << "\n";
    }
}

bool ARAnetwlayer::ID(FANT *dtg, bool flag){
    if(flag){
        for(int i = 0; i < id; i++){
            if(dtg->getId() == id_lastest_FANT[i])
                return true;
        }
    }else{
        id_lastest_FANT[id%3] = dtg->getId();
        id++;
        if(id >= 3) id = 0;
    }
    return false;
}

bool ARAnetwlayer::IDB(BANT *dtg, bool flag){
    if(flag){
        for(int i = 0; i < idb; i++){
            if(dtg->getId() == id_lastest_BANT[i])
                return true;
        }
    }else{
        id_lastest_BANT[idb%3] = dtg->getId();
        idb++;
        if(idb >= 3) idb = 0;
    }
    return false;
}

void ARAnetwlayer::handleEvaporation(table *routing_table){
    for(int i= 0; i <= index; i ++){
        routing_table[i].pheromone_value *= (1-q);
    }
    if(TTL > 0){
        // Continue to evaporate each evaporation_time s
        if(evaporation->isScheduled()){
            cancelEvent(evaporation);
        }
        scheduleAt(simTime()+evaporation_time,evaporation);
    }
}
/*
 *  For a BANT choose a path, he must verify all the neighbors and
 *  choose the one with most pheromone
 *  Sort the routing table based on the high value of pheromone
 */
int ARAnetwlayer::handleChoosePath(table *routing_table){
    double path, higher_path = -999;
    int node_position = 0;
    for(int i=0; i <= index; i ++){
        //path = routing_table->pheromone_value/(index*routing_table->pheromone_value);
        path = routing_table[i].pheromone_value;
        if(path > higher_path){
            higher_path = path;
            node_position = i;
        }
    }
    return node_position;
}
/***********************************************************
 *              END OF THE AUXILIAR METHODS                *
 **********************************************************/


/***********************************************************
 *           START OF ERROR AND TTL METHODS                *
 **********************************************************/
/*
 *  Seek for the address of the broken link and deactivate it
 */
void ARAnetwlayer::handleERROR(DATA *error){
    // seek for the address and set the pheromone to zero
    //getParentModule()->bubble("HANDLE ERROR");
    EV << "[ HANDLE ERROR ]\n";
    for (int i = 0; i < index; i ++){
        if(routing_table[i].dest_addr == error->getMy_addr()){
            routing_table[i].pheromone_value = 0;
            /* before decrement index, i must realign the table*/
            //if(index >= 0) index --;
            break;
        }
    }
    // if the dest_addr is me, i need to resent the data again
    if(error->getDest_addr() == getParentModule()->getId() and route){
        EV << "[ RESENT DATA ]\n";
        error->setERROR(false);
        error->setId(error->getId()+1);
        // error here, because a neighbor could not have the data to resent
        handleDataPkt(error);
    }
}
/*
 * HOW PROPERTY DECREMENT THE TIMEOUT
 * THIS WILL ONLY OCCUR WHEN THE ROUTE IS ALREADY STABLISH
 * The trigger is the TimeOut Out
 * Treat the routing failure with a TimeOut
 * The TimeOut is associated with a packet,message,datagram.
 * When the TimeOut is out, set pheromone to 0 and try other route.
 * If all routes fail, transmit back to the node that send a request
 * a message ROUTE_ERROR.
 * This node than set to 0 the pheromone and try all again.
 * When back to source, he need to retry.
 *
 * IMPLEMENT AN COUNTER
 */
void ARAnetwlayer::handleRoutingFailure(table *routing_table, DATA *data, bool flag){
    // is is sink, need to restart the phase of discovery route
    //getParentModule()->bubble("ROUTING FAIL");
    if(isSinkNet){
        EV << "[ ROUTING FAILURE SINK ]\n";
        route = false;
        if(step_forward->isScheduled()){
            cancelEvent(step_forward);
        }
        scheduleAt(simTime(),step_forward);
    } else {
        EV << "[ ROUTING FAILURE ]\n";
        // deactivate the link
        routing_table[last_sent].pheromone_value = 0;
        // inform all neighbors that i failed on the duty
        if(flag){
            //ROUTE_ERROR *error = new ROUTE_ERROR("ROUTE_error",ROUTE_error);
            //error->setMy_addr(getParentModule()->getId());
            //error->setDest_addr(routing_table[last_sent].next_hop_backward);
            // EV << error << "\n";
            data->setERROR(true);
            data->setMy_addr(getParentModule()->getId());
            // error->setDest_addr(routing_table[position_sent].next_hop_backward);
            setDownControlInfo(data, LAddress::L2BROADCAST);
            sendDown(data);
            sent++;
            //refreshDisplay();

        }else{
            // try to send
            EV << data << "\n";
            //getParentModule()->bubble("handleRoutingFail");
            data->setId(data->getId()+1);
            //data->setERROR(true);
            handleDataPkt(data);
        }
    }

}
/*
 * Discount the reamain TTL
 * Comparate the TTL if 0, routing failure
 */
void ARAnetwlayer::handleTTL(){
    EV << "[ DISCOUNT TTL ] " << TTL << "[ NODE ] " << getParentModule()->getId() << "\n";
    if( (TTL -= 1) == 0){
        EV << "[ TTL EXPIRED ]\n";
        // if is not the sink, so
        if(!isSinkNet){
            // if localTime out, call the method to handle failure
            if ((trying += 1) >= 2){
                trying = 0;
                //getParentModule()->bubble("FAIL 1");
                EV << "[ ROUTING FAILURE CASE 1 ]\n";
                // sent an message to neighbors
                handleRoutingFailure(routing_table, back_data, true);
            }else{
                //getParentModule()->bubble("FAIL 2");
                EV << "[ ROUTING FAILURE CASE 2 ]\n";
                TTL = 10;
                if(ttl->isScheduled()){
                    cancelEvent(ttl);
                }
                scheduleAt(simTime()+ttl_time,ttl);
                handleRoutingFailure(routing_table, back_data, false);
            }
            // if is the sink, so i need to retry the messages, if in teoric enter here,
            // so the sink is not reachable, and i must retry
        }else{
            route = false;
            //retry = new cMessage("retry");
            if(retry->isScheduled()){
                cancelEvent(retry);
            }
            scheduleAt(simTime(),retry);
        }
    }
    // find a way to stop the ttl, when the data packet is sent as answer
    if(TTL > 0 and route){
        if(ttl->isScheduled()){
            cancelEvent(ttl);
        }
        scheduleAt(simTime()+ttl_time,ttl);
    }
}
/*
 * Discount the remain TTLF
 * Comparate the TTLF if 0, routing failure
 */
void ARAnetwlayer::handleTTLF(){
    if( (TTLF -= 1) > 0 and !route){
        EV << "[ TTLF DECREMENTED ] " << TTLF <<"\n";
        if(ttlf->isScheduled()){
            cancelEvent(ttlf);
        }
        scheduleAt(simTime()+ttl_time,ttlf);
    }
    if( TTLF == 0){
        //getParentModule()->bubble("TTLF OUT");
        EV << "[ TTLF OUT ]\n";
        // if localTime out, call the method to handle failure
        route = false;
        //retry = new cMessage("retry");
        if(retry->isScheduled()){
            cancelEvent(retry);
        }
        scheduleAt(simTime(),retry);
    }
}
/***********************************************************
 *             END OF ERROR AND TTL METHODS                *
 **********************************************************/


/***********************************************************
 *              START OF PACKETS METHODS                   *
 **********************************************************/
/*
 *  First need to check if already exists a route to destination
 *  if yes just send
 *  if not start routing process
 *  Check if is a forward data or a backward data
 */
void ARAnetwlayer::handleDataPkt(DATA *pkt){

    if(pkt->getERROR()){
        data_error ++;
        handleERROR(pkt);
    }else{
        if((!isSinkNet || route) && data_last_id != pkt->getId() &&
                (pkt->getNext_addr() == getParentModule()->getId() || pkt->getNext_addr() == -1)){

            data ++;

            destination = pkt->getDest_addr();
            source_addr = pkt->getSource_addr();

            back_data = (DATA*) pkt->dup();       // backup data
            back_data->setId(back_data->getId()+1);
            data_last_id = pkt->getId();        // storing the last id

            EV << "[ DATA ACCEPT DEST ] " << pkt->getDest_addr() << "\n";

            if(pkt->getDest_addr() == getParentModule()->getId()){
                if(isSinkNet){
                    EV << "[ ARRIVED AT SINK ]\n";
                    EV << "[ DATA ]: " << pkt->getData() << "\n";
                    //data ++;
                    delete pkt;
//                    route = false;
                    data_last_id = -1;
                    //retry = new cMessage("retry");
                    if(retry->isScheduled()){
                        cancelEvent(retry);
                    }
                    scheduleAt(simTime(),retry);
                }else{
                    EV << "[ ARRIVED TO DESTINY ] : " << pkt << "\n";
                    //data ++;
                    DATA *CPKT = pkt->dup();
                    sendUp(CPKT);
                    delete pkt;
                }
            }else{
                // choosing who i will send
                node_position = handleChoosePath(routing_table);
                routing_table[node_position].pheromone_value += pkt->getPheromone_value();
                // is forward or backward ? each one has a way to go
                if(pkt->getForward()){
                    pkt->setNext_addr(routing_table[node_position].next_hop_forward);
                }else{
                    pkt->setNext_addr(routing_table[node_position].next_hop_backward);
                }

                EV << "[ HANDLE DATA PKT ] \n";
                EV << "[ ACTUAL NODE ] : " << getParentModule()->getId();
                EV << "  [ NEXT HOP ] : " << pkt->getNext_addr();
                EV << "  [ INDEX ] : " << node_position << "\n\n";
                print(routing_table);

                pkt->setHops(pkt->getHops()+1);
                pkt->setPheromone_value(1/pkt->getHops());

                if(isSinkNet){
                    TTL = bTTL;
                    pkt->setTTL(TTL-ttl_discount);
                }else{
                    pkt->setTTL(pkt->getTTL()-ttl_discount);
                }

                cObject * pCtrlInfo = pkt->removeControlInfo();
                if (pCtrlInfo != NULL)
                    delete pCtrlInfo;
                setDownControlInfo(pkt, LAddress::L2BROADCAST);
                EV << "[ DATA SENT ]\n";
                // if the data of the pkt is 666, so is a backward pkt, then i need to set the route
                // to false, for stoping the ttl to decrement
                if(pkt->getData() != 0) route = false;
                sent++;

                /**************************************************************
                 *                          TIMEOUT                           *
                 *************************************************************/
                // if pkt data is 0, so is a forward pkt, and i must start the TTL
                if(pkt->getData() == 0){
                    // TTL/hop because the nodes that are distant need a small TTL than the others close
                    if (!isSinkNet){
                        if(trying == 0){
                            TTL = pkt->getTTL();
                        }else{
                            TTL = 10;
                        }
                    }
                    last_sent = node_position;
                    //telling to the node that he is part of the route
                    //route = true;
                    //TTL = bTTL;
                    // start to decrement the ttl
                    if(ttl->isScheduled()){
                        cancelEvent(ttl);
                    }
                    scheduleAt(simTime()+ttl_time,ttl);
                }

                sendDown(pkt);
            }
        }else{

            destination = pkt->getDest_addr();
            source_addr = pkt->getSource_addr();

            if(isSinkNet && route == false){
                delete(pkt);
                data_last_id = -1;
                EV << "[ NO ROUTE ]\n";
                if(step_forward->isScheduled()){
                    cancelEvent(step_forward);
                }
                scheduleAt(simTime()+0.1,step_forward);
            }
        }
    }

}

/*
 *  A FANT is a Forward ANT that is broadcasting in a flood way
 *  When a node receives for a first time an FANT, so he need to
 *  create a entry to his routing table
 *  The pheromone value must evaporate (1-q)*ph_value q=(0,1]
 *  The pheromone will start the evaporation when the first entry of the
 *  routing table is inserted
 */
void ARAnetwlayer::handleFantPkt(FANT *dtg){

    EV << "[ FANT RECEIVED ] " << getParentModule()->getId() << " [ FROM ] " << dtg->getPrevious_addr() << "\n";
    // verify if the fant already pass
    if(!ID(dtg,true)){
        EV << "[ FANT ACCEPT ] " << getParentModule()->getId() << " [ FROM ] " << dtg->getPrevious_addr() << "\n";

        ID(dtg,false);
        // First set the pheromone value 1/hops
        dtg->setPheromone_value(1/dtg->getHops());

        // reset the routing
        for(int i = 0; i < table_size; i ++){
            routing_table[i].pheromone_value = 0;
        }

        index = 0;  // Because is a new requisition
        routing_table[index].dest_addr = dtg->getSource_addr();
        routing_table[index].next_hop_backward = dtg->getPrevious_addr();
        //routing_table[index].dest_addr_forward = destination; //change here
        routing_table[index].pheromone_value += dtg->getPheromone_value();

        if(dtg->getDest_addr() == getParentModule()->getId()){
            EV << "[ SENDING BANT ] " << getParentModule()->getId() << " [ FROM ] " << dtg->getPrevious_addr() << "\n";
            if(step_backward->isScheduled()){
                cancelEvent(step_backward);
            }
            scheduleAt(simTime(),step_backward);
        }else{
            dtg->setHops(dtg->getHops()+1);
            dtg->setPrevious_addr(getParentModule()->getId());
            cObject * pCtrlInfo = dtg->removeControlInfo();
            if (pCtrlInfo != NULL)
                delete pCtrlInfo;
            setDownControlInfo(dtg, LAddress::L2BROADCAST);
            sendDown(dtg);
            EV << "[ SENDING FANT ] " << getParentModule()->getId() << "\n";
            sent++;
        }

    }else{
        if(index < table_size) index ++;
        if(index < table_size){  // To store the neighbors info
            dtg->setPheromone_value(1/dtg->getHops());
            routing_table[index].dest_addr = dtg->getSource_addr();
            routing_table[index].next_hop_backward = dtg->getPrevious_addr();
            routing_table[index].pheromone_value += dtg->getPheromone_value();
        }
        delete dtg;
    }
    // Continue to evaporate each 0.1s
    if(evaporation->isScheduled()){
        cancelEvent(evaporation);
    }
    scheduleAt(simTime()+evaporation_time,evaporation);
}
/*
 *  A BANT is a Backward ANT that is broadcast in unicasting way
 *  A BANT will use a probabilistic equation to follow a track.
 *  The equation is like: take the pheromone of node i and divide
 *  with the sum of all nodes * pheromone value
 */
void ARAnetwlayer::handleBantPkt(BANT *dtg){
    /* looooop */
    EV << "[ BANT RECEIVED ] " << getParentModule()->getId() << " [ FROM ] " << dtg->getPrevious_addr() << "\n";
    if(dtg->getNext_addr() == getParentModule()->getId() and !IDB(dtg,true)){

        IDB(dtg,false);

        EV << "[ BANT ACCEPT ] " << getParentModule()->getId() << " [ FROM ] " << dtg->getPrevious_addr() << "\n";
        node_position = handleChoosePath(routing_table);
        routing_table[node_position].next_hop_forward = dtg->getPrevious_addr();

        if(getParentModule()->getId() == dtg->getDest_addr()){  // if the final dest is me
            if(isSinkNet){
                route = true;
                //data_last_id = -1;
                EV << "[ ROUTE TRUE ]\n";
                //retry = new cMessage("retry");

                if(retry->isScheduled()){
                    cancelEvent(retry);
                }
                delete dtg;
                scheduleAt(simTime(),retry);
            }
        }else{ // means that i'm in the way back to the source
            print(routing_table);
            route = true;
            dtg->setNext_addr(routing_table[node_position].next_hop_backward);
            dtg->setPrevious_addr(getParentModule()->getId());
            dtg->setHops(dtg->getHops()+1);
            dtg->setPheromone_value(1/dtg->getHops());
            routing_table[node_position].pheromone_value += dtg->getPheromone_value();
            cObject * pCtrlInfo = dtg->removeControlInfo();
            if (pCtrlInfo != NULL)
                delete pCtrlInfo;
            setDownControlInfo(dtg, LAddress::L2BROADCAST);
            sendDown(dtg);
            sent++;
        }
    }else{ delete dtg; }
}
/***********************************************************
 *               END OF PACKETS METHODS                    *
 **********************************************************/
