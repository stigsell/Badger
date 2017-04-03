//
// Created by Nick Stigsell on 3/29/17.
//

#ifndef BADGER_GRAPH_H
#define BADGER_GRAPH_H


#include <map>
#include <vector>
#include "Location.h"

class Graph {
private:
    std::string campusName;
    std::vector<Location> locations;
public:
    Graph(std::string campusName); //TODO remove the need for campusName. Should just be able to call a default constructor
    bool addVertex(Location l);
    std::vector<Location> getAllLocations();
    Location getLocation(std::string name);
};


#endif //BADGER_GRAPH_H
