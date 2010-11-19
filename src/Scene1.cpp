#include "Scene1.h"


Scene1::Scene1()
{
	ofBackground(0, 0, 0);
	_img.loadImage("typeyourname.png");
	_test.loadImage("step1.jpg");
	_font.loadFont("GothamRounded-Book.ttf", 60, true, true);
}

void Scene1::update()
{
	
}

void Scene1::display()
{
	ofFill();
	ofSetColor(255, 255, 255);
	
	ofEnableAlphaBlending();
	//_test.draw(0, 0);
	_img.draw(206, 324);

	ofRect(804, 418, 24, 36);
	
	ofDisableAlphaBlending();
}
