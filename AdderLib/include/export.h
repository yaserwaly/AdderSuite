//// export.h
//#pragma once
//
//#if defined(_WIN32)
//  #if defined(BUILDING_ADDERLIB)
//    #define ADDER_API __declspec(dllexport)
//  #else
//    #define ADDER_API __declspec(dllimport)
//  #endif
//#else
//  #define ADDER_API
//#endif


#pragma once

// export.h
// تعريف ماكرو ADDER_API للتصدير والاستيراد على ويندوز
#if defined(_WIN32) || defined(_WIN64)
#if defined(ADDERLIB_EXPORTS)
#define ADDER_API __declspec(dllexport)
#else
#define ADDER_API __declspec(dllimport)
#endif
#else
#if __GNUC__ >= 4
#define ADDER_API __attribute__((visibility("default")))
#else
#define ADDER_API
#endif
#endif
