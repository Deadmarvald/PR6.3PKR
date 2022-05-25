#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR6.3/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT63
{
	TEST_CLASS(UT63)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;

			for (int i = 0; i < 2; i++)
			{
				enqueue(first, last, 2);
			}

			Assert::AreEqual(first->info, last->info);
		}
	};
}