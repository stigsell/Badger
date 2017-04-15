#include "Schedule.h"
#include <iostream>

Schedule::Schedule(std::string scheduleName) : name(scheduleName) {
    day = 0;
    time = 0;
    days[0] = "Monday";
    days[1] = "Tuesday";
    days[2] = "Wednesday";
    days[3] = "Thursday";
    days[4] = "Friday";
    days[5] = "Saturday";
    days[6] = "Sunday";

    times[0] = "Morning";
    times[1] = "Early Afternoon";
    times[2] = "Late Afternoon";
    times[3] = "Dinner";
    times[4] = "Night";
}

void Schedule::createSchedule(int grades, int sleep, int work, int social) {
    if(grades >= sleep && grades >= work && grades >= social) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = gradeSchedule[i][j];
            }
        }
    } else if(sleep >= grades && sleep >= work && sleep >= social) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = sleepSchedule[i][j];
            }
        }
    } else if(work >= grades && work >= sleep && work >= social) {
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = workSchedule[i][j];
            }
        }
    } else { //social heavy
        for(int i=0; i<5; i++) {
            for(int j=0; j<7; j++) {

                schedule[i][j] = socialSchedule[i][j];
            }
        }
    }



}

void Schedule::printSchedule() {
    std::cout << "----------------------------------------------------------------------" << std::endl;
    std::cout << "Time \t \t \t Mon\tTues\tWed\t\tThur\tFri\t\tSat\t\tSun" << std::endl;
    std::cout << "----------------------------------------------------------------------" << std::endl;
    for(int i=0; i<5; i++) {
        if(i == 1 || i == 2) { //format long time names (early afternoon, late afternoon) better
            std::cout << times[i] << "\t|";
        } else {
            std::cout << times[i] << "\t \t \t|";
        }

        for(int j=0; j<7; j++) {
            if(!schedule[i][j].compare("")) {
                std::cout << "Open" << "\t";
            } else {
                std::cout << schedule[i][j] << "\t";
            }

        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------------------------------------" << std::endl;
}

void Schedule::createConflicts() {

}

void Schedule::freeTime() {

}

void Schedule::getCurrentDay() {
    std::cout << "Current day: " << days[day] << std::endl;

//    switch (day) {
//        case 0: std::cout << "Monday" << std::endl;
//            break;
//        case 1: std::cout << "Tuesday" << std::endl;
//            break;
//        case 2: std::cout << "Wednesday"<< std::endl;
//            break;
//        case 3: std::cout << "Thursday"<< std::endl;
//            break;
//        case 4: std::cout << "Friday"<< std::endl;
//            break;
//        case 5: std::cout << "Saturday"<< std::endl;
//            break;
//        case 6: std::cout << "Sunday"<< std::endl;
//            break;
//        default: std::cout << "ERROR: Invalid day" << std::endl;
//            break;
//    }
}

void Schedule::getCurrentTime() {
    std::cout << "Current time: " << times[time] << std::endl;
//    switch (time) {
//        case 0: std::cout << "Morning" << std::endl;
//            break;
//        case 1: std::cout << "Early Afternoon"<< std::endl;
//            break;
//        case 2: std::cout << "Late Afternoon"<< std::endl;
//            break;
//        case 3: std::cout << "Dinner"<< std::endl;
//            break;
//        case 4: std::cout << "Night"<< std::endl;
//            break;
//        default: std::cout << "ERROR: Invalid time" << std::endl;
//            break;
//    }
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