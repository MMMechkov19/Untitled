#include "pch.h"
#include "CppUnitTest.h"
#include "..\MazeGame\mazeFunctions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenCoordinatesAreValidEasyMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnTrueWhenCoordinatesAreValidEasyMode)
		{
			int x = 5;
			int y = 5;
			int width = 11;
			int height = 11;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(true, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnFalseWhenCoordinatesAreEqualEasyMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnFalseWhenCoordinatesAreEqualEasyMode)
		{
			int x = 11;
			int y = 11;
			int width = 11;
			int height = 11;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(false, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnFalseWhenCoordinatesAreNotInRangeEasyMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnFalseWhenCoordinatesAreNotInRangeEasyMode)
		{
			int x = -1;
			int y = -1;
			int width = 11;
			int height = 11;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(false, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenCoordinatesAreValidMediumMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnTrueWhenCoordinatesAreValidMediumMode)
		{
			int x = 5;
			int y = 5;
			int width = 21;
			int height = 21;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(true, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnFalseWhenCoordinatesAreEqualMediumMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnFalseWhenCoordinatesAreEqualMediumMode)
		{
			int x = 21;
			int y = 21;
			int width = 21;
			int height = 21;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(false, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnFalseWhenCoordinatesAreNotInRangeMediumMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnFalseWhenCoordinatesAreNotInRangeMediumMode)
		{
			int x = -1;
			int y = -1;
			int width = 21;
			int height = 21;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(false, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnTrueWhenCoordinatesAreValidHardMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnTrueWhenCoordinatesAreValidHardMode)
		{
			int x = 5;
			int y = 5;
			int width = 21;
			int height = 31;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(true, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnFalseWhenCoordinatesAreEqualHardMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnFalseWhenCoordinatesAreEqualHardMode)
		{
			int x = 21;
			int y = 31;
			int width = 21;
			int height = 31;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(false, result);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(expectToReturnFalseWhenCoordinatesAreNotInRangeHardMode)
		TEST_OWNER(L"VNTeneve19")
		TEST_PRIORITY("Low")
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(expectToReturnFalseWhenCoordinatesAreNotInRangeHardMode)
		{
			int x = -1;
			int y = -1;
			int width = 21;
			int height = 31;

			bool result = isInBounds(x, y, width, height);

			Assert::AreEqual(false, result);
		}
	};
}
