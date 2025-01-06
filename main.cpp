
#include <iostream>
#include <vector>
#include <limits>
#include "User.h"
#include "CardioWorkout.h"
#include "StrengthWorkout.h"


void displayMenu() {
    std::cout << "1. Add Workout\n"
              << "2. Log Progress\n"
              << "3. Display User Info\n"
              << "4. Exit\n";
}

void clearInputStream() {
    std::cin.clear();  
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  
}

int main() {
    User user("John Smith");

    int choice;
    while (true) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {  
            clearInputStream();
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        if (choice == 1) {
            int workoutType;
            std::cout << "1. Cardio\n2. Strength\n";
            std::cin >> workoutType;

            if (std::cin.fail() || (workoutType != 1 && workoutType != 2)) {
                clearInputStream();
                std::cout << "Invalid workout type. Please enter 1 for Cardio or 2 for Strength." << std::endl;
                continue;
            }

            std::string name;
            int duration;
            std::cout << "Enter Workout Name: ";
            clearInputStream();  
            std::getline(std::cin, name);  
            std::cout << "Enter Duration (minutes): ";
            std::cin >> duration;

            if (std::cin.fail()) {
                clearInputStream();
                std::cout << "Invalid duration. Please enter a number." << std::endl;
                continue;
            }

            if (workoutType == 1) {
                int distance;
                std::cout << "Enter Distance Completed (miles): ";
                std::cin >> distance;

                if (std::cin.fail()) {
                    clearInputStream();
                    std::cout << "Invalid distance. Please enter a number." << std::endl;
                    continue;
                }

                user.addWorkout(new CardioWorkout(name, duration, distance));
            } else if (workoutType == 2) {
                int sets, reps;
                std::cout << "Enter Sets: ";
                std::cin >> sets;
                std::cout << "Enter Reps: ";
                std::cin >> reps;

                if (std::cin.fail()) {
                    clearInputStream();
                    std::cout << "Invalid sets or reps. Please enter numbers." << std::endl;
                    continue;
                }

                user.addWorkout(new StrengthWorkout(name, duration, sets, reps));
            }
        } else if (choice == 2) {
            std::string date;
            int metric;
            std::vector<int> metrics;
            std::cout << "Enter Date (MM-DD-YYYY): ";
            clearInputStream(); 
            std::getline(std::cin, date);
            std::cout << "Enter Weight (0 to end): ";

            while (std::cin >> metric) {
                if (metric == 0) break; 
                if (std::cin.fail()) {
                    clearInputStream();
                    std::cout << "Invalid weight. Please enter a number." << std::endl;
                    continue;
                }
                metrics.push_back(metric);
            }

            clearInputStream();  
            user.logProgress(date, metrics);
        } else if (choice == 3) {
            user.displayUserInfo();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }

    return 0;
}
