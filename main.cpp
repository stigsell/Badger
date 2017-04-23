#include <iostream>
#include <stdlib.h>
#include<limits>
#include "Player.h"
#include "Location.h"
#include "Graph.h"
#include "Schedule.h"
//Global pointers
Player *player;
Graph *campus;
Schedule *mySchedule;
//Global variables
static const int TOTAL_POINTS = 20;
static const double BASE_STARTING_MONEY = 400;
std::map<std::string, std::vector<std::string>> activitiesActions;
std::string playerHome;
/*
 * Creates the schedule for the player and prints it so the user sees it
 */
void createSchedule() {
    mySchedule = new Schedule("");
    mySchedule->createSchedule(player->getGradesAttribute(), player->getSleepAttribute(), player->getWorkAttribute(), player->getSocialAttribute());
    mySchedule->printSchedule();
}
/*
 * Gets user input to create the player object
 */
void assignPlayerDetails() {
    //Name
    std::string playerName;
    std::cout << "What is your name? ";
    getline(std::cin, playerName);
    std::cout << "Welcome, " << playerName << "! We're glad you're playing" << std::endl;

    //Age
    int playerAge;
    do {
        std::cout << "What is your age? ";
        while(!(std::cin >> playerAge)) {
            std::cout << "Incorrect input. Please try again. ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if(playerAge < 18) {
            std::cout << "Error: Age must be greater than or equal to 18" << std::endl;
        }
    } while(playerAge < 18);
    std::cout << "You're " << playerAge << " years old" << std::endl; //remove
    //Major
    bool validInput = true;
    std::string playerMajor;
    do {
        int decision;
        std::cout << "What's your major? Your choices are: business, science, CS, or engineering.  Enter '1' for business, '2' for science, '3' for CS, '4' for engineering" << std::endl;
        while(!(std::cin >> decision)) {
            std::cout << "Incorrect input. Please try again. ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if(decision == 1) {
            playerMajor = "business";
            validInput = true;
        } else if(decision == 2) {
            playerMajor = "science";
            validInput = true;
        } else if(decision == 3) {
            playerMajor = "CS";
            validInput = true;
        } else if(decision == 4) {
            playerMajor = "engineering";
            validInput = true;
        } else {
            std::cout << "Error: Enter '1', '2', '3', or '4'" << std::endl;
            validInput = false;
        }
    } while (!validInput);
    std::cout << playerMajor << "! Nice choice" << std::endl;

    //Work location
    std::cout << "You work as a cook at Union South. Whenever you have work you need to go to Union South" << std::endl;

    //Create Player object
    player = new Player(playerName, playerAge, playerMajor, campus->getLocation("union south"));
}
/*
 * Assigns player attributes by getting user input
 */
void assignPlayerAttributes() {
    int pointsUsed = 0;
    std::cout << "Now's the time to assign attributes to your player." << std::endl;
    std::cout << "There are 4 attributes: sleep, work, grades, and social life" << std::endl;
    std::cout << "To start off the game, you have 20 attribute points to distribute among the 4 attributes" << std::endl;
    std::cout << "It's important to have a balance of attributes" << std::endl;
    std::cout << "These attributes will change throughout the game as you make decisions" << std::endl;

    //sleep
    int sleep;
    do {
        std::cout << "How many points would you like to allocate to sleep? You have " << TOTAL_POINTS - pointsUsed << " points left. " << std::endl;
        while(!(std::cin >> sleep)) {
            std::cout << "Incorrect input. Please try again. ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if(sleep > TOTAL_POINTS - pointsUsed) {
            std::cout << "Error: You don't have that many points available" << std::endl;
        }
        if(sleep < 0) {
            std::cout << "Error: Must be a positive number" << std::endl;
        }
    } while ((sleep > TOTAL_POINTS - pointsUsed) || (sleep < 0));

    pointsUsed += sleep;
    std::cout << "You allocated " << sleep << " points to sleep. You have " << TOTAL_POINTS - pointsUsed << " left to allocate." << std::endl;

    //work
    int work;
    do {
        std::cout << "How many points would you like to allocate to work? You have " << TOTAL_POINTS - pointsUsed << " points left. " << std::endl;
        while(!(std::cin >> work)) {
            std::cout << "Incorrect input. Please try again. ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if(work > TOTAL_POINTS - pointsUsed) {
            std::cout << "Error: You don't have that many points available" << std::endl;
        }
        if(work < 0) {
            std::cout << "Error: Must be a positive number" << std::endl;
        }
    } while ((work > TOTAL_POINTS - pointsUsed) || (work < 0));

    pointsUsed += work;
    std::cout << "You allocated " << work << " points to work. You have " << TOTAL_POINTS - pointsUsed << " left to allocate." << std::endl;

    //grades
    int grades;
    do {
        std::cout << "How many points would you like to allocate to grades? You have " << TOTAL_POINTS - pointsUsed << " points left. " << std::endl;
        while(!(std::cin >> grades)) {
            std::cout << "Incorrect input. Please try again. ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if(grades > TOTAL_POINTS - pointsUsed) {
            std::cout << "Error: You don't have that many points available" << std::endl;
        }
        if(grades < 0) {
            std::cout << "Error: Must be a positive number" << std::endl;
        }
    } while ((grades > TOTAL_POINTS - pointsUsed) || (grades < 0));

    pointsUsed += grades;
    std::cout << "You allocated " << grades << " points to grades. You have " << TOTAL_POINTS - pointsUsed << " left to allocate." << std::endl;

    //social
    int social = TOTAL_POINTS - pointsUsed;
    std::cout << "You have " << TOTAL_POINTS - pointsUsed << " points left. They are all automatically allocated to social life." << std::endl;

    player->changeSleepAttribute(sleep);
    player->changeWorkAttribute(work);
    player->changeGradesAttribute(grades);
    player->changeSocialAttribute(social);
}
/*
 * Gives the user a random amount of money. Adds $150 if their work score is 7 or higher
 */
