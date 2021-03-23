#include "stdafx.h"
#include "CppUnitTest.h"
#include "../lab2/lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(BothAnyTest)// ќбе любые
		{
			Assert::IsTrue(func(0, 0 ,0, 0, 0, 0)=="5", L"Branch1");
		}

		TEST_METHOD(SingleXandSingleY) //х=х0 , у=у0
		{
			Assert::IsTrue(func(1, 2, 1, 1, 4, 3) == "2 2.000000 1.000000", L"Branch2");
		}

		TEST_METHOD(NoSolutions)// решений нет
		{
			Assert::IsTrue(func(0, 0, 0, 0, 0, 1) == "0", L"Branch5");
		}

		TEST_METHOD(AnyXandSingleY)//х-любой , у=у0
		{
			Assert::IsTrue(func(0, 0, 0, 2, 0, 3) == "4 1.500000", L"Branch3");
			Assert::IsTrue(func(0, 1, 0, 2, 2, 4) == "4 2.000000", L"Branch6");
		}
	
		TEST_METHOD(SingleXandAnyY)//х=х0 , у-любой
		{
			Assert::IsTrue(func(20, 0, 0, 0, 2, 0) == "3 0.100000", L"Branch4");
			Assert::IsTrue(func(1, 0, 2, 0, 2, 4) == "3 2.000000", L"Branch7");
		}
		TEST_METHOD(IsKX_Plus_N) //y=kx+n
		{
			Assert::IsTrue(func(0, 0, -1, 1, 0, 0) == "1 1.000000 0.000000", L"Branch8");
			Assert::IsTrue(func(-1, 1, 0, 0, 0, 0) == "1 1.000000 0.000000", L"Branch9");
			Assert::IsTrue(func(0, 6.6, 1, 10, 0, 0) == "1 -10.000000 0.000000", L"Branch10");
			Assert::IsTrue(func(1, 10, 0, 6.6, 0, 0) == "1 -10.000000 0.000000", L"Branch11");
			Assert::IsTrue(func(6, 1, 6, 1, 5, 5) == "1 -6.000000 5.000000", L"Branch12");
		}

		TEST_METHOD(ComputationalErrorTest)
		{
			Assert::IsTrue(func(5, 2.55, 15, 7.65, 10, 30) == "Are you kidding me?", L"Branch13");
		}
	};
}