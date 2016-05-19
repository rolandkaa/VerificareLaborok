#include <iostream>
#include "stdafx.h"
#include <memory>

#ifdef LOGANALAYSER_EXPORTS
#define LOGANALAYSER_API __declspec(dllexport)
#else
#define LOGANALAYSER_API __declspec(dllimport)
#endif

class LOGANALAYSER_API FileExtensionManagerFactory {
private:
	std::shared_ptr<CFileExtMng> fem;
	static std::shared_ptr<FileExtensionManagerFactory> me;
	FileExtensionManagerFactory();
public:
	void setFileExtensionManager(std::shared_ptr<CFileExtMng> fm);
	std::shared_ptr<CFileExtMng> getFileExtensionManager();
	static std::shared_ptr<FileExtensionManagerFactory> getFEMFactory();
};


extern LOGANALAYSER_API int nLogAnalyser;

LOGANALAYSER_API int fnLogAnalyser(void);