void assignPlayerMoney() {
    srand(time(0)); //sets random seed
    double money = rand() % 100 + 1;
    money += BASE_STARTING_MONEY;
    player->addMoney(money);
    std::cout << "You've started the game with : $" << money << std::endl;
    if(player->getWorkAttribute() >= 7) {
        std::cout << "Congrats! Your high work score has added $150 to your balance." << std::endl;
        player->addMoney(150);
        std::cout << "You now have $" << player->getBalance() << std::endl;
    }
}
/*
 * Creates the graph that stores the locations of the game
 */
void setUpLocationsGraph() {
    campus = new Graph("UW-Madison"); //create graph
    //create locations
    Location lakeshore("Lakeshore", "lakeshore", {"study", "relax", "socialize", "go out", "eat at home"});
    Location eHall("Engineering Hall", "engineering hall", {"study"});
    Location crHousing("Housing Near Camp Randall", "housing near camp randall", {"study", "relax", "socialize", "eat at home"});
    Location cRandall("Camp Randall", "camp randall", {"socialize", "go out"});
    Location uSouth("Union South", "union south", {"study", "socialize", "eat out with friends"});
    Location bascom("Bascom Hill", "bascom hill", {"study", "relax"});
    Location collegeLib("College Library", "college library", {"study"});
    Location csBuilding("CS Building", "cs building", {"study"});
    Location grainger("Grainger Hall", "grainger hall", {"study"});
    Location stateSt("State Street", "state street", {"socialize", "go out", "eat out with friends"});
    Location theHub("The Hub", "the hub", {"study", "relax", "socialize", "go out", "eat at home"});
    Location dons("Gordon's Dining Hall", "gordon's dining hall", {"socialize", "eat out with friends"});
    Location mifflin("Mifflin St.", "mifflin st.", {"study", "relax", "socialize", "go out", "eat at home"});
    //add edges

    //lakeshore
    lakeshore.addEdge(eHall);
    lakeshore.addEdge(bascom);
    //eHall
    eHall.addEdge(lakeshore);
    eHall.addEdge(uSouth);
    eHall.addEdge(cRandall);
    eHall.addEdge(crHousing);
    //crHousing
    crHousing.addEdge(eHall);
    crHousing.addEdge(cRandall);
    //cRandall
    cRandall.addEdge(uSouth);
    cRandall.addEdge(eHall);
    cRandall.addEdge(crHousing);
    cRandall.addEdge(mifflin);
    //uSouth
    uSouth.addEdge(bascom);
    uSouth.addEdge(csBuilding);
    uSouth.addEdge(dons);
    uSouth.addEdge(cRandall);
    uSouth.addEdge(eHall);
    //bascom
    bascom.addEdge(lakeshore);
    bascom.addEdge(uSouth);
    bascom.addEdge(grainger);
    bascom.addEdge(collegeLib);
    //collegeLib
    collegeLib.addEdge(bascom);
    collegeLib.addEdge(grainger);
    collegeLib.addEdge(stateSt);
    //csBuilding
    csBuilding.addEdge(uSouth);
    csBuilding.addEdge(grainger);
    //grainger
    grainger.addEdge(stateSt);
    grainger.addEdge(collegeLib);
    grainger.addEdge(bascom);
    grainger.addEdge(csBuilding);
    grainger.addEdge(dons);
    //stateSt
    stateSt.addEdge(theHub);
    stateSt.addEdge(collegeLib);
    stateSt.addEdge(grainger);
    //theHub
    theHub.addEdge(stateSt);
    //dons
    dons.addEdge(mifflin);
    dons.addEdge(grainger);
    dons.addEdge(uSouth);
    //mifflin
    mifflin.addEdge(cRandall);
    mifflin.addEdge(dons);

    //add locations to graph
    campus->addVertex(lakeshore);
    campus->addVertex(eHall);
    campus->addVertex(crHousing);
    campus->addVertex(cRandall);
    campus->addVertex(uSouth);
    campus->addVertex(bascom);
    campus->addVertex(collegeLib);
    campus->addVertex(csBuilding);
    campus->addVertex(grainger);
    campus->addVertex(stateSt);
    campus->addVertex(theHub);
    campus->addVertex(dons);
    campus->addVertex(mifflin);

    //A map that maps an action with a list of places where that action can be performed
    activitiesActions["study"] = {"Lakeshore", "Engineering Hall", "Housing Near Camp Randall", "Union South", "Bascom Hill", "College Library", "CS Building", "Grainger Hall", "The Hub", "Mifflin St."};
    activitiesActions["relax"] = {"Lakeshore", "Housing Near Camp Randall", "The Hub", "Mifflin St.", "Bascom Hill"};
    activitiesActions["socialize"] = {"Lakeshore", "Housing Near Camp Randall", "Camp Randall", "Union South", "State Street", "The Hub", "Gordon's Dining Hall", "Mifflin St."};
    activitiesActions["go out"] = {"Lakeshore", "Housing Near Camp Randall", "State Street", "The Hub", "Mifflin St."};
    activitiesActions["eat at home"] = {"Lakeshore", "Housing Near Camp Randall", "The Hub", "Mifflin St."};
    activitiesActions["eat out with friends"] = {"Union South", "State Street", "Gordon's Dining Hall"};
    activitiesActions["stay in"] = {"Lakeshore", "Housing Near Camp Randall", "The Hub", "Mifflin St."};
}
/*
 * Gets user input to determine the player's home and update the player object with the player home
 */
