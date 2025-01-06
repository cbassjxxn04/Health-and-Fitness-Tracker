#include "User.h"
#include <iostream>

User::User(const std::string& name) : name(name) {}

void User::addWorkout(Workout* workout) {
    workouts.push_back(workout);
}

void User::logProgress(const std::string& date, const std::vector<int>& metrics) {
    progressTracker.addProgress(date, metrics);
}

void User::displayUserInfo() const {
    std::cout << "User: " << name << std::endl;
    std::cout << "Workouts:" << std::endl;
    for (const Workout* workout : workouts) {
        workout->displayWorkout();
    }
    std::cout << "Progress:" << std::endl;
    progressTracker.displayProgress();
}

User::~User() {
    for (Workout* workout : workouts) {
        delete workout;
    }
}
