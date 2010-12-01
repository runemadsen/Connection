#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"
#include "App.h"
#include "CountDown.h"

class SceneBeforeRecording : public Scene 
{
	
public:
	
	SceneBeforeRecording();
	
	void init();
	void update();
	void display();
	
	void keyPressed(int key);
	
	void showNoVideosSign();
	
private:
	
	Tween _fadeDown;
	
	int _signToShow;
	
	string _msg1;
	string _msg2;
	
	ofTrueTypeFont _font;
};