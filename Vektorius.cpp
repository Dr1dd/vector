#include <iostream>
#include <exception>
#include <algorithm>
#include <stdexcept>
#include "Vektorius.h"

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& v) { 
 if (&v == this) return *this;
 T* p = new T[v.sz];
 for (int i=0; i!=v.sz; ++i) 
 p[i] = v.elem[i];
 delete[] elem; 
 elem = p;
 sz = v.sz;
 capacity = v.capacity;
 return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector&& v) {
 if (&v == this)
 return *this;
 delete[] elem;
 elem = v.elem;
 capacity = v.capacity;
 sz = v.sz;
 v.elem = nullptr;
 v.sz = 0;
 v.capacity = 0;
 return *this;
 }
 
template <class T>
bool Vector<T>::empty() const {
    return (sz == 0);
}

template <class T>
void Vector<T>::swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
Iterator<T> Vector<T>::end(){
     Iterator<T> temp(elem + sz);
    return temp;
}

template<class T>
Iterator<T> Vector<T>::begin(){
    Iterator<T> temp(elem);
    return temp;
}

template<class T>
void Vector<T>::resize(int kiek) {
    if (kiek < 0)
        throw std::exception();
    else if (kiek < sz)
        sz = kiek;
    else if (kiek > capacity) {
        T *tempElem = new T[kiek];
        for (int i = 0; i < sz; i++)
            tempElem[i] = elem[i];
        delete[] elem;
        elem = tempElem;
    }
}

template<class T>
T &Vector<T>::front() {
    if (sz > 0)
        return elem[0];
    else
        throw std::exception();
}

template<class T>
const T &Vector<T>::front() const {
    if (sz > 0)
        return elem[0];
    else
        throw std::exception();
}

template<class T>
const T &Vector<T>::back() const {
    if (sz == 0)
        throw std::exception();

    return elem[sz - 1];
}

template<class T>
T &Vector<T>::back() {
    if (sz == 0)
        throw std::exception();

    return elem[sz - 1];
}

template<class T>
void Vector<T>::push_back(T v) {
    if (sz == capacity) {
        capacity *= 2 ;
        T *temp = new T[capacity];
        for (int i = 0; i < sz; i++)
            temp[i] = elem[i];

        temp[sz] = v;
        delete[] elem;
        elem = temp;
        sz++;
    } else {
        elem[sz] = v;
        sz++;
    }
}
template<class T>
void Vector<T>::pop_back() {
    if (sz > 0)
        sz--;
}
template<class T>
void Vector<T>::reserve(int kiek){
	if(kiek > 9223372036854775807)
		throw std::exception();
		
	if(kiek > capacity) capacity = kiek;
}
template<class T>
long int Vector<T>::max_size(){
	return 9223372036854775807;
}

template<class T>
Iterator<T> Vector<T>::erase(Iterator<T> pos) {
    int i = 0;
    auto it = (*this).begin();
    for (it; it != pos; it++, i++);
    for (auto it = pos + 1; it != (*this).end(); it++, i++)
        elem[i] = elem[i + 1];
    sz--;
    return pos;
}
template<class T>
Iterator<T> Vector<T>::erase(Iterator<T> first, Iterator<T> last){
    int i = 0;
    int temp = 0;
    auto it = (*this).begin();
    for (it; it != first; it++, i++);
    for (it = first; it != last; it++, temp++, i++);
    for (auto it = last; it != (*this).end(); it++, i++)
        elem[i - temp] = elem[i];
    sz -=  temp;
    return last;
}

template<class T>
Iterator<T> Vector<T>::insert(Iterator<T> pos, const T & value){
    int i = 0;

    if (capacity > sz){
        for(Iterator<T> it = elem + sz; it != pos; it--, i++)
            elem[sz - i] = elem[sz - i - 1];
        *pos = value;
        sz++;
    } else{
        T * temp = new T[sz + 1];
            for (Iterator<T> it = elem; it != pos; it++, i++)
             temp[i] = elem[i];
        temp[i] = value;
        i++;
            for (Iterator<T> it = elem + i + 1; it != elem + sz + 2; it++, i++)
            temp[i] = elem[i-1];
        delete [] elem;
        elem = temp;
        sz++;
        capacity = sz;
    }
}

template<class T>
void Vector<T>::insert(Iterator<T> pos, int count, const T & value){
    T * temp = new T[sz + count];
    int i = 0, j = 0;

    for (Iterator<T> it = elem; it != pos; it++, i++)
        temp[i] = elem[i];

    for (j; j < count; j++)
        temp[i+j] = value;

    for (Iterator<T> it = elem + i; it != elem + sz; it++, i++)
        temp[i+j] = elem[i];

    sz += count;
    capacity = sz;
    delete [] elem;
    elem = temp;
}
template<class T>
void Vector<T>::shrink_to_fit(){
	capacity = sz;
}
int main() {
 Vector<double> v1 {1, 2, 5, 1, 111, 252};
 Vector<double>::iterator as = v1.begin();

    std::cout << v1.Capacity() << " gg"<< std::endl;
 v1.push_back(8);
   std::cout << v1.Capacity() << " gg"<< std::endl;
  v1.push_back(8);
   std::cout << v1.Capacity() << " gg"<< std::endl;
for(int i = 0; i < v1.size(); i++){
	std::cout << v1[i] << std::endl;
}
v1.reserve(50.0);
std::cout << v1.Capacity() << " gg"<< std::endl;
v1.erase(v1.begin());
std::cout << v1.Capacity() << " gg"<< std::endl;
v1.shrink_to_fit();
 std::cout << v1.Capacity() << " gg"<< std::endl;

 return 0;
}
