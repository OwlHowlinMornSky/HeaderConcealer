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
#include <iostream>

#include "ClassC.h"

int main() {
	bool run = true;
	test::ClassC* z = nullptr;

	std::cout << test::ClassC::dummy_size_when_compile() << std::endl;

START:
	if (run)
		z = new test::ClassC();
	else
		z = new test::ClassC("Hello World!", 1234.0, 5678);

	test::ClassB* y = z;
	test::ClassA* x = y;
	std::cout << std::endl;

	x->ClassA::func();
	x->func();
	y->ClassB::func();
	y->func();
	z->ClassA::func();
	z->ClassB::func();
	z->func();

	std::cout << std::endl;
	z->set(9);
	std::cout << std::endl;

	x->ClassA::func();
	x->func();
	y->ClassB::func();
	y->func();
	z->ClassA::func();
	z->ClassB::func();
	z->func();

	std::cout << std::endl;
	delete z;
	x = y = z = nullptr;

	std::cout << "\nOver.\n" << std::endl;

	if (run) {
		run = false;
		goto START;
	}

	return 0;
}
