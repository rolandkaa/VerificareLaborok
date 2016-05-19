// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LOGANALYSER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LOGANALYSER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#include <iostream>
#include "stdafx.h"
#include <memory>

using namespace std;
#ifdef LOGANALAYSER_EXPORTS
#define LOGANALAYSER_API __declspec(dllexport)
#else
#define LOGANALAYSER_API __declspec(dllimport)
#endif

// This class is exported from the LogAnalyser.dll
class LOGANALAYSER_API CLogAnalayser {
	std::shared_ptr<IWebService> webService;

public:
	CLogAnalayser(const std::shared_ptr<IWebService>& webService);
	bool endsWith(char* s);
	bool isTheFileValid(std::string s);
	// TODO: add your methods here.
};

class invalidFileName : public std::exception {

public:
	const char *what() { return "File name is invalid"; };
};



extern LOGANALAYSER_API int nLogAnalyser;

LOGANALAYSER_API int fnLogAnalyser(void);
