#include <iostream>
#include <iomanip>
#include "Contact.hpp"
#include "utils.hpp"

void    Contact::add_contact(void)
{
    std::cout << "Please enter your first name" << std::endl;
    first_name = safe_getline();
    while (first_name.empty())
        first_name = safe_getline();
    std::cout << "Please enter your last name" << std::endl;
    last_name = safe_getline();
    while (last_name.empty())
        last_name = safe_getline();
    std::cout << "Please enter your nick name" << std::endl;
    nick_name = safe_getline();
    while (nick_name.empty())
        nick_name = safe_getline();
    std::cout << "Please enter your phone number" << std::endl;
    phone_number = safe_getline();
    while (phone_number.empty())
        phone_number = safe_getline();
    std::cout << "Please enter your darkest secret" << std::endl;
    darkest_secret = safe_getline();
    while (darkest_secret.empty())
        darkest_secret = safe_getline();
    std::cout << "Added successfully." << std::endl;
}

std::string Contact::fit_str(const std::string &str) const
{
    if (str.size() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void    Contact::show_short_contact(void) const 
{
    std::cout << std::setfill(' ') << std::setw(10) << fit_str(first_name) << "|";
    std::cout << std::setw(10) << fit_str(last_name) << "|";
    std::cout << std::setw(10) << fit_str(nick_name) << "|" << "\n";
}

void    Contact::show_all_contact(void) const
{
    std::cout << "first name: " << first_name << std::endl;
	std::cout << "last name: " << last_name << std::endl;
	std::cout << "nickname: " << nick_name << std::endl;
	std::cout << "phone number: " << phone_number << std::endl;
	std::cout << "darkest secret: " << darkest_secret << std::endl;
}