#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle: public Shape{
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float r;

public:
	Circle();

	Circle(float, float, float);

	Circle(float, float, float, float, float, float);

	Circle(const Circle&);

	bool operator== (const Circle&);

	~Circle();

	bool contains(float, float) const;

	void draw();

	float getX() const ;

	float getY() const ;

	float getW() const ;

	float getH() const ;

	float getR() const ;

	float getG() const ;

	float getB() const ;

	void setX(float x);

	void setY(float y);

	void setR(float r);
};




#endif
