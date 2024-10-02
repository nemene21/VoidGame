#ifndef stats_hpp
#define stats_hpp

#include <string>
#include <map>

class Stats {
private:
    struct Stat {float value; float multiplier;};
    std::map<std::string, Stat> stats;
public:
    void newstat(const std::string& name, Stat);

    void fetchstat(const std::string& name) const;

    void newvalue(const std::string& name, float value);

    void newmult(const std::string& name, float multiplier);
};

#endif stats_hpp