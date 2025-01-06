#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "Workout.h"
#include "ProgressTracker.h"


class User {
private:
    std::string name;
    std::vector<Workout*> workouts;
    ProgressTracker progressTracker;

public:
    User(const std::string& name);
    void addWorkout(Workout* workout);
    void logProgress(const std::string& date, const std::vector<int>& metrics);
    void displayUserInfo() const;
    ~User();
};

#endif 
