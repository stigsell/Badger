#ifndef BADGER_PLAYER_H
#define BADGER_PLAYER_H

#include <string>
#include "Location.h"

class Player {
private:
    std::string name;
    int age;
    std::string major;
    double balance;
    int attributes[4]; //[sleep, work, grades, social]
    Location currentLocation;
    std::string home;
public:
    /*
     * Constructs a Player object
     */
    Player(std::string name, int age, std::string major, Location startingLoc);
    /*
     * Returns the player name
     */
    std::string getName();
    /*
     * Returns the player age
     */
    int getAge();
    /*
     * Returns the player home
     */
    std::string getHome();
    /*
     * Sets the player home to the specified home
     */
    void setHome(std::string playerHome);
    /*
     * Sends the player home
     */
    void goToHome(Location playerHome);
    /*
     * Returns the player major
     */
    std::string getMajor();
    /*
     * Returns the class location based on the player's major
     */
    std::string getClassLocation();
    /*
     * Returns the player's bank balance
     */
    double getBalance();
    /*
     * Adds money to the bank balance
     */
    void addMoney(double money);
    /*
     * Subtracts money from the bank balance. Throws an error of balance is negative
     */
    int subtractMoney(double money);
    /*
     * Changes sleep attribute
     */
    void changeSleepAttribute(int sleep);
    /*
     * Returns sleep attribute
     */
    int getSleepAttribute();
    /*
     * Changes work attribute
     */
    void changeWorkAttribute(int work);
    /*
     * Returns work attribute
     */
    int getWorkAttribute();
    /*
     * Changes grades attribute
     */
    void changeGradesAttribute(int grades);
    /*
     * Returns grades attribute
     */
    int getGradesAttribute();
    /*
     * Changes social attribute
     */
    void changeSocialAttribute(int social);
    /*
     * Returns social attribute
     */
    int getSocialAttribute();
    /*
     * Prints player's stats
     */
    void printStats();
    /*
     * Returns the current location
     */
    Location getCurrentLocation();
    /*
     * Sets the current location to the specified location
     */
    int setCurrentLocation(Location loc);
};

#endif //BADGER_PLAYER_H