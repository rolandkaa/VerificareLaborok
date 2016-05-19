#include <iostream>
#include "stdafx.h"

#ifdef LOGANALAYSER_EXPORTS
#define LOGANALAYSER_API __declspec(dllexport)
#else
#define LOGANALAYSER_API __declspec(dllimport)
#endif

class LOGANALAYSER_API ManualMockService : public IWebService
{
public:
	virtual void logError(const std::string& errorMsg);
	std::string getError() const;

private:
	std::string error;
};



extern LOGANALAYSER_API int nLogAnalyser;

LOGANALAYSER_API int fnLogAnalyser(void);