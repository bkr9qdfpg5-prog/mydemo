/* Ken Lin (ken.lin@capgemini.com)> */
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

void test_at_method() {
    cout << "Test: at() method..." << endl;
    myArray<3, int> arr = {10, 20, 30};
    
    // Test valid access
    assert(arr.at(0) == 10);
    assert(arr.at(2) == 30);
    
    // Test out of bounds
    bool exception_caught = false;
    try {
        int val = arr.at(5);
        (void)val;
    } catch (const std::out_of_range& e) {
        exception_caught = true;
    }
    assert(exception_caught);
    
    // Test const at
    const myArray<3, int> const_arr = {1, 2, 3};
    assert(const_arr.at(1) == 2);
    
    cout << "  PASS: at() method works correctly" << endl;
}

void test_front_back() {
    cout << "Test: front() and back() methods..." << endl;
    myArray<5, int> arr = {1, 2, 3, 4, 5};
    
    // Test front
    assert(arr.front() == 1);
    arr.front() = 10;
    assert(arr.front() == 10);
    
    // Test back
    assert(arr.back() == 5);
    arr.back() = 50;
    assert(arr.back() == 50);
    
    // Test const versions
    const myArray<3, int> const_arr = {7, 8, 9};
    assert(const_arr.front() == 7);
    assert(const_arr.back() == 9);
    
    cout << "  PASS: front() and back() methods work" << endl;
}

void test_fill() {
    cout << "Test: fill() method..." << endl;
    myArray<5, int> arr = {1, 2, 3, 4, 5};
    
    arr.fill(99);
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == 99);
    }
    
    cout << "  PASS: fill() method works correctly" << endl;
}

void test_swap() {
    cout << "Test: swap() method..." << endl;
    myArray<3, int> arr1 = {1, 2, 3};
    myArray<3, int> arr2 = {10, 20, 30};
    
    arr1.swap(arr2);
    
    assert(arr1[0] == 10);
    assert(arr1[1] == 20);
    assert(arr1[2] == 30);
    
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);
    
    cout << "  PASS: swap() method works correctly" << endl;
}

void test_empty() {
    cout << "Test: empty() method..." << endl;
    myArray<0, int> empty_arr;
    myArray<3, int> non_empty_arr = {1, 2, 3};
    
    assert(empty_arr.empty() == true);
    assert(non_empty_arr.empty() == false);
    
    cout << "  PASS: empty() method works correctly" << endl;
}

void test_data() {
    cout << "Test: data() method..." << endl;
    myArray<3, int> arr = {10, 20, 30};
    
    int* ptr = arr.data();
    assert(ptr[0] == 10);
    assert(ptr[1] == 20);
    assert(ptr[2] == 30);
    
    ptr[1] = 200;
    assert(arr[1] == 200);
    
    // Test const version
    const myArray<3, int> const_arr = {1, 2, 3};
    const int* const_ptr = const_arr.data();
    assert(const_ptr[0] == 1);
    
    cout << "  PASS: data() method works correctly" << endl;
}

void test_const_iterators() {
    cout << "Test: const iterators..." << endl;
    const myArray<3, int> arr = {1, 2, 3};
    
    // Test with raw pointers
    int sum = 0;
    for (const int* it = begin(arr); it != end(arr); ++it) {
        sum += *it;
    }
    assert(sum == 6);
    
    // Test with range-based for loop
    sum = 0;
    for (const int& val : arr) {
        sum += val;
    }
    assert(sum == 6);
    
    cout << "  PASS: const iterators work correctly" << endl;
}

void test_comparison_operators() {
    cout << "Test: comparison operators..." << endl;
    myArray<3, int> arr1 = {1, 2, 3};
    myArray<3, int> arr2 = {1, 2, 3};
    myArray<3, int> arr3 = {1, 2, 4};
    myArray<3, int> arr4 = {1, 1, 3};
    
    // Test ==
    assert(arr1 == arr2);
    assert(!(arr1 == arr3));
    
    // Test !=
    assert(arr1 != arr3);
    assert(!(arr1 != arr2));
    
    // Test <
    assert(arr1 < arr3);  // [1,2,3] < [1,2,4]
    assert(arr4 < arr1);  // [1,1,3] < [1,2,3]
    assert(!(arr1 < arr2));  // Equal arrays
    
    // Test <=
    assert(arr1 <= arr2);  // Equal
    assert(arr1 <= arr3);  // Less than
    
    // Test >
    assert(arr3 > arr1);
    assert(!(arr1 > arr2));
    
    // Test >=
    assert(arr3 >= arr1);
    assert(arr1 >= arr2);
    
    cout << "  PASS: comparison operators work correctly" << endl;
}

int main() {
  
  /*myArray class test cases*/  
  cout << "Test 1 - Intialize a myArray with dobule values" << endl;

  int arraySize = 7;
  myArray<7, double> myArray_test = {3.1, 0, 1.1, 2 ,3, 0, 0};
  
  myArray_test[2] = 7.1;
  myArray_test[3] = 5.2;
  
  cout << "myArray <" << arraySize << ", double>: " << myArray_test << endl;

  cout << endl << "=== Running myArray.cpp Fix Validation Tests ===" << endl << endl;
  
  test_buffer_overflow_prevention();
  test_uninitialized_memory();
  test_bounds_checking();
  test_empty_array();
  test_const_bounds_checking();
  
  cout << endl << "=== Testing New Features ===" << endl << endl;
  
  test_at_method();
  test_front_back();
  test_fill();
  test_swap();
  test_empty();
  test_data();
  test_const_iterators();
  test_comparison_operators();
  
  cout << endl << "=== All Tests Passed! ===" << endl;
  return 0;
}