#pragma once

#include "ofMain.h"

class Scene
{
	
public:
	
	Scene() {}
	virtual void update() {}
	virtual void display() {}
	virtual void keyPressed(int key) {}
	
	bool finished() { return _finished; }
	
protected:
	
	bool _finished;
	
private:
	
	
	
};