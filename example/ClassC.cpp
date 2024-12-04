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
#include "ClassC.h"
#include <string>
#include <iostream>
#include "ClassA.M.h"
#include <Concealer.s.h>

namespace test {

struct ClassC::dummy_members {
	char testC;
	std::string str;

	~dummy_members() {
		std::cout << "Class C Member: Destruct.\n";
	}
	dummy_members() :
		testC(0xC),
		str("null") {
		std::cout << "Class C Member: Construct.\n";
	}
	dummy_members(std::string_view _str) :
		testC(0xC),
		str(_str) {
		std::cout << "Class C Member: Construct, with (std::string_view).\n";
	}
};

CHECK_MEMBERS(ClassC)
IMPL_INFOFUNC(ClassC)

ClassC::~ClassC() {
	DROP_MEMBERS();
	std::cout << "Class C: Destruct.\n";
}

ClassC::ClassC() :
	testL(0x7CCCCCCC) {
	std::cout << "Class C: Construct.\n";
	INIT_NOCHECK_MEMBERS();
}

ClassC::ClassC(std::string_view _str, double _d, int _i) :
	ClassB(_d, _i),
	testL(0x7CCCCCCC) {
	std::cout << "Class C: Construct, with (std::string_view, double, int).\n";
	INIT_NOCHECK_MEMBERS(_str);
}

void ClassC::func() {
	std::cout << "Class C: Say \"" << THIS->str << "\"." << std::endl;
	return;
}

void ClassC::set(int _i) {
	BASE(ClassA)->i = _i;
	std::cout << "Class C: Set \"" << _i << "\"." << std::endl;
	return;
}

}
