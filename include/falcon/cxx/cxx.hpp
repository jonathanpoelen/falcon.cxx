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


#include <falcon/cxx/compiler_version.hpp>

#define FALCON_CXX_STD_03 199711L // 1998/2003
#define FALCON_CXX_STD_11 201103L
#define FALCON_CXX_STD_14 201402L

#ifdef _MSC_VER
# if _MSC_VER < 1800
#  define FALCON_CXX_CPLUSPLUS FALCON_CXX_STD_03
# elif _MSC_VER < 1900
#  define FALCON_CXX_CPLUSPLUS FALCON_CXX_STD_11
# else
#  define FALCON_CXX_CPLUSPLUS FALCON_CXX_STD_14
# endif
#else
# define FALCON_CXX_CPLUSPLUS __cplusplus
#endif

#if FALCON_CXX_CPLUSPLUS < FALCON_CXX_STD_11
# define FALCON_CXX_STD_VERSION 03
#elif FALCON_CXX_CPLUSPLUS == FALCON_CXX_STD_11
# define FALCON_CXX_STD_VERSION 11
#elif FALCON_CXX_CPLUSPLUS < FALCON_CXX_STD_14
# define FALCON_CXX_STD_VERSION 11
#elif FALCON_CXX_CPLUSPLUS == FALCON_CXX_STD_14
# define FALCON_CXX_STD_VERSION 14
#elif FALCON_CXX_CPLUSPLUS > FALCON_CXX_STD_14
# define FALCON_CXX_STD_VERSION 17
#endif

// https://gcc.gnu.org/projects/cxx-status.html
// http://en.cppreference.com/w/cpp/experimental/feature_test
// https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations


// C++98 Features
//@{

#ifndef FALCON_CXX_FEATURE_RTTI
# if (defined(__cpp_rtti) && __cpp_rtti >= 199711) || (defined(_CPPRTTI) && _CPPRTTI == 1)
#  define FALCON_CXX_FEATURE_RTTI 1
# else
#  define FALCON_CXX_FEATURE_RTTI 0
# endif
#endif

#ifndef FALCON_CXX_FEATURE_EXCEPTIONS
# if defined(__cpp_exceptions) && __cpp_exceptions >= 199711
#  define FALCON_CXX_FEATURE_EXCEPTIONS 1
# else
#  define FALCON_CXX_FEATURE_EXCEPTIONS 0
# endif
#endif

//@}


// C++11 Features
//@{

#ifndef FALCON_CXX_FEATURE_STATIC_ASSERT
# if FALCON_CXX_CPLUSPLUS < FALCON_CXX_STD_11
#  define FALCON_CXX_FEATURE_STATIC_ASSERT 0
# else
#  define FALCON_CXX_FEATURE_STATIC_ASSERT 1
# endif
#endif

//@}


// C++14 Features
//@{

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472.pdf
#ifndef FALCON_CXX_FEATURE_BINARY_LITERALS
# if defined(__cpp_binary_literals) && __cpp_binary_literals >= 201304
#  define FALCON_CXX_FEATURE_BINARY_LITERALS 1
# else
#  define FALCON_CXX_FEATURE_BINARY_LITERALS 0
# endif
#endif

// https://isocpp.org/files/papers/N3638.html
#ifndef FALCON_CXX_FEATURE_DECLTYPE_AUTO
# if defined(__cpp_decltype_auto) && __cpp_decltype_auto >= 201304
#  define FALCON_CXX_FEATURE_DECLTYPE_AUTO 1
# else
#  define FALCON_CXX_FEATURE_DECLTYPE_AUTO 0
# endif
#endif

// https://isocpp.org/files/papers/N3638.html
#ifndef FALCON_CXX_FEATURE_RETURN_TYPE_DEDUCTION
# if defined(__cpp_return_type_deduction) && __cpp_return_type_deduction >= 201304
#  define FALCON_CXX_FEATURE_RETURN_TYPE_DEDUCTION 1
# else
#  define FALCON_CXX_FEATURE_RETURN_TYPE_DEDUCTION 0
# endif
#endif

// https://isocpp.org/files/papers/N3648.html
#ifndef FALCON_CXX_FEATURE_INIT_CAPTURES
# if defined(__cpp_init_captures) && __cpp_init_captures >= 201304
#  define FALCON_CXX_FEATURE_INIT_CAPTURES 1
# else
#  define FALCON_CXX_FEATURE_INIT_CAPTURES 0
# endif
#endif

