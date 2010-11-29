#pragma once

#include "ofMain.h"
#include "Tween.h"

class Scene
{
	
public:
	
	Scene() { _finished = false; _fadeMode = false; }
	virtual void update() {}
	virtual void display() {}
	virtual void keyPressed(int key) {}
	virtual void init() {}
	
	bool finished() { return _finished; }
	
protected:
	
	bool _finished;
	ofImage _test;
	
	bool _fadeMode;
	
private:
	
	
	
};