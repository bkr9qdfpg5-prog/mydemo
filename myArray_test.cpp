/* Ken Lin (ken.lin@capgemini.com)> */
#include "myArray.cpp"

int main() {
  
  /*myArray class test cases*/  
  cout << "Test 1 - Intialize a myArray with dobule values" << endl;

  int arraySize = 7;
  myArray<7, double> myArray_test = {3.1, 0, 1.1, 2 ,3, 0, 0};
  
  myArray_test[2] = 7.1;
  myArray_test[3] = 5.2;
  
  cout << "myArray <" << arraySize << ", double>: " << myArray_test << endl;

}