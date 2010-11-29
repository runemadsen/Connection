#pragma once

#include "ofMain.h"
#include "Scene.h"
#include "Tools.h"
#include "App.h"

class ScenePlayback : public Scene 
{
	
public:
	
	ScenePlayback();
	
	void init();
	void update();
	void display();
	
	void keyPressed(int key);
	
private:
	
	ofVideoPlayer _video;
	
	int _curVideo;
	
	Tween _videoFadeUp;
	Tween _videoFadeDown;
};