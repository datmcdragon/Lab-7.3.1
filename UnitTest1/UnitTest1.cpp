#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab-7.3.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int k = 3;
			int n = 5;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];
			int s = Zero(a, k, 2);
			Assert::AreEqual(s, 0);
		}
	};
}
