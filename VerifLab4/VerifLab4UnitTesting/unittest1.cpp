#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\LogAnalayser\LogAnalayser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace VerifLab4UnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		BEGIN_TEST_METHOD_ATTRIBUTE(TestMethod5)
			TEST_OWNER(L"Roliii")
			TEST_IGNORE()
			END_TEST_METHOD_ATTRIBUTE()

			TEST_METHOD(TestMethod1)
		{
				Assert::AreEqual(1, 1);
				// TODO: Your test code here
			}

		TEST_METHOD(TestMethod2)
		{
			CLogAnalayser cl;
			Assert::AreEqual(
				// Expected value:
				true,
				// Actual value:
				cl.endsWith("valamislf"),
				// Tolerance:
				0.0,
				// Message:
				L"Basic test failed",
				// Line number - used if there is no PDB file:
				LINE_INFO());
			// TODO: Your test code here
		}

		TEST_METHOD(TestMethod4)
		{
			CLogAnalayser cl;
			Assert::AreEqual(
				// Expected value:
				true,
				// Actual value:
				cl.isTheFileValid("valami"),
				// Tolerance:
				0.0,
				// Message:
				L"The file name is not valid",
				// Line number - used if there is no PDB file:
				LINE_INFO());
			// TODO: Your test code here
		}
		TEST_METHOD(TestMethod5)
		{
			CLogAnalayser cl;
			Assert::AreEqual(
				// Expected value:
				true,
				// Actual value:
				cl.isTheFileValid("va"),
				// Tolerance:
				0.0,
				// Message:
				L"The file name is not valid",
				// Line number - used if there is no PDB file:
				LINE_INFO());
			// TODO: Your test code here
		}

	

		TEST_METHOD(isValidFileName_ValidFileName_ReturnsTrue) {
			shared_ptr<CFileExtMng> ffm = shared_ptr<CFakeFileExtMng>(new CFakeFileExtMng);
			std::dynamic_pointer_cast<CFakeFileExtMng>(ffm)->setErtek(true);
			FileExtensionManagerFactory::getFEMFactory()->setFileExtensionManager(ffm);
			CFakeFileExtMng* fem = new CFakeFileExtMng();
			CLogAnalayser la;
			string s = "filename.txt";

			Assert::IsTrue(la.isTheFileValid(s));

		}
	};
}