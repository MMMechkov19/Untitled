#include "pch.h"
#include "CppUnitTest.h"
#include "..\MazeGame\mazeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenCoordinatesAreValid)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnTrueWhenCoordinatesAreValid)
		{
			int x = 5;
			int y = 5;
			int width = 11;
			int height = 11;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(true, result);
		}
	};
}
