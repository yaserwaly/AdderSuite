// AdderApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "adder.h"       // لو بدك استخدام Adder مباشرة
#include "adder_factory.h"// لو المصنع يرجع unique_ptr<IAdder>
#include "c_api.h"       // واجهة الـ C API
#include "logger.h"      // نظام الـ Logging
#include "error.h"       // نوع الخطأ المخصص
#include "iadder.h"

#include "adder_adapter.h"


#include <iostream>
#include <memory>         // unique_ptr, make_unique
#include <cstdlib>        // system (اختياري)
#include <utility>  // std::move
#include <limits>   // numeric_limits

//#include <windows.h>

//#include <io.h>
//#include <fcntl.h>
//#include <locale>
#include <string>

//AdderAdapter.hpp
//class clsAdderAdapter : public IAdder {
//public:
//    explicit clsAdderAdapter(
//        std::unique_ptr<IAdder> adder = nullptr
//    );
//    int add(int a, int b) override;
//private:
//    std::unique_ptr<IAdder> m_Adder;
//};
//
////AdderAdapter.cpp
//clsAdderAdapter::clsAdderAdapter(
//    std::unique_ptr<IAdder> adder
//) : m_Adder(adder ? std::move(adder) : std::make_unique<Adder>()) {
//}
//
//int clsAdderAdapter::add(int a, int b) {
//    return m_Adder->add(a, b);
//}

int main()
{

    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);
    //std::cout << "Hello World!\n";
    
    // ضبط مستوى الـ Logger
    Logger::set_level(LogLevel::Debug);

    try {
        // استخدام الكلاس Adder مباشرة
        Adder a;
        int result1 = a.add(10, 20);
        std::cout << "Adder::add(10,20) = " << result1 << std::endl;

        // استخدام الافتراضي (سيُنشئ Adder داخلياً)
        AdderAdapter adapterDefault;
        int resultAdapter = adapterDefault.add(2, 3);
        std::cout << "Adapter default -> add(2,3) = " << resultAdapter << std::endl;

        // حقن Stub أو Mock عبر unique_ptr
        // auto stub = std::make_unique<AdderStub>();
        // clsAdderAdapter adapterWithStub(std::move(stub));

        // 1) إنشاء Adder مباشرة باستخدام make_unique
        auto adderDirect = std::make_unique<Adder>();
        int result2 = adderDirect->add(10, 20);
        std::cout << "Adder (make_unique) -> add(10,20) = " << result2 << std::endl;

        // 2) الحصول على Adder عبر المصنع (يفضل إذا المصنع يرجع unique_ptr<IAdder>)
        auto adderFromFactory = AdderFactory::create(AdderType::Real); // unique_ptr<IAdder>
        int resultFactory = adderFromFactory->add(15, 25);
        std::cout << "Adder (factory) -> add(15,25) = " << resultFactory << std::endl;

        // استخدام الـ C API
        int result3 = add_numbers(30, 40);
        std::cout << "add_numbers(30,40) = " << result3 << std::endl;

        // تجربة Overflow (سيُرمي ArithmeticError)
        //int big = INT32_MAX;
        constexpr int big = std::numeric_limits<int>::max();
        std::cout << "Attempting overflow add(" << big << ", 1)..." << std::endl;
        int result4 = a.add(big, 1); // هذا سيولّد خطأ
        std::cout << "Result = " << result4 << std::endl;
    }
    catch (const ArithmeticError& e) {
        std::cerr << "Caught ArithmeticError: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught std::exception: " << e.what() << std::endl;
    }

    //system("pause");  // يطبع رسالة "Press any key to continue . . ." وينتظر كبسة
    
    // إيقاف الشاشة بطريقة محمولة (أفضل من system("pause"))
    std::cout << "Press any key to continue . . ." << std::endl;
    std::cin.get();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
