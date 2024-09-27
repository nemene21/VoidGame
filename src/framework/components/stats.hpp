#ifndef stats_hpp
#define stats_hpp

#include <string>
#include <map>

class Stats {
public:
    void fetch_stat(const std::string& name) const;

    void new_stat(const std::string& name, float value, float multiplier);
    void new_value(const std::string& name, float value);
    void new_mult(const std::string& name, float multiplier);

    void add_value(const std::string& name, float incrvalue);
    void add_mult(const std::string& name, float incrmult);

private:
    std::map<std::string, float> stat;
    std::map<std::string, float> multiplier;
};

#endif stats_hpp