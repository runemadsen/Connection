#pragma once

#include "Tween.h"
#include "ofMain.h"

class CountDown
{

public:
	
	CountDown();
	
	void play();
	
	void update();
	void draw();
	
	bool finished() { return _finished; }
	
private:
	
	Tween _letter1;
	Tween _letter1Down;
	Tween _letter2;
	Tween _letter3;
	
	ofTrueTypeFont _font;
	
	bool _finished;
};