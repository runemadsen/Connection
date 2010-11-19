#pragma once

#include "ofMain.h"
#include "Scene.h"

class Scene1 : public Scene {
	
	public:
		
	Scene1();
	void update();
	void display();

	private:
	
	ofImage _img;
	ofTrueTypeFont _font;
	ofImage _test;
};