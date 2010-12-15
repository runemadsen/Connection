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
	virtual void reset() {}
	
	bool finished() { return _finished; }
	
	int getName() { return _name; }
	
protected:
	
	bool _finished;
	ofImage _test;
	
	bool _fadeMode;
	
	int _name;
	
private:
	
	
	
};