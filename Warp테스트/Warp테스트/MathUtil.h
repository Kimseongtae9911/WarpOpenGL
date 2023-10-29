#pragma once 
class Vector2
{
public:
	Vector2() { x = 0.f, y = 0.f; }
	Vector2(float x, float y) :x(x), y(y) {}

	friend ostream& operator <<(ostream& os, const Vector2& v) {
		return os << v.x << ", " << v.y;
	}

	friend Vector2 operator + (const Vector2& l, const Vector2& r) {
		return Vector2(l.x + r.x, l.y + r.y);
	}
	
	friend Vector2 operator * (const Vector2& l, float r) {
		return Vector2(l.x * r, l.y * r);
	}

	void operator+=(const Vector2& r) {
		x += r.x;
		y += r.y;
	}

	float x;
	float y;
};