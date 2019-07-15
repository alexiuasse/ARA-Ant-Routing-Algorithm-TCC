/*
 * ARAappl.cc
 *
 *  Created on: 30/01/2016
 *      Author: sushi
 */
/*
 * The app layer will only request a data from a certain node i
 * Create a function that generate random number for data.
 */

#include <ARAappl.h>
#include <ARAmessages_m.h>
#include <cenvir.h>
#include <cmessage.h>
#include <cmodule.h>
#include <cobjectfactory.h>
#include <cpar.h>
#include <cregistrationlist.h>
#include <csimulation.h>
#include <regmacros.h>
#include <simutil.h>

Define_Module (ARAappl);
/*
 *
 */
void ARAappl::initialize(int stage){
    BaseApplLayer::initialize(stage);
    if(stage == 0){
        isSinkAppl = par("isSinkAppl");
        if(isSinkAppl){
            topo = new cTopology("topo");
            std::vector<std::string> nedTypes;
            nedTypes.push_back(getParentModule()->getNedTypeName());
            topo->extractByNedTypeName(nedTypes);

            destination = topo->getNode(7)->getModuleId();
            source_addr = topo->getNode(0)->getModuleId();
//            thisNode = topo->getNode(0)->getModuleId();

            WATCH(destination);
            WATCH(source_addr);
        }

    }else if(stage == 1){
        //        EV << getId() << "\n";
        request_data = new cMessage("request_data");
        if(isSinkAppl){
            if(request_data->isScheduled()){
                cancelEvent(request_data);
            }
            scheduleAt(simTime()+0.5,request_data);
        }
    }
}

ARAappl::~ARAappl(){

    cOwnedObject *Del=NULL;
    int OwnedSize=this->defaultListSize();
    for(int i=0;i<OwnedSize;i++){
        Del=this->defaultListGet(0);
        this->drop(Del);
        delete Del;
    }
    //cancelAndDelete(request_data);
}

/*
 * Create a packet request of data and send to network layer
 */
void ARAappl::handleSelfMsg(cMessage *msg){
    if(msg == request_data){

//        if(at == 2){
//            while(true){
//                destination = topo->getNode(rand()%topo->getNumNodes())->getModuleId();
//                if (destination != source_addr) break; // skip ourselves
//            }
//            ev << "[ DESTINATION ] : " << destination << "\n";
//            at = 0;
//        }else{
//            at ++;
//        }

        // EV << "IN DATA\n";
        DATA *pkt = new DATA("DATA_PKT",DATA_PKT);
        pkt->setDest_addr(destination);
        pkt->setSource_addr(source_addr);
        pkt->setForward(true);
        pkt->setData(0);
        pkt->setERROR(false);
        pkt->setNext_addr(-1);
        pkt->setId(0);
        EV << "[ SINK CREATE A DATA ] : " << pkt << "\n";
        sendDown(pkt);
    }
}
/*
 *
 */
void ARAappl::handleLowerMsg(cMessage *msg){

    //EV << "[ MSG KIND APPL ] " << msg->getFullName() << "\n";
    if(isSinkAppl){
        delete msg;
        EV << "[ RETRY DATA ]\n";
        if(request_data->isScheduled()){
            cancelEvent(request_data);
        }
        scheduleAt(simTime(),request_data);
    }else{
        EV << "[ DATA ]\n";
        handleDataPkt(static_cast<DATA*>(msg));
    }
}
/*
 *
 */
void ARAappl::handleDataPkt(DATA *pkt){
    EV << "[ NODE CREATING DATA ] : " << pkt << "\n";
    LAddress::L3Type addr = pkt->getDest_addr();
    pkt->setData(rand()%2000);
    pkt->setForward(false);
    pkt->setERROR(false);
    pkt->setId(pkt->getId()+1);
    pkt->setDest_addr(pkt->getSource_addr());
    pkt->setSource_addr(addr);
    sendDown(pkt);
}


