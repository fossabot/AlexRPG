#include "game.h"

static inline void tutorial(GameData *data) {
    std::cout << "Alright! AlexRPG is an RPG where you play as Alex, on a journey to " <<
        "destroy Googular, a biting allegory for corporate America.\n";
    std::cout << "Rather than fight with weapons, you tell jokes. " <<
        "The measure of joke-telling ability is called wit. To start out you have " <<
        data->getWit() << " wit.\n";
    std::cout << "While there is no real violence from the attacking side, these jokes cause real damage. " <<
        "The defending side will have real and gruesome injuries from these jokes.";
}

GameData gameLoop(GameData data) {
    char yOrN;
    bool inputRecognized{ false };
    switch (data.getTurns()) {
    case 0:
        std::cout << "You appear to be new to AlexRPG, would you like to hear how things work? (Y or N) ";
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
    }
    return data;
}