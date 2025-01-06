#ifndef WORKOUT_H
#define WORKOUT_H

#include <string>


class Workout {
protected:
    std::string name;
    int duration; 

public:
    Workout(const std::string& name, int duration);
    virtual void displayWorkout() const;
    virtual ~Workout() = default;
};

#endif 
