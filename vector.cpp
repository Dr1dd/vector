#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <random>
#include <cctype>
#include <fstream>
#include <cmath>
#include <stdexcept>
#include <chrono>
#include "funkcijos.h"
#include "Vektorius_klase.h"
#include "Vektorius_Iterator.h"

void vector(){
	std::string pradinis;
	std::string generate;
	std::cout << "Pasirinkta vector konteineriai" << std::endl;
    std::cout << "Skaitymas is failo ar ivestis? (1 = Skaitymas, 0=Ivestis)" << std::endl;
    std::cin >> pradinis;
    Vector<Studentai> StudentuInfo;
    while (pradinis != "1" && pradinis != "0") {
        std::cout << "Ivestis neteisinga, bandykite dar karta ivesdami 1 ar 0" << std::endl;
        std::cin >> pradinis;
    }
    if (pradinis == "1") {
        std::cout << "Ar norite generuoti tekstinius failus? (taip ar ne)" << std::endl;
        std::cin >> generate;
        while (generate != "taip" && generate != "ne") {
            std::cout << "Ivestis neteisinga, bandykite dar karta ivesdami taip arba ne" << std::endl;
            std::cin >> generate;
        }
        if (generate == "taip") {
            if (fileExists("10.txt") && fileExists("10neislaike.txt")) {
            		auto start = std::chrono::high_resolution_clock::now();
                std::string pav;
                std::cout << "Failai jau egzistuoja" << std::endl;
                std::cout << "Pradedami skaitymai is failu" << std::endl;
                for (int i = 1; i <= 5; i++) {
                    std::stringstream ss;
                    ss << std::round(pow(10, i));
                    std::string pav = ss.str() + ".txt";
                    std::cout << pav << std::endl;
                    Skaitymas(StudentuInfo, pav);
                }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Failu skaitymo laikas: " << diff.count() << " s." << std::endl;
            } else {
            		auto start1 = std::chrono::high_resolution_clock::now();
                for (int z = 1; z <= 5; z++) {
                    Generuoti(StudentuInfo, std::round(pow(10, z)));
                    StudentuInfo.clear();
                }
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        std::cout << "Failu generavimo laikas: " << diff1.count() << " s." << std::endl;
            }
        }
        if (generate == "ne") {
        	auto start2 = std::chrono::high_resolution_clock::now();
            Skaitymas(StudentuInfo, "kursiokai.txt");
            Spausdinti(StudentuInfo);
         auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
        std::cout << "Programos laikas: " << diff2.count() << " s." << std::endl;
        }
    } else {
        int studSkaic;
        bool valid = true;
        std::string tekstas;
        std::cout << "Iveskite studentu skaiciu" << std::endl;
        std::cin.sync();
        while (valid) {
            valid = false;
            try {
                studSkaic = TikrintiSkaicius(tekstas);
            }
            catch (const std::out_of_range &e) {
                std::cout << "Sis skaicius yra per didelis, bandykite dar karta" << std::endl;
                valid = true;

            }
        }
        StudentuInfo.reserve(studSkaic);

        for (int i = 0; i < studSkaic; i++) StudentuInfo.push_back(Informacija());


        std::string tipas;
        std::cout << "Pasirinkite kokio rezultato norite - Vid ar Med" << std::endl;
        std::cin >> tipas;

        while (tipas != "Vid" && tipas != "Med") {
            std::cout << "Ivestis neteisinga, bandykite dar karta" << std::endl;
            std::cin >> tipas;
        }
        auto start1 = std::chrono::high_resolution_clock::now();
        Spausdinti(StudentuInfo, tipas, studSkaic);
          auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        std::cout << "Programos laikas: " << diff1.count() << " s." << std::endl;

    }

}
void Generuoti(Vector<Studentai> StudentuInfo, int n){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 gen(seed);
	std::uniform_int_distribution<std::mt19937::result_type> genSK (1, 10);
	StudentuInfo.clear();
	StudentuInfo.reserve(n+1);
	std::string lname;
	std::string fname;
	Studentai Stud;
//	for(int ff = 0; ff < 10; ff++) Stud.setND(ff);

	double suma = 0;
	int egzrez;
	double pazymys;
	double vidurkis;
	double galutinis;
	for(int i = 0; i <= n; i++){
			suma = 0;
			lname = "Pavarde";
			lname+= std::to_string(i);
			//	std::cout << "hello2" << std::endl;
			Stud.setLname(lname);
			fname = "Vardas";
			fname+= std::to_string(i);
			//	std::cout << "hello22" << std::endl;
			Stud.setFname(fname);
			Stud.getND().reserve(35);
			for(int j = 0; j <= 30; j++){
					pazymys = genSK(gen);
					Stud.setND(pazymys);
			}
			suma += Stud; // cia panaudotas += operatorius
		egzrez = Stud.getND(30);
		vidurkis = suma /30;
		galutinis = 0.4*vidurkis + 0.6*egzrez;
		Stud.setegzRez(galutinis);
		StudentuInfo.push_back(Stud);

		Stud.getND().clear();
	}
	FailuIrasymas(StudentuInfo, n);
}
void FailuIrasymas(Vector<Studentai> StudentuInfo, int n){
		std::stringstream ss;
	ss << n;
	std::string pav= ss.str() + ".txt";
	std::ofstream fr(pav);
	std::string N1;
	for(int i = 0; i <= n; i++){
		if(i == 0){
			fr << std::left<< std::setw(14) << "Pavarde" << std::left << std::setw(14) << "Vardas";
			for(int y = 1; y <=31; y++) {
			N1 = "N";
			N1+= std::to_string(y);
			if(y != 31) fr << std::left << std::setw(7) << N1;
				else fr << std::left << std::setw(13) << "Egzaminas" << std::endl;
			}
		}
		else{
			fr << StudentuInfo[i];
			for(int j = 0; j <= 30; j++){
				if(j != 30) fr << std::left << std::setw(7) << StudentuInfo[i].getND(j);
				else fr << std::left << std::setw(13) << StudentuInfo[i].getND(j) << std::endl;
				}
			}
		}
		std::string strat;
		std::cout << "Pasirinkite rusiavimo strategija: 1- pirma, 2 - antra, 3 - papildoma" << std::endl;
		std::cin >> strat;
		while(strat != "1" && strat != "2" && strat != "3"){
			std::cout << "Ivestis neteisinga, bandykite is naujo irasydami arba 1 arba 2 arba 3" << std::endl;
			std::cin >> strat;
		}
		if(strat == "1"){
		auto start = std::chrono::high_resolution_clock::now();
     	VectorRusiavimas1strat(StudentuInfo, n);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << n << " Studentu rusiavimo laikas: " << diff.count() << " s." << std::endl;	
		}
		if( strat == "2"){
		auto start1 = std::chrono::high_resolution_clock::now();
     	VectorRusiavimas2strat(StudentuInfo, n);
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        std::cout << n << " Studentu rusiavimo laikas: " << diff1.count() << " s." << std::endl;		
		}
		if(strat == "3"){
		auto start2 = std::chrono::high_resolution_clock::now();
        raskMinkstus(StudentuInfo, n);
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
        std::cout << n << " 'Minkstu' Studentu rusiavimo laikas: " << diff2.count() << " s." << std::endl;	
        
        auto start3 = std::chrono::high_resolution_clock::now();
        iterpkKietus(StudentuInfo, n);
        auto end3 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff3 = end3 - start3;
        std::cout << n << " 'Kietu' Studentu rusiavimo laikas: " << diff3.count() << " s." << std::endl;
		}
		
 fr.close();

}
void VectorRusiavimas1strat(Vector<Studentai> StudentuInfo, int n){
	std::stringstream ss;
	ss << n;
	std::string pav1= ss.str() +"islaike.txt";
	std::string pav2= ss.str()+ "neislaike.txt";
	Vector<Studentai> neislaike;
	Vector<Studentai> islaike;
	std::ofstream fr1(pav1);
	std::ofstream fr2(pav2);
			fr1 << std::right << std::setw(23) << "Islaike" << std::endl; 
			fr1 << std::left << std::setw(14) << "Pavarde" << std::left  << std::setw(14) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr1 <<std::endl;
		    fr2 << std::right << std::setw(23) << "Neislaike" << std::endl; 
		    fr2 << std::left << std::setw(14) << "Pavarde" << std::left  << std::setw(14) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr2 <<std::endl;

StudentuInfo.erase(StudentuInfo.begin());
for(int i = 0; i <n ;i++){
	if(StudentuInfo[i].getEgzRez() >= 5) islaike.push_back(StudentuInfo[i]);
		if(StudentuInfo[i].getEgzRez() < 5) neislaike.push_back(StudentuInfo[i]);
	 }
 //auto it = std::copy_if (StudentuInfo.begin(), StudentuInfo.end(), neislaike.begin(), [](Studentai & i){return i.getEgzRez() <5;} );
//	std::cout  << " hello 4" << std::endl;
//	neislaike.resize(std::distance(neislaike.begin(),it));
//	std::cout  << " hello 5" << std::endl;
 //auto it1 = std::copy_if (StudentuInfo.begin(), StudentuInfo.end(), islaike.begin(), [](Studentai & f){return f.getEgzRez() >=5;} );
//	islaike.resize(std::distance(islaike.begin(),it1));	
	
		
	int dydis1 = islaike.size();
	int dydis2 = neislaike.size();
	for(int j = 0; j< dydis1; j++){
		fr1 << islaike[j] << std::left << std::setw(7) << islaike[j].getEgzRez() << std::endl;
	}
		for(int j1 = 0; j1< dydis2; j1++){
		fr2 <<  neislaike[j1] << std::left << std::setw(7) << neislaike[j1].getEgzRez()<< std::endl; // panaudotas << operatorius
	}
	fr1.close();
	fr2.close();
}
void VectorRusiavimas2strat(Vector<Studentai> StudentuInfo, int n){
	std::stringstream ss;
	ss << n;
	std::string pav1= ss.str() +"islaike.txt";
	std::string pav2= ss.str()+ "neislaike.txt";
	Vector<Studentai> neislaike;
	std::ofstream fr1(pav1);
	std::ofstream fr2(pav2);
			fr1 << std::right << std::setw(23) << "Islaike" << std::endl; 
			fr1 << std::left << std::setw(14) << "Pavarde" << std::left  << std::setw(14) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr1 <<std::endl;
		    fr2 << std::right << std::setw(23) << "Neislaike" << std::endl; 
		    fr2 << std::left << std::setw(14) << "Pavarde" << std::left  << std::setw(14) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr2 <<std::endl;
	 StudentuInfo.erase(StudentuInfo.begin());
	 for(int i = 0; i <n ;i++){
		if(StudentuInfo[i].getEgzRez() < 5) neislaike.push_back(StudentuInfo[i]);
	 }
//auto it = std::copy_if (StudentuInfo.begin(), StudentuInfo.end(), neislaike.begin(), [](Studentai & i){return i.getEgzRez() <5;} );
//	neislaike.resize(std::distance(neislaike.begin(),it));
  StudentuInfo.erase(std::remove_if(StudentuInfo.begin(), StudentuInfo.end(), maziau), StudentuInfo.end());
	StudentuInfo.shrink_to_fit();
	neislaike.shrink_to_fit();
	int dydis1 = StudentuInfo.size();
	int dydis2 = neislaike.size();
	for(int j = 0; j < dydis1; j++){
		fr1 << std::left << std::setw(13) << StudentuInfo[j].pavarde() << std::left << std::setw(13) << StudentuInfo[j].vardas() << std::left << std::setw(7) << StudentuInfo[j].getEgzRez() << std::endl;
	}
		for(int j1 = 0; j1< dydis2; j1++){
		fr2 << std::left << std::setw(13) << neislaike[j1].pavarde() << std::left << std::setw(13) << neislaike[j1].vardas() << std::left << std::setw(7) << neislaike[j1].getEgzRez() << std::endl;
	}
	fr1.close();
	fr2.close();
}
bool maziau(Studentai & i)
{ 
    return i.getEgzRez() < 5; 
} 

