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

package org.mixim.examples.nodes;

import org.mixim.modules.node.WirelessNodeBatteryNetwl;


//
// TODO auto-generated type
//
module ARAnode extends WirelessNodeBatteryNetwl
{
    parameters:
        networkType = "org.mixim.examples.nodes.netwlayer.ARAnetwlayer";
        nicType = "Nic802154_TI_CC2420";								//Radio model
        int numHosts;

        @display("i=device/pocketpc;is=n;bgl=3");
    connections allowunconnected:
}
