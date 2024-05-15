#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->entier = 0;
}

Fixed::Fixed(const int entier)
{
	std::cout << "Int constructor called\n";
	this->entier = entier << this->nbb;
}
Fixed::Fixed(const float fl)
{
	std::cout << "Int constructor called\n";
	this->entier = roundf(fl * (1 << this->nbb));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called\n";
	this->setRawBits(obj.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &obj)
		this->entier = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->entier);
}

void	Fixed::setRawBits(int const raw)
{
	this->entier = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->entier) / (1 << this->nbb));
}

int		Fixed::toInt(void) const
{
	return (this->entier >> this->nbb);
}

std::ostream & operator<<( std::ostream &stream, Fixed const &entier)
{
	stream << entier.toFloat();
	return stream;
}
