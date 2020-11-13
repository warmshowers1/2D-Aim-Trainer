#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square: public Shape{
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float s;

public:
	Square();

	Square(float, float, float);

	Square(float, float, float, float, float, float);

	Square(const Square&);

	bool operator== (const Square&);

	~Square();

	void draw();

	bool contains(float, float) const;

	float getX() const ;

	float getY() const ;

	float getS() const ;

	float getR() const ;

	float getG() const ;

	float getB() const ;

	void setX(float x);

	void setY(float y);

	void setS(float S);
};




#endif
