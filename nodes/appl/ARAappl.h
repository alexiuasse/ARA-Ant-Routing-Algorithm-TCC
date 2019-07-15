/*
 * ARAappl.h
 *
 *  Created on: 30/01/2016
 *      Author: sushi
 */
/*
 * The app layer will only request a data from a certain node i
 *
 */

#ifndef ARAAPPL_H_
#define ARAAPPL_H_

#include <BaseApplLayer.h>
#include <SimpleAddress.h>


class DATA;

class ARAappl : public BaseApplLayer{

private:
    bool isSinkAppl;
    cMessage *request_data;
    int destination;
    int source_addr;
    cTopology *topo;
//    int thisNode;
    int at = 0;

public:

    enum{
        DATA_PKT,
        RETRY_DATA
    };

    virtual ~ARAappl();
    void handleDataPkt(DATA *pkt);
    virtual void initialize(int stage);
    virtual void handleSelfMsg(cMessage *msg);
    virtual void handleLowerMsg(cMessage *msg);

protected:

};



#endif /* ARAAPPL_H_ */
