
#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

#define UNIT_TEST
#include "C:/Users/Sasha/Downloads/student/vs/LR8.1iter/LR8.1iter/LR8.1iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestEmptyString)
        {
            Assert::IsFalse(hasNoOrOn(""));
        }

        TEST_METHOD(TestNoPairs)
        {
            Assert::IsFalse(hasNoOrOn("hello"));
        }

        TEST_METHOD(TestPairOn)
        {
            Assert::IsTrue(hasNoOrOn("only"));
        }

        TEST_METHOD(TestPairNo)
        {
            Assert::IsTrue(hasNoOrOn("know"));
        }

        TEST_METHOD(TestTwoReplacements)
        {
            char result[128] = {};

            bool ok = replaceNo("nono on", result, sizeof(result));

            Assert::IsTrue(ok);
            Assert::IsTrue(strcmp(result, "****** on") == 0);
        }

        TEST_METHOD(TestOnNotReplaced)
        {
            char result[128] = {};

            bool ok = replaceNo("on", result, sizeof(result));

            Assert::IsTrue(ok);
            Assert::IsTrue(strcmp(result, "on") == 0);
        }

        TEST_METHOD(TestBufferOverflow)
        {
            char result[2] = {};

            bool ok = replaceNo("nono", result, sizeof(result));

            Assert::IsFalse(ok);
        }
    };
}
