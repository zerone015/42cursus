#include "Contact.hpp"
#include "utils.hpp"

void    Contact::add_contact(void)
{
    std::cout << "Please enter your first name" << std::endl;
    first_name = safe_getline();
    std::cout << "Please enter your last name" << std::endl;
    last_name = safe_getline();
    std::cout << "Please enter your nick name" << std::endl;
    nick_name = safe_getline();
    std::cout << "Please enter your phone number" << std::endl;
    phone_number = safe_getline();
    std::cout << "Please enter your darkest secret" << std::endl;
    darkest_secret = safe_getline();
    std::cout << "Added successfully." << std::endl;
}

std::string Contact::get_short_str(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (std::string(10 - static_cast<int>(str.length()), ' ') + str);
}

void    Contact::show_short_contact(void)
{
    std::cout << get_short_str(first_name) << "|";
    std::cout << get_short_str(last_name) << "|";
    std::cout << get_short_str(nick_name) << "|" << "\n";
}

void    Contact::show_all_contact(void)
{
    std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nick_name << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "darkest secret: " << darkest_secret << std::endl;
}