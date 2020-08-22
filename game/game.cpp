#include "game.h"

// The game logic along with the main loop

// I had to do this inline but honestly, this probably wasn't neccessary
static inline void tutorial(GameData *data);

static char turnChoice();

GameData gameLoop(GameData data) {
    // Define the items
    Items items;
    // Char used when user needs to decide yes or no
    char yOrN;
    char decision;
    // bool used to avoid recursion (for whatever reason)
    bool inputRecognized{ false };
    // Main turn checker
    switch (data.getTurns()) {
    // If it is turn 0 give the user a tutorial
    case 0:
        std::cout << "You appear to be new to AlexRPG, would you like to hear how things work? " <<
        red << "(Y or N) " << reset;
        while (!inputRecognized) {
            std::cin >> yOrN;
            switch (yOrN) {
            case 'y':
            case 'Y':
                inputRecognized = true;
                tutorial(&data);
                break;
            case 'n':
            case 'N':
                inputRecognized = true;
                break;
            default:
                std::cout << "Input not recognized, try again\n";
                break;
            }
        }
        std::cout << '\n';
        std::cout << "Alright then! Let's begin. You find yourself in a ditch near downtown Phoenix, " <<
        "the city skyline in the horizon.\n";
        std::cout << "You spot a crappy microphone near you on the ground, " <<
        "you pick it up just in case it might help.\n";
        // The starting mic for the game
        data.addItem(items.toyMic);
        decision = turnChoice();
        switch (decision) {
            case 'I':
            // todo: check inventory
            break;
            case 'S':
            // todo: check status
            data.checkStatus();
            break;
            case 'y':
            std::cout << "Come back soon!\n";
            data.gameStatus = 1;
            break;
        }
    }
    return data;
}

static char turnChoice() {
    char input;
    bool inputRecognized{ false };
    std::cout << "Would you like to " << red << "(N)" << magenta << 
    " Next Turn" << reset << ", " << red << "(I)" << magenta << 
    " Check Inventory" << reset << "," << red << " (S)" << magenta << 
    " Check Status" << reset << ", or " << red << "(Q)" << magenta <<
    " Quit\n" << reset;
    std::cin >> input;
    while (!inputRecognized) {
        switch (input) {
        case 'I':
        case 'i':
            // Check inventory
            inputRecognized = true;
            return 'I';
            break;
        case 'S':
        case 's':
            // Check status
            inputRecognized = true;
            return 'S';
            break;
        case 'Q':
        case 'q':
            // Quit
            inputRecognized = true;
            break;
        default:
            std::cout << "Input not recognized! Please try again.\n";
            break;
        }
    }
    return 'y';
}

static inline void tutorial(GameData *data) {
    std::cout << "Alright! AlexRPG is an RPG where you play as Alex, on a journey to " <<
        "destroy Googular, a biting allegory for corporate America.\n";
    std::cout << "Rather than fight with weapons, you tell jokes. " <<
        "The measure of joke-telling ability is called wit. To start out you have " <<
        data->getWit() << " wit.\n";
    std::cout << "While there is no real violence from the attacking side, these jokes cause real damage. " <<
        "The defending side will have real and gruesome injuries from these jokes.\n";
    std::cout << "The defending side can attempt a comeback to reverse the damage, " <<
    "but if it fails they lose the turn and take the damage.\n";
}