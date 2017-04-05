//
// Created by Nick Stigsell on 3/29/17.
//

#ifndef BADGER_PLAYER_H
#define BADGER_PLAYER_H


#include <string>
#include "Location.h"

class Player {
private:
    std::string name;
    int age;
    bool playerLivesInHouse;
    bool playerLivesInSoutheast;
    std::string major;
    double balance;
    int attributes[4]; //[sleep, work, grades, social]
    Location currentLocation;
public:
    Player(std::string name, int age, bool house, bool southeast, std::string major, Location startingLoc);
    std::string getName();
    int getAge();
    bool getLivingSituation();
    bool getLivingLocation();
    std::string getMajor();
    double getBalance();
    void addMoney(double money);
    int subtractMoney(double money);
    void changeSleepAttribute(int sleep);
    int getSleepAttribute();
    void changeWorkAttribute(int work);
    int getWorkAttribute();
    void changeGradesAttribute(int grades);
    int getGradesAttribute();
    void changeSocialAttribute(int social);
    int getSocialAttribute();
    void printStats();
    Location getCurrentLocation();
    int setCurrentLocation(Location loc);
};


#endif //BADGER_PLAYER_H
