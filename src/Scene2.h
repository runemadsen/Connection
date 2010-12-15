#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"
#include "Constants.h"

class Scene2 : public Scene {
	
public:
	
	Scene2();
	void init();
	void update();
	void display();
	void keyPressed(int key);
	void reset();
	
private:
	
	ofImage _title;
	ofImage _hand;
	ofTrueTypeFont _font;
	
	Timer _countDown;
	
	Tween _titleFade;
	Tween _handFade;
};