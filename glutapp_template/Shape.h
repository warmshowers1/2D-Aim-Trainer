#ifndef Shape_h
#define Shape_h

class Shape{
    float x;
    float y;

    float red;
    float green;
    float blue;

    float r;

public:
    Shape();
    virtual void draw();
    
    ~Shape();
};

#endif
