//
// Created by Nick Stigsell on 3/29/17.
//

#ifndef BADGER_SCHEDULE_H
#define BADGER_SCHEDULE_H


#include <string>
#include <vector>
#include <map>

class Schedule {
private:
    std::string name;
    std::string schedule[5][7];
    std::string gradeSchedule[5][7] = {
            { "Class", "Work", "Class", "", "Class", "", "" },
            { "", "Class", "", "Class", "Class", "", "" },
            { "Class", "", "Class", "", "Class", "", "" },
            { "", "", "", "", "", "", "" },
            { "", "", "", "Work", "", "", "" }
    };
    std::string sleepSchedule[5][7] = {
            { "", "", "", "", "", "", "" },
            { "Class", "Class", "Class", "Class", "Class", "", "" },
            { "Class", "", "Work", "", "", "", "" },
            { "", "", "", "", "", "", "" },
            { "", "Work", "", "", "", "", "" }
    };
    std::string workSchedule[5][7] = {
            { "Class", "", "Class", "", "Class", "Work", "" },
            { "", "Class", "", "Class", "", "Work", "" },
            { "", "", "", "Work", "", "", "" },
            { "", "", "", "", "", "", "" },
            { "Work", "", "Work", "", "", "", "Work" }
    };
    std::string socialSchedule[5][7] = {
            { "Class", "Work", "Class", "Work", "", "", "" },
            { "", "Class", "", "Class", "", "", "" },
            { "Class", "", "", "", "", "", "" },
            { "", "", "", "", "", "", "" },
            { "", "", "", "", "", "", "" }
    };
    int day;
    int time;
    std::map<int, std::string> days;
    std::map<int, std::string> times;
    std::map<int, std::vector<std::string>> allowableActivities;
public:
    Schedule(std::string name);
    void createSchedule(int grades, int sleep, int work, int social);
    void printSchedule();
    void createConflicts();
    void freeTime();
    void getCurrentDay();
    void getCurrentTime();
    bool isNight();
    bool hasClass();
    bool hasWork();
    bool hasFreetime();
    std::string getTask();
    void advanceTime();
    std::vector<std::string> getAllowableActivitiesAtCurrentTime();
    bool isAllowed(std::string);
};


#endif //BADGER_SCHEDULE_H

