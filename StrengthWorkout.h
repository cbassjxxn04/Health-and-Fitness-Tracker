#ifndef STRENGTHWORKOUT_H
#define STRENGTHWORKOUT_H

#include "Workout.h"

class StrengthWorkout : public Workout {
private:
    int sets;
    int reps;

public:
    StrengthWorkout(const std::string& name, int duration, int sets, int reps);
    void displayWorkout() const override;
};

#endif 
