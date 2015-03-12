/**
 * \file callback1.cc
 * \author Michael Egli
 * \date 08-Mar-2015
 * \copyright 2015 wisol technologie GmbH
 *
 * Overview
 * ========
 *
 * Shows how to use `std::function` as a callback.
 *
 * A nice property of `std::function` is that it can bind to anything callable.
 * Here we show how to call a free function, a member function (method), and a
 * lambda type.
 */

#include <functional>
#include <iostream>

namespace {

using cb1_t = std::function<void()>;
using cb2_t = std::function<void(int)>;

void foo1()
{
	std::cout << "foo1 is called\n";
}

void foo2(int i)
{
	std::cout << "foo2 is called with: " << i << "\n";
}

struct S {
	void foo3()
	{
		std::cout << "foo3 is called.\n";
	}
};

} // end anonymous namespace

int main()
{
	// Bind a free function.
	cb1_t f1 = std::bind(&foo1);
	// Invoke the function foo1.
	f1();

	// Bind a free function with an int argument.
	// Note that the argument can be specified with bind directly.
	cb1_t f2 = std::bind(&foo2, 5);
	// Invoke the function foo2.
	f2();

	// Bind a function with a placeholder.
	cb2_t f3 = std::bind(&foo2, std::placeholders::_1);
	// Invoke the function with an argument.
	f3(42);

	// Bind a member function.
	S s;
	cb1_t	f4 = std::bind(&S::foo3, &s);
	// Invoke the method foo3.
	f4();

	// Bind a lambda.
	cb1_t f5 = std::bind([] { std::cout << "lambda is called\n"; });
	f5();

	return 0;
}
