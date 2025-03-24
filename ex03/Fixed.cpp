#include "Fixed.h"
#include <iostream>

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed(const int value) {
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::~Fixed() {
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	_value = fixed.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const {
	return _value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const {
	return _value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const {
	return _value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const {
	return _value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const {
	return _value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const {
	return _value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return Fixed(toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return Fixed(toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return Fixed(toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return Fixed(toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void) {
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

int Fixed::getRawBits(void) const {
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return _value >> _fractionalBits;
}

