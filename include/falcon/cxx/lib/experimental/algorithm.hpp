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


#if defined(__has_include) && __has_include(<experimental/algorithm>)
#  include <experimental/algorithm>

// std::sample
#  if defined(__cpp_lib_experimental_sample) && __cpp_lib_experimental_sample >= 201402
#    define FALCON_CXX_LIB_EXPERIMENTAL_SAMPLE 1
#  endif

// Extensions for parallelism
#  if defined(__cpp_lib_experimental_parallel_algorithm) && __cpp_lib_experimental_parallel_algorithm >= 201505
#    define FALCON_CXX_LIB_EXPERIMENTAL_PARALLEL_ALGORITHM 1
#  endif

#endif


#ifndef FALCON_CXX_LIB_EXPERIMENTAL_SAMPLE
#  define FALCON_CXX_LIB_EXPERIMENTAL_SAMPLE 0
#endif

#ifndef FALCON_CXX_LIB_EXPERIMENTAL_PARALLEL_ALGORITHM
#  define FALCON_CXX_LIB_EXPERIMENTAL_PARALLEL_ALGORITHM 0
#endif
