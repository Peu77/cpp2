#ifndef FIXED_H
#define FIXED_H


class Fixed {
private:
	int _value;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif //FIXED_H
