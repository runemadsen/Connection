#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"
#include "App.h"
#include "CountDown.h"

class SceneFinished : public Scene 
{
	
public:
	
	SceneFinished();
	
	void init();
	void update();
	void display();
	void reset();
	
	void keyPressed(int key);
	
private:
	
	Tween _fadeDown;
	
	ofTrueTypeFont _font;
};