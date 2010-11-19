#include "Scene2.h"
#include "Sine.h"
#include "Quad.h"


Scene2::Scene2()
{
	ofBackground(0, 0, 0);
	
	_test.loadImage("step3.jpg");
	_hand.loadImage("hand.png");
	_hand.resize(_hand.width * 0.7, _hand.height * 0.7);
	_title.loadImage("placeyourhand.png");
	
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
}

void Scene2::update()
{
}

void Scene2::display()
{
	ofDrawBitmapString("Rune", 0, 0);
	ofEnableAlphaBlending();
	ofPoint loc;
	loc.set((ofGetWidth() / 2) - (_hand.width / 2), (ofGetHeight() / 2) - (_hand.height / 2) - 35);
	_hand.draw(loc.x, loc.y);
	_title.draw((ofGetWidth() / 2) - (_title.width / 2), loc.y + _hand.height + 30);
	ofDisableAlphaBlending();
}

void Scene2::keyPressed(int key)
{
}
