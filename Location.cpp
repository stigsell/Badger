//
// Created by Nick Stigsell on 3/29/17.
//

#include <iostream>
#include "Location.h"
Location::Location(std::string dName, std::string sName, std::vector<std::string> allowable)
            : displayName(dName), shortName(sName), allowableActivities(allowable) {

}

std::string Location::getDisplayName(){
    return displayName;
}
std::string Location::getShortName(){
    return shortName;
}
std::vector<std::string> Location::getAllowableActivities() {
    return allowableActivities;
}
bool Location::isAllowed(std::string activity) {
    for(auto a : allowableActivities) {
        if(!activity.compare(a)) {
            return true;
        }
    }
    return false;
    //TODO implement this function
}
bool Location::isAdjacentTo(Location loc) {
    for(auto l : adjacentLocations) {
        if(!l.getDisplayName().compare(loc.getDisplayName())) {
            return true;
        }
    }
    return false;
}
std::vector<Location> Location::getAdjacentLocations() {
    return adjacentLocations;
}
bool Location::addEdge(Location &loc) {
    adjacentLocations.push_back(loc);
    return true;
}