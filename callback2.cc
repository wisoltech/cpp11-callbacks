/**
 * \file callback2.cc
 * \author Michael Egli
 * \date 08-Mar-2015
 * \copyright 2015 wisol technologie GmbH
 *
 * Overview
 * ========
 *
 * Shows how to store callbacks in a `std::vector`.
 *
 * Here we use a single type of callback. This limits what we can store in the
 * vector, but is enough in many cases. Also note that known arguments can be
 * bound and are not part of the type.
 */

#include <vector>
#include <functional>
#include <iostream>

namespace {

using cb1_t = std::function<void()>;
using callbacks_t = std::vector<cb1_t>;

callbacks_t callbacks;

void foo1()
{
	std::cout << "foo1 is called\n";
}

void foo2(int i)
{
	std::cout << "foo2 is called with: " << i << "\n";
}

} // end anonymous namespace

int main()
{
	// Bind a free function.
	cb1_t f1 = std::bind(&foo1);
	callbacks.push_back(f1);

	// Bind a free function with an int argument.
	// Here the argument is statically known.
	cb1_t f2 = std::bind(&foo2, 5);
	callbacks.push_back(f2);

	// Bind a free function with an int argument.
	// Here the argument is bound and can be changed at runtime.
	int n = 15;
	cb1_t f3 = std::bind(&foo2, std::cref(n));
	callbacks.push_back(f3);

	// Invoke the functions
	for(auto& fun : callbacks) {
		fun();
	}

	return 0;
}
