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


#define FALCON_CXX_STD_11 201103
#define FALCON_CXX_STD_14 201402

// https://gcc.gnu.org/projects/cxx-status.html
// http://en.cppreference.com/w/cpp/experimental/feature_test
// https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations


// C++98 Features
//@{

#ifndef FALCON_CXX_RTTI
# if defined(__cpp_rtti) && __cpp_rtti >= 199711
#  define FALCON_CXX_RTTI 1
# else
#  define FALCON_CXX_RTTI 0
# endif
#endif

#ifndef FALCON_CXX_EXCEPTIONS
# if defined(__cpp_exceptions) && __cpp_exceptions >= 199711
#  define FALCON_CXX_EXCEPTIONS 1
# else
#  define FALCON_CXX_EXCEPTIONS 0
# endif
#endif

//@}


// C++11 Features
//@{

#ifndef FALCON_CXX_STATIC_ASSERT
# if __cplusplus < FALCON_CXX_STD_11
#  define FALCON_CXX_STATIC_ASSERT 0
# else
#  define FALCON_CXX_STATIC_ASSERT 1
# endif
#endif

//@}


// C++14 Features
//@{

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472.pdf
#ifndef FALCON_CXX_BINARY_LITERALS
# if defined(__cpp_binary_literals) && __cpp_binary_literals >= 201304
#  define FALCON_CXX_BINARY_LITERALS 1
# else
#  define FALCON_CXX_BINARY_LITERALS 0
# endif
#endif

// https://isocpp.org/files/papers/N3638.html
#ifndef FALCON_CXX_DECLTYPE_AUTO
# if defined(__cpp_decltype_auto) && __cpp_decltype_auto >= 201304
#  define FALCON_CXX_DECLTYPE_AUTO 1
# else
#  define FALCON_CXX_DECLTYPE_AUTO 0
# endif
#endif

// https://isocpp.org/files/papers/N3638.html
#ifndef FALCON_CXX_RETURN_TYPE_DEDUCTION
# if defined(__cpp_return_type_deduction) && __cpp_return_type_deduction >= 201304
#  define FALCON_CXX_RETURN_TYPE_DEDUCTION 1
# else
#  define FALCON_CXX_RETURN_TYPE_DEDUCTION 0
# endif
#endif

// https://isocpp.org/files/papers/N3648.html
#ifndef FALCON_CXX_INIT_CAPTURES
# if defined(__cpp_init_captures) && __cpp_init_captures >= 201304
#  define FALCON_CXX_INIT_CAPTURES 1
# else
#  define FALCON_CXX_INIT_CAPTURES 0
# endif
#endif

// https://isocpp.org/files/papers/N3649.html
#ifndef FALCON_CXX_GENERIC_LAMBDAS
# if defined(__cpp_generic_lambdas) && __cpp_generic_lambdas >= 201304
#  define FALCON_CXX_GENERIC_LAMBDAS 1
# else
#  define FALCON_CXX_GENERIC_LAMBDAS 0
# endif
#endif

// https://isocpp.org/files/papers/N3651.pdf
#ifndef FALCON_CXX_VARIABLE_TEMPLATES
# if defined(__cpp_variable_templates) && __cpp_variable_templates >= 201304
#  define FALCON_CXX_VARIABLE_TEMPLATES 1
# else
#  define FALCON_CXX_VARIABLE_TEMPLATES 0
# endif
#endif

// https://isocpp.org/files/papers/N3652.html
#ifndef FALCON_CXX_RELAXED_CONSTEXPR
# if defined(__cpp_constexpr) && __cpp_constexpr >= 201304
#  define FALCON_CXX_RELAXED_CONSTEXPR 1
# else
#  define FALCON_CXX_RELAXED_CONSTEXPR 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3653.html
#ifndef FALCON_CXX_AGGREGATE_INITIALIZATION
# if defined(__cpp_aggregate_nsdmi) && __cpp_aggregate_nsdmi >= 201304
#  define FALCON_CXX_AGGREGATE_INITIALIZATION 1
# else
#  define FALCON_CXX_AGGREGATE_INITIALIZATION 0
# endif
#endif

