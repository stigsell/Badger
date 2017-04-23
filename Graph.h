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
    /*
     * Constructs a graph object
     */
    Graph(std::string campusName); //TODO remove the need for campusName. Should just be able to call a default constructor
    /*
     * Add a location to the graph
     */
    void addVertex(Location l);
    /*
     * Checks if the location exists in the graph
     */
    bool isValidLocation(std::string locationName);
    /*
     * Checks if the two specified locations are adjacent to each other
     */
    bool isValidMove(Location loc1, Location loc2);
    /*
     * Returns a vector of all locations in the graph
     */
    std::vector<Location> getAllLocations();
    /*
     * Returns a location object based on the name specified
     */
    Location getLocation(std::string name);
};

#endif //BADGER_GRAPH_H