// https://isocpp.org/files/papers/N3649.html
#ifndef FALCON_CXX_FEATURE_GENERIC_LAMBDAS
# if defined(__cpp_generic_lambdas) && __cpp_generic_lambdas >= 201304
#  define FALCON_CXX_FEATURE_GENERIC_LAMBDAS 1
# else
#  define FALCON_CXX_FEATURE_GENERIC_LAMBDAS 0
# endif
#endif

// https://isocpp.org/files/papers/N3651.pdf
#ifndef FALCON_CXX_FEATURE_VARIABLE_TEMPLATES
# if defined(__cpp_variable_templates) && __cpp_variable_templates >= 201304
#  define FALCON_CXX_FEATURE_VARIABLE_TEMPLATES 1
# else
#  define FALCON_CXX_FEATURE_VARIABLE_TEMPLATES 0
# endif
#endif

// https://isocpp.org/files/papers/N3652.html
#ifndef FALCON_CXX_FEATURE_RELAXED_CONSTEXPR
# if defined(__cpp_constexpr) && __cpp_constexpr >= 201304
#  define FALCON_CXX_FEATURE_RELAXED_CONSTEXPR 1
# else
#  define FALCON_CXX_FEATURE_RELAXED_CONSTEXPR 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3653.html
#ifndef FALCON_CXX_FEATURE_AGGREGATE_INITIALIZATION
# if defined(__cpp_aggregate_nsdmi) && __cpp_aggregate_nsdmi >= 201304
#  define FALCON_CXX_FEATURE_AGGREGATE_INITIALIZATION 1
# else
#  define FALCON_CXX_FEATURE_AGGREGATE_INITIALIZATION 0
# endif
#endif

// https://isocpp.org/files/papers/n3778.html
#ifndef FALCON_CXX_FEATURE_SIZED_DEALLOCATION
# if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309
#  define FALCON_CXX_FEATURE_SIZED_DEALLOCATION 1
# else
#  define FALCON_CXX_FEATURE_SIZED_DEALLOCATION 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf
#ifndef FALCON_CXX_FEATURE_DIGIT_SEPARATOR
# if defined(__cpp_digit_separator) && __cpp_digit_separator >= 201309
#  define FALCON_CXX_FEATURE_DIGIT_SEPARATOR 1
# else
#  define FALCON_CXX_FEATURE_DIGIT_SEPARATOR 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3639.html
// (Removed from the standard)
#ifndef FALCON_CXX_FEATURE_RUNTIME_ARRAYS
# if defined(__cpp_runtime_arrays) && __cpp_runtime_arrays >= 198712
#  define FALCON_CXX_FEATURE_RUNTIME_ARRAYS 1
# else
#  define FALCON_CXX_FEATURE_RUNTIME_ARRAYS 0
# endif
#endif

//@}


