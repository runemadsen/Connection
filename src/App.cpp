#include "App.h"

/* Singleton stuff
 ___________________________________________________________ */

App * App::m_pInstance = NULL;

App * App::getInstance()
{
	if (!m_pInstance)   
		m_pInstance = new App;
	
	return m_pInstance;
}

/* Constructor
 ___________________________________________________________ */

App::App()
{
}

/* Load user data
 ___________________________________________________________ */

void App::loadUserData(string userName)
{
	// sanitize name
	
	_xml.loadUserData(userName, &user);
}
