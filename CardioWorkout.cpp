#include "CardioWorkout.h"
#include <iostream>

CardioWorkout::CardioWorkout(const std::string& name, int duration, int distance)
    : Workout(name, duration), distance(distance) {}

void CardioWorkout::displayWorkout() const {
    std::cout << "Cardio Workout: " << name << ", Duration: " << duration 
              << " minutes, Distance: " << distance << " km" << std::endl;
}
