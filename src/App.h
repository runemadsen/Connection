#pragma once

#include "User.h"
#include "ofMain.h"
#include "XMLLoader.h"

class App  
{
	
public:
	
	static App * getInstance();
	
	User user;
	
	void loadUserData(string userName);
	
private:
	
	// singleton stuff
	App();  
	App(App const&){};   
	App& operator=(App const&){};
	static App* m_pInstance;
	
	XMLLoader _xml;
};