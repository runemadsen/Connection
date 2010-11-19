#pragma once

#include "ofMain.h"

class Scene
{
	
public:
	
	Scene() {}
	virtual void update() {}
	virtual void display() {}
	
	bool finished() { return _finished; }
	
protected:
	
	bool _finished;
	
private:
	
	
	
};