// https://isocpp.org/files/papers/n3778.html
#ifndef FALCON_CXX_SIZED_DEALLOCATION
# if defined(__cpp_sized_deallocation) && __cpp_sized_deallocation >= 201309
#  define FALCON_CXX_SIZED_DEALLOCATION 1
# else
#  define FALCON_CXX_SIZED_DEALLOCATION 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf
#ifndef FALCON_CXX_DIGIT_SEPARATOR
# if defined(__cpp_digit_separator) && __cpp_digit_separator >= 201309
#  define FALCON_CXX_DIGIT_SEPARATOR 1
# else
#  define FALCON_CXX_DIGIT_SEPARATOR 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3639.html
// (Removed from the standard)
#ifndef FALCON_CXX_RUNTIME_ARRAYS
# if defined(__cpp_runtime_arrays) && __cpp_runtime_arrays >= 198712
#  define FALCON_CXX_RUNTIME_ARRAYS 1
# else
#  define FALCON_CXX_RUNTIME_ARRAYS 0
# endif
#endif

//@}


// C++17 Features
//@{

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html
#ifndef FALCON_CXX_UNICODE_CHARACTERS
# if defined(__cpp_unicode_characters) && __cpp_unicode_characters >= 201411
#  define FALCON_CXX_UNICODE_CHARACTERS 1
# else
#  define FALCON_CXX_UNICODE_CHARACTERS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html
#ifndef FALCON_CXX_FOLD_EXPRESSIONS
# if defined(__cpp_fold_expressions) && __cpp_fold_expressions >= 201411
#  define FALCON_CXX_FOLD_EXPRESSIONS 1
# else
#  define FALCON_CXX_FOLD_EXPRESSIONS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html
#ifndef FALCON_CXX_NAMESPACE_ATTRIBUTES
# if defined(__cpp_namespace_attributes) && __cpp_namespace_attributes >= 201411
#  define FALCON_CXX_NAMESPACE_ATTRIBUTES 1
# else
#  define FALCON_CXX_NAMESPACE_ATTRIBUTES 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html
#ifndef FALCON_CXX_ENUMERATOR_ATTRIBUTES
# if defined(__cpp_enumerator_attributes) && __cpp_enumerator_attributes >= 201411
#  define FALCON_CXX_ENUMERATOR_ATTRIBUTES 1
# else
#  define FALCON_CXX_ENUMERATOR_ATTRIBUTES 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230.html
#ifndef FALCON_CXX_NESTED_NAMESPACE_DEFINITIONS
# if defined(__cpp_nested_namespace_definitions) && __cpp_nested_namespace_definitions >= 201411
#  define FALCON_CXX_NESTED_NAMESPACE_DEFINITIONS 1
# else
#  define FALCON_CXX_NESTED_NAMESPACE_DEFINITIONS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268.html
#ifndef FALCON_CXX_NONTYPE_TEMPLATE_ARGS
# if defined(__cpp_nontype_template_args) && __cpp_nontype_template_args >= 201411
#  define FALCON_CXX_NONTYPE_TEMPLATE_ARGS 1
# else
#  define FALCON_CXX_NONTYPE_TEMPLATE_ARGS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.html
#ifndef FALCON_CXX_STATIC_ASSERT_MSG
# if defined(__cpp_static_assert) && __cpp_static_assert >= 201411
#  define FALCON_CXX_STATIC_ASSERT_MSG 1
# else
#  define FALCON_CXX_STATIC_ASSERT_MSG 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html
#ifndef FALCON_CXX_AGGREGATE_BASES
# if defined(__cpp_aggregate_bases) && __cpp_aggregate_bases >= 201603
#  define FALCON_CXX_AGGREGATE_BASES 1
# else
#  define FALCON_CXX_AGGREGATE_BASES 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1.pdf
#ifndef FALCON_CXX_CONSTEXPR_LAMBDA
# if defined(__cpp_constexpr) && __cpp_constexpr >= 201603
#  define FALCON_CXX_CONSTEXPR_LAMBDA 1
# else
#  define FALCON_CXX_CONSTEXPR_LAMBDA 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0.pdf
#ifndef FALCON_CXX_UNARY_FOLD_EXPRESSIONS
# if defined(__cpp_fold_expressions) && __cpp_fold_expressions >= 201603
#  define FALCON_CXX_UNARY_FOLD_EXPRESSIONS 1
# else
#  define FALCON_CXX_UNARY_FOLD_EXPRESSIONS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html
#ifndef FALCON_CXX_RANGE_BASED_FOR
# if defined(__cpp_range_based_for) && __cpp_range_based_for >= 201603
#  define FALCON_CXX_RANGE_BASED_FOR 1
# else
#  define FALCON_CXX_RANGE_BASED_FOR 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html
#ifndef FALCON_CXX_CAPTURE_STAR_THIS
# if defined(__cpp_capture_star_this) && __cpp_capture_star_this >= 201603
#  define FALCON_CXX_CAPTURE_STAR_THIS 1
# else
#  define FALCON_CXX_CAPTURE_STAR_THIS 0
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1.html
#ifndef FALCON_CXX_HEX_FLOAT
# if defined(__cpp_hex_float) && __cpp_hex_float >= 201603
#  define FALCON_CXX_HEX_FLOAT 1
# else
#  define FALCON_CXX_HEX_FLOAT 0
# endif
#endif

