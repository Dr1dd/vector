#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H
#include "Vektorius_klase.h"
#include "Vektorius_Iterator.h"

class Zmogus{
	public:
void setFname(std::string fname_){
	fname = fname_;
}
void setLname(std::string lname_){
	lname = lname_;
}
const std::string &vardas() const {
	return fname;
}
const std::string &pavarde() const {
	return lname;
}
virtual void setegzRez(double egzGalutinis) = 0;
	protected:
		std::string fname;
		std::string lname;
		double ugis;
		bool lytis; // pvz 1 - vyras 0 - moteris
};

class Studentai : public Zmogus{
	private:
		double egzGal;
		double mediana;
	 Vector<double> ND;	
	public:
		/**
		* Konstruktorius (paprastas)
		**/
		Studentai(){
			fname = " ";
			lname = " ";
			egzGal = 0;
			mediana = 0;
		}
		/**
		* Destruktorius
		**/
		~Studentai(){}
		/**
		* copy Konstruktorius
		**/
		Studentai(const  Studentai& a)
		{
			fname = a.fname;
			lname = a.lname;
			egzGal = a.egzGal;
			mediana = a.mediana;
			for(int i = 0; i < ND.size(); i++){
				ND[i] = a.ND[i];
			}
		}
		/**
		* copy assignment operatorius
		**/
		Studentai& operator=(const Studentai& a){
			if(&a == this) return *this;
			fname = a.fname;
			lname = a.lname;
			egzGal = a.egzGal;
			mediana = a.mediana;
			ND = a.ND;
			return *this;
		}
	void setegzRez(double egzGalutinis);
	void setMediana(double med);
	void setND(double ND_);
	Vector<double>& getND();
	double getND(int nr);
	double getEgzRez() const{ return egzGal; }
	double getMediana() const{ return mediana; }
	
		friend std::ostream& operator<<(std::ostream& out, const Studentai &a){
			out <<std::left << std::setw(14) << a.lname << std::left << std::setw(14) <<a.fname;
			return out;
		}
		friend std::istream& operator>>(std::istream& in, Studentai &a){
			in >> a.fname >> a.lname;
			return in;
		}
		friend bool operator> (Studentai &a, Studentai &b){
			 return a.egzGal > b.egzGal;
		} 
		friend bool operator<= (Studentai &a, Studentai &b){
			 return a.egzGal <= b.egzGal;
		}       
   		friend double operator/ (const Studentai& a, double n){
   			return a.egzGal / n;
		   }
		friend double& operator+=(double& b, const Studentai& a){
		for(auto &i : a.ND)	b = b + i;
			return b;
		}

};

 bool operator== (Studentai &a, Studentai &b);
 bool operator!= (Studentai &a, Studentai &b);
Studentai Informacija();
void Spausdinti(Vector<Studentai> Studentai, std::string tipas, int studSkaic);
void Spausdinti(Vector<Studentai> Studentai);
double Mediana(Studentai Stud, int n, int p);
std::string Tikrinti(std::string tekstas);
double TikrintiSkaicius(std::string tekstas);
void Skaitymas(Vector<Studentai> &StudentuInfo, std::string pav);
bool Lyginimas(const Studentai &a, const Studentai &b);
bool fileExists(const std::string& filename);
void Generuoti(int n);
void Generuoti(Vector<Studentai> StudentuInfo, int n);
void FailuIrasymas(Vector<Studentai> StudentuInfo, int n);
void VectorRusiavimas1strat(Vector<Studentai> StudentuInfo, int n);
void VectorRusiavimas2strat(Vector<Studentai> StudentuInfo, int n);
void vector();
bool maziau(Studentai &i);
void raskMinkstus(Vector<Studentai> &StudentuInfo, int n);
void iterpkKietus(Vector<Studentai> &StudentuInfo, int n);

#endif
