#ifndef TEST_ASSERT_H
#define TEST_ASSERT_H 1

#include <iostream>
#include <cinttypes>
#include <cmath>

#define MAX_ULP_DIFFERENCE 5

#include <cassert>

// Macro to assert that two values relate to each other in the manner specified by the operation parameter
// This macro should not be used directly, instead, use the Assert... functions below
// Example Usage: 	MAKE_ASSERTION(2, <=, 1); // This fails the test. For example purposes, this is on line #210 in file Class.cpp
// Example Output:	Assertion Failed @ Class.cpp:210 - var1 <= var2
//			(2 <= 1)
#define MAKE_ASSERTION(op1, operation, op2) \
    assert(((op1) operation (op2)) \
            || !(std::cout << "Assertion Failed @ " << __FILE__ << ":" << __LINE__ << " - " << #op1 << " " << #operation << " " << #op2 \
                           << "\n(" << op1 << #operation << op2 << ")\n"))

// Please don't use this union. It should only be used internally by tests
union Float_t {
    Float_t(float val) : f(val) { }
    bool negative() { return f < 0.0f; }

    int32_t i;
    float f;
};

// Please don't use this union. It should only be used internally by tests
union Double_t {
    Double_t(double val) : d(val) { }
    bool negative() { return d < 0.0f; }

    int64_t i;
    double d;
};

/**
 *  METHOD NAME: clid::AssertEquals
 *
 *  @FullDescription
 *  Assert that two different things are equal, and halt, logging the error, if the assertion
 *  fails.
 *
 *  @tparam T   Type of things to be compared. Must provide an operator==
 *
 *  @param  arg1    First thing to check for equality
 *  @param  arg2    Second thing to check for equality
 */
template<typename T>
void AssertEquals( T arg1, T arg2 )
{
    MAKE_ASSERTION( arg1, ==, arg2 );
}

/**
 * Assert that two floating point values are equivalent. This checks equivalency using the 
 * difference in the least significant bits of the float method
 * @param [in] arg1	First value to check for equivalence
 * @param [in] arg2	Value to check against arg1
 */
template<>
void AssertEquals(float arg1, float arg2)
{
    Float_t f1(arg1);
    Float_t f2(arg2);

    if(f1.negative() != f2.negative()) {
        if(std::fabs(f1.f) == std::fabs(f2.f))
            return;
        MAKE_ASSERTION(f1.f, ==, f2.f);
    }

    int ulpDiff = std::abs(f1.i - f2.i);
    MAKE_ASSERTION(ulpDiff, <=, MAX_ULP_DIFFERENCE);
}

/**
 * Assert that two floating point values are equivalent. This checks equivalency using the 
 * difference in the least significant bits of the float method
 * @param [in] arg1	First value to check for equivalence
 * @param [in] arg2	Value to check against arg1
 */
template<>
void AssertEquals(double arg1, double arg2)
{
    Double_t d1(arg1);
    Double_t d2(arg2);

    if(d1.negative() != d2.negative()) {
	// If they have different signs, but are equal (?) then don't assert
        if(std::fabs(d1.d) == std::fabs(d2.d))
            return;
	// Values have different signedness, test fails, use MAKE_ASSERTION to print the message
        MAKE_ASSERTION(d1.d, ==, d2.d);
    }

    // Get the difference between the float representations in ints to check units of least precisions
    int ulpDiff = std::abs(d1.i - d2.i);
    MAKE_ASSERTION(ulpDiff, <=, MAX_ULP_DIFFERENCE);
}

#endif // TEST_ASSERT_H
