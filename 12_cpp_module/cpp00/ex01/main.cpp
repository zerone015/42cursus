#include <iostream>
#include "PhoneBook.hpp"
#include "utils.hpp"

void show_manual(void)
{
    std::cout << "**** You can use three commands: [ADD] [SEARCH] [EXIT]" << "\n";
    std::cout << "**** Please enter the command you want to use." << std::endl;
}

void execute_command(PhoneBook *phonebook, std::string command)
{
    if (command == "ADD")
        phonebook->add_contact();
    else if (command == "SEARCH")
        phonebook->search_contact();
    else if (command == "EXIT")
        exit(EXIT_SUCCESS);
    else
        std::cout << "Command not found. Please try again." << std::endl;
}

int main(void)
{
    PhoneBook   phonebook;
    std::string command;

    std::cout << "**** Welcome to the phone book" << std::endl;
    while (1)
    {
        show_manual();
        command = safe_getline();
        execute_command(&phonebook, str_to_upper(trim_whitespace(command)));
    }
    return (0);
}