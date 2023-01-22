template <typename T>
unsigned int    Array<T>::size() const
{
	return this->_size;
}

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
    std::cout << "unsigned int constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &src)
{
    std::cout << "Copy constructor called" << std::endl;
	this->_size = src.size();
	this->_array = new T[src.size()];
	for (unsigned int i = 0; i < src.size(); i++)
		this->_array[i] = src[i]; 
}

template <typename T>
Array<T>&   Array<T>::operator=(const Array &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
	delete [] this->_array;
	this->_size = src.size();
	this->_array = new T[src.size()];
	for (unsigned int i = 0; i < src.size(); i++)
		this->_array[i] = src[i]; 
	return *this;
}


template <typename T>
T&  Array<T>::operator[](unsigned int idx) const
{
	if (idx >= this->_size)
		throw std::out_of_range("out of range.");
	return this->_array[idx];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "destroyed" << std::endl;
	delete [] this->_array;
}