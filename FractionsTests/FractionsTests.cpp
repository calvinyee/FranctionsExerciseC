#include "pch.h"
#include "CppUnitTest.h"
#include "../FractionsExercise/Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FractionsTests
{
	// Unit tests. Call View->Test Explorer to run them.

	TEST_CLASS(FractionsTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Fraction f1("1/2");
			Fraction f2("3&3/4");
			Fraction res = calculate(f1, f2, "*");
			Assert::IsTrue(res == Fraction("1&7/8"));
		}

		TEST_METHOD(TestMethod2)
		{
			Fraction f1("1/2");
			Fraction f2("3/4");
			Fraction res = calculate(f1, f2, "+");
			Assert::IsTrue(res == Fraction("5/4"));
		}

		TEST_METHOD(TestMethod3)
		{
			Fraction f1("2&3/8");
			Fraction f2("9/8");
			Fraction res = calculate(f1, f2, "+");
			Assert::IsTrue(res == Fraction("3&1/2"));
		}

		TEST_METHOD(TestMethod4)
		{
			Fraction f1("1&3/4");
			Fraction f2("2");
			Fraction res = calculate(f1, f2, "-");
			Assert::IsTrue(res == Fraction("-1/4"));
		}

		TEST_METHOD(TestMethod5)
		{			
			bool exceptionThrown = false;
			Fraction f1("1/5");
			Fraction f2("0");
			try
			{
				Fraction res = calculate(f1, f2, "/");
			}
			catch (...) 
			{
				exceptionThrown = true;
			}
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(TestMethod6)
		{
			Fraction f1("1/2");
			Fraction f2("-1/2");
			Fraction res = calculate(f1, f2, "+");
			Assert::IsTrue(res == Fraction("0"));
		}
	};
}