// C++17 Features
//@{

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html
#ifndef FALCON_CXX_FEATURE_UNICODE_CHARACTERS
# if defined(__cpp_unicode_characters) && __cpp_unicode_characters >= 201411
#  define FALCON_CXX_FEATURE_UNICODE_CHARACTERS 1
# else
#  define FALCON_CXX_FEATURE_UNICODE_CHARACTERS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html
#ifndef FALCON_CXX_FEATURE_FOLD_EXPRESSIONS
# if defined(__cpp_fold_expressions) && __cpp_fold_expressions >= 201411
#  define FALCON_CXX_FEATURE_FOLD_EXPRESSIONS 1
# else
#  define FALCON_CXX_FEATURE_FOLD_EXPRESSIONS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html
#ifndef FALCON_CXX_FEATURE_NAMESPACE_ATTRIBUTES
# if defined(__cpp_namespace_attributes) && __cpp_namespace_attributes >= 201411
#  define FALCON_CXX_FEATURE_NAMESPACE_ATTRIBUTES 1
# else
#  define FALCON_CXX_FEATURE_NAMESPACE_ATTRIBUTES 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html
#ifndef FALCON_CXX_FEATURE_ENUMERATOR_ATTRIBUTES
# if defined(__cpp_enumerator_attributes) && __cpp_enumerator_attributes >= 201411
#  define FALCON_CXX_FEATURE_ENUMERATOR_ATTRIBUTES 1
# else
#  define FALCON_CXX_FEATURE_ENUMERATOR_ATTRIBUTES 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230.html
#ifndef FALCON_CXX_FEATURE_NESTED_NAMESPACE_DEFINITIONS
# if defined(__cpp_nested_namespace_definitions) && __cpp_nested_namespace_definitions >= 201411
#  define FALCON_CXX_FEATURE_NESTED_NAMESPACE_DEFINITIONS 1
# else
#  define FALCON_CXX_FEATURE_NESTED_NAMESPACE_DEFINITIONS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268.html
#ifndef FALCON_CXX_FEATURE_NONTYPE_TEMPLATE_ARGS
# if defined(__cpp_nontype_template_args) && __cpp_nontype_template_args >= 201411
#  define FALCON_CXX_FEATURE_NONTYPE_TEMPLATE_ARGS 1
# else
#  define FALCON_CXX_FEATURE_NONTYPE_TEMPLATE_ARGS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.html
#ifndef FALCON_CXX_FEATURE_STATIC_ASSERT_MSG
# if defined(__cpp_static_assert) && __cpp_static_assert >= 201411
#  define FALCON_CXX_FEATURE_STATIC_ASSERT_MSG 1
# else
#  define FALCON_CXX_FEATURE_STATIC_ASSERT_MSG 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html
#ifndef FALCON_CXX_FEATURE_AGGREGATE_BASES
# if defined(__cpp_aggregate_bases) && __cpp_aggregate_bases >= 201603
#  define FALCON_CXX_FEATURE_AGGREGATE_BASES 1
# else
#  define FALCON_CXX_FEATURE_AGGREGATE_BASES 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1.pdf
#ifndef FALCON_CXX_FEATURE_CONSTEXPR_LAMBDA
# if defined(__cpp_constexpr) && __cpp_constexpr >= 201603
#  define FALCON_CXX_FEATURE_CONSTEXPR_LAMBDA 1
# else
#  define FALCON_CXX_FEATURE_CONSTEXPR_LAMBDA 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0.pdf
#ifndef FALCON_CXX_FEATURE_UNARY_FOLD_EXPRESSIONS
# if defined(__cpp_fold_expressions) && __cpp_fold_expressions >= 201603
#  define FALCON_CXX_FEATURE_UNARY_FOLD_EXPRESSIONS 1
# else
#  define FALCON_CXX_FEATURE_UNARY_FOLD_EXPRESSIONS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html
#ifndef FALCON_CXX_FEATURE_RANGE_BASED_FOR
# if defined(__cpp_range_based_for) && __cpp_range_based_for >= 201603
#  define FALCON_CXX_FEATURE_RANGE_BASED_FOR 1
# else
#  define FALCON_CXX_FEATURE_RANGE_BASED_FOR 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html
#ifndef FALCON_CXX_FEATURE_CAPTURE_STAR_THIS
# if defined(__cpp_capture_star_this) && __cpp_capture_star_this >= 201603
#  define FALCON_CXX_FEATURE_CAPTURE_STAR_THIS 1
# else
#  define FALCON_CXX_FEATURE_CAPTURE_STAR_THIS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1.html
#ifndef FALCON_CXX_FEATURE_HEX_FLOAT
# if defined(__cpp_hex_float) && __cpp_hex_float >= 201603
#  define FALCON_CXX_FEATURE_HEX_FLOAT 1
# else
#  define FALCON_CXX_FEATURE_HEX_FLOAT 0
# endif
#endif

// http://wg21.link/p0035
#ifndef FALCON_CXX_FEATURE_ALIGNED_NEW
# if defined(__cpp_aligned_new) && __cpp_aligned_new >= 201606
#  define FALCON_CXX_FEATURE_ALIGNED_NEW 1
# else
#  define FALCON_CXX_FEATURE_ALIGNED_NEW 0
# endif
#endif

// http://wg21.link/p0292
#ifndef FALCON_CXX_FEATURE_IF_CONSTEXPR
# if defined(__cpp_if_constexpr) && __cpp_if_constexpr >= 201606
#  define FALCON_CXX_FEATURE_IF_CONSTEXPR 1
# else
#  define FALCON_CXX_FEATURE_IF_CONSTEXPR 0
# endif
#endif

// http://wg21.link/p0091
#ifndef FALCON_CXX_FEATURE_DEDUCTION_GUIDES
# if defined(__cpp_deduction_guides) && __cpp_deduction_guides >= 201606
#  define FALCON_CXX_FEATURE_DEDUCTION_GUIDES 1
# else
#  define FALCON_CXX_FEATURE_DEDUCTION_GUIDES 0
# endif
#endif

// http://wg21.link/p0127
#ifndef FALCON_CXX_FEATURE_TEMPLATE_AUTO
# if defined(__cpp_template_auto) && __cpp_template_auto >= 201606
#  define FALCON_CXX_FEATURE_TEMPLATE_AUTO 1
# else
#  define FALCON_CXX_FEATURE_TEMPLATE_AUTO 0
# endif
#endif

