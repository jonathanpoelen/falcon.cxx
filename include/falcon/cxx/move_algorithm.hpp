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

#include <algorithm>
#include <iterator>


#if __cplusplus >= FALCON_CXX_STD_11
# define FALCON_MOVE_BACKWARD3(first, last, d_last) std::move_backward(first, last, d_last)
# define FALCON_MOVE3(first, last, d_first) std::move(first, last, d_first)
# define FALCON_MAKE_MOVE_ITERATOR(iter) std::make_move_iterator(iter)
# define FALCON_MAKE_MOVE_IF_NOEXCEPT_ITERATOR(iter) std::make_move_if_noexcept_iterator(iter)
#else
# define FALCON_MOVE_BACKWARD3(first, last, d_last) std::copy_backward(first, last, d_last)
# define FALCON_MOVE3(first, last, d_first) std::copy(first, last, d_first)
# define FALCON_MAKE_MOVE_ITERATOR(iter) (iter)
# define FALCON_MAKE_MOVE_IF_NOEXCEPT_ITERATOR(iter) (iter)
#endif
