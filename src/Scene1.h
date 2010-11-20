#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"

class Scene1 : public Scene {
	
	public:
		
	Scene1();
	void update();
	void display();
	void keyPressed(int key);

	private:
	
	ofImage _img;
	ofTrueTypeFont _font;
	
	Tween _titleFade;
	Tween _nameFade;
	
	Timer _nameCounter;
	
	string _userName;	
};