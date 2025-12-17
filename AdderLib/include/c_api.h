// AdderSuite/src/c_api/c_api.h
#pragma once

#include "export.h"

//extern "C" {
//    int add_numbers(int a, int b);
//}

#ifdef __cplusplus
extern "C" {
#endif

	ADDER_API int add_numbers(int a, int b);

#ifdef __cplusplus
}
#endif

