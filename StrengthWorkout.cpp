#include "StrengthWorkout.h"
#include <iostream>

StrengthWorkout::StrengthWorkout(const std::string& name, int duration, int sets, int reps)
    : Workout(name, duration), sets(sets), reps(reps) {}

void StrengthWorkout::displayWorkout() const {
    std::cout << "Strength Workout: " << name << ", Duration: " << duration 
              << " minutes, Sets: " << sets << ", Reps: " << reps << std::endl;
}
