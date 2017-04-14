//
// Created by Nick Stigsell on 3/29/17.
//

#ifndef BADGER_SCHEDULE_H
#define BADGER_SCHEDULE_H


#include <string>
#include <vector>

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
public:
    Schedule(std::string name);
    void createSchedule(int grades, int sleep, int work, int social);
    void printSchedule();
    std::string getCurrentEvent();
    void createConflicts();
    void freeTime();
    void getCurrentDay();
    void getCurrentTime();
    std::string getTask();
    void advanceTime();
    std::string scheduleAccess(int r, int c);
};


#endif //BADGER_SCHEDULE_H

