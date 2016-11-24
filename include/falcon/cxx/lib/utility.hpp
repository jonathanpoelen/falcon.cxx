/* The MIT License (MIT)

Copyright (c) 2016 jonathan poelen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/**
* \author    Jonathan Poelen <jonathan.poelen+falcon@gmail.com>
* \version   0.1
* \brief     c++11, 14, 17 utility macros
*/

#pragma once


#include <utility>

// std::exchange
#if defined(__cpp_lib_exchange_function) && __cpp_lib_exchange_function >= 201304
#  define FALCON_CXX_LIB_EXCHANGE_FUNCTION 1
#else
#  define FALCON_CXX_LIB_EXCHANGE_FUNCTION 0
#endif

// Compile-time integer sequences
#if defined(__cpp_lib_integer_sequence) && __cpp_lib_integer_sequence >= 201304
#  define FALCON_CXX_LIB_INTEGER_SEQUENCE 1
#else
#  define FALCON_CXX_LIB_INTEGER_SEQUENCE 0
#endif

// std::tuple_element_t
#if defined __cpp_lib_tuple_element_t && __cpp_lib_tuple_element_t >= 201402
#  define FALCON_CXX_LIB_TUPLE_ELEMENT_T 1
#else
#  define FALCON_CXX_LIB_TUPLE_ELEMENT_T 0
#endif

// std::get<T>
#if defined __cpp_lib_tuples_by_type && __cpp_lib_tuples_by_type >= 201304
#  define FALCON_CXX_LIB_TUPLES_BY_TYPE 1
#else
#  define FALCON_CXX_LIB_TUPLES_BY_TYPE 0
#endif
