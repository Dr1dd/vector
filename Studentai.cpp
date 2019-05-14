#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <random>
#include <fstream>
#include "funkcijos.h"
#include "Vektorius_klase.h"
#include "Vektorius_Iterator.h"

void Studentai::setegzRez(double egzGalutinis){
	egzGal = egzGalutinis;
}
void Studentai::setMediana(double med){
	mediana = med;
}
void Studentai::setND(double ND_){
	ND.push_back(ND_);
}
Vector<double>& Studentai::getND(){
	return ND;
}
double Studentai::getND(int nr){
	return ND[nr];
}
bool operator== (Studentai &a, Studentai &b){
			 return a.vardas()==b.vardas() && a.pavarde() == b.pavarde()&& a.getEgzRez() == b.getEgzRez();
}
bool operator!= (Studentai &a, Studentai &b){
			 return !(a==b);
}
