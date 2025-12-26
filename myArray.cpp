/* Ken Lin (ken.lin@capgemini.com)> */
#include <iostream>
#include <stdexcept>
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
  os << "[";
  if (N > 0) {
    os << a[0];
    for (int i = 1; i < a.Size(); i++) {
      os << ", " << a[i];
    }
  }
  os << "]";
  return os;
}


template <int N, typename T>
myArray<N, T>::myArray() {
    for (T& v : data) {
        v = T();
    }
}

template <int N, typename T>
myArray<N,T>::myArray(initializer_list<T> l) {
  int i = 0;
  for(T t : l) {
      if (i >= N) break;  // Prevent buffer overflow
      data[i++] = t;
  }
  // Initialize remaining elements
  for (; i < N; i++) {
      data[i] = T();
  }
}

template <int N, typename T>
T& myArray<N, T>::operator[](int i) {
  if (i < 0 || i >= N) {
    throw std::out_of_range("Index out of bounds");
  }
  return data[i];
}

template <int N, typename T>
T myArray<N, T>::operator[](int i) const {
  if (i < 0 || i >= N) {
    throw std::out_of_range("Index out of bounds");
  }
  return data[i];
}

template <int N, typename T>
int myArray<N, T>::Size() const {
    return N;
}
