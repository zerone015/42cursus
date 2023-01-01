#include "PhoneBook.hpp"
#include "utils.hpp"

void    PhoneBook::add_contact(void)
{
    contacts[num_of_added % 8].add_contact();
    num_of_added++;
}

void    PhoneBook::show_short_contacts(void)
{
    int repeatCount;

    std::cout << "--------------------------------------------" << "\n";
    std::cout << "              Your Contact List           " << "\n";
    std::cout << "     index|first name| last name| nick name|" << "\n";
    repeatCount = num_of_added <= 8 ? num_of_added : 8;
    for (int i = 0; i < repeatCount; i++)
    {
        std::cout << "         " << i << "|";
        contacts[i].show_short_contact();
    }
    std::cout << "--------------------------------------------" << std::endl;
}

void    PhoneBook::search_contact(void)
{
    int input;

    if (!num_of_added)
    {
        std::cout << "There are no contacts added." << std::endl;
        return ;
    }
    show_short_contacts();
    std::cout << "Please enter the index of the contact you want." << std::endl;
    input = safe_cin();
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. You can only enter numbers." << std::endl;
        return ;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (input < 0 || input > 7 || input >= num_of_added)
    {
        std::cout << "Input is out of range." << std::endl;
        return ;
    }
    contacts[input].show_all_contact();
}