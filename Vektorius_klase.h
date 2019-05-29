#ifndef VEKTORIUS_KLASE_H
#define VEKTORIUS_KLASE_H

#include "Vektorius_Iterator.h"
#include <iostream>
#include <exception>
#include <algorithm>
#include <stdexcept>

template <class T>
class Vector{
private:
 int sz, cap;
 T* elem;
public:
	
	Vector() : elem(nullptr), sz(), cap() {}
    explicit Vector(int size);
    Vector(int size, int val);
    Vector(const std::initializer_list<T> & v);
    Vector(const Vector<T> & v);
    Vector(Vector<T> && v);
	~Vector() {
	 delete[] elem;
	  } 

Vector & operator=(const Vector<T> &v); //copy assign
Vector& operator=(Vector&& v); // move assign

 const T& operator[](int i) const { return elem[i]; } 
 T& operator[](int i) { return elem[i]; }
  
  bool operator==(const Vector<T> & v) const;
    bool operator!=(const Vector<T> & v) const;
  bool operator<(const Vector<T> & v) const;
    bool operator<=(const Vector<T> & v) const;
  bool operator>(const Vector<T> & v) const;
    bool operator>=(const Vector<T> & v) const;
  
  
int size() const { return sz; } 
int capacity() const { return cap;}
bool empty() const;
void swap(T& x, T& y);
void swap(Vector &v) noexcept;
void resize(int kiek);
T & front();
const T & front() const;
const T & back() const;
T & back();
void push_back(T & v);
const Vector push_back(T const& v);
void pop_back();
void reserve(int kiek);
size_t max_size() const;
void shrink_to_fit();
void assign(int kiek, const T &value);
void clear();
const T at(int pos) const;

friend class Iterator<T>;
typedef class Iterator<T> iterator;
Iterator<T> end();
Iterator<T> begin(); 
Iterator<T> rbegin();
Iterator<T> rend();
Iterator<T> end() const;
Iterator<T> begin() const; 
Iterator<T> rbegin() const; 
Iterator<T> rend() const; 

Iterator<T> erase(Iterator<T> pos);
Iterator<T> erase(Iterator<T> first, Iterator<T> last);
Iterator<T> insert(Iterator<T> pos, const T & value);
void insert(iterator pos, int count, const T & value);
};

template<class T>
Vector<T>::Vector(int size) : sz(size), cap(size) {
    elem = new T[size];
}

template<class T>
Vector<T>::Vector(int size, int val) : sz(size), cap(size){
    elem = new T[sz];

    for (int i = 0; i < sz; i++)
        elem[i] = val;
}

template<class T>
Vector<T>::Vector(const std::initializer_list<T> &v) : sz(v.size()), cap(v.size()) {
    elem = new T[v.size()];

    for (int i = 0; i < v.size(); i++)
        elem[i] = *(v.begin() + i);
}

template<class T>
Vector<T>::Vector(const Vector<T> &v) : sz(v.sz), cap(v.cap) {
    elem = new T[cap];

    for (int i = 0; i < sz; i++)
        elem[i] = v.elem[i];
}

template<class T>
Vector<T>::Vector(Vector<T> &&v) : sz(v.sz), cap(v.cap) {
//	std::cout << "move" << std::endl;
    elem = v.elem;
    v.elem = nullptr;
    v.sz = 0;
    v.cap = 0;
}


template <class T>
Vector<T> &Vector<T>::operator=(const Vector<T> &v) { 
    Vector<T> c(v);
    c.swap(*this);
    return *this;
}

template<class T>
void Vector<T>::swap(Vector &v) noexcept {
    using std::swap;
    swap(elem, v.elem);
    swap(sz, v.sz);
    swap(cap,v.cap);
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector&& v) {
    Vector<T> copy(v);
    copy.swap(*this);
    return *this;
 }
 
template<class T>
bool Vector<T>::operator==(const Vector<T> &v) const {
    if (sz == v.sz && cap == v.cap) {
        for (int i = 0; i < sz; i++)
            if (elem[i] != v.elem[i])
                return false;
        return true;
    }
    return false;

}

template<class T>
bool Vector<T>::operator!=(const Vector<T> &v) const {
    return !operator==(v);
}

template<class T>
bool Vector<T>::operator<(const Vector<T> &v) const {
    if(sz < v.sz && cap < v.cap){
    	for (int i = 0; i < sz; i++)
            if (elem[i] < v.elem[i])
                return false;
        return true;
	}
	return false;

}

template<class T>
bool Vector<T>::operator<=(const Vector<T> &v) const {
    if(sz <= v.sz && cap <= v.cap){
    	for (int i = 0; i < sz; i++)
            if (elem[i] <= v.elem[i])
                return false;
        return true;
	}
	return false;

}

template<class T>
bool Vector<T>::operator>(const Vector<T> &v) const {
    if(sz > v.sz && cap > v.cap){
    	for (int i = 0; i < sz; i++)
            if (elem[i] > v.elem[i])
                return false;
        return true;
	}
	return false;

}

template<class T>
bool Vector<T>::operator>=(const Vector<T> &v) const {
    if(sz >= v.sz && cap >= v.cap){
    	for (int i = 0; i < sz; i++)
            if (elem[i] >= v.elem[i])
                return false;
        return true;
	}
	return false;

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
Iterator<T> Vector<T>::end() {
    Iterator<T> temp(elem+sz);
    return temp;
}

template<class T>
Iterator<T> Vector<T>::begin() {
    Iterator<T> temp(elem);
    return temp;
}

template<class T>
Iterator<T> Vector<T>::rbegin(){
    Iterator<T> temp(elem+sz-1);
    return temp;
}

template<class T>
Iterator<T> Vector<T>::rend(){
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
void Vector<T>::push_back(T & v) {
    if (sz == cap) {
		if(cap == 0) cap = cap+1;
       else cap *=2;
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
const Vector<T> Vector<T>::push_back(T const& v) {
    if (sz == cap) {
		if(cap == 0) cap = cap+1;
       else cap *=2;
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
      return *this;
}



template<class T>
void Vector<T>::pop_back() {
    if (sz > 0)
        sz--;
}
template<class T>
void Vector<T>::reserve(int kiek){
	if(kiek > cap){
		T* temp = new T[kiek];
		for(int i = 0; i < sz; i++){
			temp[i] = elem[i];
		}
		delete [] elem;
		elem = temp;
		cap = kiek;
		
	}
	if(kiek > max_size()) throw std::out_of_range("JEff");
	
	
	
}

template <class T>
size_t Vector<T>::max_size() const {
    return std::numeric_limits<size_t>::max();
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
template <class T>
void Vector<T>::clear(){
 delete []elem;
 sz =0;
 cap = 2;
 elem = new T[cap];
}

template<class T>
const T Vector<T>::at(int pos) const{
   if(!(pos<sz)) 
		throw std::out_of_range("out of range");
  else return *(elem+pos);
}


		
#endif