// http://wg21.link/p0217
#ifndef FALCON_CXX_FEATURE_STRUCTURED_BINDINGS
# if defined(__cpp_structured_bindings) && __cpp_structured_bindings >= 201606
#  define FALCON_CXX_FEATURE_STRUCTURED_BINDINGS 1
# else
#  define FALCON_CXX_FEATURE_STRUCTURED_BINDINGS 0
# endif
#endif

// http://wg21.link/p0012
#ifndef FALCON_CXX_FEATURE_NOEXCEPT_FUNCTION_TYPE
# if defined(__cpp_noexcept_function_type) && __cpp_noexcept_function_type >= 201510
#  define FALCON_CXX_FEATURE_NOEXCEPT_FUNCTION_TYPE 1
# else
#  define FALCON_CXX_FEATURE_NOEXCEPT_FUNCTION_TYPE 0
# endif
#endif

// http://wg21.link/p0136
#ifndef FALCON_CXX_FEATURE_INHERITING_CONSTRUCTORS
# if defined(__cpp_inheriting_constructors) && __cpp_inheriting_constructors >= 201511
#  define FALCON_CXX_FEATURE_INHERITING_CONSTRUCTORS 1
# else
#  define FALCON_CXX_FEATURE_INHERITING_CONSTRUCTORS 0
# endif
#endif

// http://wg21.link/p0386r2
#ifndef FALCON_CXX_FEATURE_INLINE_VARIABLES
# if defined(__cpp_inline_variables) && __cpp_inline_variables >= 201606
#  define FALCON_CXX_FEATURE_INLINE_VARIABLES 1
# else
#  define FALCON_CXX_FEATURE_INLINE_VARIABLES 0
# endif
#endif


// TS

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4377.pdf
// -fconcepts
#ifndef FALCON_CXX_FEATURE_CONCEPTS
# if defined(__cpp_concepts) && __cpp_concepts >= 201507
#  define FALCON_CXX_FEATURE_CONCEPTS 1
# else
#  define FALCON_CXX_FEATURE_CONCEPTS 0
# endif
#endif

// http://www.open-std.org/Jtc1/sc22/wg21/docs/papers/2015/n4514.pdf
// -fgnu-tm
#ifndef FALCON_CXX_FEATURE_TRANSACTIONAL_MEMORY
# if defined(__cpp_transactional_memory) && __cpp_transactional_memory >= 201505
#  define FALCON_CXX_FEATURE_TRANSACTIONAL_MEMORY 1
# else
#  define FALCON_CXX_FEATURE_TRANSACTIONAL_MEMORY 0
# endif
#endif

//@}


// Standard Attributes (http://en.cppreference.com/w/cpp/language/attributes)
//@{

#ifdef __has_cpp_attribute
# define FALCON_HAS_CPP_ATTRIBUTE(attr) __has_cpp_attribute(attr)
#else
# define FALCON_HAS_CPP_ATTRIBUTE(attr) 0
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3760.html
#ifndef FALCON_HAS_CPP_ATTRIBUTE_DEPRECATED
# if FALCON_HAS_CPP_ATTRIBUTE(deprecated) >= 201309 \
   || defined(__cpp_attribute_deprecated)
#  define FALCON_HAS_CPP_ATTRIBUTE_DEPRECATED 1
# else
#  define FALCON_HAS_CPP_ATTRIBUTE_DEPRECATED 0
# endif
#endif

#ifndef FALCON_ATTRIBUTE_DEPRECATED
# if defined(FALCON_DISABLE_DEPRECATED_WARNINGS)
#  if FALCON_HAS_CPP_ATTRIBUTE_DEPRECATED
#   define FALCON_ATTRIBUTE_DEPRECATED [[deprecated]]
#   define FALCON_ATTRIBUTE_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#  elif defined(__GNUC__) || defined(__clang__)
#   define FALCON_ATTRIBUTE_DEPRECATED __attribute__((deprecated("deprecated")))
#   define FALCON_ATTRIBUTE_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#  elif defined(_MSC_VER)
#   define FALCON_ATTRIBUTE_DEPRECATED __declspec(deprecated("deprecated"))
#   define FALCON_ATTRIBUTE_DEPRECATED_MSG(msg) __declspec(deprecated(msg))
#  else
#   define FALCON_ATTRIBUTE_DEPRECATED
#   define FALCON_ATTRIBUTE_DEPRECATED_MSG(msg)
#  endif
# else
#  define FALCON_ATTRIBUTE_DEPRECATED
#  define FALCON_ATTRIBUTE_DEPRECATED_MSG(msg)
# endif
#endif

