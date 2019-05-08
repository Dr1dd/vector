#ifndef VEKTORIUS_H
#define VEKTORIUS_H

#include "Vektorius_Iterator.h"


template <class T>
class Vector {
private:
 int sz, capacity;
 T* elem;
public:
	Vector() : sz(0), capacity(0), elem(new T[sz]) {}  // default konstruktorius
	Vector(int s) : sz{ s }, capacity{ s }, elem{ new T[sz] } { std::fill_n(elem, s, 0.0); }                            
	Vector(int s, T val);
	~Vector() { delete[] elem; } 
	Vector(const Vector& v) :elem{new T[v.sz]}, sz{v.sz}, capacity{v.capacity} {
 		for (int i=0; i!=sz; ++i) elem[i] = v.elem[i];
 	} //copy konstruktorius
Vector& operator=(const Vector& v); //copy assign
Vector(Vector&& v) : sz{v.sz}, capacity{v.capacity}, elem{v.elem} // move konstruktorius
{
 	v.elem = nullptr;
	v.sz = 0;
	v.capacity = 0;
}
Vector& operator=(Vector&& v); // move assign
  Vector(std::initializer_list<T> il) : sz{static_cast<int>(il.size())}, capacity(il.size()), elem{new double[il.size()]}
{
 std::copy(il.begin(),il.end(),elem); 
} //  {n.. n}
 const T& operator[](int i) const { return elem[i]; } 
  
int size() const { return sz; } 
int Capacity() const { return capacity;}
bool empty() const;
void swap(T& x, T& y);
void resize(int kiek);
T & front();
const T & front() const;
const T & back() const;
T & back();
void push_back(T v);
void pop_back();
void reserve(int kiek);
long int max_size();
void shrink_to_fit();

friend class Iterator<T>;
typedef class Iterator<T> iterator;
Iterator<T> end();
Iterator<T> begin(); 
Iterator<T> erase(Iterator<T> pos);
Iterator<T> erase(Iterator<T> first, Iterator<T> last);
Iterator<T> insert(Iterator<T> pos, const T & value);
void insert(iterator pos, int count, const T & value);
     };
#endif