void assignPlayerHome() {
    bool validInput = true;
    do {
        int decision;
        std::cout << "Where would you like to live? Enter '1' for Lakeshore, '2' for The Hub, '3' for Mifflin St., '4' for Housing Near Camp Randall" << std::endl;
        while(!(std::cin >> decision)) {
            std::cout << "Incorrect input. Please try again. ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if(decision == 1) {
            playerHome = "lakeshore";
            validInput = true;
        } else if(decision == 2) {
            playerHome = "the hub";
            validInput = true;
        } else if(decision == 3) {
            playerHome = "mifflin st.";
            validInput = true;
        } else if(decision == 4) {
            playerHome = "housing near camp randall";
            validInput = true;
        } else {
            std::cout << "Error: Enter '1', '2', '3', or '4'" << std::endl;
            validInput = false;
        }
    } while (!validInput);
    std::cout << playerHome << "! Nice choice" << std::endl;
    player->setHome(playerHome);
    player->goToHome(campus->getLocation(playerHome));
}
/*
 * Prints the player stats
 */
void processStatsCommand() {
    player->printStats();
    mySchedule->printSchedule();
}
/*
 * Prints the current day and time
 */
void processNowCommand() {
    mySchedule->getCurrentDay();
    mySchedule->getCurrentTime();
}
/*
 * Prints the current location and the adjacent locations
 */
void processNearmeCommand() {
    std::cout << "You are at: " << player->getCurrentLocation().getDisplayName() << std::endl;
    std::cout << "From here, you can move to: " << std::endl;
    std::vector<Location> nearby = player->getCurrentLocation().getAdjacentLocations();
    for(auto l : nearby) {
        std::cout << "\t" << l.getDisplayName() << std::endl;
    }
}
/*
 * Moves the player to the location specified by token
 */
