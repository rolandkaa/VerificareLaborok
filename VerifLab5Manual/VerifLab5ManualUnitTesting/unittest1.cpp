#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\LogAnalayser\LogAnalayser.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VerifLab5ManualUnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::shared_ptr<IWebService> webService(
				std::shared_ptr<ManualMockService>(new ManualMockService)
				);

			CLogAnalayser la(webService);

			la.isTheFileValid("xyz");
			string a = "xyz";
			Assert::AreEqual(a, std::dynamic_pointer_cast<ManualMockService>(webService)->getError());
		}

	};
}