void raskMinkstus(Vector<Studentai> &StudentuInfo, int n){
	std::stringstream ss;
	ss << n;
	std::string pav2= ss.str()+ "neislaike.txt";
	Vector<Studentai> neislaike;
	std::ofstream fr2(pav2);
		    fr2 << std::right << std::setw(23) << "Neislaike" << std::endl; 
		    fr2 << std::left << std::setw(13) << "Pavarde" << std::left  << std::setw(13) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr2 <<std::endl;
	 StudentuInfo.erase(StudentuInfo.begin());
	 StudentuInfo.shrink_to_fit();

int i = 0;  

int f1 = 0;
while(i != StudentuInfo.size()){	
		if(StudentuInfo[i].getEgzRez() < 5){
			if(StudentuInfo[i].vardas() == "") break;
			 neislaike.push_back(StudentuInfo[i]);
			 f1++;
}
i++;
	}
	neislaike.resize(std::distance(neislaike.begin(),neislaike.begin() + f1));
	neislaike.shrink_to_fit();
	int dydis2 = neislaike.size();
		for(int j1 = 0; j1< dydis2; j1++){
		fr2 << std::left << std::setw(13) << neislaike[j1].pavarde() << std::left << std::setw(13) << neislaike[j1].vardas() << std::left << std::setw(7) << neislaike[j1].getEgzRez()<< std::endl;
	}
	fr2.close();
}
void iterpkKietus(Vector<Studentai> &StudentuInfo, int n){
		std::stringstream ss;
	ss << n;
	std::string pav1= ss.str() +"islaike.txt";
	std::ofstream fr1(pav1);
			fr1 << std::right << std::setw(23) << "Islaike" << std::endl; 
			fr1 << std::left << std::setw(13) << "Pavarde" << std::left  << std::setw(13) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr1 <<std::endl;
int i = 0; 

int f = 0;
while(i != StudentuInfo.size()){	
		if(StudentuInfo[i].getEgzRez() >= 5){
			if(StudentuInfo[i].vardas() == "") break;
			 StudentuInfo.insert(StudentuInfo.begin(), StudentuInfo[i]);
			i++;
			f++;
}
i++;
	}
	StudentuInfo.resize(std::distance(StudentuInfo.begin(),StudentuInfo.begin()+f));
	StudentuInfo.shrink_to_fit();
	 std::reverse(StudentuInfo.begin(),StudentuInfo.end()); 
	int dydis1 = StudentuInfo.size();
	for(int j = 0; j < dydis1; j++){
		fr1 << std::left << std::setw(13) << StudentuInfo[j].vardas() << std::left << std::setw(13) << StudentuInfo[j].pavarde() << std::left << std::setw(7) << StudentuInfo[j].getEgzRez() << std::endl;
	}
	
	fr1.close();
}



