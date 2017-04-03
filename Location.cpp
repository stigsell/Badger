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
bool Location::isAllowed(std::string) {
    return true;
    //TODO implement this function
}
std::vector<Location> Location::getAdjacentLocations() {
    return adjacentLocations;
}
bool Location::addEdge(Location &loc) {
    adjacentLocations.push_back(loc);
    return true;
}