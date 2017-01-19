# falcon.cxx [![version.badge]](http://semver.org) [![travis.badge]][travis.url] [![appveyor.badge]][appveyor.url]


## Links

- https://gcc.gnu.org/projects/cxx-status.html
- http://en.cppreference.com/w/cpp/experimental/feature_test
- https://isocpp.org/std/standing-documents/sd-6-sg10-feature-test-recommendations
- http://clang.llvm.org/docs/AttributeReference.html
- https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes
- https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html
- https://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Extensions.html#C_002b_002b-Extensions


## Macros

- cxx.hpp

```c++
FALCON_CXX_STD_11 // 201103
FALCON_CXX_STD_14 // 201402


// Keywords

FALCON_CONSTEXPR // constexpr
FALCON_CXX14_CONSTEXPR // c++14 on later : `constexpr`, otherwise `inline`
FALCON_CONSTEXPR_AFTER_CXX11
FALCON_CONSTEXPR_AFTER_CXX14

FALCON_NOEXCEPT // noexcept
FALCON_NOEXCEPT_EXPR(expr) // `noexcept(expr)`
FALCON_NOEXCEPT_EXPR2(...) // `noexcept(noexcept(...))`

FALCON_RESTRICT // `__restrict__`
FALCON_STATIC_ASSERT(expr) // `static_assert(expr, #expr)`

FALCON_ALWAYS_INLINE // `__attribute__((always_inline))` or `__forceinline`

// http://clang.llvm.org/docs/LanguageExtensions.html
FALCON_HAS_BUILTIN(builtin) // `__has_builtin(builtin)`
FALCON_HAS_FEATURE(feature) // `__has_feature(feature)` or `__has_extension(feature)`
FALCON_HAS_CPP_ATTRIBUTE(attr) // `__has_cpp_attribute(attr)`
FALCON_HAS_ATTRIBUTE(attr) // `__has_attribute(attr)`
FALCON_HAS_DECLSPEC_ATTRIBUTE(attr) // `__has_declspec_attribute(attr)`
FALCON_HAS_INCLUDE(filename) // `__has_include(filename)`
FALCON_HAS_INCLUDE_NEXT(filename) // `__has_include(filename)`

FALCON_PRAGMA(X) // `_Pragma(#X)`

// To provide the compiler with branch prediction information
FALCON_LIKELY(X)
FALCON_UNLIKELY(X)


// Syntax

FALCON_RETURN_NOEXCEPT(...) // `noexcept(noexcept(...)) { return ...; }`
FALCON_DECLTYPE_NOEXCEPT(...) // `noexcept(noexcept(...)) -> decltype(...)`
FALCON_DECLTYPE_AUTO_RETURN(...) // -> `decltype(...) { return ...; }`
FALCON_DECLTYPE_AUTO_RETURN_NOEXCEPT(...) // `noexcept(noexcept(...)) -> decltype(...) { return ...; }`

FALCON_CXX11_DEFAULT_MOVE(class_name) // move-ctor, move-assignement
FALCON_CXX11_DEFAULT_COPY_MOVE(class_name) // move/copy-ctor, move/copy-assignement
FALCON_CXX11_DEFAULT_SPECIAL_MEMBER(class_name) // move/copy-ctor, move/copy-assignement, default ctor

FALCON_INLINE_VARIABLE(type, name)
FALCON_SCOPED_INLINE_VARIABLE(type, name) // anonymous namespace

FALCON_EMPTY_CLASS(name) // `struct name { constexpr name() noexcept {} }`

FALCON_PACK // c++11 or later: `...`, otherwise empty
FALCON_UNPACK(...) // c++11 or later: `std::initializer_list<int>{(void(__VA_ARGS__), 0)...}`, otherwise `void(__VA_ARGS__)`

FALCON_IN_IDE_PARSER_CONDITIONAL(in_ide_expr, not_ide_expr)

FALCON_PP_NIL


// Diagnostic

FALCON_DIAGNOSTIC_PUSH
FALCON_DIAGNOSTIC_POP

FALCON_DIAGNOSTIC_CLANG_IGNORE(X)
FALCON_DIAGNOSTIC_GCC_IGNORE(X)
FALCON_DIAGNOSTIC_GCC_ONLY_IGNORE(X)
FALCON_DIAGNOSTIC_MSVC_IGNORE(X)

FALCON_DIAGNOSTIC_CLANG_WARNING(X)
FALCON_DIAGNOSTIC_GCC_WARNING(X)
FALCON_DIAGNOSTIC_GCC_ONLY_WARNING(X)
FALCON_DIAGNOSTIC_MSVC_WARNING(X)

FALCON_DIAGNOSTIC_WARNING_MSG(MSG)


// Attributes

FALCON_ATTRIBUTE_NODISCARD // `[[nodiscard]]`
FALCON_ATTRIBUTE_FALLTHROUGH // `[[fallthrough]]`
FALCON_ATTRIBUTE_NORETURN // `[[noreturn]]`
FALCON_ATTRIBUTE_CARRIES_DEPENDENCY // `[[carries_dependency]]`
FALCON_ATTRIBUTE_MAYBE_UNUSED // `[[maybe_unused]]`
FALCON_ATTRIBUTE_DEPRECATED // `[[deprecated]]`
FALCON_ATTRIBUTE_DEPRECATED_MSG(msg) // `[[deprecated(msg)]]`
FALCON_DEPRECATED // FALCON_CXX_ATTRIBUTE_DEPRECATED
FALCON_DEPRECATED_MSG(msg) // FALCON_CXX_ATTRIBUTE_DEPRECATED_MSG(msg)

// (0 or 1)
FALCON_HAS_CPP_ATTRIBUTE_CARRIES_DEPENDENCY
FALCON_HAS_CPP_ATTRIBUTE_DEPRECATED
FALCON_HAS_CPP_ATTRIBUTE_FALLTHROUGH
FALCON_HAS_CPP_ATTRIBUTE_MAYBE_UNUSED
FALCON_HAS_CPP_ATTRIBUTE_NODISCARD
FALCON_HAS_CPP_ATTRIBUTE_NORETURN


// Features (0 or 1)

// C++98 Features

FALCON_CXX_FEATURE_RTTI
FALCON_CXX_FEATURE_EXCEPTIONS

// C++11 Features

FALCON_CXX_FEATURE_STATIC_ASSERT

// C++14 Features

FALCON_CXX_FEATURE_BINARY_LITERALS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3472.pdf
FALCON_CXX_FEATURE_DECLTYPE_AUTO // https://isocpp.org/files/papers/N3638.html
FALCON_CXX_FEATURE_RETURN_TYPE_DEDUCTION // https://isocpp.org/files/papers/N3638.html
FALCON_CXX_FEATURE_INIT_CAPTURES // https://isocpp.org/files/papers/N3648.html
FALCON_CXX_FEATURE_GENERIC_LAMBDAS // https://isocpp.org/files/papers/N3649.html
FALCON_CXX_FEATURE_VARIABLE_TEMPLATES // https://isocpp.org/files/papers/N3651.pdf
FALCON_CXX_FEATURE_RELAXED_CONSTEXPR // https://isocpp.org/files/papers/N3652.html
FALCON_CXX_FEATURE_AGGREGATE_INITIALIZATION // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3653.html
FALCON_CXX_FEATURE_SIZED_DEALLOCATION // https://isocpp.org/files/papers/n3778.html
FALCON_CXX_FEATURE_DIGIT_SEPARATOR // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3781.pdf
FALCON_CXX_FEATURE_RUNTIME_ARRAYS // (Removed from the standard) http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3639.html

// C++1z Features

FALCON_CXX_FEATURE_UNICODE_CHARACTERS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4267.html
FALCON_CXX_FEATURE_FOLD_EXPRESSIONS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4295.html
FALCON_CXX_FEATURE_NAMESPACE_ATTRIBUTES // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html
FALCON_CXX_FEATURE_ENUMERATOR_ATTRIBUTES // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4266.html
FALCON_CXX_FEATURE_NESTED_NAMESPACE_DEFINITIONS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4230.html
FALCON_CXX_FEATURE_NONTYPE_TEMPLATE_ARGS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4268.html
FALCON_CXX_FEATURE_STATIC_ASSERT_MSG // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n3928.html
FALCON_CXX_FEATURE_AGGREGATE_BASES // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0017r1.html
FALCON_CXX_FEATURE_CONSTEXPR_LAMBDA // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0170r1.pdf
FALCON_CXX_FEATURE_UNARY_FOLD_EXPRESSIONS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0036r0.pdf
FALCON_CXX_FEATURE_RANGE_BASED_FOR // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0184r0.html
FALCON_CXX_FEATURE_CAPTURE_STAR_THIS // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0018r3.html
FALCON_CXX_FEATURE_HEX_FLOAT // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0245r1.html
FALCON_CXX_FEATURE_ALIGNED_NEW // http://wg21.link/p0035
FALCON_CXX_FEATURE_IF_CONSTEXPR // http://wg21.link/p0292
FALCON_CXX_FEATURE_DEDUCTION_GUIDES // http://wg21.link/p0091
FALCON_CXX_FEATURE_TEMPLATE_AUTO // http://wg21.link/p0127
FALCON_CXX_FEATURE_STRUCTURED_BINDINGS // http://wg21.link/p0217
FALCON_CXX_FEATURE_NOEXCEPT_FUNCTION_TYPE // http://wg21.link/p0012
FALCON_CXX_FEATURE_INHERITING_CONSTRUCTORS // http://wg21.link/p0136
FALCON_CXX_FEATURE_INLINE_VARIABLES // http://wg21.link/p0386r2

// TS

FALCON_CXX_FEATURE_CONCEPTS // -fconcepts  http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4377.pdf
FALCON_CXX_FEATURE_TRANSACTIONAL_MEMORY // -fgnu-tm  http://www.open-std.org/Jtc1/sc22/wg21/docs/papers/2015/n4514.pdf
```

- move.hpp

```c++
FALCON_CXX11_RVALUE // c++11 or later: `&&`, otherwise empty
FALCON_CXX03_CONST_REF // c++11 or later: empty, otherwise `const &`,
FALCON_RVALUE_OR_CONST_REF // c++11 or later: `&&`, otherwise `const &`
FALCON_MOVE(x) // `std::move(x)` or empty
FALCON_FORWARD(T, x) // `std::forward<T>(x)` or empty
FALCON_MOVE_IF_NOEXCEPT(x) // `std::move_if_noexcept(x)` or empty
```

- move_algorithm.hpp

```c++
FALCON_MOVE_BACKWARD3(first, last, d_last) // `std::move_backward(first, last, d_last)` or `std::copy_backward(first, last, d_last)`
FALCON_MOVE3(first, last, d_first) // `std::move(first, last, d_last)` or `std::copy(first, last, d_last)`
FALCON_MAKE_MOVE_ITERATOR(iter) // `std::make_move_iterator(iter)` or `(iter)`
FALCON_MAKE_MOVE_IF_NOEXCEPT_ITERATOR(iter) // `std::make_move_if_noexcept_iterator(iter)` or `(iter)`
```

- compiler_attributes.hpp

```c++
FALCON_CXX_ATTRIBUTE_ACQUIRE(...)
FALCON_CXX_ATTRIBUTE_ACQUIRED_AFTER(...)
FALCON_CXX_ATTRIBUTE_ACQUIRED_BEFORE(...)
FALCON_CXX_ATTRIBUTE_ACQUIRE_SHARED(...)
FALCON_CXX_ATTRIBUTE_ALIGN_VALUE(n)
FALCON_CXX_ATTRIBUTE_ALWAYS_INLINE
FALCON_CXX_ATTRIBUTE_ASSERT_CAPABILITY(x)
FALCON_CXX_ATTRIBUTE_ASSERT_SHARED_CAPABILITY(x)
FALCON_CXX_ATTRIBUTE_ASSUME_ALIGNED(...)
FALCON_CXX_ATTRIBUTE_AVAILABILITY(...)
FALCON_CXX_ATTRIBUTE_CAPABILITY(x)
FALCON_CXX_ATTRIBUTE_CONVERGENT(...)
FALCON_CXX_ATTRIBUTE_DISABLE_TAIL_CALLS(...)
FALCON_CXX_ATTRIBUTE_DLLEXPORT
FALCON_CXX_ATTRIBUTE_DLLIMPORT
FALCON_CXX_ATTRIBUTE_EXCLUDES(...)
FALCON_CXX_ATTRIBUTE_FLAG_ENUM
FALCON_CXX_ATTRIBUTE_FLATTEN
FALCON_CXX_ATTRIBUTE_FORMAT(
FALCON_CXX_ATTRIBUTE_GUARDED_BY(x)
FALCON_CXX_ATTRIBUTE_IFUNC
FALCON_CXX_ATTRIBUTE_INTERNAL_LINKAGE
FALCON_CXX_ATTRIBUTE_INTERRUPT(arg)
FALCON_CXX_ATTRIBUTE_KERNEL
FALCON_CXX_ATTRIBUTE_LAYOUT_VERSION
FALCON_CXX_ATTRIBUTE_LTO_VISIBILITY_PUBLIC
FALCON_CXX_ATTRIBUTE_NOALIAS
FALCON_CXX_ATTRIBUTE_NODEBUG
FALCON_CXX_ATTRIBUTE_NODUPLICATE
FALCON_CXX_ATTRIBUTE_NONNULL
FALCON_CXX_ATTRIBUTE_NO_SANITIZE_ADDRESS
FALCON_CXX_ATTRIBUTE_NO_SANITIZE_MEMORY
FALCON_CXX_ATTRIBUTE_NO_SANITIZE_THREAD
FALCON_CXX_ATTRIBUTE_NO_SPLIT_STACK
FALCON_CXX_ATTRIBUTE_NO_STACK_LIMIT
FALCON_CXX_ATTRIBUTE_NOSVM
FALCON_CXX_ATTRIBUTE_NO_THREAD_SAFETY_ANALYSIS
FALCON_CXX_ATTRIBUTE_NOT_TAIL_CALLED
FALCON_CXX_ATTRIBUTE_NOVTABLE
FALCON_CXX_ATTRIBUTE_OPENCL_UNROLL_HINT
FALCON_CXX_ATTRIBUTE_OPTNONE
FALCON_CXX_ATTRIBUTE_PT_GUARDED_BY(x)
FALCON_CXX_ATTRIBUTE_RELEASE(...)
FALCON_CXX_ATTRIBUTE_RELEASE_SHARED(...)
FALCON_CXX_ATTRIBUTE_REQUIRE_CONSTANT_INITIALIZATION
FALCON_CXX_ATTRIBUTE_REQUIRES(...)
FALCON_CXX_ATTRIBUTE_REQUIRES_SHARED(...)
FALCON_CXX_ATTRIBUTE_RETURN_CAPABILITY(x)
FALCON_CXX_ATTRIBUTE_RETURNS_NONNULL
FALCON_CXX_ATTRIBUTE_SCOPED_CAPABILITY
FALCON_CXX_ATTRIBUTE_SECTION
FALCON_CXX_ATTRIBUTE_TARGET(...)
FALCON_CXX_ATTRIBUTE_THREAD
FALCON_CXX_ATTRIBUTE_TLS_MODEL(model)
FALCON_CXX_ATTRIBUTE_TRY_ACQUIRE(...)
FALCON_CXX_ATTRIBUTE_TRY_ACQUIRE_SHARED(...)
FALCON_CXX_ATTRIBUTE_XRAY_ALWAYS_INSTRUMENT
```

- lib.hpp (0 or 1)

```c++
// http://en.cppreference.com/w/cpp/experimental/feature_test
FALCON_CXX_LIB_CHRONO_UDLS
FALCON_CXX_LIB_COMPLEX_UDLS
FALCON_CXX_LIB_EXCHANGE_FUNCTION
FALCON_CXX_LIB_GENERIC_ASSOCIATIVE_LOOKUP
FALCON_CXX_LIB_INTEGER_SEQUENCE
FALCON_CXX_LIB_INTEGRAL_CONSTANT_CALLABLE
FALCON_CXX_LIB_IS_FINAL
FALCON_CXX_LIB_IS_NULL_POINTER
FALCON_CXX_LIB_MAKE_REVERSE_ITERATOR
FALCON_CXX_LIB_MAKE_UNIQUE
FALCON_CXX_LIB_NULL_ITERATORS
FALCON_CXX_LIB_QUOTED_STRING_IO
FALCON_CXX_LIB_RESULT_OF_SFINAE
FALCON_CXX_LIB_ROBUST_NONMODIFYING_SEQ_OPS
FALCON_CXX_LIB_SHARED_TIMED_MUTEX
FALCON_CXX_LIB_STRING_UDLS
FALCON_CXX_LIB_TRANSFORMATION_TRAIT_ALIASES
FALCON_CXX_LIB_TRANSPARENT_OPERATORS
FALCON_CXX_LIB_TUPLES_BY_TYPE
FALCON_CXX_LIB_TUPLE_ELEMENT_T
```

- lib_experimental.hpp (0 or 1)

```c++
// http://en.cppreference.com/w/cpp/experimental/feature_test
FALCON_CXX_LIB_EXPERIMENTAL_ANY
FALCON_CXX_LIB_EXPERIMENTAL_APPLY
FALCON_CXX_LIB_EXPERIMENTAL_BOYER_MOORE_SEARCHING
FALCON_CXX_LIB_EXPERIMENTAL_FILESYSTEM
FALCON_CXX_LIB_EXPERIMENTAL_FUNCTION_ERASED_ALLOCATOR
FALCON_CXX_LIB_EXPERIMENTAL_INVOCATION_TYPE
FALCON_CXX_LIB_EXPERIMENTAL_MEMORY_RESOURCE
FALCON_CXX_LIB_EXPERIMENTAL_OPTIONAL
FALCON_CXX_LIB_EXPERIMENTAL_PACKAGED_TASK_ERASED_ALLOCATOR
FALCON_CXX_LIB_EXPERIMENTAL_PARALLEL_ALGORITHM
FALCON_CXX_LIB_EXPERIMENTAL_PROMISE_ERASED_ALLOCATOR
FALCON_CXX_LIB_EXPERIMENTAL_SAMPLE
FALCON_CXX_LIB_EXPERIMENTAL_SHARED_PTR_ARRAYS
FALCON_CXX_LIB_EXPERIMENTAL_STRING_VIEW
FALCON_CXX_LIB_EXPERIMENTAL_TYPE_TRAIT_VARIABLE_TEMPLATES
```


<!-- links -->

[version.badge]: https://badge.fury.io/gh/jonathanpoelen%2Ffalcon.cxx.svg

[travis.url]: https://travis-ci.org/jonathanpoelen/falcon.cxx
[travis.badge]: https://travis-ci.org/jonathanpoelen/falcon.cxx.svg?branch=master

[appveyor.url]: https://ci.appveyor.com/project/jonathanpoelen/falcon-cxx
[appveyor.badge]: https://ci.appveyor.com/api/projects/status/github/jonathanpoelen/falcon.cxx
