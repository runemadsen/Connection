#pragma once

#include "ofMain.h"

class Scene
{
	
public:
	
	Scene() { _finished = false; }
	virtual void update() {}
	virtual void display() {}
	virtual void keyPressed(int key) {}
	
	bool finished() { return _finished; }
	
protected:
	
	bool _finished;
	ofImage _test;
	
private:
	
	
	
};