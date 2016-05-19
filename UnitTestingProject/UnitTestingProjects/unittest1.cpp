#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\LogAnalyser\LogAnalyser.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestingProjects
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
			CLogAnalyser cl;
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

		TEST_METHOD(TestMethod3)
		{
			CLogAnalyser cl;
			Assert::AreEqual(
				// Expected value:
				true,
				// Actual value:
				cl.endsWith("valami"),
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
			CLogAnalyser cl;
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
			CLogAnalyser cl;
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
		

		TEST_METHOD(TestMethod6)
		{
			wchar_t message[200];
			CLogAnalyser cl;

			try
			{
				// Should raise an exception:
				bool res = cl.isTheFileValid("aaa");
				_swprintf(message, L"No exception for input %g", "aaa");
				//::IsTrue(res, message, LINE_INFO());
				Assert::Fail(message, LINE_INFO());
			}
			catch (invalidFileName ex)
			{
				Logger::WriteMessage("Correct exeption");
			}
			catch (...)
			{
				_swprintf(message, L"Incorrect exception for %g", "aa");
				Assert::Fail(message, LINE_INFO());
			}
		}


		TEST_METHOD(ParametrizedTest)
		{
			string st[] = { "aa", "bb", "cc" };
			wchar_t message[200];
			CLogAnalyser cl;
			for (int i = 0; i < 3; i++)
			{
				try
				{
					// Should raise an exception:
					bool res = cl.isTheFileValid(st[i]);
					_swprintf(message, L"No exception for input %g", "aaa");
					//::IsTrue(res, message, LINE_INFO());
					Assert::Fail(message, LINE_INFO());
				}
				catch (invalidFileName ex)
				{
					continue;
				}
				catch (...)
				{
					_swprintf(message, L"Incorrect exception for %g", "aa");
					Assert::Fail(message, LINE_INFO());
				}
			}
		}

		TEST_METHOD(isValidFileName_ValidFileName_ReturnsTrue) {

			CFakeFileExtMng* fem = new CFakeFileExtMng();
			fem->setErtek(true);
			CLogAnalyser la(fem);
			string s = "filename.txt";

			Assert::IsTrue(la.isTheFileValid(s));
			
		}

	};
}