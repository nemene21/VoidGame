#ifndef COMMANDS_H
#define COMMANDS_H

#include <string>
#include <vector>
#include <map>
#include <functional>

#include <scene.hpp>


//map of commands
extern std::map <std::string, std::function<void(std::vector<std::string>)> > commands; 

//functions for commands
void commands_init();
std::vector<std::string> parse_command(char* input);
void register_command(std::string name, std::function<void(std::vector<std::string>)> instruction);
void run_command(std::vector<std::string> command_vector);

#endif