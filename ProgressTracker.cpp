#include "ProgressTracker.h"
#include <iostream>

void ProgressTracker::addProgress(const std::string& date, const std::vector<int>& metrics) {
    progress[date] = metrics;
}

void ProgressTracker::displayProgress() const {
    for (const auto& entry : progress) {
        std::cout << "Date: " << entry.first << ", Weight: ";
        for (int metric : entry.second) {
            std::cout << metric << " ";
        }
        std::cout << std::endl;
    }
}
