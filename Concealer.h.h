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
// Include this file in your header files.
// 
// Another one (Concealer.s.h) is not needed in your header files.
//
#pragma once
#include <cstdint>

template<size_t _align_as>
struct dummy_array_type {
	uint64_t dummy;
};
template<>
struct dummy_array_type<1> {
	uint8_t dummy;
};
template<>
struct dummy_array_type<2> {
	uint16_t dummy;
};
template<>
struct dummy_array_type<4> {
	uint32_t dummy;
};
template<>
struct dummy_array_type<8> {
	uint64_t dummy;
};

// This is used to declare a concealer struct, an info function, and a dummy array in classes.
#define OHMS_DECLARE_MEMBERS(_size_in_bytes, _align_as) \
struct dummy_members; \
static size_t dummy_size_when_compile();\
dummy_array_type<_align_as> _dummy_array \
[(_size_in_bytes + sizeof(dummy_array_type<_align_as>) - 1) / sizeof(dummy_array_type<_align_as>)]
