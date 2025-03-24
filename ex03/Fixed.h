#ifndef FIXED_H
#define FIXED_H
#include <ostream>


class Fixed {
private:
	int _value{};
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed(const int  value);
	Fixed(const float value);
	~Fixed();

	friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

	Fixed &operator=(const Fixed &fixed);
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	Fixed operator+(const Fixed &fixed) const;
	Fixed operator-(const Fixed &fixed) const;
	Fixed operator*(const Fixed &fixed) const;
	Fixed operator/(const Fixed &fixed) const;

	Fixed &operator++(void);
	Fixed operator++(int);
	Fixed &operator--(void);
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

};


#endif //FIXED_H
