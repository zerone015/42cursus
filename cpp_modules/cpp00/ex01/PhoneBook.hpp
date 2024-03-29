#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     num_of_added;
    public:
        PhoneBook(void);
        void    add_contact(void);
        void    search_contact(void);
        void    show_short_contacts(void);
};

#endif