#define FALCON_DEPRECATED          FALCON_ATTRIBUTE_DEPRECATED
#define FALCON_DEPRECATED_MSG(msg) FALCON_ATTRIBUTE_DEPRECATED_MSG(msg)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r1.pdf
#ifndef FALCON_HAS_CPP_ATTRIBUTE_FALLTHROUGH
# if FALCON_HAS_CPP_ATTRIBUTE(fallthrough)
#  define FALCON_HAS_CPP_ATTRIBUTE_FALLTHROUGH 1
# else
#  define FALCON_HAS_CPP_ATTRIBUTE_FALLTHROUGH 0
# endif
#endif

#ifndef FALCON_ATTRIBUTE_FALLTHROUGH
# if FALCON_HAS_CPP_ATTRIBUTE_FALLTHROUGH
#  define FALCON_ATTRIBUTE_FALLTHROUGH [[fallthrough]]
# elif defined(__clang__)
#  define FALCON_ATTRIBUTE_FALLTHROUGH [[clang::fallthrough]]
# else
#  define FALCON_ATTRIBUTE_FALLTHROUGH void(0)
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0189r1.pdf
#ifndef FALCON_HAS_CPP_ATTRIBUTE_NODISCARD
# if FALCON_HAS_CPP_ATTRIBUTE(nodiscard)
#  define FALCON_HAS_CPP_ATTRIBUTE_NODISCARD 1
# else
#  define FALCON_HAS_CPP_ATTRIBUTE_NODISCARD 0
# endif
#endif

#ifndef FALCON_ATTRIBUTE_NODISCARD
# if FALCON_HAS_CPP_ATTRIBUTE_NODISCARD
#  define FALCON_ATTRIBUTE_NODISCARD [[nodiscard]]
# elif defined(__GNUC__) || defined(__clang__)
#  define FALCON_ATTRIBUTE_NODISCARD __attribute__((warn_unused_result))
# elif defined(_MSC_VER)
#  define FALCON_ATTRIBUTE_NODISCARD _Check_return_
# else
#  define FALCON_ATTRIBUTE_NODISCARD
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0212r1.pdf
#ifndef FALCON_HAS_CPP_ATTRIBUTE_MAYBE_UNUSED
# if FALCON_HAS_CPP_ATTRIBUTE(maybe_unused)
#  define FALCON_HAS_CPP_ATTRIBUTE_MAYBE_UNUSED 1
# else
#  define FALCON_HAS_CPP_ATTRIBUTE_MAYBE_UNUSED 0
# endif
#endif

#ifndef FALCON_ATTRIBUTE_MAYBE_UNUSED
# if FALCON_HAS_CPP_ATTRIBUTE_MAYBE_UNUSED
#  define FALCON_ATTRIBUTE_MAYBE_UNUSED [[maybe_unused]]
# elif defined(__GNUC__) || defined(__clang__)
#  define FALCON_ATTRIBUTE_MAYBE_UNUSED __attribute__((unused))
# else
#  define FALCON_ATTRIBUTE_MAYBE_UNUSED
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761.pdf
#ifndef FALCON_HAS_CPP_ATTRIBUTE_NORETURN
# if FALCON_HAS_CPP_ATTRIBUTE(noreturn) >= 200809
#  define FALCON_HAS_CPP_ATTRIBUTE_NORETURN 1
# else
#  define FALCON_HAS_CPP_ATTRIBUTE_NORETURN 0
# endif
#endif

#ifndef FALCON_ATTRIBUTE_NORETURN
# if FALCON_HAS_CPP_ATTRIBUTE_NORETURN
#  define FALCON_ATTRIBUTE_NORETURN [[noreturn]]
# elif defined(__GNUC__) || defined(__clang__)
#  define FALCON_ATTRIBUTE_NORETURN __attribute__((noreturn))
# elif defined(_MSC_VER)
#  define FALCON_ATTRIBUTE_NORETURN __declspec(noreturn)
# else
#  define FALCON_ATTRIBUTE_NORETURN
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761.pdf
#ifndef FALCON_HAS_CPP_ATTRIBUTE_CARRIES_DEPENDENCY
# if FALCON_HAS_CPP_ATTRIBUTE(carries_dependency) >= 200809
#  define FALCON_HAS_CPP_ATTRIBUTE_CARRIES_DEPENDENCY 1
# else
#  define FALCON_HAS_CPP_ATTRIBUTE_CARRIES_DEPENDENCY 0
# endif
#endif

