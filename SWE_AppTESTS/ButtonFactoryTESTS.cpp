#include "pch.h"
#include "CppUnitTest.h"
#include "../SWE_App/ButtonFactory.h"

// create 10 test conditions for ButtonFactory, 
// test that certain functions return buttons w specific labels, IDs, pos, size

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SWE_AppTESTS
{

    TEST_CLASS(CppUnitTest01)
    {
  
    public:

        // 1) equals
        TEST_METHOD(TestEquals)
        {
        
            wxButton* button = ButtonFactory::CreateEqualsButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(18, id);
            

            //wxButton* button = ButtonFactory::CreateEqualsButton(nullptr);
            //wxPoint pos = button->GetPosition();
            //Assert::AreEqual(160, pos.x);
            //Assert::AreEqual(400, pos.y);

            //Assert::IsTrue(true);

            //wxButton* button = ButtonFactory::CreateEqualsButton(test);
            //Assert::IsNotNull(button);
            //std::string expected = "=";
            //std::string given = button->GetLabel().ToStdString();
            //Assert::AreEqual(expected, given);
            // fail
        }

        // 2) AC
        TEST_METHOD(TestAC)
        {
            wxButton* button = ButtonFactory::CreateACButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(19, id);
        }

        // 3) C
        TEST_METHOD(TestClear)
        {
            wxButton* button = ButtonFactory::CreateCButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(20, id);
        }

        // 4) Decimal
        TEST_METHOD(TestDecimal)
        {
            wxButton* button = ButtonFactory::CreateDecimalButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(21, id);
        }

        // 5) Negative
        TEST_METHOD(TestNegative)
        {
            wxButton* button = ButtonFactory::CreateNegativeButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(22, id);
        }

        // 6)
        TEST_METHOD(TestPlusSign)
        {
            wxButton* button = ButtonFactory::CreateAddButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(10, id);
        }

        // 7)
        TEST_METHOD(TestMinusSign)
        {
            wxButton* button = ButtonFactory::CreateSubButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(11, id);
        }

        // 8)
        TEST_METHOD(TestMultSign)
        {
            wxButton* button = ButtonFactory::CreateMultButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(12, id);
        }

        // 9)
        TEST_METHOD(TestDivSign)
        {
            wxButton* button = ButtonFactory::CreateDivButton(nullptr);
            int id = button->GetId();
            Assert::AreEqual(13, id);
        }

        // 10)
        TEST_METHOD(TestZeroButton)
        {
            wxButton* button = ButtonFactory::CreateNumber0Button(nullptr);
            int id = button->GetId();
            Assert::AreEqual(0, id);
        }
    };

    //wxFrame* CppUnitTest01::test = nullptr;

}

//TEST_METHOD(TestClassInit)
//{
//    std::string name = "Bill";
//    MyClass mc(name);
//    Assert::AreEqual(name, mc.GetName());
//}

// IDs from enum
//ID_NUMBER_0,           0
//ID_NUMBER_1,           1
//ID_NUMBER_2,           2
//ID_NUMBER_3,           3
//ID_NUMBER_4,           4
//ID_NUMBER_5,           5
//ID_NUMBER_6,           6
//ID_NUMBER_7,           7
//ID_NUMBER_8,           8
//ID_NUMBER_9,           9
//ID_ADD,                10
//ID_SUB,                11
//ID_MULT,               12
//ID_DIV,                13
//ID_MOD,                14
//ID_SIN,                15
//ID_COS,                16
//ID_TAN,                17
//ID_EQUALS,             18
//ID_AC,                 19
//ID_C,                  20
//ID_DECIMAL,            21
//ID_NEGATIVE            22