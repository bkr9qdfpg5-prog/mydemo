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

// ===== New Test Cases for Built-in Data Types =====

void test_char_type() {
    cout << "Test: char data type..." << endl;
    myArray<5, char> arr = {'H', 'e', 'l', 'l', 'o'};
    
    assert(arr[0] == 'H');
    assert(arr[1] == 'e');
    assert(arr[4] == 'o');
    assert(arr.Size() == 5);
    
    arr[1] = 'a';
    assert(arr[1] == 'a');
    
    cout << "  PASS: char type works correctly, array = " << arr << endl;
}

void test_bool_type() {
    cout << "Test: bool data type..." << endl;
    myArray<4, bool> arr = {true, false, true, false};
    
    assert(arr[0] == true);
    assert(arr[1] == false);
    assert(arr[2] == true);
    assert(arr[3] == false);
    assert(arr.Size() == 4);
    
    arr[1] = true;
    assert(arr[1] == true);
    
    cout << "  PASS: bool type works correctly, array = " << arr << endl;
}

void test_float_type() {
    cout << "Test: float data type..." << endl;
    myArray<4, float> arr = {1.5f, 2.7f, 3.14f, 4.0f};
    
    assert(arr[0] == 1.5f);
    assert(arr[1] == 2.7f);
    assert(arr[2] == 3.14f);
    assert(arr.Size() == 4);
    
    arr[3] = 5.5f;
    assert(arr[3] == 5.5f);
    
    cout << "  PASS: float type works correctly, array = " << arr << endl;
}

void test_long_type() {
    cout << "Test: long data type..." << endl;
    myArray<5, long> arr = {100L, 200L, 300L, 400L, 500L};
    
    assert(arr[0] == 100L);
    assert(arr[2] == 300L);
    assert(arr[4] == 500L);
    assert(arr.Size() == 5);
    
    arr[2] = 999L;
    assert(arr[2] == 999L);
    
    cout << "  PASS: long type works correctly, array = " << arr << endl;
}

// ===== Self-defined Class for Testing =====

class Point {
  public:
    int x, y;
    
    Point() : x(0), y(0) {}
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

void test_custom_class() {
    cout << "Test: Custom class (Point)..." << endl;
    myArray<3, Point> arr = {Point(1, 2), Point(3, 4), Point(5, 6)};
    
    assert(arr[0] == Point(1, 2));
    assert(arr[1] == Point(3, 4));
    assert(arr[2] == Point(5, 6));
    assert(arr.Size() == 3);
    
    arr[1] = Point(10, 20);
    assert(arr[1] == Point(10, 20));
    
    cout << "  PASS: Custom class works correctly, array = " << arr << endl;
}

void test_custom_class_default_initialization() {
    cout << "Test: Custom class default initialization..." << endl;
    myArray<4, Point> arr = {Point(1, 1), Point(2, 2)};
    
    // First two elements should be initialized with provided values
    assert(arr[0] == Point(1, 1));
    assert(arr[1] == Point(2, 2));
    
    // Remaining elements should be default-initialized
    assert(arr[2] == Point(0, 0));
    assert(arr[3] == Point(0, 0));
    
    cout << "  PASS: Custom class default initialization works, array = " << arr << endl;
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
  
  cout << endl << "=== Running Built-in Data Type Tests ===" << endl << endl;
  
  test_char_type();
  test_bool_type();
  test_float_type();
  test_long_type();
  
  cout << endl << "=== Running Custom Class Tests ===" << endl << endl;
  
  test_custom_class();
  test_custom_class_default_initialization();
  
  cout << endl << "=== All Tests Passed! ===" << endl;
  return 0;
}