#ifndef FALCON_ATTRIBUTE_CARRIES_DEPENDENCY
# if FALCON_HAS_CPP_ATTRIBUTE_CARRIES_DEPENDENCY
#  define FALCON_ATTRIBUTE_CARRIES_DEPENDENCY [[carries_dependency]]
# else
#  define FALCON_ATTRIBUTE_CARRIES_DEPENDENCY
# endif
#endif

//@}


#ifdef __has_builtin
# define FALCON_HAS_BUILTIN(builtin) __has_builtin(builtin)
#else
# define FALCON_HAS_BUILTIN(builtin) 0
#endif

#ifdef __has_feature
# define FALCON_HAS_FEATURE(feature) __has_feature(feature)
#elif defined __has_extension
# define FALCON_HAS_FEATURE(feature) __has_extension(feature)
#else
# define FALCON_HAS_FEATURE(feature) 0
#endif

#ifdef __has_attribute
# define FALCON_HAS_ATTRIBUTE(attr) __has_attribute(attr)
#else
# define FALCON_HAS_ATTRIBUTE(attr) 0
#endif

#ifdef __has_declspec_attribute
# define FALCON_HAS_DECLSPEC_ATTRIBUTE(attr) __has_declspec_attribute(attr)
#else
# define FALCON_HAS_DECLSPEC_ATTRIBUTE(attr) 0
#endif

#ifdef __has_include
# define FALCON_HAS_INCLUDE(filename) __has_include(filename)
#else
# define FALCON_HAS_INCLUDE(filename) 0
#endif

#ifdef __has_include_next
# define FALCON_HAS_INCLUDE_NEXT(filename) __has_include_next(filename)
#else
# define FALCON_HAS_INCLUDE_NEXT(filename) 0
#endif


// Diagnostic
//@{

# define FALCON_PRAGMA(X) _Pragma(#X)

#ifdef _MSC_VER

# define FALCON_DIAGNOSTIC_PUSH __pragma(warning(push))
# define FALCON_DIAGNOSTIC_POP __pragma(warning(pop))

# define FALCON_DIAGNOSTIC_MSVC_IGNORE(X) __pragma(warning(disable:X))
# define FALCON_DIAGNOSTIC_GCC_ONLY_IGNORE(X)
# define FALCON_DIAGNOSTIC_GCC_IGNORE(X)
# define FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
# define FALCON_DIAGNOSTIC_MSVC_WARNING(X) __pragma(warning(4:X))
# define FALCON_DIAGNOSTIC_GCC_ONLY_WARNING(X)
# define FALCON_DIAGNOSTIC_GCC_WARNING(X)
# define FALCON_DIAGNOSTIC_CLANG_WARNING(X)

# define FALCON_DIAGNOSTIC_WARNING_MSG(MSG) \
  __pragma(warning())                       \
  __pragma(message("warning:" MSG))

#elif defined(__GNUC__) || defined(__clang__)

# define FALCON_DIAGNOSTIC_PUSH FALCON_PRAGMA(GCC diagnostic push)
# define FALCON_DIAGNOSTIC_POP FALCON_PRAGMA(GCC diagnostic pop)

# define FALCON_DIAGNOSTIC_MSVC_IGNORE(X)
# define FALCON_DIAGNOSTIC_GCC_IGNORE(X) FALCON_PRAGMA(GCC diagnostic ignored X)
# define FALCON_DIAGNOSTIC_MSVC_WARNING(X)
# define FALCON_DIAGNOSTIC_GCC_WARNING(X) FALCON_PRAGMA(GCC diagnostic warning X)
# ifdef __clang__
#  define FALCON_DIAGNOSTIC_GCC_ONLY_IGNORE(X)
#  define FALCON_DIAGNOSTIC_CLANG_IGNORE FALCON_DIAGNOSTIC_GCC_IGNORE
#  define FALCON_DIAGNOSTIC_GCC_ONLY_WARNING(X)
#  define FALCON_DIAGNOSTIC_CLANG_WARNING FALCON_DIAGNOSTIC_GCC_WARNING
# else
#  define FALCON_DIAGNOSTIC_GCC_ONLY_IGNORE FALCON_DIAGNOSTIC_GCC_IGNORE
#  define FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
#  define FALCON_DIAGNOSTIC_GCC_ONLY_WARNING FALCON_DIAGNOSTIC_GCC_WARNING
#  define FALCON_DIAGNOSTIC_CLANG_WARNING(X)
# endif

# define FALCON_DIAGNOSTIC_WARNING_MSG(MSG) FALCON_PRAGMA(GCC warning MSG)

