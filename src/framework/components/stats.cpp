#include "stats.hpp"
#include <iostream>

void Stats::newstat(const std::string& name, Stat stat) {
    stats[name] = stat;
}

void Stats::fetchstat(const std::string& name) const {
    if (stats.find(name) != stats.end()) {
        std::cout << "Name: " <<
        << "\n" << "Value: " <<
        << "\n" << "Modifier: " << << std::endl;
    }
}

void Stats::newvalue(const std::string& name, float value) {
    if (stats.find(name) != stats.end()) {
        stats[name].value = value;
    }
}

void Stats::newmult(const std::string& name, float multiplier) {
    if (stats.find(name) != stats.end()) {
        stats[name].multiplier = multiplier;
    }
}