// http://wg21.link/p0035
#ifndef FALCON_CXX_ALIGNED_NEW
# if defined(__cpp_aligned_new) && __cpp_aligned_new >= 201606
#  define FALCON_CXX_ALIGNED_NEW 1
# else
#  define FALCON_CXX_ALIGNED_NEW 0
# endif
#endif

// http://wg21.link/p0292
#ifndef FALCON_CXX_IF_CONSTEXPR
# if defined(__cpp_if_constexpr) && __cpp_if_constexpr >= 201606
#  define FALCON_CXX_IF_CONSTEXPR 1
# else
#  define FALCON_CXX_IF_CONSTEXPR 0
# endif
#endif

// http://wg21.link/p0091
#ifndef FALCON_CXX_DEDUCTION_GUIDES
# if defined(__cpp_deduction_guides) && __cpp_deduction_guides >= 201606
#  define FALCON_CXX_DEDUCTION_GUIDES 1
# else
#  define FALCON_CXX_DEDUCTION_GUIDES 0
# endif
#endif

// http://wg21.link/p0127
#ifndef FALCON_CXX_TEMPLATE_AUTO
# if defined(__cpp_template_auto) && __cpp_template_auto >= 201606
#  define FALCON_CXX_TEMPLATE_AUTO 1
# else
#  define FALCON_CXX_TEMPLATE_AUTO 0
# endif
#endif

// http://wg21.link/p0217
#ifndef FALCON_CXX_STRUCTURED_BINDINGS
# if defined(__cpp_structured_bindings) && __cpp_structured_bindings >= 201606
#  define FALCON_CXX_STRUCTURED_BINDINGS 1
# else
#  define FALCON_CXX_STRUCTURED_BINDINGS 0
# endif
#endif

// http://wg21.link/p0012
#ifndef FALCON_CXX_NOEXCEPT_FUNCTION_TYPE
# if defined(__cpp_noexcept_function_type) && __cpp_noexcept_function_type >= 201510
#  define FALCON_CXX_NOEXCEPT_FUNCTION_TYPE 1
# else
#  define FALCON_CXX_NOEXCEPT_FUNCTION_TYPE 0
# endif
#endif