#else
# define FALCON_DIAGNOSTIC_PUSH
# define FALCON_DIAGNOSTIC_POP
# define FALCON_DIAGNOSTIC_MSVC_IGNORE(X)
# define FALCON_DIAGNOSTIC_GCC_IGNORE(X)
# define FALCON_DIAGNOSTIC_GCC_ONLY_IGNORE(X)
# define FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
# define FALCON_DIAGNOSTIC_MSVC_WARNING(X)
# define FALCON_DIAGNOSTIC_GCC_WARNING(X)
# define FALCON_DIAGNOSTIC_GCC_ONLY_WARNING(X)
# define FALCON_DIAGNOSTIC_CLANG_WARNING(X)
# define FALCON_DIAGNOSTIC_WARNING_MSG(MSG) FALCON_PRAGMA(warning MSG)
#endif

//@}


// Keywords and Syntax
//@{

#ifndef NDEBUG
# define FALCON_UNREACHABLE() assert(!"Unreachable code reached.")
# define FALCON_UNREACHABLE_IF(condition) \
  assert((condition) && "Unreachable code reached.")
#else
# define FALCON_UNREACHABLE_IF(condition) \
  do { if (condition) FALCON_UNREACHABLE(); } while (0)
#endif

#if defined(__GNUC__) || defined(__clang__)
// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
# define FALCON_LIKELY(condition) __builtin_expect(bool(condition), 1)
# define FALCON_UNLIKELY(condition) __builtin_expect(bool(condition), 0)
# if !defined(FALCON_UNREACHABLE) \
  && ( FALCON_COMP_GNUC >= FALCON_VERSION_NUMBER(4, 5, 0) \
    || defined(__clang__))
#  define FALCON_UNREACHABLE() __builtin_unreachable()
# endif
# define FALCON_ALWAYS_INLINE __attribute__((always_inline))
#else
# define FALCON_LIKELY(condition) (condition)
# define FALCON_UNLIKELY(condition) (condition)
# ifdef _MSC_VER && _MSC_VER >= 1900
#  if !defined FALCON_UNREACHABLE && _MSC_VER >= 1900
#   define FALCON_UNREACHABLE() __assume(0)
#  endif
#  define FALCON_ALWAYS_INLINE __forceinline
# else
#  define FALCON_ALWAYS_INLINE
# endif
#endif

#ifndef FALCON_UNREACHABLE
# define FALCON_UNREACHABLE() do { } while (0)
#endif


// C++14 constexpr functions are inline in C++11

#if FALCON_CXX_CPLUSPLUS < FALCON_CXX_STD_14 \
 || (defined _MSC_VER && _MSC_VER <= 1900)
# define FALCON_CXX14_CONSTEXPR inline
# define FALCON_CONSTEXPR_AFTER_CXX11
#else
# define FALCON_CXX14_CONSTEXPR constexpr
# define FALCON_CONSTEXPR_AFTER_CXX11 constexpr
#endif

#if FALCON_CXX_CPLUSPLUS > FALCON_CXX_STD_14
# define FALCON_CONSTEXPR_AFTER_CXX14 constexpr
#else
# define FALCON_CONSTEXPR_AFTER_CXX14
#endif

FALCON_DIAGNOSTIC_PUSH
FALCON_DIAGNOSTIC_CLANG_IGNORE("-Wc++98-compat-pedantic")

#if FALCON_CXX_CPLUSPLUS >= FALCON_CXX_STD_11
# define FALCON_CONSTEXPR constexpr
# define FALCON_NOEXCEPT noexcept
# define FALCON_NOEXCEPT_EXPR(expr) noexcept(expr)
# ifndef IN_IDE_PARSER
#  define FALCON_PACK ...
#  define FALCON_NOEXCEPT_EXPR2(...) noexcept(noexcept(__VA_ARGS__))
namespace falcon { using swallow = int[]; }
#  define FALCON_UNPACK(...) (void)falcon::swallow{((void)(__VA_ARGS__), 0)...}
# else
#  define FALCON_PACK
#  define FALCON_NOEXCEPT_EXPR2(expr) noexcept(noexcept(expr))
#  define FALCON_UNPACK
# endif
#else
# define FALCON_PACK
# define FALCON_CONSTEXPR
# define FALCON_NOEXCEPT
# define FALCON_NOEXCEPT_EXPR(expr)
# define FALCON_NOEXCEPT_EXPR2(...)
# define FALCON_UNPACK(...) (void)(__VA_ARGS__)
#endif

