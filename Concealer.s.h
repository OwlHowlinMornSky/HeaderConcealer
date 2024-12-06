/*
*    Header Concealer
*
*    Copyright (c) 2024 Tyler Parret True
*
*    MIT License
*
*    Permission is hereby granted, free of charge, to any person obtaining a copy
*    of this software and associated documentation files (the "Software"), to deal
*    in the Software without restriction, including without limitation the rights
*    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*    copies of the Software, and to permit persons to whom the Software is
*    furnished to do so, subject to the following conditions:
*
*    The above copyright notice and this permission notice shall be included in all
*    copies or substantial portions of the Software.
*
*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*    SOFTWARE.
*
* @Authors
*    Tyler Parret True <mysteryworldgod@outlook.com><https://github.com/OwlHowlinMornSky>
*/
// Include this file in your source files.
// 
// This is not needed in your header files.
//
#pragma once
#include <new>

// Define or set it into project properties to allow larger dummy arraies.
#ifndef OHMS_HEADERCUTTER_LOOSE
#define DUMMYARRAY_SIZE(_size_in_bytes, _align_as) \
(((_size_in_bytes + sizeof(dummy_array_type<_align_as>) - 1) / sizeof(dummy_array_type<_align_as>)) * sizeof(dummy_array_type<_align_as>))
#define ___OHMS_CHECK_MEMBER_SIZE \
static_assert(sizeof(_dummy_array) == DUMMYARRAY_SIZE(sizeof(dummy_members), alignof(dummy_members)), "HeaderConcealer: Array size is not fit!")
#define ___OHMS_CHECK_MEMBER_SIZE_NAME(_class) \
static_assert(sizeof(_class::_dummy_array) == DUMMYARRAY_SIZE(sizeof(_class::dummy_members), alignof(_class::dummy_members)), "HeaderConcealer: Array size is not fit in [" #_class "]!")
#else
#define ___OHMS_CHECK_MEMBER_SIZE \
static_assert(sizeof(_dummy_array) >= sizeof(dummy_members), "HeaderConcealer: Array size is not enough!")
#define ___OHMS_CHECK_MEMBER_SIZE_NAME(_class) \
static_assert(sizeof(_class::_dummy_array) >= sizeof(_class::dummy_members), "HeaderConcealer: Array size is not enough in [" #_class "]!")
#endif
#define ___OHMS_CHECK_MEMBER_ALIGN \
static_assert(alignof(decltype(_dummy_array)) == alignof(dummy_members), "HeaderConcealer: Array align is wrong!")
#define ___OHMS_CHECK_MEMBER_ALIGN_NAME(_class) \
static_assert(alignof(decltype(_class::_dummy_array)) == alignof(_class::dummy_members), "HeaderConcealer: Array align is wrong in [" #_class "]!")

// Use this to access members of current class.
#define THIS                  ((dummy_members*)(_dummy_array))

// Use this to check if it is right that size and align of the dummy array of the specified class.
// The array must be public to use this, otherwise, no use of INIT_NOCHECK_MEMBERS but INIT_MEMBERS.
#define CHECK_MEMBERS(_class) ___OHMS_CHECK_MEMBER_SIZE_NAME(_class); ___OHMS_CHECK_MEMBER_ALIGN_NAME(_class);

// Construct members. You can add params after this, like "INIT_NOCHECK_MEMBERS(a, b, c);".
// This won't check the size and align of the array.
#define INIT_NOCHECK_MEMBERS  new(THIS) dummy_members

// Construct members. You can add params after this, like "INIT_MEMBERS(a, b, c);".
// This will check the size and align of the array.
#define INIT_MEMBERS          ___OHMS_CHECK_MEMBER_SIZE; ___OHMS_CHECK_MEMBER_ALIGN; (void)dummy_size_when_compile();INIT_NOCHECK_MEMBERS

// Deconstruct members.
#define DROP_MEMBERS          THIS->~dummy_members

// Use this to access members of based classes.
#define BASE(_class)          ((_class::dummy_members*)(_class::_dummy_array))

// Use this to implement the info function.
#define IMPL_INFOFUNC(_class) size_t _class::dummy_size_when_compile(){return sizeof(_class::dummy_members);}

/*
#ifdef _MSC_VER
#define OHMS_ALIGNOF __alignof
#else
#define OHMS_ALIGNOF alignof
#endif
#define ___OHMS_CHECK_MEMBER_ALIGN \
static_assert(OHMS_ALIGNOF(DummyArray) == OHMS_ALIGNOF(DummyMembers), "HeaderCutter: Array align is wrong!");
#define ___OHMS_CHECK_MEMBER_ALIGN_NAME(_class) \
static_assert(OHMS_ALIGNOF(_class::DummyArray) == OHMS_ALIGNOF(_class::DummyMembers), "HeaderCutter: Array align is wrong in [" #_class "]!");
*/
