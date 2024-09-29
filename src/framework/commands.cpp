#include <commands.hpp>

std::map <std::string, std::function<void(std::vector<std::string>)> > commands;

std::vector<std::string> parse_command(char* input) {
    std::string raw_string = input;
    std::vector<std::string> variables;


    while (raw_string.find("  ") != std::string::npos){
        int index = raw_string.find("  ");
        raw_string = raw_string.substr(0, index) + raw_string.substr(index + 1, raw_string.length() - index);
    }

    if (raw_string[0] == ' ') raw_string = raw_string.substr(1, raw_string.length() - 1);


    while (raw_string.find(" ") != std::string::npos){
        int var_index = raw_string.find(" ");
        variables.push_back(raw_string.substr(0, var_index));
        raw_string = raw_string.substr(var_index + 1, raw_string.length() - var_index);    
    }

    variables.push_back(raw_string);

    return variables;
}

void register_command(std::string name, std::function<void(std::vector<std::string>)> instruction ) {
    commands.insert({name, instruction});
}

void run_command(std::vector<std::string> command_vector) {
    std::string name = command_vector[0];
    command_vector.erase(command_vector.begin());
    commands[name](command_vector);

}