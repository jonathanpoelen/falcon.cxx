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


#if __cplusplus >= FALCON_CXX_STD_11
# include <utility>
# define FALCON_CXX11_RVALUE &&
# define FALCON_CXX03_CONST_REF
# define FALCON_RVALUE_OR_CONST_REF &&
# define FALCON_MOVE(x) std::move(x)
# define FALCON_FORWARD(T, x) std::forward<T>(x)
# define FALCON_MOVE_IF_NOEXCEPT(x) std::move_if_noexcept(x)
#else
# define FALCON_CXX11_RVALUE
# define FALCON_CXX03_CONST_REF const &
# define FALCON_RVALUE_OR_CONST_REF const &
# define FALCON_MOVE(x) (x)
# define FALCON_FORWARD(T, x) (x)
# define FALCON_MOVE_IF_NOEXCEPT(x) (x)
#endif
