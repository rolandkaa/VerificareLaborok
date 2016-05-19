#include <iostream>
#include "stdafx.h"

#ifdef LOGANALAYSER_EXPORTS
#define LOGANALAYSER_API __declspec(dllexport)
#else
#define LOGANALAYSER_API __declspec(dllimport)
#endif

class LOGANALAYSER_API CFakeFileExtMng :public CFileExtMng{
private:
	bool v;
public:
	CFakeFileExtMng();
	~CFakeFileExtMng();
	bool isExtensionValid(std::string name);
	void setErtek(bool v);
};

extern LOGANALAYSER_API int nLogAnalyser;

LOGANALAYSER_API int fnLogAnalyser(void);