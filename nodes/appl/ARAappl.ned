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

package org.mixim.examples.nodes.appl;

import org.mixim.base.modules.IBaseApplLayer;

//
// TODO auto-generated type
//
simple ARAappl like IBaseApplLayer
{
    parameters:
        int destination = default(0);
        int source_addr = default(0);
        int headerLength @unit("bit");
        bool isSinkAppl = default(false);
        @class(ARAappl);

    gates:
        input lowerLayerIn; 	// From network layer
        output lowerLayerOut; 	// To network layer
        input lowerControlIn; 	// Control from network layer
        output lowerControlOut; // Control to network layer 
}
