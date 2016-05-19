#include <iostream>
#include "stdafx.h"

#ifdef LOGANALAYSER_EXPORTS
#define LOGANALAYSER_API __declspec(dllexport)
#else
#define LOGANALAYSER_API __declspec(dllimport)
#endif


class LOGANALAYSER_API IWebService
{
public:
	virtual void logError(const std::string& errorMsg) = 0;
	virtual ~IWebService() {};
};


extern LOGANALAYSER_API int nLogAnalyser;

LOGANALAYSER_API int fnLogAnalyser(void);