// http://wg21.link/p0136
#ifndef FALCON_CXX_INHERITING_CONSTRUCTORS
# if defined(__cpp_inheriting_constructors) && __cpp_inheriting_constructors >= 201511
#  define FALCON_CXX_INHERITING_CONSTRUCTORS 1
# else
#  define FALCON_CXX_INHERITING_CONSTRUCTORS 0
# endif
#endif

// http://wg21.link/p0386r2
#ifndef FALCON_CXX_INLINE_VARIABLES
# if defined(__cpp_inline_variables) && __cpp_inline_variables >= 201606
#  define FALCON_CXX_INLINE_VARIABLES 1
# else
#  define FALCON_CXX_INLINE_VARIABLES 0
# endif
#endif


// TS

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4377.pdf
// -fconcepts
#ifndef FALCON_CXX_CONCEPTS
# if defined(__cpp_concepts) && __cpp_concepts >= 201507
#  define FALCON_CXX_CONCEPTS 1
# else
#  define FALCON_CXX_CONCEPTS 0
# endif
#endif

// http://www.open-std.org/Jtc1/sc22/wg21/docs/papers/2015/n4514.pdf
// -fgnu-tm
#ifndef FALCON_CXX_TRANSACTIONAL_MEMORY
# if defined(__cpp_transactional_memory) && __cpp_transactional_memory >= 201505
#  define FALCON_CXX_TRANSACTIONAL_MEMORY 1
# else
#  define FALCON_CXX_TRANSACTIONAL_MEMORY 0
# endif
#endif

//@}


// Standard Attributes (http://en.cppreference.com/w/cpp/language/attributes)
//@{

#ifdef __has_cpp_attribute
# define FALCON_CXX_HAS_ATTRIBUTE(attr) __has_cpp_attribute(attr)
#else
# define FALCON_CXX_HAS_ATTRIBUTE(attr) 0
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3760.html
#ifndef FALCON_CXX_HAS_ATTRIBUTE_DEPRECATED
# if FALCON_CXX_HAS_ATTRIBUTE(deprecated) >= 201309 \
   || defined(__cpp_attribute_deprecated)
#  define FALCON_CXX_HAS_ATTRIBUTE_DEPRECATED 1
# else
#  define FALCON_CXX_HAS_ATTRIBUTE_DEPRECATED 0
# endif
#endif

#ifndef FALCON_CXX_ATTRIBUTE_DEPRECATED
# if defined(FALCON_DISABLE_DEPRECATED_WARNINGS)
#  if FALCON_CXX_HAS_ATTRIBUTE_DEPRECATED
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED(msg) [[deprecated]]
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#  elif defined(__clang__) || defined(__GNUC__)
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED __attribute__((deprecated("deprecated")))
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg) __attribute__((deprecated(msg)))
#  elif defined(_MSC_VER)
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED __declspec(deprecated("deprecated"))
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg) __declspec(deprecated(msg))
#  else
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED
#   define FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg)
#  endif
# else
#  define FALCON_CXX_ATTRIBUTE_DEPRECATED
#  define FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg)
# endif
#endif

#define FALCON_DEPRECATED          FALCON_CXX_ATTRIBUTE_DEPRECATED
#define FALCON_DEPRECATED_MSG(msg) FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg)

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0188r1.pdf
#ifndef FALCON_CXX_HAS_ATTRIBUTE_FALLTHROUGH
# if FALCON_CXX_HAS_ATTRIBUTE(fallthrough)
#  define FALCON_CXX_HAS_ATTRIBUTE_FALLTHROUGH 1
# else
#  define FALCON_CXX_HAS_ATTRIBUTE_FALLTHROUGH 0
# endif
#endif

