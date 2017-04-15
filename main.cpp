#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Location.h"
#include "Graph.h"
#include "Schedule.h"

Player *player;
Graph *campus;
Schedule *mySchedule;
static const int TOTAL_POINTS = 20;
static const double BASE_STARTING_MONEY = 400;

void showWelcomeMessage() {
    std::cout << "Welcome to the game!" << std::endl;
    std::cout << "Happy you're here!" << std::endl;
}

void createSchedule() {
    mySchedule = new Schedule("A good schedule");
    mySchedule->createSchedule(player->getGradesAttribute(), player->getSleepAttribute(), player->getWorkAttribute(), player->getSocialAttribute());
    mySchedule->printSchedule();
}

void assignPlayerDetails() {

    //Name
    std::string playerName;
    std::cout << "What is your name? ";
    getline(std::cin, playerName);
    std::cout << "Welcome, " << playerName << "! We're glad you're playing" << std::endl; //remove

    //Age
    int playerAge;
    do {
        std::cout << "What is your age? ";
        std::cin >> playerAge;
        if(playerAge < 18) {
            std::cout << "Error: Age must be greater than or equal to 18" << std::endl;
        }
    } while (playerAge < 18);
    std::cout << "You're " << playerAge << " years old" << std::endl; //remove

    //What you live in
    bool playerLivesInHouse;
    bool validInput = true;
    do {
        char decision;
        std::cout << "What's your living situation like? House or apartment? Enter 'H' for house or 'A' for apartment" << std::endl;
        std::cin >> decision;
        if(decision == 'A' || decision == 'a') {
            playerLivesInHouse = false;
            std::cout << "Apartment! Nice choice" << std::endl;
            validInput = true;
        } else if(decision == 'H' || decision == 'h') {
            playerLivesInHouse = true;
            std::cout << "House! Nice choice" << std::endl;
            validInput = true;
        } else {
            std::cout << "Error: Enter 'H' or 'A'" << std::endl;
            validInput = false;
        }
    } while (!validInput);

    //Where you live
    bool playerLivesInSoutheast;
    //we can reuse the validInput boolean because at this point it must be true
    do {
        char decision;
        std::cout << "Where do you live? Lakeshore or Southeast? Enter 'L' for Lakeshore or 'S' for Southeast" << std::endl;
        std::cin >> decision;
        if(decision == 'L' || decision == 'l') {
            playerLivesInSoutheast = false;
            std::cout << "Lakeshore! Nice choice" << std::endl;
            validInput = true;
        } else if(decision == 'S' || decision == 's') {
            playerLivesInSoutheast = true;
            std::cout << "Southeast! Nice choice" << std::endl;
            validInput = true;
        } else {
            std::cout << "Error: Enter 'L' or 'S'" << std::endl;
            validInput = false;
        }
    } while (!validInput);

    //Major TODO fix bug where entering a non-integer (like a char) creates infinite loop
    std::string playerMajor;
    //we can reuse the validInput boolean because at this point it must be true
    do {
        int decision;
        std::cout << "What's your major? Your choices are: business, science, CS, or engineering.  Enter '1' for business, '2' for science, '3' for CS, '4' for engineering" << std::endl;
        std::cin >> decision;
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
    player = new Player(playerName, playerAge, playerLivesInHouse, playerLivesInSoutheast, playerMajor, campus->getLocation("union south"));
}

void assignPlayerAttributes() {
    int pointsUsed = 0;
    std::cout << "Now's the time to assign attributes to your player." << std::endl;
    std::cout << "There are 4 attributes: sleep, work, grades, and social life" << std::endl;
    std::cout << "To start off the game, you have 20 attribute points to distribute among the 4 attributes" << std::endl;
    std::cout << "It's important to have a balance of attributes" << std::endl;
    std::cout << "NOTE: Think hard about your decisions. These can't be changed later on." << std::endl;
    //sleep
    int sleep;
    do {
        std::cout << "How many points would you like to allocate to sleep? You have " << TOTAL_POINTS - pointsUsed << " points left. " << std::endl;
        std::cin >> sleep;
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
        std::cin >> work;
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
        std::cin >> grades;
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

void assignPlayerMoney() {
    std::cout << "Player money" << std::endl;
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

void setUpLocationsGraph() {
    std::cout << "Setting up game locations..." << std::endl;
    campus = new Graph("UW-Madison"); //create graph
    //create locations
    Location lakeshore("Lakeshore", "lakeshore", {"study", "relax", "socialize", "go out"});
    Location eHall("Engineering Hall", "engineering hall", {"study"});
    Location crHousing("Housing Near Camp Randall", "housing near camp randall", {"study", "relax", "socialize"});
    Location cRandall("Camp Randall", "camp randall", {"socialize", "go out"});
    Location uSouth("Union South", "union south", {"study", "socialize"});
    Location bascom("Bascom Hill", "bascom hill", {"study"});
    Location collegeLib("College Library", "college library", {"study"});
    Location csBuilding("CS Building", "cs building", {"study"});
    Location grainger("Grainger Hall", "grainger hall", {"study"});
    Location stateSt("State Street", "state street", {"socialize", "go out"});
    Location theHub("The Hub", "the hub", {"study", "relax", "socialize", "go out"});
    Location dons("Gordon's Dining Hall", "gordon's dining hall", {"socialize"});
    Location mifflin("Mifflin St.", "mifflin st.", {"study", "relax", "socialize", "go out"});
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

    //print all locations and their neighbors
    for(auto location : campus->getAllLocations()) {
        std::cout << location.getDisplayName() << "--> " << "\t";
        std::vector<Location> neighbors = location.getAdjacentLocations();
        for(auto n : neighbors) {
            std::cout << n.getDisplayName() << " , "; //TODO remove end comma (or come up with better way to display graph)
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
   // Location loca = campus->getLocation("Union South");
    //player->setCurrentLocation(loca);

}

void processStatsCommand() {
    player->printStats();
    mySchedule->printSchedule();
}

void processNowCommand() {
    mySchedule->getCurrentDay();
    mySchedule->getCurrentTime();
}


void processNearmeCommand() {
    std::cout << "You are at: " << player->getCurrentLocation().getDisplayName() << std::endl;
    std::cout << "From here, you can move to: " << std::endl;
    std::vector<Location> nearby = player->getCurrentLocation().getAdjacentLocations();
    for(auto l : nearby) {
        std::cout << "\t" << l.getDisplayName() << std::endl;
    }
}

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

void processTaskCommand(std::string token) {
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

    if(token.size() == 0) {
        std::cout << "You have: ";
        if(!mySchedule->getTask().compare("")) {
            std::cout << "Open";
        } else {
            std::cout << mySchedule->getTask();
        }
        std::cout << std::endl;
    }
    if((!mySchedule->getTask().compare("Class"))  && (!token.compare("class"))) {
        if(!player->getCurrentLocation().getDisplayName().compare(classLocation)) {
            std::cout << "Thanks for coming to class!" << std::endl;
            mySchedule->advanceTime();
            return; //exit function
        } else {
            std::cout << "You're not in your class location. Move to " << classLocation << std::endl;
        }
    }

    if((!mySchedule->getTask().compare("Work"))  && (!token.compare("work"))) {
        if(!player->getCurrentLocation().getDisplayName().compare("Union South")) {
            std::cout << "Thanks for coming to work!" << std::endl;
            mySchedule->advanceTime();
            return; //exit function
        } else {
            std::cout << "You're not in your work location. Move to Union South" << std::endl;
        }
    }

    if((!mySchedule->getTask().compare("")) && token.compare("")) {
        if((!token.compare("study")) && player->getCurrentLocation().isAllowed(token)) {
            std::cout << "You chose to " << token << std::endl;
            mySchedule->advanceTime();
        } else {
            std::cout << "Error: activity doesn't exist or isn't allowed at this location" << std::endl;
        }
    }


}

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
}

void processQuitCommand() {
    std::cout << "Thanks for playing!" << std::endl;
    exit(0);
}


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

void initializePlayer() {
    showWelcomeMessage();
    assignPlayerDetails();
    assignPlayerAttributes();
    assignPlayerMoney();
}

int main() {
    setUpLocationsGraph();
    initializePlayer();
    player->printStats();
    createSchedule();
    processUserCommands();
    return 0;
}