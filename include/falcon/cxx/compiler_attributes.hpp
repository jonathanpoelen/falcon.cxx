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
* \brief     c++11, 14, 17 compiler attributes
*/

// Non-standards Attributes
//@{

// http://clang.llvm.org/docs/AttributeReference.html
// https://gcc.gnu.org/onlinedocs/gcc/Common-Variable-Attributes.html#Common-Variable-Attributes
// https://gcc.gnu.org/onlinedocs/gcc/Common-Function-Attributes.html
// https://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Extensions.html#C_002b_002b-Extensions

#if defined(__clang__)
# define FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(x)     __attribute__((x))
# define FALCON_ANNOTATION_ATTRIBUTE_GCC__(x)           // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG__(x)         __attribute__((x))
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(x)    __attribute__((x))
# define FALCON_ANNOTATION_ATTRIBUTE__(x)               __attribute__((x))
#elif defined(__GNUC__)
# define FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(x)     __attribute__((x))
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG__(x)         // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_GCC__(x)           __attribute__((x))
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(x)    // no-op
# define FALCON_ANNOTATION_ATTRIBUTE__(x)               __attribute__((x))
#elif defined(_MSC_VER)
# define FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(x)     // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG__(x)         // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_GCC__(x)           // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(x)    __declspec(x)
# define FALCON_ANNOTATION_ATTRIBUTE__(x)               __declspec(x)
#else
# define FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(x)     // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG__(x)         // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_GCC__(x)           // no-op
# define FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(x)    // no-op
# define FALCON_ANNOTATION_ATTRIBUTE__(x)               // no-op
#endif


#define FALCON_ATTR_ASSUME_ALIGNED(...) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(assume_aligned(__VA_ARGS__))

#define FALCON_ATTR_AVAILABILITY(...) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(availability(__VA_ARGS__))

#define FALCON_ATTR_CONVERGENT(...) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(convergent(__VA_ARGS__))

#define FALCON_ATTR_DISABLE_TAIL_CALLS(...) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(disable_tail_calls(__VA_ARGS__))

#define FALCON_ATTR_FLATTEN \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(flatten)

#define FALCON_ATTR_FORMAT(...) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(__format__(__VA_ARGS__))

#define FALCON_ATTR_IFUNC \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(ifunc("resolver"))

#define FALCON_ATTR_INTERNAL_LINKAGE \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(internal_linkage)

#define FALCON_ATTR_INTERRUPT(arg) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(interrupt(arg))

#define FALCON_ATTR_NOALIAS \
  FALCON_ANNOTATION_ATTRIBUTE_MSGCC_CLANG__(noalias)

#define FALCON_ATTR_NODUPLICATE \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(noduplicate)

#define FALCON_ATTR_NO_SANITIZE_ADDRESS \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(no_sanitize_address)

#define FALCON_ATTR_NO_SANITIZE_THREAD \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(no_sanitize_thread)

#define FALCON_ATTR_NO_SANITIZE_MEMORY \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(no_sanitize_memory)

#define FALCON_ATTR_NO_SPLIT_STACK \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(no_split_stack)

#define FALCON_ATTR_NOT_TAIL_CALLED \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(not_tail_called)

#define FALCON_ATTR_NO_STACK_LIMIT \
  FALCON_ANNOTATION_ATTRIBUTE_GCC__(no_stack_limit)

#define FALCON_ATTR_OPTNONE \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(optnone)

#define FALCON_ATTR_KERNEL \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(kernel)

#define FALCON_ATTR_TARGET(...) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(target(__VA_ARGS__))

#define FALCON_ATTR_XRAY_ALWAYS_INSTRUMENT \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(xray_always_instrument)

#define FALCON_ATTR_DLLEXPORT \
  FALCON_ANNOTATION_ATTRIBUTE__(dllexport)

#define FALCON_ATTR_DLLIMPORT \
  FALCON_ANNOTATION_ATTRIBUTE__(dllimport)

#define FALCON_ATTR_NODEBUG \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(nodebug)

#define FALCON_ATTR_NOSVM \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(nosvm)

#define FALCON_ATTR_REQUIRE_CONSTANT_INITIALIZATION \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(require_constant_initialization)

#define FALCON_ATTR_SECTION \
  FALCON_ANNOTATION_ATTRIBUTE__(section)

#define FALCON_ATTR_TLS_MODEL(model) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(tls_model(model))

#define FALCON_ATTR_THREAD \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(thread)

#define FALCON_ATTR_ALIGN_VALUE(n) \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(align_value(n))

#define FALCON_ATTR_FLAG_ENUM \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(flag_enum)

#define FALCON_ATTR_LTO_VISIBILITY_PUBLIC \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(lto_visibility_public)

#define FALCON_ATTR_LAYOUT_VERSION \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(layout_version)

#define FALCON_ATTR_NOVTABLE \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG_MSVC__(novtable)

#define FALCON_ATTR_OPENCL_UNROLL_HINT \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(opencl_unroll_hint)

#define FALCON_ATTR_NONNULL \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(nonnull)

#define FALCON_ATTR_RETURNS_NONNULL \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(returns_nonnull)

#define FALCON_ATTR_ALWAYS_INLINE \
  FALCON_ANNOTATION_ATTRIBUTE_GCC_CLANG__(always_inline)


// http://clang.llvm.org/docs/ThreadSafetyAnalysis.html
//@{
#define FALCON_ATTR_CAPABILITY(x) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(capability(x))

#define FALCON_ATTR_SCOPED_CAPABILITY \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(scoped_lockable)

#define FALCON_ATTR_GUARDED_BY(x) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(guarded_by(x))

#define FALCON_ATTR_PT_GUARDED_BY(x) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(pt_guarded_by(x))

#define FALCON_ATTR_ACQUIRED_BEFORE(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(acquired_before(__VA_ARGS__))

#define FALCON_ATTR_ACQUIRED_AFTER(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(acquired_after(__VA_ARGS__))

#define FALCON_ATTR_REQUIRES(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(requires_capability(__VA_ARGS__))

#define FALCON_ATTR_REQUIRES_SHARED(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(requires_shared_capability(__VA_ARGS__))

#define FALCON_ATTR_ACQUIRE(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(acquire_capability(__VA_ARGS__))

#define FALCON_ATTR_ACQUIRE_SHARED(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(acquire_shared_capability(__VA_ARGS__))

#define FALCON_ATTR_RELEASE(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(release_capability(__VA_ARGS__))

#define FALCON_ATTR_RELEASE_SHARED(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(release_shared_capability(__VA_ARGS__))

#define FALCON_ATTR_TRY_ACQUIRE(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(try_acquire_capability(__VA_ARGS__))

#define FALCON_ATTR_TRY_ACQUIRE_SHARED(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(try_acquire_shared_capability(__VA_ARGS__))

#define FALCON_ATTR_EXCLUDES(...) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(locks_excluded(__VA_ARGS__))

#define FALCON_ATTR_ASSERT_CAPABILITY(x) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(assert_capability(x))

#define FALCON_ATTR_ASSERT_SHARED_CAPABILITY(x) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(assert_shared_capability(x))

#define FALCON_ATTR_RETURN_CAPABILITY(x) \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(lock_returned(x))

#define FALCON_ATTR_NO_THREAD_SAFETY_ANALYSIS \
  FALCON_ANNOTATION_ATTRIBUTE_CLANG__(no_thread_safety_analysis)
//@}

//@}
