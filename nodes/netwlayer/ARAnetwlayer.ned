//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package org.mixim.examples.nodes.netwlayer;

import org.mixim.base.modules.BaseNetwLayer;


//
// TODO auto-generated type
//
simple ARAnetwlayer extends BaseNetwLayer
{
    parameters:
        @class(ARAnetwlayer);
        //********** TIME TO LIVE **********//
        int TTL = default(100);								// Time To Live in counter mode
        double ttl_time @unit(s) = default(0.01s);			// constant time to decrement ttl
        int ttl_discount = default(10);						// discount to each transmission
        
        //********** EVAPORATION **********//
        double q = default(0.5);							// constant of amount evaporation        
        double evaporation_time @unit(s) = default(0.001s);	// interval to evaporate

        int source_addr = default(0);
        int destination = default(0);
        int table_size = default(5);						// size of the routing table

        bool isSinkNet = default(false);
        bool isRecNet = default(false);
}
