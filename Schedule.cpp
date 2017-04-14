#include "Schedule.h"
#include <iostream>

Schedule::Schedule(std::string scheduleName) : name(scheduleName) {
    day = 0;
    time = 0;
}

void Schedule::createSchedule(int grades, int sleep, int work, int social) {
    if(grades >= sleep && grades >= work && grades >= social) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = gradeSchedule[i][j];
            }
        }
        std::cout << "grades heavy schedule" << std::endl;
    } else if(sleep >= grades && sleep >= work && sleep >= social) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = sleepSchedule[i][j];
            }
        }
        std::cout << "sleep heavy schedule" << std::endl;
    } else if(work >= grades && work >= sleep && work >= social) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = workSchedule[i][j];
            }
        }
        std::cout << "work heavy schedule" << std::endl;
    } else { //social heavy
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = socialSchedule[i][j];
            }
        }
        std::cout << "social heavy schedule" << std::endl;
    }



}

void Schedule::printSchedule() {
    std::cout << "--------------------------------------------------------" << std::endl;
    for(int i=0; i<5; i++) {
        for(int j=0; j<7; j++) {
            if(!schedule[i][j].compare("")) {
                std::cout << "Open" << "\t";
            } else {
                std::cout << schedule[i][j] << "\t";
            }

        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------------------------------" << std::endl;
}

std::string Schedule::getCurrentEvent() { //TODO is this duplicate method?
    return schedule[time][day];
}

void Schedule::createConflicts() {

}

void Schedule::freeTime() {

}

void Schedule::getCurrentDay() {
    std::cout << "Current day: ";
    switch (day) {
        case 0: std::cout << "Monday" << std::endl;
            break;
        case 1: std::cout << "Tuesday" << std::endl;
            break;
        case 2: std::cout << "Wednesday"<< std::endl;
            break;
        case 3: std::cout << "Thursday"<< std::endl;
            break;
        case 4: std::cout << "Friday"<< std::endl;
            break;
        case 5: std::cout << "Saturday"<< std::endl;
            break;
        case 6: std::cout << "Sunday"<< std::endl;
            break;
        default: std::cout << "ERROR: Invalid day" << std::endl;
            break;
    }
}

void Schedule::getCurrentTime() {
    std::cout << "Current time: ";
    switch (time) {
        case 0: std::cout << "Morning" << std::endl;
            break;
        case 1: std::cout << "Early Afternoon"<< std::endl;
            break;
        case 2: std::cout << "Late Afternoon"<< std::endl;
            break;
        case 3: std::cout << "Dinner"<< std::endl;
            break;
        case 4: std::cout << "Night"<< std::endl;
            break;
        default: std::cout << "ERROR: Invalid time" << std::endl;
            break;
    }
}

std::string Schedule::getTask() {
    return schedule[time][day];
}
void Schedule::advanceTime() {
    if(time == 4) {
        if(day == 6) {
            std::cout << "Game over" << std::endl;
        } else {
            time = 0;
            day++;
        }
    } else {
        time++;
    }
    getCurrentTime();
}
std::string Schedule::scheduleAccess(int r, int c) {

}