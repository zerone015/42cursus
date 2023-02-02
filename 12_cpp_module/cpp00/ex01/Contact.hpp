#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

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
        void        show_short_contact() const;
        void        show_all_contact() const;
        std::string fit_str(const std::string &str) const;
};

#endif