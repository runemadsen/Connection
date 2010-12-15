#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"
#include "App.h"

class Scene1 : public Scene {
	
	public:
		
	Scene1();
	void init();
	void update();
	void display();
	void keyPressed(int key);
	void reset();

	private:
	
	ofImage _img;
	ofTrueTypeFont _font;
	
	Tween _titleFade;
	Tween _nameFade;
	
	Timer _nameCounter;
	
	string _userName;	
};