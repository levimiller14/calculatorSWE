#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/CalculatorProcessor.h"

// create 10 test conditions for CalculatorProcessor
// including tests of individual operations and order or operations

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWE_AppTESTS
{
    TEST_CLASS(CalculatorProcessorTESTS)
    {
    public:
        
        // test individual oeperations
        // addition (1)
        TEST_METHOD(TestAddition)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("5 + 3");
            Assert::AreEqual(8.0, result);
            // pass
        }

        // 2) subtraction
        TEST_METHOD(TestSubtraction)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("5 - 3");
            Assert::AreEqual(2.0, result);
            // pass
        }

        // 3) mult
        TEST_METHOD(TestMult)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("5 * 3");
            Assert::AreEqual(15.0, result);
            // pass
        }

        // 4) div
        TEST_METHOD(TestDiv)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("10 / 2");
            Assert::AreEqual(5.0, result);
            // pass
        }

        // 5) mod
        TEST_METHOD(TestMod)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("5 % 2");
            Assert::AreEqual(1.0, result);
            // fail? 5mod1 = 1?
            // 5mod2 = 1 smh
        }

        // 6) sin
        TEST_METHOD(TestSIN)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("sin90");
            Assert::AreEqual(1.0, result);
            // pass
        }

        // 7) cos
        TEST_METHOD(TestCOS)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("cos0");
            Assert::AreEqual(1.0, result);
            // pass
        }

        // 8) tan
        TEST_METHOD(TestTAN)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("tan45");
            Assert::AreEqual(1.0, result, .001);
            // fails? expects <1> but gets <1> ?
            // add tolerance?
            // pass
            
        }       

        // 9) Order of Operations
        TEST_METHOD(TestOOP)
        {
            CalculatorProcessor* calc = CalculatorProcessor::GetInstance();
            double result = calc->Calculate("5 + 2 * (6/2) * 3");
            Assert::AreEqual(23.0, result);
            // fail, expected 23 got 44?
            // mmmmmmmmmmmmmmm
            // implicit mult in OOP not supported??....
            // passing with * explicity stated, need to update?

        }
        // 10) ?
    };
}

//TEST_METHOD(TestClassInit)
//{
//    std::string name = "Bill";
//    MyClass mc(name);
//    Assert::AreEqual(name, mc.GetName());
//}