void processMoveCommand(std::string token) {
    if(campus->isValidLocation(token)) {
        Location loc = campus->getLocation(token);
        if(campus->isValidMove(player->getCurrentLocation(), loc)) {
            player->setCurrentLocation(loc);
            std::cout << "Welcome to " << player->getCurrentLocation().getDisplayName() << std::endl;
            std::cout << "From here, you can move to: " << std::endl;
            std::vector<Location> nearby = player->getCurrentLocation().getAdjacentLocations();
            for(auto l : nearby) {
                std::cout << "\t" << l.getDisplayName() << std::endl;
            }
        } else {
            std::cout << "Error: " << loc.getDisplayName() << " is not accessible from " << player->getCurrentLocation().getDisplayName() << std::endl;
        }
    } else {
        std::cout << "Error: not a valid location. Make sure you typed it exactly as it appears on your screen " << std::endl;
    }
}
/*
 * Performs the task specified by token. If token is blank, print a list of available actions based on time and location
 */
void processTaskCommand(std::string token) {
    //Get class location
    std::string classLocation;
    if(!player->getMajor().compare("business")) {
        classLocation = "Grainger Hall";
    } else if (!player->getMajor().compare("science")) {
        classLocation = "Bascom Hill";
    } else if (!player->getMajor().compare("CS")) {
        classLocation = "CS Building";
    } else { //engineering
        classLocation = "Engineering Hall";
    }
    //Blank token. Print available actions
    if(token.size() == 0) {
        std::cout << "You have: ";
        if(!mySchedule->getTask().compare("")) {
            std::cout << "Open" << std::endl;
            std::cout << "Right now you can:";
            for(auto a : mySchedule->getAllowableActivitiesAtCurrentTime()) {
                std::cout << " " << a << ",";
            }
            std::cout << std::endl;
            for(auto a : mySchedule->getAllowableActivitiesAtCurrentTime()) {
                std::cout << "\tYou can " << a << " at : ";
                for(auto l : activitiesActions[a]) {
                    std::cout << " " << l << ",";
                }
                std::cout << std::endl;
            }
            std::cout << "Here, you can:";
            for(auto a : player->getCurrentLocation().getAllowableActivities()) {
                std::cout << " " << a << ",";
            }
        } else {
            std::cout << mySchedule->getTask();
        }
        std::cout << std::endl;
    }
    //Class
    if((!mySchedule->getTask().compare("Class"))  && (!token.compare("class"))) {
        if(!player->getCurrentLocation().getDisplayName().compare(classLocation)) {
            std::cout << "Thanks for coming to class!" << std::endl;
            player->changeGradesAttribute(1);
            if(mySchedule->isNight()) {
                player->goToHome(campus->getLocation(player->getHome()));
                std::cout << "Now that the night's over, you are now at home" << std::endl;
            }
            mySchedule->advanceTime();
            return; //exit function
        } else {
            std::cout << "You're not in your class location. Move to " << classLocation << std::endl;
        }
    }
    //Work
    if((!mySchedule->getTask().compare("Work"))  && (!token.compare("work"))) {
        if(!player->getCurrentLocation().getDisplayName().compare("Union South")) {
            std::cout << "Thanks for coming to work!" << std::endl;
            player->changeWorkAttribute(1);
            player->addMoney(40.00);
            if(mySchedule->isNight()) {
                player->goToHome(campus->getLocation(player->getHome()));
                std::cout << "Now that the night's over, you are now at home" << std::endl;
            }
            mySchedule->advanceTime();
            return; //exit function
        } else {
            std::cout << "You're not in your work location. Move to Union South" << std::endl;
        }
    }
    //User has free time and specified a token
    if((!mySchedule->getTask().compare("")) && token.compare("")) { //TODO improve performance of this. We don't need to check if allowed at this time twice
        //token = socialize - the activity they want to do
        std::vector<std::string> allowedActivitiesNow = mySchedule->getAllowableActivitiesAtCurrentTime();
        for(auto activity : allowedActivitiesNow) {
            if(!activity.compare(token)) {

                if(player->getCurrentLocation().isAllowed(token) && mySchedule->isAllowed(token)) {
                    std::cout << "You chose to " << token << std::endl;
                    if(!token.compare("relax")) {
                        player->changeSleepAttribute(1);
                    } else if(!token.compare("study")) {
                        player->changeGradesAttribute(1);
                    } else if(!token.compare("socialize")) {
                        player->changeSocialAttribute(1);
                    } else if(!token.compare("go out")) {
                        player->changeSocialAttribute(1);
                        player->subtractMoney(20.00);
                    } else if(!token.compare("eat out with friends")) {
                        player->changeSocialAttribute(1);
                        player->subtractMoney(10.00);
                    } else if (!token.compare("stay in")) {
                        player->changeSleepAttribute(1);
                    }
                    if(mySchedule->isNight()) {
                        player->goToHome(campus->getLocation(player->getHome()));
                        std::cout << "Now that the night's over, you are now at home" << std::endl;
                    }
                    mySchedule->advanceTime();
                    return;
                } else {
                    std::cout << token << " is not allowed at this time or location" << std::endl;
                    return;
                }

            }
        }
        //token not found
        std::cout << token << " is not allowed at this time. Select another activity" << std::endl;
    }
}
/*
 * Prints a list of commands available in the game
 */