#ifndef FALCON_CXX_ATTRIBUTE_FALLTHROUGH
# if FALCON_CXX_HAS_ATTRIBUTE_FALLTHROUGH
#  define FALCON_CXX_ATTRIBUTE_FALLTHROUGH [[fallthrough]]
# elif defined(__clang__)
#  define FALCON_CXX_ATTRIBUTE_FALLTHROUGH [[clang::fallthrough]]
# else
#  define FALCON_CXX_ATTRIBUTE_FALLTHROUGH void(0)
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0189r1.pdf
#ifndef FALCON_CXX_HAS_ATTRIBUTE_NODISCARD
# if FALCON_CXX_HAS_ATTRIBUTE(nodiscard)
#  define FALCON_CXX_HAS_ATTRIBUTE_NODISCARD 1
# else
#  define FALCON_CXX_HAS_ATTRIBUTE_NODISCARD 0
# endif
#endif

#ifndef FALCON_CXX_ATTRIBUTE_NODISCARD
# if FALCON_CXX_HAS_ATTRIBUTE_NODISCARD
#  define FALCON_CXX_ATTRIBUTE_NODISCARD [[nodiscard]]
# elif defined(__clang__) || defined(__GNUC__)
#  define FALCON_CXX_ATTRIBUTE_NODISCARD __attribute__((warn_unused_result))
# elif defined(_MSC_VER)
#  define FALCON_CXX_ATTRIBUTE_NODISCARD _Check_return_
# else
#  define FALCON_CXX_ATTRIBUTE_NODISCARD
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0212r1.pdf
#ifndef FALCON_CXX_HAS_ATTRIBUTE_MAYBE_UNUSED
# if FALCON_CXX_HAS_ATTRIBUTE(maybe_unused)
#  define FALCON_CXX_HAS_ATTRIBUTE_MAYBE_UNUSED 1
# else
#  define FALCON_CXX_HAS_ATTRIBUTE_MAYBE_UNUSED 0
# endif
#endif

#ifndef FALCON_CXX_ATTRIBUTE_MAYBE_UNUSED
# if FALCON_CXX_HAS_ATTRIBUTE_MAYBE_UNUSED
#  define FALCON_CXX_ATTRIBUTE_MAYBE_UNUSED [[maybe_unused]]
# elif defined(__clang__) || defined(__GNUC__)
#  define FALCON_CXX_ATTRIBUTE_MAYBE_UNUSED __attribute__((unused))
# else
#  define FALCON_CXX_ATTRIBUTE_MAYBE_UNUSED
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761.pdf
#ifndef FALCON_CXX_HAS_ATTRIBUTE_NORETURN
# if FALCON_CXX_HAS_ATTRIBUTE(noreturn) >= 200809
#  define FALCON_CXX_HAS_ATTRIBUTE_NORETURN 1
# else
#  define FALCON_CXX_HAS_ATTRIBUTE_NORETURN 0
# endif
#endif

#ifndef FALCON_CXX_ATTRIBUTE_NORETURN
# if FALCON_CXX_HAS_ATTRIBUTE_NORETURN
#  define FALCON_CXX_ATTRIBUTE_NORETURN [[noreturn]]
# elif defined(__clang__) || defined(__GNUC__)
#  define FALCON_CXX_ATTRIBUTE_NORETURN __attribute__((noreturn))
# elif defined(_MSC_VER)
#  define FALCON_CXX_ATTRIBUTE_NORETURN __declspec(noreturn)
# else
#  define FALCON_CXX_ATTRIBUTE_NORETURN
# endif
#endif

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2761.pdf
#ifndef FALCON_CXX_HAS_ATTRIBUTE_CARRIES_DEPENDENCY
# if FALCON_CXX_HAS_ATTRIBUTE(carries_dependency) >= 200809
#  define FALCON_CXX_HAS_ATTRIBUTE_CARRIES_DEPENDENCY 1
# else
#  define FALCON_CXX_HAS_ATTRIBUTE_CARRIES_DEPENDENCY 0
# endif
#endif

#ifndef FALCON_CXX_ATTRIBUTE_CARRIES_DEPENDENCY
# if FALCON_CXX_HAS_ATTRIBUTE_CARRIES_DEPENDENCY
#  define FALCON_CXX_ATTRIBUTE_CARRIES_DEPENDENCY [[carries_dependency]]
# else
#  define FALCON_CXX_ATTRIBUTE_CARRIES_DEPENDENCY
# endif
#endif

