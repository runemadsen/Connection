#include "testApp.h"

/* Setup
_______________________________________________________________ */

void testApp::setup()
{
	ofSetWindowTitle("template project");

	ofSetFrameRate(60);
	
	curScene = 0;
	
	scenes.push_back( new Scene1() );
}

/* Update
 _______________________________________________________________ */

void testApp::update()
{
	scenes[curScene]->update();
	
	if (scenes[curScene]->finished()) 
	{
		if (curScene + 1 < scenes.size()) 
		{
			curScene++;
		}
	}
}

/* Draw
 _______________________________________________________________ */

void testApp::draw()
{
	scenes[curScene]->display();
}


/* Keypressed
 _______________________________________________________________ */

void testApp::keyPressed  (int key)
{
	if (key == 'f'){
		ofToggleFullscreen();
	}
}


void testApp::keyReleased  (int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}