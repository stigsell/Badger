//
// Created by Nick Stigsell on 3/29/17.
//

#include "Player.h"
#include <iostream>

Player::Player(std::string name, int age, std::string major, Location startingLoc)
             : name(name), age(age), major(major), currentLocation(startingLoc) {
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
void Player::changeSleepAttribute(int sleep) {
    attributes[0] += sleep;
}
int Player::getSleepAttribute() {
    return attributes[0];
}
void Player::changeWorkAttribute(int work) {
    attributes[1] += work;
}
int Player::getWorkAttribute() {
    return attributes[1];
}
void Player::changeGradesAttribute(int grades) {
    attributes[2] += grades;
}
int Player::getGradesAttribute() {
    return attributes[2];
}
void Player::changeSocialAttribute(int social) {
    attributes[3] += social;
}
int Player::getSocialAttribute() {
    return attributes[3];
}
std::string Player::getHome() {
    return home;
}
void Player::setHome(std::string playerHome) {
    home = playerHome;
}
void Player::goToHome(Location playerHome) {
    currentLocation = playerHome;
}
void Player::printStats() {
    std::cout << "Sleep: " << getSleepAttribute() << std::endl;
    std::cout << "Work: " << getWorkAttribute() << std::endl;
    std::cout << "Grades: " << getGradesAttribute() << std::endl;
    std::cout << "Social: " << getSocialAttribute() << std::endl;
    std::cout << "Bank balance: $" << getBalance() << std::endl;
    std::cout << "Major: " << major << std::endl;
    std::cout << "Work location: Union South" << std::endl;
    std::cout << "Home: " << home << std::endl;
    std::string classLocation;
    if(!major.compare("business")) {
        classLocation = "Grainger Hall";
    } else if (!major.compare("science")) {
        classLocation = "Bascom Hill";
    } else if (!major.compare("CS")) {
        classLocation = "CS Building";
    } else { //engineering
        classLocation = "Engineering Hall";
    }
    std::cout << "Class location: " << classLocation << std::endl;
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