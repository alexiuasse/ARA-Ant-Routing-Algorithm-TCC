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

//
// TODO generated message class
//
cplusplus {{
#include "SimpleAddress.h"
}}

class LAddress::L3Type extends void;

packet RETRY{
    bool flag;
}

//packet ROUTE_ERROR{
//    LAddress::L3Type my_addr;
//    LAddress::L3Type dest_addr;
//}
//
//packet FANT {
//    int id;
//    double pheromone_value;
//    double hops;
//    LAddress::L3Type dest_addr;
//    LAddress::L3Type previous_addr;
//    LAddress::L3Type source_addr;
//}
//
//packet BANT {
//    double pheromone_value;
//    double hops;
//    int id;
//    LAddress::L3Type dest_addr;
//    LAddress::L3Type next_addr;
//    LAddress::L3Type source_addr;
//    LAddress::L3Type previous_addr;
//}
//
//packet DATA {
//    int data;    
//    double pheromone_value;
//    double hops;
//    int id;
//    int TTL;
//    bool forward;
//    bool ERROR;    
//    LAddress::L3Type my_addr;
//    LAddress::L3Type dest_addr;
//    LAddress::L3Type next_addr;
//    LAddress::L3Type source_addr;
//
//}

packet ROUTE_ERROR{
    int my_addr;
    int dest_addr;
}

packet FANT {
    int id;
    double pheromone_value;
    double hops;
    int dest_addr;
    int previous_addr;
    int source_addr;
}

packet BANT {
    double pheromone_value;
    double hops;
    int id;
    int dest_addr;
    int next_addr;
    int source_addr;
    int previous_addr;
}

packet DATA {
    int data;    
    double pheromone_value;
    double hops;
    int id;
    int TTL;
    bool forward;
    bool ERROR;    
    int my_addr;
    int dest_addr;
    int next_addr;
    int source_addr;

}