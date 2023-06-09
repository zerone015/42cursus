#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin(void) {return this->c.begin();}
        iterator end(void) {return this->c.end();}

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin(void) {return this->c.rbegin();}
        reverse_iterator rend(void) {return this->c.rend();}

        typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
        const_iterator cbegin(void) {return this->c.cbegin();}
	    const_iterator cend(void) {return this->c.cend();}

        typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator crbegin(void) {return this->c.crbegin();}
	    const_reverse_iterator crend(void) {return this->c.crend();}
        
        MutantStack(){};
        MutantStack(const MutantStack &src) {*this = src;}
        MutantStack& operator=(const MutantStack &src) {this->c = src.c; return *this;}
        ~MutantStack(){};
};

#endif