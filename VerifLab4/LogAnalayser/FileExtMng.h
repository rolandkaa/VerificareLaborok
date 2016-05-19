#include <iostream>
#include "stdafx.h"

using namespace std;

#ifdef LOGANALAYSER_EXPORTS
#define LOGANALAYSER_API __declspec(dllexport)
#else
#define LOGANALAYSER_API __declspec(dllimport)
#endif

class CFileExtMng{
public:
	CFileExtMng();
	virtual ~CFileExtMng();
	virtual bool isExtensionValid(std::string name) = 0;

};

extern LOGANALAYSER_API int nLogAnalyser;

LOGANALAYSER_API int fnLogAnalyser(void);