#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <list>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <random>
#include <fstream>
#include <iterator>
#include "funkcijos.h"

void Spausdinti(Vector<Studentai> Studentai, std::string tipas, int studSkaic){
	std::sort(Studentai.begin(), Studentai.end(), Lyginimas);
	int ilgiausiasV = 0;
	int ilgiausiaP = 0;

	for(int i = 0; i < studSkaic; i++) {
		if(Studentai[i].vardas().size() > ilgiausiasV) ilgiausiasV = Studentai[i].vardas().size();
		if(Studentai[i].pavarde().size() > ilgiausiaP) ilgiausiaP = Studentai[i].pavarde().size();
	}
	
	if(tipas == "Vid"){
		std::cout <<std::left <<std::setw(7+ilgiausiaP)<<"Pavarde" <<std::left << std::setw(7+ilgiausiasV) << "Vardas" <<std::left << std::setw(19) <<"Galutinis (Vid.)" <<std::endl;
		std::cout <<std::setfill('-') << std::setw(14+ilgiausiaP+ilgiausiasV+19) << "-"<< std::endl;
		std::cout << std::setfill(' ');
		for(int nuo = 0; nuo < studSkaic; nuo++){
			std::cout <<std::left <<std::setw(7+ilgiausiaP)<< Studentai[nuo].pavarde() << std::left << std::setw(7+ilgiausiasV)  << Studentai[nuo].vardas() <<std::left << std::setw(19) << std::setprecision(2) <<std::fixed << Studentai[nuo].getEgzRez() << std::endl;
		}
	}
	else{
		std::cout <<std::left <<std::setw(7+ilgiausiaP)<<"Pavarde" <<std::left << std::setw(7+ilgiausiasV) << "Vardas" <<std::left << std::setw(19) << "Galutinis (Med.)" <<std::endl;
		std::cout <<std::setfill('-') << std::setw(14+ilgiausiaP+ilgiausiasV+19) << "-"<< std::endl;
		std::cout << std::setfill(' ');
		for(int nuo1 = 0; nuo1 < studSkaic; nuo1++){
			std::cout <<std::left <<std::setw(7+ilgiausiaP)<< Studentai[nuo1].pavarde() << std::left << std::setw(7+ilgiausiasV)  << Studentai[nuo1].vardas() <<std::left << std::setw(19) << std::setprecision(2) <<std::fixed << Studentai[nuo1].getMediana() << std::endl;
		}
	}

}