//@}


#ifdef __has_feature
# define FALCON_CXX_HAS_FEATURE(feature) __has_feature(feature)
#else
# define FALCON_CXX_HAS_FEATURE(feature) 0
#endif


//@{

# define FALCON_PRAGMA(X) _Pragma(#X)

#if defined(_MSC_VER)
# define FALCON_DIAGNOSTIC_PUSH __pragma(warning(push))
# define FALCON_DIAGNOSTIC_POP __pragma(warning(pop))
# define FALCON_DIAGNOSTIC_MSVC_IGNORE(X) __pragma(warning(disable:X))
# define FALCON_DIAGNOSTIC_GCC_IGNORE(X)
# define FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
#elif defined(__GNUC__) || defined(__clang__)
# define FALCON_DIAGNOSTIC_PUSH FALCON_PRAGMA(GCC diagnostic push)
# define FALCON_DIAGNOSTIC_POP FALCON_PRAGMA(GCC diagnostic pop)
# define FALCON_DIAGNOSTIC_MSVC_IGNORE(X)
# define FALCON_DIAGNOSTIC_GCC_IGNORE(X) RANGES_PRAGMA(GCC diagnostic ignored X)
# ifdef __clang__
#  define FALCON_DIAGNOSTIC_CLANG_IGNORE(X) RANGES_PRAGMA(GCC diagnostic ignored X)
# else
#  define FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
# endif
#else
# define FALCON_DIAGNOSTIC_PUSH
# define FALCON_DIAGNOSTIC_POP
# define FALCON_DIAGNOSTIC_MSVC_IGNORE(X)
# define FALCON_DIAGNOSTIC_GCC_IGNORE(X)
# define FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
#endif

//@}


#if defined(IN_KDEVELOP_PARSER) && !defined(IN_IDE_PARSER)
# define IN_IDE_PARSER
#endif


// Keywords and Syntax
//@{

// C++14 constexpr functions are inline in C++11
#if __cplusplus >= FALCON_CXX_STD_14
# define FALCON_CXX14_CONSTEXPR constexpr
#else
# define FALCON_CXX14_CONSTEXPR inline
#endif

#if FALCON_CXX_STATIC_ASSERT_MSG
# define FALCON_STATIC_ASSERT(expr) static_assert(expr)
#else
# define FALCON_STATIC_ASSERT(expr) static_assert(expr, #expr)
#endif

#define FALCON_CXX_RESTRICT __restrict__

#ifndef FALCON_PP_NIL
# define FALCON_PP_NIL
#endif

#if defined(IN_IDE_PARSER)
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

# define FALCON_CXX_EXPAND
# define FALCON_IN_IDE_PARSER_CONDITIONAL(expr1, expr2) expr1
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

# define FALCON_CXX_EXPAND ...
# define FALCON_IN_IDE_PARSER_CONDITIONAL(expr1, expr2) expr2
#endif


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
#if FALCON_CXX_INLINE_VARIABLES
# define FALCON_INLINE_VARIABLE(type, name) \
  inline constexpr type name{}
# define FALCON_SCOPED_INLINE_VARIABLE(type, name) \
  inline namespace {                               \
    inline constexpr type name{};                  \
  }
#else
namespace falcon { namespace detail {
  template<class T> struct static_const { static constexpr T value{}; };
  template<class T> constexpr T static_const<T>::value;
} }
# define FALCON_INLINE_VARIABLE(type, name)                            \
  constexpr auto & name = ::falcon::detail::static_const<type>::value
# define FALCON_SCOPED_INLINE_VARIABLE(type, name) \
  inline namespace {                               \
    constexpr auto & name = ::falcon::detail::static_const<type>::value; \
  }
#endif


#define FALCON_EMPTY_CLASS(name) \
  struct name { FALCON_CXX_CONSTEXPR name() FALCON_CXX_NOEXCEPT {} }

//@}
