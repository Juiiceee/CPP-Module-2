#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <string>

class Fixed
{
	private:
		int					_entier;
		int const static	_nbb = 8;
	
	public:
		Fixed();
		~Fixed();
		Fixed(const int entier);
		Fixed(const float fl);
		Fixed(const Fixed &obj);
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed	&operator=(const Fixed &obj);

		bool	operator>(const Fixed &obj);
		bool	operator<(const Fixed &obj);
		bool	operator>=(const Fixed &obj);
		bool	operator<=(const Fixed &obj);
		bool	operator==(const Fixed &obj);
		bool	operator!=(const Fixed &obj);

		Fixed	operator+(const Fixed &obj);
		Fixed	operator-(const Fixed &obj);
		Fixed	operator*(const Fixed &obj);
		Fixed	operator/(const Fixed &obj);

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		static	Fixed	max(Fixed& f1, Fixed& f2);
		static	const Fixed	max(const Fixed& f1, const Fixed& f2);
		static	Fixed	min(Fixed& f1, Fixed& f2);
		static	const Fixed	min(const Fixed& f1, const Fixed& f2);
};
std::ostream &operator<<( std::ostream &stream, const Fixed &entier);
#endif