void Spausdinti(Vector<Studentai> Studentai){
	std::sort(Studentai.begin(), Studentai.end(), Lyginimas);
	int studSkaic = 0;
	for(int z=0; z<Studentai.size(); z++){
		studSkaic++;
	}
	int ilg;
	int ilgiausiasV = 0;
	int ilgiausiaP = 0;
	for(int i = 0; i < studSkaic; i++) {	
    if(Studentai[i].vardas().size() > ilgiausiasV) ilgiausiasV = Studentai[i].vardas().size();
    if(Studentai[i].pavarde().size() > ilgiausiaP) ilgiausiaP = Studentai[i].pavarde().size();
}
	std::cout <<std::left <<std::setw(7+ilgiausiaP)<<"Pavarde" <<std::left << std::setw(7+ilgiausiasV) << "Vardas" <<std::left << std::setw(19) <<"Galutinis (Vid.)" <<std::left << std::setw(19) <<"Galutinis (Med.)" <<std::endl;
	std::cout <<std::setfill('-') << std::setw(14+ilgiausiaP+ilgiausiasV+38) << "-"<< std::endl;
	std::cout << std::setfill(' ');
	for(int nuo = 0; nuo < studSkaic; nuo++){
		std::cout <<std::left <<std::setw(7+ilgiausiaP)<< Studentai[nuo].pavarde() << std::left << std::setw(7+ilgiausiasV)  << Studentai[nuo].vardas() <<std::left << std::setw(19) << std::setprecision(2) <<std::fixed << Studentai[nuo].getEgzRez() << std::setw(19) << std::setprecision(2) <<std::fixed << Studentai[nuo].getMediana()<< std::endl;
	}

}
void Skaitymas(Vector<Studentai> &StudentuInfo, std::string pav){
	std::string a;
	std::string b;
	int skaicius = 0;
	int elSkaic = 0;
	int ndSkaic;
	double egz;
	int p = 0;
	Studentai Stud;
	double vidurkis;
	double galutinis;
	double mediana;
	int suma = 0;
	
	std::ifstream fd;
	fd.open(pav);
	if (!fd.is_open())
    {
       std::cout <<"Nepavyko atidaryti failo" << std::endl;
    }
    else{
	while(std::getline(fd, a)) skaicius++;
	fd.clear();
	fd.seekg(0, std::ios::beg);
	while(!fd.eof()){
		fd >> a;
		elSkaic++;
		if(a == "Egzaminas") break;
	}
	ndSkaic = elSkaic - 3;
	for(int i = 0; i < skaicius-1; i++){
		for(int j = 0; j < elSkaic; j++){
			fd >> b;
			if(j == 0) Stud.setLname(b);
			if(j == 1) Stud.setFname(b);
			if(j == elSkaic-1) egz = std::stoi(b);
			if(j>1 && j < elSkaic-1) {
			Stud.getND().push_back(std::stoi(b));	
			}
		}
	vidurkis = (double)suma/ndSkaic;
	galutinis = 0.4 * vidurkis + 0.6*egz;
	Stud.setegzRez(galutinis);
	mediana = Mediana(Stud, ndSkaic, p);
	Stud.setMediana(0.4 * mediana + 0.6*egz);
	StudentuInfo.push_back(Stud);
	//std::cout<< "hello " << std::endl;
	Stud.getND().clear();
}
	fd.close();
}
}
void Generuoti(int n){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 gen(seed);
	std::uniform_int_distribution<std::mt19937::result_type> genSK (1, 10);
	std::stringstream ss;
	ss << n;
	std::string pav= ss.str() + ".txt";
	std::string pav1= ss.str() +"islaike.txt";
	std::string pav2= ss.str()+ "neislaike.txt";
	std::ofstream fr(pav);
	std::ofstream fr1(pav1);
	std::ofstream fr2(pav2);
	std::string lname;
	std::string fname;
	std::string N1;
	double suma = 0;
	int egzrez;
	int pazymys;
	double vidurkis;
	double galutinis;
	for(int i = 0; i <= n; i++){
		if(i == 0){
			fr1 << std::right << std::setw(23) << "Islaike" << std::endl; 
			fr1 << std::left << std::setw(13) << "Pavarde" << std::left  << std::setw(13) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr1 <<std::endl;
		    fr2 << std::right << std::setw(23) << "Neislaike" << std::endl; 
		    fr2 << std::left << std::setw(13) << "Pavarde" << std::left  << std::setw(13) << "Vardas" << std::left << std::setw(7) << "Galutinis balas" << std::endl;
			fr2 <<std::endl;
			fr << std::left<< std::setw(14) << "Pavarde" << std::left << std::setw(14) << "Vardas";
			for(int y = 1; y <=101; y++) {
			N1 = "N";
			N1+= std::to_string(y);
			if(y != 101) fr << std::left << std::setw(7) << N1;
				else fr << std::left << std::setw(13) << "Egzaminas" << std::endl;
			}
		}
		else{
			suma = 0;
			lname = "Pavarde";
			lname+= std::to_string(i);
			fname = "Vardas";
			fname+= std::to_string(i);
			fr <<std::left << std::setw(14) << lname << std::left << std::setw(14) <<fname;
			for(int j = 1; j <= 101; j++){
				if(j != 101){
					pazymys = genSK(gen);
					fr << std::left << std::setw(7) << pazymys;
					suma += pazymys;
				}
				else {
					egzrez = genSK(gen);
				fr << std::left << std::setw(13) << egzrez << std::endl;	
				}
			
			}
		vidurkis = suma /100;
		galutinis = 0.4*vidurkis + 0.6*egzrez;
		if(galutinis >= 5){
			fr1 << std::left << std::setw(13) << lname << std::left << std::setw(13) << fname << std::left << std::setw(7) << galutinis << std::endl;
		}
		else{
			fr2 << std::left << std::setw(13) << lname << std::left << std::setw(13) << fname << std::left << std::setw(7) << galutinis << std::endl;
		}
		}
	}
	fr.close();
	fr1.close();
	fr2.close();
}

