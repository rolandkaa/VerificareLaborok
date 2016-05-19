#include <iostream>
#include "stdafx.h"

using namespace std;

#ifdef LOGANALYSER_EXPORTS
#define LOGANALYSER_API __declspec(dllexport)
#else
#define LOGANALYSER_API __declspec(dllimport)
#endif

class CFileExtMng{
public:
	CFileExtMng();
	virtual ~CFileExtMng();
	virtual bool isExtensionValid(std::string name) = 0;

};

class LOGANALYSER_API CFakeFileExtMng :public CFileExtMng{
private:
	bool v;
public:
	CFakeFileExtMng();
	~CFakeFileExtMng();
	bool isExtensionValid(std::string name);
	void setErtek(bool v);
};

extern LOGANALYSER_API int nLogAnalyser;

LOGANALYSER_API int fnLogAnalyser(void);