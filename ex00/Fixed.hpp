#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <string>

class Fixed
{
	private:
		int					entier;
		int const static	nbb;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed	&operator=(const Fixed &obj);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};
#endif
