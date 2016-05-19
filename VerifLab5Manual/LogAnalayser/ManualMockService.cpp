#include "stdafx.h"

void ManualMockService::logError(const std::string& errorMsg)
{
	error = errorMsg;
}

std::string ManualMockService::getError() const {
	return error;
}