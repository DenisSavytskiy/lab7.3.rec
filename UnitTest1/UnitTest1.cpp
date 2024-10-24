#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№7.3.рек/AP_Lab№7.3.рек.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Test matrix
            a[0][0] = 1; a[0][1] = 2; a[0][2] = -3;
            a[1][0] = 2; a[1][1] = 1; a[1][2] = 4;
            a[2][0] = 3; a[2][1] = 4; a[2][2] = 1;

            int sum = Part2_SumNegativeRows_Recursive(a, n, 0);
            Assert::AreEqual(0, sum);

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}