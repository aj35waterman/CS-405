// NumericOverflows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>     // std::cout
#include <limits>       // std::numeric_limits

/// <summary>
/// Template function to abstract away the logic of:
///   start + (increment * steps)
/// </summary>
/// <typeparam name="T">A type that with basic math functions</typeparam>
/// <param name="start">The number to start with</param>
/// <param name="increment">How much to add each step</param>
/// <param name="steps">The number of steps to iterate</param>
/// <returns>start + (increment * steps)</returns>
bool status = false; // This variable is used to track whether an overflow or underflow was detected in the add_numbers and subtract_numbers functions. It is set to true when an overflow or underflow is detected and is used in the test_overflow and test_underflow functions to inform the user of the result.
template <typename T>
T add_numbers(T const& start, T const& increment, unsigned long int const& steps)
{
    T result = start;
	T max = std::numeric_limits<T>::max(); // Get the maximum value for type T
	T min = std::numeric_limits<T>::min(); // Get the minimum value for type T

    for (unsigned long int i = 0; i < steps; ++i)
    { 
        // TODO: The add_numbers template function will overflow in the second method call
    //        You need to change the add_numbers method to:
    //        1. Detect when an overflow will happen
    //        2. Prevent it from happening
    //        3. Return the correct value when no overflow happened or
    //        4. Return something to tell test_overflow the addition failed
    //        NOTE: The add_numbers method must remain a template in the NumericFunctions header.
        if (increment >= 0 && result > max - increment) // If increment is positive and adding it would exceed the maximum value for type T, we know an overflow would occur.
        {

            status = true;
            return result;
        }
		if (increment < 0 && result < min - increment) // If increment is negative and adding it would be less than the minimum value for type T, we know an overflow would occur.
        { 
			status = true;
            return result;
        }
        result += increment; // If no overflow would occur, we can safely add the increment to the result.
    }
	return result;
        
}

/// <summary>
/// Template function to abstract away the logic of:
///   start - (increment * steps)
/// </summary>
/// <typeparam name="T">A type that with basic math functions</typeparam>
/// <param name="start">The number to start with</param>
/// <param name="increment">How much to subtract each step</param>
/// <param name="steps">The number of steps to iterate</param>
/// <returns>start - (increment * steps)</returns>

template <typename T>
T subtract_numbers(T const& start, T const& decrement, unsigned long int const& steps)
{
    T result = start;
    T max = std::numeric_limits<T>::max(); // Get the maximum value for type T
    T min = std::numeric_limits<T>::min(); // Get the minimum value for type T

    for (unsigned long int i = 0; i < steps; ++i)
        // TODO: The subtract_numbers template function will underflow in the second method call
    //        You need to change the subtract_numbers method to:
    //        1. Detect when an underflow will happen
    //        2. Prevent it from happening
    //        3. Return the correct value when no underflow happened or
    //        4. Return something to tell test_underflow the subtraction failed
    //        NOTE: The subtract_numbers method must remain a template in the NumericFunctions header.
    {
        if (decrement > 0 && result < decrement)
        {
            status = true;
            return result;
		}
        if (decrement < 0 && result > max +decrement)
        {
            status = true;
            return result;
        }
        result -= decrement;
	}
	return result;
}



//  NOTE:
//    You will see the unary ('+') operator used in front of the variables in the test_XXX methods.
//    This forces the output to be a number for cases where cout would assume it is a character. 

template <typename T>
void test_overflow()
{


    //       You need to change the test_overflow method to:
    //        1. Detect when an add_numbers failed
    //        2. Inform the user the overflow happened
    //        3. A successful result displays the same result as before you changed the method
    //        NOTE: You cannot change anything between START / END DO NOT CHANGE
    //              The test_overflow method must remain a template in the NumericOverflows source file
    //
    //  There are more than one possible solution to this problem. 
    //  The solution must work for all of the data types used to call test_overflow() in main().

    // START DO NOT CHANGE
    //  how many times will we iterate
    const unsigned long int steps = 5;
    // how much will we add each step (result should be: start + (increment * steps))
    const T increment = std::numeric_limits<T>::max() / steps;
    // whats our starting point
    const T start = 0;

    std::cout << "Overflow Test of Type = " << typeid(T).name() << std::endl;
    // END DO NOT CHANGE

    std::cout << "\tAdding Numbers Without Overflow (" << +start << ", " << +increment << ", " << steps << ") = ";
    T result = add_numbers<T>(start, increment, steps);
	if (status == false)
    {
		std::cout << +result << std::endl; // If no overflow was detected in the add_numbers function, we can safely output the result.
        
    }
    else
    {
		std::cout << "Overflow Detected!" << std::endl;// If an overflow was detected in the add_numbers function, we inform the user.
		status = false; // Reset the status variable for the next test.
    }

    std::cout << "\tAdding Numbers With Overflow (" << +start << ", " << +increment << ", " << (steps + 1) << ") = ";
    result = add_numbers<T>(start, increment, steps + 1);
	if (status == false)
    {
		std::cout << +result << std::endl; // If no overflow was detected in the add_numbers function, we can safely output the result.

        
    }
    else
    {
		std::cout << "Overflow Detected!" << std::endl; // If an overflow was detected in the add_numbers function, we inform the user.
		status = false; // Reset the status variable for the next test.
    }
}

