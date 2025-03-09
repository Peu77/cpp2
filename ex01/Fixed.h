#ifndef FIXED_H
#define FIXED_H
#include <ostream>


class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int  value);
	Fixed(const float value);

	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};


#endif //FIXED_H
