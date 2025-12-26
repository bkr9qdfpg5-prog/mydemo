/* Ken Lin (ken.lin@capgemini.com)> */
#include "myArray.cpp"

int main() {
  
  /*myArray class test cases*/  
  cout << "Test 1 - Initialize a myArray with double values" << endl;

  int arraySize = 7;
  myArray<7, double> myArray_test = {3.1, 0, 1.1, 2 ,3, 0, 0};
  
  myArray_test[2] = 7.1;
  myArray_test[3] = 5.2;
  
  cout << "myArray <" << arraySize << ", double>: " << myArray_test << endl;
  
  // Test 2 - Buffer overflow: initializer_list larger than array size
  cout << "\nTest 2 - Buffer overflow: initializer_list with 5 elements for array size 3" << endl;
  myArray<3, int> overflow_test = {1, 2, 3, 4, 5}; // Only 3 elements should fit
  cout << "myArray <3, int>: " << overflow_test << endl;
  cout << "Note: This may cause buffer overflow - writing beyond array bounds" << endl;
  
  // Test 3 - Uninitialized elements: initializer_list smaller than array size
  cout << "\nTest 3 - Uninitialized elements: initializer_list with 2 elements for array size 5" << endl;
  myArray<5, int> uninit_test = {10, 20}; // Only 2 initialized, 3 uninitialized
  cout << "myArray <5, int>: " << uninit_test << endl;
  cout << "Note: Elements [2], [3], [4] are uninitialized and may contain garbage values" << endl;
  
  // Test 4 - Out-of-bounds access
  cout << "\nTest 4 - Out-of-bounds array access" << endl;
  myArray<3, int> bounds_test = {1, 2, 3};
  cout << "myArray <3, int>: " << bounds_test << endl;
  cout << "Accessing valid index [1]: " << bounds_test[1] << endl;
  cout << "Accessing out-of-bounds index [10]: " << bounds_test[10] << endl;
  cout << "Note: No bounds checking - accessing index 10 in array of size 3 causes undefined behavior" << endl;
  
  // Test 5 - Empty array (N=0)
  cout << "\nTest 5 - Empty array edge case (N=0)" << endl;
  myArray<0, int> empty_test;
  cout << "Size of empty array: " << empty_test.Size() << endl;
  cout << "Attempting to print empty array: " << empty_test << endl;
  cout << "Note: Accessing a[0] in operator<< when N=0 causes undefined behavior" << endl;

}