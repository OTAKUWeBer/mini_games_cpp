#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>


std::string toLower(const std::string &s) {
    std::string result;
    for (char c : s) {
        result.push_back(std::tolower(c));
    }
    return result;
}

class TaskList {
private:
    std::vector<std::string> tasks;
    void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

public:
    void add(const std::string &task) {
        std::string taskLower = toLower(task);
        bool exists = false;
        for (const std::string &t : tasks) {
            if (toLower(t) == taskLower) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            tasks.push_back(task);
            std::cout << "'" << task << "' added to the list.\n";
        } else {
            std::cout << "'" << task << "' is already in the list.\n";
        }
    }

    void displayList() {
        if (tasks.empty()) {
            std::cout << "Your list is empty.\n";
        } else {
            std::cout << "________________________\n";
            std::cout << "Your task list:\n";
            // Loop through all tasks and display them.
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << (i + 1) << ". " << tasks[i] << "\n";
            }
            std::cout << "________________________\n";
        }
    }

    // Checks if a task is in the list.
    void check(const std::string &task) {
        std::string taskLower = toLower(task);
        bool found = false;
        for (const std::string &t : tasks) {
            if (toLower(t) == taskLower) {
                found = true;
                break;
            }
        }
        if (found) {
            std::cout << "Yes, '" << task << "' is on the list.\n";
        } else {
            std::cout << "No, '" << task << "' is not on the list.\n";
        }
    }

    void remove(const std::string &task) {
        std::string taskLower = toLower(task);
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (toLower(*it) == taskLower) {
                tasks.erase(it);
                std::cout << "'" << task << "' has been removed.\n";
                return;
            }
        }
        std::cout << "'" << task << "' is not on the list.\n";
    }


    void run() {
        while (true) {
            clearScreen();
            std::cout << "\nMenu:\n"
                      << "1. Add a task\n"
                      << "2. Display your list\n"
                      << "3. Check if a task is on the list\n"
                      << "4. Remove a task\n"
                      << "5. Exit\n"
                      << "Enter your choice: ";
            std::string choice;
            std::getline(std::cin, choice);

            if (choice == "1") {
                clearScreen();
                std::cout << "Enter the task: ";
                std::string taskName;
                std::getline(std::cin, taskName);
                add(taskName);
            } else if (choice == "2") {
                clearScreen();
                displayList();
            } else if (choice == "3") {
                clearScreen();
                std::cout << "Enter the task to check: ";
                std::string taskToCheck;
                std::getline(std::cin, taskToCheck);
                check(taskToCheck);
            } else if (choice == "4") {
                clearScreen();
                std::cout << "Enter the task to remove: ";
                std::string taskToRemove;
                std::getline(std::cin, taskToRemove);
                remove(taskToRemove);
            } else if (choice == "5") {
                clearScreen();
                std::cout << "Are you sure you want to exit? (y/n): ";
                std::string confirm;
                std::getline(std::cin, confirm);
                if (!confirm.empty() && (confirm[0] == 'y' || confirm[0] == 'Y')) {
                    std::cout << "Exiting...\n";
                    break;
                }
            } else {
                std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
};

int main() {
    TaskList taskManager;
    taskManager.run();
    return 0;
}
