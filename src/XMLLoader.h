#include "ofxXmlSettings.h"
#include "ofxDirList.h"
#include "Constants.h"
#include "User.h"

class XMLLoader
{
public:
	void loadUserData(string username, User * user);
	
private:
	void parseModel(string fileName, User * user);
	
	ofxXmlSettings _xml;
};
