//
// Created by Nick Stigsell on 3/29/17.
//

#ifndef BADGER_LOCATION_H
#define BADGER_LOCATION_H


#include <string>
#include <vector>

class Location {
private:
    std::string displayName;
    std::string shortName;
    std::vector<std::string> allowableActivities;
    std::vector<Location> adjacentLocations;
public:
    Location(std::string dName, std::string sName, std::vector<std::string> activities);
    std::string getDisplayName();
    std::string getShortName();
    std::vector<std::string> getAllowableActivities();
    bool isAllowed(std::string);
    bool isAdjacentTo(Location loc);
    std::vector<Location> getAdjacentLocations();
    bool addEdge(Location &loc);
};


#endif //BADGER_LOCATION_H
