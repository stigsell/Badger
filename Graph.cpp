//
// Created by Nick Stigsell on 3/29/17.
//

#include <iostream>
#include "Graph.h"

Graph::Graph(std::string name) : campusName(name) {

}
bool Graph::addVertex(Location l) {
    locations.push_back(l);
    return true;
}
std::vector<Location> Graph::getAllLocations() {
    return locations;
}
Location* Graph::getLocation(std::string name) {
    for(auto l : locations) {
        if(!l.getName().compare(name)) {
            return &l;
        }
    }
    return NULL;
}