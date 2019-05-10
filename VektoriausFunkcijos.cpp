#include <iostream>
#include <exception>
#include <algorithm>
#include <stdexcept>
#include <vector>
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
 cap = v.cap;
 return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector&& v) {
 if (&v == this)
 return *this;
 delete[] elem;
 elem = v.elem;
 cap = v.cap;
 sz = v.sz;
 v.elem = nullptr;
 v.sz = 0;
 v.cap = 0;
 return *this;
 }
/*template<class T>
bool Vector<T>::operator==(const Vector<T> & a) const {
    return pointer == iter.pointer;
}

template<class T>
bool Vector<T>::operator!=(const Vector<T> & a) const {
    return !(pointer == iter.pointer);
}

template<class T>
bool Vector<T>::operator<(const Vector<T> & a) const{
    return pointer < iter.pointer;
}

template<class T>
bool Vector<T>::operator<=(const Vector<T> & a) const{
    return pointer <= iter.pointer;
}

template<class T>
bool Vector<T>::operator>(const Vector<T> &a) const {
    return pointer > iter.pointer;
}

template<class T>
bool Vector<T>::operator>=(const Vector<T> &a) const {
    return pointer >= iter.pointer;
}
 */
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
Iterator<T> Vector<T>::end() const{
     Iterator<T> temp(elem + sz);
    return temp;
}

template<class T>
Iterator<T> Vector<T>::begin() const{
    Iterator<T> temp(elem);
    return temp;
}
template<class T>
Iterator<T> Vector<T>::rbegin() const{
    Iterator<T> temp(elem+sz-1);
    return temp;
}
template<class T>
Iterator<T> Vector<T>::rend() const{
    Iterator<T> temp(elem-1);
    return temp;
}

template<class T>
void Vector<T>::resize(int kiek) {
    if (kiek < 0)
        throw std::exception();
    else if (kiek < sz)
        sz = kiek;
    else if (kiek > cap) {
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
    if (sz == cap) {
        cap *= 2 ;
        T *temp = new T[cap];
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
    if (sz > 0)	sz--;
}
template<class T>
void Vector<T>::reserve(int kiek){
	if(kiek > 9223372036854775807)
		throw std::exception();
		
	if(kiek > cap) cap = kiek;
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

    if (cap > sz){
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
        cap = sz;
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
    cap = sz;
    delete [] elem;
    elem = temp;
}
template<class T>
void Vector<T>::shrink_to_fit(){
	cap = sz;
}
template<class T>
void Vector<T>::assign(int kiek, const T &value) {
    if (kiek < 0)
        throw std::exception();

    if (kiek < cap)
        for (int i = 0; i < kiek; i++)
            elem[i] = value;
    else if (kiek >= cap) {
        delete[] elem;
        elem = new T[kiek + 5];
        cap = kiek + 5;
        sz = kiek;
        for (int i = 0; i < kiek; i++)
            elem[i] = value;
    }
}
template<class T>
void Vector<T>::clear(){
    if(elem!=NULL)
       {
          delete[] elem;
          sz=0;
       }

}

template<class T>
const T Vector<T>::at(int pos) const{
   if(!(pos<sz)) 
		throw std::out_of_range("out of range");
  else return *(elem+pos);
}

int main(){
	std::vector<double> a{1,2,3};
	Vector<double>b{1,2,3};
	Vector<double>c{1,2,3};
	//std::cout << b.at(2) << std::endl;
	//b.pop_back();
//	std::cout << b.at(1) << std::endl;
	auto d = std::distance(a.begin(), a.end());
	std::cout <<d;
	
}

