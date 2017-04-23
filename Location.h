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
    /*
     * Constructs a location object
     */
    Location(std::string dName, std::string sName, std::vector<std::string> activities);
    /*
     * Returns the display name of this location
     */
    std::string getDisplayName();
    /*
     * Returns the short name of this location
     */
    std::string getShortName();
    /*
     * Returns a vector of allowable activities at this location
     */
    std::vector<std::string> getAllowableActivities();
    /*
     * Checks if the specified activity is allowed at this location
     */
    bool isAllowed(std::string activity);
    /*
     * Checks if this location is adjacent to the specified location
     */
    bool isAdjacentTo(Location loc);
    /*
     * Returns a vector of all locations adjacent to this one
     */
    std::vector<Location> getAdjacentLocations();
    /*
     * Adds an edge between this location and the specified location
     */
    bool addEdge(Location &loc);
};

#endif //BADGER_LOCATION_H