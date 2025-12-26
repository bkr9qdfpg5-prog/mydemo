/* Ken Lin (ken.lin@capgemini.com)> */
#include <iostream>
using namespace std;

template <int N, typename T>
class myArray {
  public:
    myArray();
    myArray(initializer_list<T>);
    T& operator[](int i);
    T operator[](int i) const;
    int Size() const;
  private:
    T data[N];
};


template <int N, typename T>
T* begin(myArray<N,T>& a) {
    return &a[0];
}

template <int N, typename T>
T* end(myArray<N,T>& a) {
    return &a[N];
}

template <int N, typename T>
ostream&
operator<<(ostream& os, const myArray<N, T>& a) {
  os << "[" << a[0];
  for (int i = 1; i < a.Size(); i++) {
    os << ", " << a[i];
  }
  os << "]";
  return os;
}


template <int N, typename T>
myArray<N, T>::myArray() : data{} {
}

template <int N, typename T>
myArray<N,T>::myArray(initializer_list<T> l) : data{} {
  int i = 0;
  for(const T& t : l) {
      if (i >= N) break;
      data[i++] = t;
  }
}

template <int N, typename T>
T& myArray<N, T>::operator[](int i) {
  return data[i];
}

template <int N, typename T>
T myArray<N, T>::operator[](int i) const {
  return data[i];
}

template <int N, typename T>
int myArray<N, T>::Size() const {
    return N;
}
