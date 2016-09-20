#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

using namespace std;

class vector2d {
	// Utility class for two-dimensional vector operations for gravity physics engine.
	// Operator overload must be a friend if it calls the constructor of the class.
public:
	vector2d() { x = 0.0; y = 0.0; }
	vector2d(double a, double b = 0.0) { x = a; y = b; }
	bool operator== (const vector2d &v) const { if ((x == v.x) && (y == v.y)) return true; else return false; }
	bool operator!= (const vector2d &v) const { if ((x != v.x) || (y != v.y)) return true; else return false; }
	vector2d operator+ (const vector2d &v) const { return vector2d(x + v.x, y + v.y); }
	vector2d operator- (const vector2d &v) const { return vector2d(x - v.x, y - v.y); }
	friend vector2d operator- (const vector2d &v) { return vector2d(-v.x, -v.y); }
	vector2d& operator+= (const vector2d &v) { x += v.x; y += v.y; ; return *this; }
	vector2d& operator-= (const vector2d &v) { x -= v.x; y -= v.y; ; return *this; }
	double operator* (const vector2d &v) const { return (x*v.x + y*v.y); }
	friend vector2d operator* (const vector2d &v, const double &a) { return vector2d(v.x*a, v.y*a); }
	friend vector2d operator* (const double &a, const vector2d &v) { return vector2d(v.x*a, v.y*a); }
	vector2d& operator*= (const double &a) { x *= a; y *= a; return *this; }
	vector2d operator/ (const double &a) const { return vector2d(x / a, y / a); }
	vector2d& operator/= (const double &a) { x /= a; y /= a; return *this; }
	double abs2() const { return (x*x + y*y); }
	double abs() const { return sqrt(this->abs2()); }
	vector2d norm() const { double s(this->abs()); if (s == 0) return *this; else return vector2d(x / s, y / s); }
	friend ostream& operator<< (ostream &out, const vector2d &v) { out << v.x << ' ' << v.y << ' '; return out; }
	double x, y;
private:
};

#endif //VECTOR2D_H