#include <iostream>
#include "Graph.h"
/*
 *
 */
Graph::Graph(std::string name) : campusName(name) {

}

void Graph::addVertex(Location l) {
    locations.push_back(l);
}

bool Graph::isValidLocation(std::string locationName) {
    for(auto l : locations) {
        if(!l.getShortName().compare(locationName)) {
            return true;
        }
    }
    return false;
}

bool Graph::isValidMove(Location loc1, Location loc2) {
    if(loc1.isAdjacentTo(loc2) && loc2.isAdjacentTo(loc1)) { //TODO do we need to check both directions? i.e. loc1 -> loc 2 && loc2 -> loc1
        return true;
    }
    return false;
}

std::vector<Location> Graph::getAllLocations() {
    return locations;
}

Location Graph::getLocation(std::string name) {
    for(auto l : locations) {
        if(!l.getShortName().compare(name)) {
            return l;
        }
    }
    //no location found
    throw "No location found"; //TODO more advanced error handling
}