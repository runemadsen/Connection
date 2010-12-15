#include "Scene1.h"

Scene1::Scene1()
{
	ofBackground(0, 0, 0);
	
	_name = SCENE_1;
	
	_img.loadImage("typeyourname.png");
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
	
	_nameCounter.duration = 200;
	
	_titleFade.setup(100, 255, -255, Easing::QuadEaseOut);
	_nameFade.setup(100, 255, -255, Easing::QuadEaseOut, 50);
	
	
	_userName = "";
}

void Scene1::update()
{
	_nameCounter.tick();
	
	
	if(_userName.size() > 0 && _nameCounter.time == _nameCounter.duration && !_fadeMode)
	{
		_fadeMode = true;
		
		// load user data
		App::getInstance()->loadUserData(_userName);
		
		_titleFade.play();
		_nameFade.play();
	}
	
	if(_fadeMode)
	{
		_titleFade.update();
		_nameFade.update();
		
		if(_nameFade.finished())
		{
			_finished = true;
		}
	}
}

void Scene1::display()
{
	ofEnableAlphaBlending();
	
	// Draw title
	//float a = Quad::easeOut(_titleFade.time, 255, -255, _titleFade.duration);
	
	float a =  _titleFade.num;
	float xPos = (ofGetWidth() / 2) - (_img.width / 2);
	float yPos = (ofGetHeight() / 2) - (_img.height / 2);
	
	ofSetColor(255, 255, 255, a);
	
	_img.draw(xPos, yPos);
	
	// Draw Blinker
	if(ofGetFrameNum() % 100 > 50)
	{
		a = 0;
	}
	
	ofFill();
	ofSetColor(255, 255, 255, a);
	
	xPos += _img.width - 24;
	yPos += _img.height + 20;
	
	ofRect(xPos, yPos, 24, 36);
	
	//Draw name
	
	ofSetColor(255, 255, 255, _nameFade.num);
	
	_font.drawString(_userName, xPos - 15 - _font.stringWidth(_userName), yPos + 25);
	
	ofDisableAlphaBlending();
}

void Scene1::keyPressed(int key)
{
	_userName.push_back(key);
	
	_nameCounter.time = 0;
	_nameCounter.state = 1;
}
