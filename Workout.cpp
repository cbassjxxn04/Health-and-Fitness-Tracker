#include "Workout.h"
#include <iostream>

Workout::Workout(const std::string& name, int duration) : name(name), duration(duration) {}

void Workout::displayWorkout() const {
    std::cout << "Workout: " << name << ", Duration: " << duration << " minutes" << std::endl;
}
