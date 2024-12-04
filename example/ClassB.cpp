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
#include "ClassB.h"
#include <iostream>
#include "ClassA.M.h"
#include <Concealer.s.h>

namespace test {

struct ClassB::dummy_members {
	double d;

	~dummy_members() {
		std::cout << "Class B Member: Destruct.\n";
	}
	dummy_members() :
		d(0) {
		std::cout << "Class B Member: Construct.\n";
	}
	dummy_members(double _d) :
		d(_d) {
		std::cout << "Class B Member: Construct, with (double).\n";
	}
};

IMPL_INFOFUNC(ClassB)

ClassB::~ClassB() {
	DROP_MEMBERS();
	std::cout << "Class B: Destruct.\n";
}

ClassB::ClassB() :
	testB(true),
	testCCC(0x7C),
	testFA{ 3.14f, 3.14f, 3.14f, 3.14f } {
	std::cout << "Class B: Construct.\n";
	INIT_MEMBERS(456.0);
}

ClassB::ClassB(double _d, int _i) :
	testB(true),
	testCCC(0x7C),
	testFA{ 3.14f, 3.14f, 3.14f, 3.14f } {
	BASE(ClassA)->i = _i;
	std::cout << "Class B: Construct, with (double, int).\n";
	INIT_MEMBERS(_d);
}

void ClassB::func() {
	std::cout << "Class B: Say \"" << THIS->d << "\"." << std::endl;
	return;
}

}
