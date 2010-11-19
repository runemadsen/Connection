#include "Scene1.h"
#include "Sine.h"
#include "Quad.h"


Scene1::Scene1()
{
	ofBackground(0, 0, 0);
	
	_img.loadImage("typeyourname.png");
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
	
	_nameCounter.duration = 200;
	_titleFade.duration = 100;
	_nameFade.duration = 100;
	
	_userName = "";
	
	_fadeMode = false;
}

void Scene1::update()
{
	_nameCounter.tick();
	
	if(_userName.size() > 0 && _nameCounter.time == _nameCounter.duration && !_fadeMode)
	{
		_fadeMode = true;
	}
	
	if(_fadeMode)
	{
		_titleFade.tick();
		
		if(_titleFade.time > 50)
		{
			_nameFade.tick();
		}
		
		if(_nameFade.time == _nameFade.duration)
		{
			_finished = true;	
		}
	}
}

void Scene1::display()
{
	ofEnableAlphaBlending();
	
	// Draw title
	float a = Quad::easeOut(_titleFade.time, 255, -255, _titleFade.duration);
	
	ofSetColor(255, 255, 255, a);
	_img.draw(206, 324);
	
	// Draw Blinker
	
	if(ofGetFrameNum() % 100 > 50)
	{
		a = 0;
	}
	
	ofFill();
	ofSetColor(255, 255, 255, a);
	
	ofRect(804, 418, 24, 36);
	
	//Draw name
	
	a = Quad::easeOut(_nameFade.time, 255, -255, _nameFade.duration);
	ofSetColor(255, 255, 255, a);
	
	_font.drawString(_userName, 793 - _font.stringWidth(_userName), 445);
	
	ofDisableAlphaBlending();
}

void Scene1::keyPressed(int key)
{
	_userName.push_back(key);
	
	_nameCounter.time = 0;
	_nameCounter.state = 1;
}
