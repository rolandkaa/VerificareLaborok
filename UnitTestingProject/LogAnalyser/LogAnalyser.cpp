// LogAnalyser.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "LogAnalyser.h"


// This is an example of an exported variable
LOGANALYSER_API int nLogAnalyser=0;

// This is an example of an exported function.
LOGANALYSER_API int fnLogAnalyser(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see LogAnalyser.h for the class definition
CLogAnalyser::CLogAnalyser()
{
	return;
}

bool CLogAnalyser::endsWith(char* s)
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

bool CLogAnalyser::isTheFileValid(string s)
{
	if (s.length() < 3)
		//throw(someException());
		throw(invalidFileName());
	else
		return true;
}

CLogAnalyser::CLogAnalyser(CFakeFileExtMng* fem){
	logFem = fem;
}