#if FALCON_CXX_FEATURE_STATIC_ASSERT_MSG
# define FALCON_STATIC_ASSERT(expr) static_assert(expr)
#else
# define FALCON_STATIC_ASSERT(expr) static_assert(expr, #expr)
#endif

#define FALCON_RESTRICT __restrict__

#ifndef FALCON_PP_NIL
# define FALCON_PP_NIL
#endif

#ifdef IN_IDE_PARSER
# define FALCON_DECLTYPE_AUTO_RETURN(expr) \
  -> decltype(expr)                        \
  { return (expr); }

# define FALCON_DECLTYPE_AUTO_RETURN_NOEXCEPT(expr) \
  noexcept(noexcept(decltype(expr)(expr))) ->       \
  decltype(expr)                                    \
  { return (expr); }

# define FALCON_DECLTYPE_NOEXCEPT(expr)       \
  noexcept(noexcept(decltype(expr)(expr))) -> \
  decltype(expr)

# define FALCON_RETURN_NOEXCEPT(expr)      \
  noexcept(noexcept(decltype(expr)(expr))) \
  { return expr; }

# define FALCON_RETURN_VOID_NOEXCEPT(expr) \
  noexcept(noexcept(expr))                 \
  { expr; }

# define FALCON_IN_IDE_PARSER_CONDITIONAL(in_ide_expr, not_ide_expr) in_ide_expr
#else
# define FALCON_DECLTYPE_AUTO_RETURN(...) \
  -> decltype(__VA_ARGS__)                \
  { return __VA_ARGS__; }

# define FALCON_DECLTYPE_AUTO_RETURN_NOEXCEPT(...)          \
  noexcept(noexcept(decltype(__VA_ARGS__)(__VA_ARGS__))) -> \
  decltype(__VA_ARGS__)                                     \
  { return __VA_ARGS__; }

# define FALCON_DECLTYPE_NOEXCEPT(...)                      \
  noexcept(noexcept(decltype(__VA_ARGS__)(__VA_ARGS__))) -> \
  decltype(__VA_ARGS__)

# define FALCON_RETURN_NOEXCEPT(...)                     \
  noexcept(noexcept(decltype(__VA_ARGS__)(__VA_ARGS__))) \
  { return __VA_ARGS__; }

# define FALCON_RETURN_VOID_NOEXCEPT(...) \
  noexcept(noexcept(__VA_ARGS__))         \
  { __VA_ARGS__; }

FALCON_DIAGNOSTIC_POP

# define FALCON_IN_IDE_PARSER_CONDITIONAL(in_ide_expr, not_ide_expr) not_ide_expr
#endif


#define FALCON_CXX11_DEFAULT_MOVE(class_name) \
  class_name(class_name &&) = default;        \
  class_name& operator=(class_name &&) = default

#define FALCON_CXX11_DEFAULT_COPY_MOVE(class_name)     \
  class_name(class_name const &) = default;            \
  class_name(class_name &&) = default;                 \
  class_name& operator=(class_name const &) = default; \
  class_name& operator=(class_name &&) = default

#define FALCON_CXX11_DEFAULT_SPECIAL_MEMBER(class_name) \
  class_name() = default;                               \
  class_name(class_name const &) = default;             \
  class_name(class_name &&) = default;                  \
  class_name& operator=(class_name const &) = default;  \
  class_name& operator=(class_name &&) = default


// Inline variable
#if FALCON_CXX_FEATURE_INLINE_VARIABLES
# define FALCON_INLINE_VARIABLE(type, name) \
  inline constexpr type name{}
# define FALCON_SCOPED_INLINE_VARIABLE(type, name) \
  inline namespace {                               \
    inline constexpr type name{};                  \
  }
#else
# if FALCON_CXX_CPLUSPLUS >= FALCON_CXX_STD_11
namespace falcon { namespace detail {
  template<class T> struct static_const { static constexpr T value{}; };
  template<class T> constexpr T static_const<T>::value;
} }
# else
namespace falcon { namespace detail {
  template<class T> struct static_const { static T value{}; };
  template<class T> T static_const<T>::value;
} }
# endif
# define FALCON_INLINE_VARIABLE(type, name)                            \
  constexpr auto & name = ::falcon::detail::static_const<type>::value
# define FALCON_SCOPED_INLINE_VARIABLE(type, name) \
  inline namespace {                               \
    constexpr auto & name = ::falcon::detail::static_const<type>::value; \
  }
#endif


#define FALCON_EMPTY_CLASS(name) \
  struct name { FALCON_CONSTEXPR name() FALCON_NOEXCEPT {} }

//@}
