#include "pattern.h"

#include "Concealer.s.h"

namespace name {

#define CURRENT_CLASS pattern
struct CURRENT_CLASS::dummy_members {
	int a;

	~dummy_members() {}
	dummy_members() :
		a(0) {}
};
IMPL_INFOFUNC(CURRENT_CLASS)
//CHECK_MEMBERS(CURRENT_CLASS)

pattern::~pattern() {
	// Add code here.
	//-------------//
	DROP_MEMBERS();
}

pattern::pattern() {
	INIT_MEMBERS();
	//-------------//
	// Add code here.
}

}