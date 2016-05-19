// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LOGANALYSER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LOGANALYSER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <iostream>
#include "stdafx.h"

using namespace std;
#ifdef LOGANALYSER_EXPORTS
#define LOGANALYSER_API __declspec(dllexport)
#else
#define LOGANALYSER_API __declspec(dllimport)
#endif

// This class is exported from the LogAnalyser.dll
class LOGANALYSER_API CLogAnalyser {
	CFakeFileExtMng* logFem;

public:
	CLogAnalyser(void);
	bool endsWith(char* s);
	bool isTheFileValid(string s);
	CLogAnalyser(CFakeFileExtMng* fem);
	// TODO: add your methods here.
};

class invalidFileName : public exception {

public:
	const char *what() { return "File name is invalid"; };
};


class someException : public exception {

public:
	const char *what() { return "Some other exception."; };
};


extern LOGANALYSER_API int nLogAnalyser;

LOGANALYSER_API int fnLogAnalyser(void);
