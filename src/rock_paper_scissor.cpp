#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));

    std::cout << "Welcome to Rock, Paper, Scissors!\n";
    std::cout << "Please choose one of the following:\n";
    std::cout << "1. Rock\n2. Paper\n3. Scissors\n";
    std::cout << "Enter your choice: ";

    int user_choice;
    std::cin >> user_choice;

    if (user_choice < 1 || user_choice > 3) {
        std::cout << "Invalid choice. Please choose between 1-3\n";
        return 1;
    }

    int computer_choice = std::rand() % 3 + 1;
    std::cout << "Computer chooses ";

    switch (computer_choice) {
        case 1: std::cout << "Rock\n"; break;
        case 2: std::cout << "Paper\n"; break;
        case 3: std::cout << "Scissors\n"; break;
    }

    if (user_choice == computer_choice) {
        std::cout << "It's a tie!\n";
    } else {
        switch (user_choice) {
            case 1: // Rock
                std::cout << (computer_choice == 3 ? "You win! Rock beats Scissors\n" : "You lose! Paper beats Rock\n");
                break;
            case 2: // Paper
                std::cout << (computer_choice == 1 ? "You win! Paper beats Rock\n" : "You lose! Scissors beats Paper\n");
                break;
            case 3: // Scissors
                std::cout << (computer_choice == 2 ? "You win! Scissors beats Paper\n" : "You lose! Rock beats Scissors\n");
                break;
        }
    }

    return 0;
}