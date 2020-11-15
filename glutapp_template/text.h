#ifndef TEXT_H
#define TEXT_H
#include <string>


class Text {
	float x;
	float y;

	float red;
	float green; 
	float blue;
    std::string text;
    void* font;

    float width;

public:
	Text();
    Text(float);

	~Text();
    void setr();
    void renderText(float x, float y, std::string words);
    void setW(float w);
    void setColor(float r, float g, float b);
    void Lose();
    void Win();
};

#endif
