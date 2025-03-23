#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

int randomNumber() {
    return rand() % 100 + 1;
}

int main() {
    std::srand(std::time(0));
    int randomNum = randomNumber();
    std::cout << "Guess the number between (1-100). You have 10 attempts." << std::endl;
    
    int guess, attempts = 0;
    while (attempts < 10) {
        std::cout << "Attempt " << attempts + 1 << ": ";
        if (!(std::cin >> guess)) {
            std::cout << "Invalid input! Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        attempts++;
        if (guess == randomNum) {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            return 0;
        } else if (guess < randomNum) {
            std::cout << "Too low. Try again." << std::endl;
        } else {
            std::cout << "Too high. Try again." << std::endl;
        }
    }
    std::cout << "Out of attempts! The number was " << randomNum << "." << std::endl;
    return 0;
}
