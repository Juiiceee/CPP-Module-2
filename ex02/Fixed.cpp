#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _entier(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int entier) : _entier(entier << this->_nbb)
{
	std::cout << "Int constructor called\n";
}
Fixed::Fixed(const float fl) : _entier(roundf(fl * (1 << this->_nbb)))
{
	std::cout << "Int constructor called\n";
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
		this->_entier = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->_entier);
}

void	Fixed::setRawBits(int const raw)
{
	this->_entier = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_entier) / (1 << this->_nbb));
}

int		Fixed::toInt(void) const
{
	return (this->_entier >> this->_nbb);
}

std::ostream &operator<<( std::ostream &os, const Fixed &entier)
{
	os << entier.toFloat();
	return os;
}

bool	Fixed::operator==(const Fixed &obj)
{
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator!=(const Fixed &obj)
{
	return (this->getRawBits() != obj.getRawBits());
}

bool	Fixed::operator>(const Fixed &obj)
{
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator<(const Fixed &obj)
{
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator>=(const Fixed &obj)
{
	return (this->getRawBits() > obj.getRawBits() || this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator<=(const Fixed &obj)
{
	return (this->getRawBits() < obj.getRawBits() || this->getRawBits() == obj.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &obj)
{
	return Fixed(this->getRawBits() + obj.getRawBits());
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	return Fixed(this->getRawBits() - obj.getRawBits());
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	return Fixed(this->getRawBits() * obj.getRawBits());
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	return Fixed(this->getRawBits() / obj.getRawBits());
}

Fixed	Fixed::operator++(void)
{
	return (++this->_entier);
}

Fixed	Fixed::operator++(int)
{
	return (this->_entier++);
}

Fixed	Fixed::operator--(void)
{
	return (--this->_entier);
}

Fixed	Fixed::operator--(int)
{
	return (this->_entier--);
}
