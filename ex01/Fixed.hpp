#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <string>

class Fixed
{
	private:
		int					entier;
		int const static	nbb = 8;
	public:
		Fixed();
		Fixed(const int entier);
		Fixed(const float fl);
		Fixed(const Fixed &obj);
		Fixed	&operator=(const Fixed &obj);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
std::ostream &operator<<( std::ostream &stream, Fixed const &entier);
#endif
