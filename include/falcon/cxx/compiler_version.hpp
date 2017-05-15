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
* \author    Jonathan Poelen <jonathan.poelen@gmail.com>
* \version   0.1
* \brief     Compiler version (see boost/predef/compiler)
*/

#pragma once

#if defined FALCON_USE_BOOST_PREDEF

#include <boost/predef/compiler.h>

#define FALCON_VERSION_NUMBER(major, minor, patch) \
  BOOST_VERSION_NUMBER(major, minor, patch)
#define FALCON_COMP_CLANG BOOST_COMP_CLANG
#define FALCON_COMP_GNUC BOOST_COMP_GNUC
#define FALCON_COMP_MSVC BOOST_COMP_MSVC

#else

#define FALCON_VERSION_NUMBER(major, minor, patch) \
  ( (((major)%100)*10000000) + (((minor)%100)*100000) + ((patch)%100000) )


// Clang

#ifdef __clang__
# define FALCON_COMP_CLANG FALCON_VERSION_NUMBER( \
    __clang_major__,                              \
    __clang_minor__,                              \
    __clang_patchlevel__)
#else
# define FALCON_COMP_CLANG FALCON_VERSION_NUMBER_NOT_AVAILABLE
#endif


// Gcc

#ifdef __GNUC__
# ifdef __GNUC_PATCHLEVEL__
#   define FALCON_COMP_GNUC FALCON_VERSION_NUMBER( \
      __GNUC__,                                    \
      __GNUC_MINOR__,                              \
      __GNUC_PATCHLEVEL__)
# else
#   define FALCON_COMP_GNUC FALCON_VERSION_NUMBER( \
      __GNUC__,                                    \
      __GNUC_MINOR__,                              \
      0)
# endif
#else
# define FALCON_COMP_GNUC FALCON_VERSION_NUMBER_NOT_AVAILABLE
#endif


// MSVC

#if defined(_MSC_VER)
# if !defined (_MSC_FULL_VER)
#   define FALCON_COMP_MSVC_BUILD 0
# else
    /* how many digits does the build number have? */
#   if _MSC_FULL_VER / 10000 == _MSC_VER
      /* four digits */
#     define FALCON_COMP_MSVC_BUILD (_MSC_FULL_VER % 10000)
#   elif _MSC_FULL_VER / 100000 == _MSC_VER
      /* five digits */
#     define FALCON_COMP_MSVC_BUILD (_MSC_FULL_VER % 100000)
#   else
#     error "Cannot determine build number from _MSC_FULL_VER"
#   endif
# endif
  /*
  VS2014 was skipped in the release sequence for MS. Which
  means that the compiler and VS product versions are no longer
  in sync. Hence we need to use different formulas for
  mapping from MSC version to VS product version.
  */
# if (_MSC_VER >= 1900)
#   define FALCON_COMP_MSVC FALCON_VERSION_NUMBER( \
      _MSC_VER/100-5,                                      \
      _MSC_VER%100,                                        \
      FALCON_COMP_MSVC_BUILD)
# else
#   define FALCON_COMP_MSVC FALCON_VERSION_NUMBER( \
      _MSC_VER/100-6,                                      \
      _MSC_VER%100,                                        \
      FALCON_COMP_MSVC_BUILD)
# endif
#else
# define FALCON_COMP_MSVC FALCON_VERSION_NUMBER_NOT_AVAILABLE
#endif

#endif // FALCON_USE_BOOST_PREDEF
