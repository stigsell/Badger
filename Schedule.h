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
    /*
     * Constructs a Schedule object
     */
    Schedule(std::string name);
    /*
     * Assigns the user schedule based on the specified attributes
     */
    void createSchedule(int grades, int sleep, int work, int social);
    /*
     * Prints the user's schedule
     */
    void printSchedule();
    /*
     * Prints the current day
     */
    void getCurrentDay();
    /*
     * Prints the current time
     */
    void getCurrentTime();
    /*
     * Checks if it is night right now
     */
    bool isNight();
    /*
     * Checks if the user has class right now
     */
    bool hasClass();
    /*
     * Checks if the user has work right now
     */
    bool hasWork();
    /*
     * Checks if the user has free time right now
     */
    bool hasFreetime();
    /*
     * Returns the current task
     */
    std::string getTask();
    /*
     * Advances to the next time frame
     */
    void advanceTime();
    /*
     * Returns a vector of all allowable activities at the current time
     */
    std::vector<std::string> getAllowableActivitiesAtCurrentTime();
    /*
     * Checks if the specified activity is allowed at the current time
     */
    bool isAllowed(std::string activity);
};

#endif //BADGER_SCHEDULE_H