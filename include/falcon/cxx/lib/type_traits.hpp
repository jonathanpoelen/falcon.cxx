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


#if __cplusplus >= 201103
#  include <type_traits>

// std::integral_constant::operator()
#  if defined(__cpp_lib_integral_constant_callable) && __cpp_lib_integral_constant_callable >= 201304
#    define FALCON_CXX_LIB_INTEGRAL_CONSTANT_CALLABLE 1
#  endif

// std::is_final
#  if defined(__cpp_lib_is_final) && __cpp_lib_is_final >= 201402
#    define FALCON_CXX_LIB_IS_FINAL 1
#  endif

// std::is_null_pointer
#  if defined(__cpp_lib_is_null_pointer) && __cpp_lib_is_null_pointer >= 201309
#    define FALCON_CXX_LIB_IS_NULL_POINTER 1
#  endif

// std::*_t
#  if defined(__cpp_lib_transformation_trait_aliases) && __cpp_lib_transformation_trait_aliases >= 201304
#    define FALCON_CXX_LIB_HAS_TRANSFORMATION_TRAIT_ALIASES 1
#  endif

// std::result_of and SFINAE
#  if defined __cpp_lib_result_of_sfinae && __cpp_lib_result_of_sfinae >= 201210
#    define FALCON_CXX_LIB_HAS_RESULT_OF_SFINAE 1
#  endif

#endif


#ifndef FALCON_CXX_LIB_INTEGRAL_CONSTANT_CALLABLE
#  define FALCON_CXX_LIB_INTEGRAL_CONSTANT_CALLABLE 0
#endif

#ifndef FALCON_CXX_LIB_IS_FINAL
#  define FALCON_CXX_LIB_IS_FINAL 0
#endif

#ifndef FALCON_CXX_LIB_IS_NULL_POINTER
#  define FALCON_CXX_LIB_IS_NULL_POINTER 0
#endif

#ifndef FALCON_CXX_LIB_HAS_TRANSFORMATION_TRAIT_ALIASES
#  define FALCON_CXX_LIB_HAS_TRANSFORMATION_TRAIT_ALIASES 0
#endif

#ifndef FALCON_CXX_LIB_HAS_RESULT_OF_SFINAE
#  define FALCON_CXX_LIB_HAS_RESULT_OF_SFINAE 0
#endif
