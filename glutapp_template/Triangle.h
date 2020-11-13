#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle{
	float x;
	float y;

	float red;
	float green; 
	float blue;

	float s;

public:
	Triangle();

	Triangle(float, float, float);

	Triangle(float, float, float, float, float, float);

	Triangle(const Triangle&);

	bool operator== (const Triangle&);

	~Triangle();

	bool contains(float, float) const;

	void draw();

	float getX() const ;

	float getY() const ;

	float getR() const ;

	float getG() const ;

	float getB() const ;

	void setX(float x);

	void setY(float y);

	void setS(float s);
};




#endif
