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

#include <falcon/cxx/cxx.hpp>


#if __cplusplus >= FALCON_CXX_STD_14 && FALCON_HAS_INCLUDE(<experimental/functional>)
#  include <experimental/functional>

// std::experimental::search
#  if defined(__cpp_lib_experimental_boyer_moore_searching) && __cpp_lib_experimental_boyer_moore_searching >= 201411
#    define FALCON_CXX_LIB_EXPERIMENTAL_BOYER_MOORE_SEARCHING 1
#  endif

// Type-erased allocator for std::function
#  if defined(__cpp_lib_experimental_function_erased_allocator) && __cpp_lib_experimental_function_erased_allocator >= 201406
#    define FALCON_CXX_LIB_EXPERIMENTAL_FUNCTION_ERASED_ALLOCATOR 1
#  endif

#endif

#ifndef FALCON_CXX_LIB_EXPERIMENTAL_BOYER_MOORE_SEARCHING
#  define FALCON_CXX_LIB_EXPERIMENTAL_BOYER_MOORE_SEARCHING 0
#endif

#ifndef FALCON_CXX_LIB_EXPERIMENTAL_FUNCTION_ERASED_ALLOCATOR
#  define FALCON_CXX_LIB_EXPERIMENTAL_FUNCTION_ERASED_ALLOCATOR 0
#endif
