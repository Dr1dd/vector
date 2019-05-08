#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

template<class T>
class Iterator {
private:
    T * pointer;
public:
    Iterator(): pointer(nullptr){};
    Iterator(T * item) : pointer(item){}

    Iterator<T> & operator=(const Iterator<T> & iter) = default;
    ~Iterator() = default;

    Iterator operator+(int add);
    Iterator operator-(int sub);

    bool operator!=(const Iterator<T> & iter) const;
    bool operator==(const Iterator<T> & iter) const;
    bool operator<(const Iterator<T> & iter) const;
    bool operator<=(const Iterator<T> & iter) const;
    bool operator>(const Iterator<T> & iter) const;
    bool operator>=(const Iterator<T> & iter) const;

    Iterator & operator++();
    Iterator operator++(int);
    Iterator & operator--();
    Iterator operator--(int);

    T & operator[](int n);
    T & operator*();
};

template<class T>
bool Iterator<T>::operator==(const Iterator<T> & iter) const {
    return pointer == iter.pointer;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T> & iter) const {
    return !(pointer == iter.pointer);
}

template<class T>
bool Iterator<T>::operator<(const Iterator<T> & iter) const{
    return pointer < iter.pointer;
}

template<class T>
bool Iterator<T>::operator<=(const Iterator<T> & iter) const{
    return pointer <= iter.pointer;
}

template<class T>
bool Iterator<T>::operator>(const Iterator<T> &iter) const {
    return pointer > iter.pointer;
}

template<class T>
bool Iterator<T>::operator>=(const Iterator<T> &iter) const {
    return pointer >= iter.pointer;
}

template<class T>
T & Iterator<T>::operator[](int n) {
    return *(pointer + n);
}

template<class T>
Iterator<T> Iterator<T>::operator+(int add) {
    Iterator<T> temp(pointer + add);
    return temp;
}

template<class T>
Iterator<T> Iterator<T>::operator-(int sub){
    Iterator<T> temp(pointer - sub);
    return temp;
}

template<class T>
Iterator<T> operator+(int add, const Iterator<T> & iter){
    return iter + add;
}

template<class T>
Iterator<T> & Iterator<T>::operator++(){
    pointer++;
    return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator++(int){
    Iterator<T> temp = *this;
    pointer++;
    return temp;
}

template<class T>
Iterator<T> & Iterator<T>::operator--(){
    pointer--;
    return *this;
}

template<class T>
Iterator<T> Iterator<T>::operator--(int){
    Iterator<T> temp = *this;
    pointer--;
    return temp;
}

template<class T>
T & Iterator<T>::operator*(){
    return *pointer;
}
#endif
