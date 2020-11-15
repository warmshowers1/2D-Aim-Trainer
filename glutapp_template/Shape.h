#ifndef SHAPE_H
#define SHAPE_H


class Shape {
	float x;
	float y;
    float radius;

	float red;
	float green; 
	float blue;

	float w;
	float h;

	int shape;

	bool selected;

public:
	Shape();
    Shape(float, float, float, float, float, float, float);
    Shape(float, float, float, float, float, float);
    Shape(float, float, float, float, float, float, float, float);
	~Shape();

	void drawRect();

    void drawTri();

    void drawCirc();

	void select();
	void deselect();
    bool contains(float, float) const;

	float getX() const ;

	float getY() const ;

	float getW() const ;

	float getH() const ;

	float getR() const ;

	float getG() const ;

	float getB() const ;

	bool getSel() const;

	void setX(float);

	void setY(float);

	void setW(float);

	void setH(float);

    void setRad(float);

	void setCol(float, float, float);

	void setSh(int);
	int getSh() const;

};




#endif
