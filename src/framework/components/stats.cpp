#include "stats.hpp"
#include <iostream>

void Stats::new_stat(const std::string& name, float value, float multiplier) {
    stat[name] = value;
    this->multiplier[name] = multiplier;
}

void Stats::fetch_stat(const std::string& name) const {
    if (stat.find(name) != stat.end()) {
        float value = stat.at(name);
        value *= multiplier.count(name) ? multiplier.at(name) : 1.0f;
        std::cout << "Stat: " << name << "Value: " << value << std::endl;
    }
}

void Stats::new_value(const std::string& name, float value) {
    if (stat.find(name) != stat.end()) {
        stat[name] = value;
    }
}

void Stats::new_mult(const std::string& name, float multiplierValue) {
    if (multiplier.find(name) != multiplier.end()) {
        multiplier[name] = multiplierValue;
    }
}

void Stats::add_value(const std::string& name, float incrvalue) {
    stat[name] += incrvalue;
}

void Stats::add_mult(const std::string& name, float incrmult) {
    multiplier[name] += incrmult;
}