#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <algorithm>

int random(int min_roll, int max_roll) {
    return min_roll + rand() % (max_roll - min_roll + 1);
}

int roll() {
    int min_roll = 1;
    int max_roll = 6;
    int roll = random(min_roll, max_roll);
    return roll;
}

int main(){
    srand(time(0));
    int total_players;
    while (true){
        std::cout << "How many players? (2-4): ";
        std::cin >> total_players;
        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (total_players >= 2 && total_players <=4){
            std::cout << total_players << " are playing the game\n";
            break;
        }
        else{
            std::cout << "Choose between (2-4)players!\n";
        }
    }

    std::vector<int> player(total_players, 0);
    int max_score = 50;
    bool game_over = false;
    
    while (!game_over) {
        for (int player_idx = 0; player_idx < total_players; player_idx++) {
            std::cout << "It's Player " << (player_idx + 1) << " turn\n";
            std::cout << "\nYour score is: " << player[player_idx] << "\n\n";
    
            int current_score = 0;

            while (true){
                std::string should_roll;
                std::cout << "Do you want to roll the dice? (y): ";
                std::cin >> should_roll;
                if (should_roll != "y" && should_roll != "Y") {
                    break;
                }
                int value = roll();
                if (value == 1){
                    std::cout << "You rolled a 1, your score is 0\n";
                    current_score = 0;
                    break;
                }
                else{
                    current_score += value;
                    std::cout << "You rolled a " << value << "\n";
                }
                std::cout << "Your current score is " << current_score << "\n";
            }
            player[player_idx] += current_score;
            std::cout << "Your total score is " << player[player_idx] << "\n";
            
            if (player[player_idx] >= max_score) {
                std::cout << "Player " << (player_idx + 1) << " wins the game!\n";
                game_over = true;
                break;
            }
        }
    }
    return 0;
}
