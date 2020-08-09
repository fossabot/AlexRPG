#include "init.h"

static int newGame(GameData data) {
    std::string confirm;
    std::string newName;

    std::cout << "This will erase your current save data. \nType confirm to confirm. \n";
    std::cin >> confirm;
    if (confirm == "confirm" || confirm == "Confirm") {
        std::cout << "What do you want to name your player? (Blank for default) ";
        std::cin.ignore();
        std::getline (std::cin, newName);
        data.setUserName(newName);
        saveGame(data.saveToVector());
        std::cout << "Successfully overwrote the save file!\n";
        return 0;
    } else {
        std::cout << "Confirm not typed" << '\n';
        return 1;
    }
}

GameData initGame() {
    // TODO: Load a save file

    char newOrOld;
    std::vector<std::string> blankVector{"0"};
    bool inputRecognized{false};
    GameData data{};

    std::cout << "Welcome to AlexRPG" << '\n';
    while (!inputRecognized) {
        std::cout << "Would you like to (l)oad a save or start a (n)ew adventure? ";
        std::cin >> newOrOld;
        std::cout << '\n';
        switch (newOrOld) {
            case 'l':
            case 'L':
                std::cout << "This feature has not been implemented yet, come back soon!" << std::endl;
                inputRecognized = true;
                if (data.loadFromVector(loadGame()) == 1) {
                    std::cout << "Game data could not be loaded, would you like to start a new game?\n";
                    if (newGame(data) == 0) {
                        break;
                    }
                } else {
                    break;
                }
            case 'n':
            case 'N':
                if (newGame(data) == 0) {
                    inputRecognized = true;
                    break;
                }
            default:
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input not recognized, trying again." << std::endl;
        }
    }
    return data;
}