template <typename T>
void test_underflow()
{

    //
    //        You need to change the test_underflow method to:
    //        1. Detect when an subtract_numbers failed
    //        2. Inform the user the underflow happened
    //        3. A successful result displays the same result as before you changed the method
    //        NOTE: You cannot change anything between START / END DO NOT CHANGE
    //              The test_underflow method must remain a template in the NumericOverflows source file
    //
    //  There are more than one possible solution to this problem. 
    //  The solution must work for all of the data types used to call test_overflow() in main().

    // START DO NOT CHANGE
    //  how many times will we iterate
    const unsigned long int steps = 5;
    // how much will we subtract each step (result should be: start - (increment * steps))
    const T decrement = std::numeric_limits<T>::max() / steps;
    // whats our starting point
    const T start = std::numeric_limits<T>::max();

    std::cout << "Underflow Test of Type = " << typeid(T).name() << std::endl;
    // END DO NOT CHANGE

    std::cout << "\tSubtracting Numbers Without Overflow (" << +start << ", " << +decrement << ", " << steps << ") = ";
    auto result = subtract_numbers<T>(start, decrement, steps);
    if (status == false)
    {
        std::cout << +result << std::endl; // If no underflow was detected in the subtract_numbers function, we can safely output the result.

    }
    else
    {
        std::cout << "Underflow Detected!" << std::endl; // If an underflow was detected in the subtract_numbers function, we inform the user.
        status = false; // Reset the status variable for the next test.
    }
    std::cout << "\tSubtracting Numbers With Overflow (" << +start << ", " << +decrement << ", " << (steps + 1) << ") = ";
    result = subtract_numbers<T>(start, decrement, steps + 1);
    if (status == false)
    {
        std::cout << +result << std::endl; // If no underflow was detected in the subtract_numbers function, we can safely output the result.

    }
    else
    {
        std::cout << "Underflow Detected!" << std::endl; // If an underflow was detected in the subtract_numbers function, we inform the user.
        status = false; // Reset the status variable for the next test.
    }
}

void do_overflow_tests(const std::string& star_line)
{
    std::cout << std::endl << star_line << std::endl;
    std::cout << "*** Running Overflow Tests ***" << std::endl;
    std::cout << star_line << std::endl;

    // Testing C++ primative times see: https://www.geeksforgeeks.org/c-data-types/
    // signed integers
    test_overflow<char>();
    test_overflow<wchar_t>();
    test_overflow<short int>();
    test_overflow<int>();
    test_overflow<long>();
    test_overflow<long long>();

    // unsigned integers
    test_overflow<unsigned char>();
    test_overflow<unsigned short int>();
    test_overflow<unsigned int>();
    test_overflow<unsigned long>();
    test_overflow<unsigned long long>();

    // real numbers
    test_overflow<float>();
    test_overflow<double>();
    test_overflow<long double>();
}

void do_underflow_tests(const std::string& star_line)
{
    std::cout << std::endl << star_line << std::endl;
    std::cout << "*** Running Undeflow Tests ***" << std::endl;
    std::cout << star_line << std::endl;

    // Testing C++ primative times see: https://www.geeksforgeeks.org/c-data-types/
    // signed integers
    test_underflow<char>();
    test_underflow<wchar_t>();
    test_underflow<short int>();
    test_underflow<int>();
    test_underflow<long>();
    test_underflow<long long>();

    // unsigned integers
    test_underflow<unsigned char>();
    test_underflow<unsigned short int>();
    test_underflow<unsigned int>();
    test_underflow<unsigned long>();
    test_underflow<unsigned long long>();

    // real numbers
    test_underflow<float>();
    test_underflow<double>();
    test_underflow<long double>();
}

/// <summary>
/// Entry point into the application
/// </summary>
/// <returns>0 when complete</returns>
int main()
{
    //  create a string of "*" to use in the console
    const std::string star_line = std::string(50, '*');

    std::cout << "Starting Numeric Underflow / Overflow Tests!" << std::endl;

    // run the overflow tests
    do_overflow_tests(star_line);

    // run the underflow tests
    do_underflow_tests(star_line);

    std::cout << std::endl << "All Numeric Underflow / Overflow Tests Complete!" << std::endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu