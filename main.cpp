#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Location.h"
#include "Graph.h"

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
    Schedule mySchedule = new Schedule();
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

    std::cout << "Here are your attributes: " << std::endl;
    std::cout << "Sleep: " << sleep << std::endl;
    std::cout << "Work: " << work << std::endl;
    std::cout << "Grades: " << grades << std::endl;
    std::cout << "Social life: " << social << std::endl;

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
    Location lakeshore("Lakeshore", "lakeshore", {});
    Location eHall("Engineering Hall", "engineering hall", {});
    Location crHousing("Housing Near Camp Randall", "housing near camp randall", {});
    Location cRandall("Camp Randall", "camp randall", {});
    Location uSouth("Union South", "union south", {});
    Location bascom("Bascom Hill", "bascom hill", {});
    Location collegeLib("College Library", "college library", {});
    Location csBuilding("CS Building", "cs building", {});
    Location grainger("Grainger Hall", "grainger hall", {});
    Location stateSt("State Street", "state street", {});
    Location theHub("The Hub", "the hub", {});
    Location dons("Gordon's Dining Hall", "gordon's dining hall", {});
    Location mifflin("Mifflin St.", "mifflin st.", {});
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
}

void processNowCommand() {
    std::cout << mySchedule->getCurrentDay() << std::endl;
    std::cout << mySchedule->getCurrentTime() << std::endl;
    std::cout << player->getCurrentLocation().getDisplayName() << std::endl;
}

void processAdvanceCommand() {

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
    if(token.compare("")) {
        std::cout << mySchedule->getTask() << std::endl;
    }

}

void processHelpCommand() {

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
        } else if (!command.compare("advance")) {
            processAdvanceCommand();
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
    createSchedule();
    processUserCommands();
    return 0;
}