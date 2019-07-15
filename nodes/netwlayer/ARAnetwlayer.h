/*
 * ARAnetwlayer.h
 *
 *  Created on: 30/01/2016
 *      Author: sushi
 */
/*
 * The network layer will only set a route to a destination i, that was request by the app
 * layer.
 * First flood the network with a FANT, when a FANT reach on a node for the first time
 * create the routing table info about it.
 * When a FANT reach the destination, sent a BANT back to the source.
 * In all phases it is needed to update the pheromone value, with some function.
 * Function:
 */

#ifndef ARANETWLAYER_H_
#define ARANETWLAYER_H_

#include <BaseNetwLayer.h>
#include <ctopology.h>
#include <SimpleAddress.h>
#include <SimpleBattery.h>

class BaseWorldUtility;

class DATA;
class FANT;
class BANT;
class RETRY;
class RECEIVED_FANT;
class ROUTE_ERROR;

class ARAnetwlayer : public BaseNetwLayer{

private:

    struct table{
        LAddress::L3Type dest_addr;          //is the source_addr of the FANT
        LAddress::L3Type next_hop_backward;  //the addr to backward
        LAddress::L3Type next_hop_forward;   //the addr to forward a data
        double pheromone_value;              //based on the number of hops
    }typedef table;

    int id_last_FANT = 0;
    int id_lastest_FANT[3];
    int id_last_BANT = 0;
    int id_lastest_BANT[3];
    int id = 0;                              // used for id of fants
    int idb = 0;                             // used of id of bants
    long data = 0;
    long data_all = 0;
    long data_error = 0;
    long fant = 0;
    long bant = 0;
    long sent = 0;                           // number of total sent messages
    long received = 0;                       // number of total received messages
    int data_last_id = -1;
    int last_sent;
    int index = 0;                           // How much the routing table has ?
    int trying = 0;                          // time that try to sent an data
    int table_size;                          // size of the table
    int node_position = -1;
    double q;                                // amount constant to decremented
    double evaporation_time;                 // interval to decremented
    bool isSinkNet;                          // who is sink ?
    bool isRecNet;                           // who will receive ?
    bool route = false;                      // there is a route ?

    /*********************************
     * The TTL is used as counter    *
     * decremented in 10 for each    *
     * time tha a data packet is     *
     * transmitted                   *
     * When is retransmitted the     *
     * amount is decremented /2      *
     ********************************/
    int TTL;                                 // time to live in counter mode
    int bTTL;
    int TTLF;
    int ttl_discount;                        // discount to each transmission
    double ttl_time;                         // constant time to decrement ttl

    DATA *back_data;                         // backup to data, in case of routing failure
    table *routing_table;                    // routing table

    /*********************************
     * Control messages              *
     ********************************/
    cMessage *ttl;                           // discounting the ttl
    cMessage *ttlf;
    cMessage *step_forward;                  // Forward ant
    cMessage *step_backward;                 // Backward ant
    cMessage *evaporation;                   // Evaporation the pheromone
    cMessage *retry;                         // Retry to sent a data
    cMessage *routing_failure;               // The route is fail

    LAddress::L3Type destination;            // Who is the destination ?
    LAddress::L3Type source_addr;            // Who started ?

    cTopology::Node *thisNode;
    cTopology *topo;

    BaseWorldUtility* world;

    SimpleBattery* bt;

public:
    enum{
        DATA_PKT,
        FANT_DTG,
        BANT_DTG,
        EVAPORATION,
        RETRY_DATA,
        ROUTE_error
    };

    void finish();
    virtual ~ARAnetwlayer();

    void handleDataPkt(DATA *pkt);
    void handleFantPkt(FANT *dtg);
    void handleBantPkt(BANT *dtg);

    void handleRoutingFailure(table *routing_table, DATA *data, bool flag);
    void handleERROR(DATA *error);

    void handleTTLF();
    void handleTTL();
    bool ID(FANT *dtg, bool flag);
    bool IDB(BANT *dtg, bool flag);
    void handleEvaporation(table *routing_table);

    int handleChoosePath(table *routing_table);
    void initialize_table(table **routing_table, int table_size);
    void print(table *routing_table);

    virtual void initialize(int stage);
    virtual void handleUpperMsg(cMessage *msg);
    virtual void handleSelfMsg(cMessage *msg);
    virtual void handleLowerMsg(cMessage *msg);


    virtual void refreshDisplay() const;

protected:

};


#endif /* ARANETWLAYER_H_ */
