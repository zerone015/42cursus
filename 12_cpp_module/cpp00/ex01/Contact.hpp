#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string darkest_secret;
    public:
        void        add_contact(void);
        void        show_short_contact();
        void        show_all_contact();
        std::string get_short_str(std::string str);
        int         is_valid_str(std::string input);
};

#endif