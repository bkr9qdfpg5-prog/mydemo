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
    T& at(int i);
    T at(int i) const;
    T& front();
    T front() const;
    T& back();
    T back() const;
    void fill(const T& value);
    void swap(myArray<N, T>& other);
    bool empty() const;
    T* data();
    const T* data() const;
  private:
    T m_data[N];
};


template <int N, typename T>
T* begin(myArray<N,T>& a) {
    if (N == 0) return nullptr;
    return &a[0];
}

template <int N, typename T>
T* end(myArray<N,T>& a) {
    if (N == 0) return nullptr;
    return &a[N];
}

template <int N, typename T>
const T* begin(const myArray<N,T>& a) {
    if (N == 0) return nullptr;
    return a.data();
}

template <int N, typename T>
const T* end(const myArray<N,T>& a) {
    if (N == 0) return nullptr;
    return a.data() + N;
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
bool operator==(const myArray<N, T>& lhs, const myArray<N, T>& rhs) {
  for (int i = 0; i < N; i++) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <int N, typename T>
bool operator!=(const myArray<N, T>& lhs, const myArray<N, T>& rhs) {
  return !(lhs == rhs);
}

template <int N, typename T>
bool operator<(const myArray<N, T>& lhs, const myArray<N, T>& rhs) {
  for (int i = 0; i < N; i++) {
    if (lhs[i] < rhs[i]) return true;
    if (lhs[i] > rhs[i]) return false;
  }
  return false;  // Equal arrays are not less than
}

template <int N, typename T>
bool operator<=(const myArray<N, T>& lhs, const myArray<N, T>& rhs) {
  return !(rhs < lhs);
}

template <int N, typename T>
bool operator>(const myArray<N, T>& lhs, const myArray<N, T>& rhs) {
  return rhs < lhs;
}

template <int N, typename T>
bool operator>=(const myArray<N, T>& lhs, const myArray<N, T>& rhs) {
  return !(lhs < rhs);
}


template <int N, typename T>
myArray<N, T>::myArray() {
    for (T& v : m_data) {
        v = T();
    }
}

template <int N, typename T>
myArray<N,T>::myArray(initializer_list<T> l) {
  int i = 0;
  for(T t : l) {
      if (i >= N) break;  // Prevent buffer overflow
      m_data[i++] = t;
  }
  // Initialize remaining elements
  for (; i < N; i++) {
      m_data[i] = T();
  }
}

template <int N, typename T>
T& myArray<N, T>::operator[](int i) {
  if (i < 0 || i >= N) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[i];
}

template <int N, typename T>
T myArray<N, T>::operator[](int i) const {
  if (i < 0 || i >= N) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[i];
}

template <int N, typename T>
int myArray<N, T>::Size() const {
    return N;
}

template <int N, typename T>
T& myArray<N, T>::at(int i) {
  if (i < 0 || i >= N) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[i];
}

template <int N, typename T>
T myArray<N, T>::at(int i) const {
  if (i < 0 || i >= N) {
    throw std::out_of_range("Index out of bounds");
  }
  return m_data[i];
}

template <int N, typename T>
T& myArray<N, T>::front() {
  if (N == 0) {
    throw std::out_of_range("Array is empty");
  }
  return m_data[0];
}

template <int N, typename T>
T myArray<N, T>::front() const {
  if (N == 0) {
    throw std::out_of_range("Array is empty");
  }
  return m_data[0];
}

template <int N, typename T>
T& myArray<N, T>::back() {
  if (N == 0) {
    throw std::out_of_range("Array is empty");
  }
  return m_data[N - 1];
}

template <int N, typename T>
T myArray<N, T>::back() const {
  if (N == 0) {
    throw std::out_of_range("Array is empty");
  }
  return m_data[N - 1];
}

template <int N, typename T>
void myArray<N, T>::fill(const T& value) {
  for (int i = 0; i < N; i++) {
    m_data[i] = value;
  }
}

template <int N, typename T>
void myArray<N, T>::swap(myArray<N, T>& other) {
  for (int i = 0; i < N; i++) {
    T temp = m_data[i];
    m_data[i] = other.m_data[i];
    other.m_data[i] = temp;
  }
}

template <int N, typename T>
bool myArray<N, T>::empty() const {
  return N == 0;
}

template <int N, typename T>
T* myArray<N, T>::data() {
  return m_data;
}

template <int N, typename T>
const T* myArray<N, T>::data() const {
  return m_data;
}
