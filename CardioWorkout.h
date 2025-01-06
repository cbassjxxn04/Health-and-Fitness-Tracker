#ifndef CARDIOWORKOUT_H
#define CARDIOWORKOUT_H

#include "Workout.h"


class CardioWorkout : public Workout {
private:
    int distance;

public:
    CardioWorkout(const std::string& name, int duration, int distance);
    void displayWorkout() const override;
};

#endif 
