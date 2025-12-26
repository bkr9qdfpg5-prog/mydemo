/* Test file to validate fixes for myArray.cpp issues */
#include "myArray.cpp"
#include <cassert>

void test_buffer_overflow_prevention() {
    cout << "Test: Buffer overflow prevention..." << endl;
    // Test that initializer list larger than N doesn't overflow
    myArray<3, int> arr = {1, 2, 3, 4, 5};  // Should only take first 3 elements
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);
    cout << "  PASS: Buffer overflow prevented, array = " << arr << endl;
}

void test_uninitialized_memory() {
    cout << "Test: Uninitialized memory fix..." << endl;
    // Test that remaining elements are initialized when list < N
    myArray<5, int> arr = {1, 2};  // Should initialize remaining 3 elements to 0
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 0);
    assert(arr[3] == 0);
    assert(arr[4] == 0);
    cout << "  PASS: Remaining elements initialized, array = " << arr << endl;
}

void test_bounds_checking() {
    cout << "Test: Bounds checking..." << endl;
    myArray<3, int> arr = {1, 2, 3};
    
    // Test valid access
    assert(arr[0] == 1);
    assert(arr[2] == 3);
    
    // Test out of bounds access
    bool exception_caught = false;
    try {
        int val = arr[5];  // Out of bounds
        (void)val;
    } catch (const std::out_of_range& e) {
        exception_caught = true;
    }
    assert(exception_caught);
    
    exception_caught = false;
    try {
        int val = arr[-1];  // Negative index
        (void)val;
    } catch (const std::out_of_range& e) {
        exception_caught = true;
    }
    assert(exception_caught);
    
    cout << "  PASS: Bounds checking works correctly" << endl;
}

void test_empty_array() {
    cout << "Test: Empty array (N=0)..." << endl;
    // Test that operator<< handles N=0 without accessing a[0]
    myArray<0, int> arr;
    cout << "  Empty array output: " << arr << endl;
    cout << "  PASS: Empty array handled correctly" << endl;
}

void test_const_bounds_checking() {
    cout << "Test: Const operator[] bounds checking..." << endl;
    const myArray<3, int> arr = {1, 2, 3};
    
    bool exception_caught = false;
    try {
        int val = arr[5];  // Out of bounds
        (void)val;
    } catch (const std::out_of_range& e) {
        exception_caught = true;
    }
    assert(exception_caught);
    
    cout << "  PASS: Const operator[] bounds checking works" << endl;
}

int main() {
    cout << "=== Running myArray.cpp Fix Validation Tests ===" << endl << endl;
    
    test_buffer_overflow_prevention();
    test_uninitialized_memory();
    test_bounds_checking();
    test_empty_array();
    test_const_bounds_checking();
    
    cout << endl << "=== All Tests Passed! ===" << endl;
    return 0;
}