void processHelpCommand() {
    std::cout << std::endl;
    std::cout << "stats - Prints user's current attributes, major, bank balance, work location, class location, and schedule" << std::endl;
    std::cout << "now - Prints current time and day" << std::endl;
    std::cout << "nearme - Prints current location and the adjacent locations that are directly accessible from the current location" << std::endl;
    std::cout << "move <location> - Moves the user to the specified location" << std::endl;
    std::cout << "task - Prints the current task that the user must do to advance. If the user has no tasks, it prints \"Open\" " << std::endl;
    std::cout << "task <activity> - Completes the specified task and advances time" << std::endl;
    std::cout << "quit - Quits the game" << std::endl;
    std::cout << std::endl;
    //Wizard. Helps the player by giving them hints on what to do
    if(mySchedule->hasClass()) {
        if(!player->getCurrentLocation().getDisplayName().compare(player->getClassLocation())) {
            std::cout << "You have class right now. Enter \"task class\" to enter the classrooom" << std::endl;
        } else {
            std::cout << "You have class right now. Move to " << player->getClassLocation() << std::endl;
        }
    } else if(mySchedule->hasWork()) {
        if(!player->getCurrentLocation().getDisplayName().compare("Union South")) {
            std::cout << "You have work right now. Enter \"task work\" to start work" <<std::endl;
        } else {
            std::cout << "You have work right now. Move to Union South" <<std::endl;
        }
    } else {
        std::cout << "You have free time right now. Enter \"task\" to see what you can do at this time and location" << std::endl;
    }
}
/*
 * Quits the game
 */
void processQuitCommand() {
    std::cout << "Thanks for playing!" << std::endl;
    exit(0);
}
/*
 * Runs infinitely (until program is quit) to get user input and call the approporiate method based on the user command
 */
static void processUserCommands() {
    std::cin.ignore();
    std::string command = "";
    do {
        std::cout << "Enter a command. Type 'help' for help: ";
        std::getline(std::cin, command);
        std::transform(command.begin(), command.end(), command.begin(), ::tolower); //to lowercase
        //if else to process command (since you can't switch on a string)

        int space = (int)command.find(" " , 0); //returns -1 if no space
        std::string token = "";
        if(space > -1) {
            //we have a token command
            int tokenLength = command.size() - space;
            token = command.substr(space + 1, tokenLength);
            command = command.substr(0, space);
        }
        if(!command.compare("stats")) {
            processStatsCommand();
        } else if (!command.compare("now")) {
            processNowCommand();
        } else if (!command.compare("nearme")) {
            processNearmeCommand();
        } else if (!command.compare("move")) {
            if(!token.compare("")) {
                std::cout << "Usage: move <location>" << std::endl;
            } else {
                processMoveCommand(token);
            }
        } else if (!command.compare("task")) {
            processTaskCommand(token);
        } else if (!command.compare("help")) {
            processHelpCommand();
        } else if (!command.compare("quit")) {
            processQuitCommand();
        } else {
            std::cout << "Command not recognized" << std::endl;
        }
    } while(command.compare("quit"));
}
/*
 * Initialize player object
 */
void initializePlayer() {
    std::cout << "Welcome to A Week In The Life of a Badger!" << std::endl;
    assignPlayerDetails();
    assignPlayerAttributes();
    assignPlayerMoney();
}
/*
 * Main method. Controls game execution by setting up the game and then calling processUserCommands()
 */
int main() {
    setUpLocationsGraph();
    initializePlayer();
    assignPlayerHome();
    player->printStats();
    createSchedule();
    processUserCommands();
    return 0;
}