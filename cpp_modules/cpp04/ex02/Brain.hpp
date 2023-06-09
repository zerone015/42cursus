#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain 
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &src);
        Brain& operator=(const Brain &src);
        ~Brain();
        std::string getIdea(int index);
        void        setIdea(int index, std::string idea);
};

#endif