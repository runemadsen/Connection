#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"
#include "App.h"
#include "CountDown.h"

class SceneRecording : public Scene 
{
	
public:
	
	SceneRecording();
	
	void init();
	void update();
	void display();
	
	void keyPressed(int key);
	
private:
	
	Tween _captureFade;
	
	Tween _line1;
	Tween _line2;
	Tween _line3;
	Tween _line4;
	Tween _lineColor;
	
	CountDown _count;
	
	ofVideoGrabber _vidGrabber;
	
	bool _captureStarted;
	bool _recordStarted;
	
	int _rectSize;
};