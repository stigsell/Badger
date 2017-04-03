//
// Created by Nick Stigsell on 3/29/17.
//

#include "Player.h"
#include <iostream>

Player::Player(std::string name, int age, bool house, bool southeast, std::string major, Location startingLoc)
             : name(name), age(age), playerLivesInHouse(house), playerLivesInSoutheast(southeast), major(major), currentLocation(startingLoc) {
    balance = 0.0;
    attributes[0] = 0;
    attributes[1] = 0;
    attributes[2] = 0;
    attributes[3] = 0;

}
std::string Player::getName() {
    return name;
}
int Player::getAge() {
    return age;
}

bool Player::getLivingSituation() {
    return playerLivesInHouse;
}
bool Player::getLivingLocation() {
    return playerLivesInSoutheast;
}
std::string Player::getMajor() {
    return major;
}
double Player::getBalance() {
    return balance;
}
void Player::addMoney(double money) {
    balance += money;
}
int Player::subtractMoney(double money) {
    if(balance - money > 0) {
        balance -= money;
        return 0;
    } else {
        return -1; //error, not enough money for transaction
    }

}
void Player::setSleepAttribute(int sleep) {
    attributes[0] = sleep;
}
int Player::getSleepAttribute() {
    return attributes[0];
}
void Player::setWorkAttribute(int work) {
    attributes[1] = work;
}
int Player::getWorkAttribute() {
    return attributes[1];
}
void Player::setGradesAttribute(int grades) {
    attributes[2] = grades;
}
int Player::getGradesAttribute() {
    return attributes[2];
}
void Player::setSocialAttribute(int social) {
    attributes[3] = social;
}
int Player::getSocialAttribute() {
    return attributes[3];
}
void Player::printStats() {
    std::cout << "Sleep: " << getSleepAttribute() << std::endl;
    std::cout << "Work: " << getWorkAttribute() << std::endl;
    std::cout << "Grades: " << getGradesAttribute() << std::endl;
    std::cout << "Social: " << getSocialAttribute() << std::endl;
    std::cout << "Bank balance: $" << getBalance() << std::endl;
    std::cout << "Work location: Union South" << std::endl;
}
Location Player::getCurrentLocation() {
    return currentLocation;
}
int Player::setCurrentLocation(Location loc) {
    std::vector<Location> adjacentToProposedMove = currentLocation.getAdjacentLocations();
    for(auto l : adjacentToProposedMove) {
        if(!l.getDisplayName().compare(loc.getDisplayName())) {
            currentLocation = loc;
            return 0;
        }
    }
    return -1; //not accessible
}