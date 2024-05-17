#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _entier(0)
{
}

Fixed::Fixed(const int entier) : _entier(entier << this->_nbb)
{
}
Fixed::Fixed(const float fl) : _entier(roundf(fl * (1 << this->_nbb)))
{
}

Fixed::Fixed(const Fixed &obj)
{
	this->setRawBits(obj.getRawBits());
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	if (this != &obj)
		this->_entier = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
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
	return Fixed(this->toFloat() + obj.toFloat());
}

Fixed	Fixed::operator-(const Fixed &obj)
{
	return Fixed(this->toFloat() - obj.toFloat());
}

Fixed	Fixed::operator*(const Fixed &obj)
{
	return Fixed(this->toFloat() * obj.toFloat());
}

Fixed	Fixed::operator/(const Fixed &obj)
{
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	++this->_entier;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	tmp._entier = this->_entier++;
	return (tmp);
}

Fixed	Fixed::operator--(void)
{
	--this->_entier;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	tmp._entier = this->_entier--;
	return (tmp);
}

Fixed	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}
