#include "stdafx.h"
using std::shared_ptr;

shared_ptr<FileExtensionManagerFactory> FileExtensionManagerFactory::me = nullptr;

FileExtensionManagerFactory::FileExtensionManagerFactory(){}

shared_ptr<CFileExtMng> FileExtensionManagerFactory::getFileExtensionManager(){
	return fem;
}
void FileExtensionManagerFactory::setFileExtensionManager(shared_ptr<CFileExtMng> fm){
	fem = fm;
}
shared_ptr<FileExtensionManagerFactory> FileExtensionManagerFactory::getFEMFactory(){
	if (me == nullptr)
	{
		me = shared_ptr<FileExtensionManagerFactory>(new FileExtensionManagerFactory);
	}
	return me;
}
