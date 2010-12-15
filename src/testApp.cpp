#include "testApp.h"

/* Setup
_______________________________________________________________ */

void testApp::setup()
{
	ofSetWindowTitle("template project");

	ofSetFrameRate(60);
	
	curScene = 0;
	
	scenes.push_back( new Scene1() );
	scenes.push_back( new Scene2() );
	scenes.push_back( new ScenePlayback() );
	scenes.push_back( new SceneBeforeRecording() );
	scenes.push_back( new SceneRecording() );
	scenes.push_back( new SceneFinished() );
	
	scenes[0]->init();
}

/* Update
 _______________________________________________________________ */

void testApp::update()
{
	scenes[curScene]->update();
	
	if (scenes[curScene]->finished()) 
	{		
		curScene++;
		
		if(curScene == scenes.size())
		{
			curScene = 0;
			
			resetAll();
		}
		
		if(curScene == SCENE_PLAYBACK && App::getInstance()->user.videos.size() == 0)
		{
			curScene++;
			
			SceneBeforeRecording * scene = (SceneBeforeRecording *) scenes[curScene];
			scene->showNoVideosSign();
		}
		
		scenes[curScene]->init();
	}
}

/* Draw
 _______________________________________________________________ */

void testApp::draw()
{
	ofSetColor(255, 255, 255, 255);
	
	scenes[curScene]->display();
}

/* Reset All
 _______________________________________________________________ */

void testApp::resetAll()
{
	App * app = App::getInstance();
	
	app->user.name = "";
	app->user.videos.clear();
	
	for (int i = 0; i < scenes.size(); i++) 
	{
		scenes[i]->reset();
	}
}


/* Keypressed
 _______________________________________________________________ */

void testApp::keyPressed  (int key)
{
	if (key == 'f'){
		ofHideCursor();
		ofToggleFullscreen();
	}
	else 
	{
		scenes[curScene]->keyPressed(key);
	}

}


void testApp::keyReleased  (int key){}
void testApp::mouseMoved(int x, int y ){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
