#include "XMLLoader.h"

/* Load
 ___________________________________________________________ */

void XMLLoader::loadUserData(string username, User * user)
{	
	ofxDirList DIR;
	DIR.allowExt("xml");
	
	int numFiles = DIR.listDir(FOLDER);
	
	bool found = false;
	
	for(int i = 0; i < numFiles; i++)
	{
		cout << DIR.getName(i) << endl;
		
		if(username + ".xml" == DIR.getName(i))
		{
			parseModel(DIR.getName(i), user);
			
			found = true;
		}
	}
	
	if(!found)
	{
		cout << "No XML File found \n";
		
		_xml.setValue(VIDEOS, "");
		_xml.saveFile(FOLDER + username + ".xml");
	}
}

void XMLLoader::parseModel(string fileName, User * user)
{
	if(_xml.loadFile(FOLDER + fileName))
	{
		if(_xml.pushTag(VIDEOS, 0))
		{
			for (int i = 0; i < _xml.getNumTags(VIDEO); i++) 
			{
				Video * video = new Video();
				video->name = (string) _xml.getAttribute(VIDEO, NAME, "Not Found", i);
				video->date = (string) _xml.getAttribute(VIDEO, DATE, "Not Found", i);
				user->videos.push_back(video);
			}
		}
	}
}
/*
void XMLLoader::save()
{
	_xml.loadFromBuffer("<root></root>");
	
	_xml.clear();
	
	_xml.addTag(TOUCH);
	_xml.pushTag(TOUCH, 0);
	
	_xml.addTag(OUTLINE);
	_xml.pushTag(OUTLINE, 0);
	for(int i = 0; i < model->startOutline.size(); i++)
	{
		_xml.addTag(POINT);
		_xml.addAttribute(POINT, X, ofToString(model->startOutline[i].x, 1), i);
		_xml.addAttribute(POINT, Y, ofToString(model->startOutline[i].y, 1), i);
	}
	_xml.popTag();
	
	_xml.addTag(PATH);
	_xml.pushTag(PATH, 0);
	for(int i = 0; i < model->path.size(); i++)
	{
		_xml.addTag(POINT);
		_xml.addAttribute(POINT, X, ofToString(model->path[i].x, 1), i);
		_xml.addAttribute(POINT, Y, ofToString(model->path[i].y, 1), i);
	}
	_xml.popTag();
	
	_xml.addTag(DATETIME);
	_xml.addAttribute(DATETIME, YEAR, ofToString(model->dateTime[0], 0), 0);
	_xml.addAttribute(DATETIME, MONTH, ofToString(model->dateTime[1], 0), 0);
	_xml.addAttribute(DATETIME, DAY, ofToString(model->dateTime[2], 0), 0);
	_xml.addAttribute(DATETIME, HOUR, ofToString(model->dateTime[3], 0), 0);
	_xml.addAttribute(DATETIME, MINUTE, ofToString(model->dateTime[4], 0), 0);
	_xml.addAttribute(DATETIME, SECOND, ofToString(model->dateTime[5], 0), 0);
	
	string file = ofToString(model->dateTime[0]);
	file += "-";
	file += ofToString(model->dateTime[1]);
	file += "-";
	file += ofToString(model->dateTime[2]);
	file += "-";
	file += ofToString(model->dateTime[3]);
	file += "-";
	file += ofToString(model->dateTime[4]);
	file += "-";
	file += ofToString(model->dateTime[5]);
	
	if(model->fileName != "")
	{
		_xml.saveFile(FOLDER + model->fileName);
	}
	else 
	{		
		// this may fuck up if 2 people touch within a second
		_xml.saveFile(FOLDER + file + ".xml");
	}
}*/


