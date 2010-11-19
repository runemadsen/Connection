#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"

class Scene2 : public Scene {
	
public:
	
	Scene2();
	void update();
	void display();
	void keyPressed(int key);
	
private:
	
	ofImage _title;
	ofImage _hand;
	ofTrueTypeFont _font;
	
	Timer _countDown;
	Timer _titleFade;
	Timer _handFade;
};