// LogAnalyser.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "LogAnalayser.h"


// This is an example of an exported variable
LOGANALAYSER_API int nLogAnalayser = 0;

// This is an example of an exported function.
LOGANALAYSER_API int fnLogAnalyser(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see LogAnalyser.h for the class definition
CLogAnalayser::CLogAnalayser(const std::shared_ptr<IWebService>& webService)
{
	this->webService = webService;
}

bool CLogAnalayser::endsWith(char* s)
{
	char* slf = "slf";
	int j = strlen(s) - 1;
	for (int i = strlen(slf) - 1; i >= 0; i--)
	{
		if (s[j] != slf[i])
			return false;
		j--;
	}
	return true;
}

bool CLogAnalayser::isTheFileValid(string s)
{
	if (s.size() < 5)
		webService->logError(s);
	//...
	return true; //TODO modify this
}
