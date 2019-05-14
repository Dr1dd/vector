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

Studentai Informacija(){
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 genseed(seed);
	std::uniform_int_distribution<std::mt19937::result_type> genSK (1, 10);
	std::string vardas, pavarde;
	int n =0;
	double galutinis;
	double vidurkis;
	int studSkaic;
	int p = 0;
	int laikina = 1;
	int laik = 0;
	int ilgis;
	int egzam = 0;
	double egzaminas = 0;
	double mediana = 0;
	
	int suma = 0;
	bool valid;
	Studentai Stud;
	bool raides = true;
	bool skaiciai = false;
	std::string tekstas;
	std::string ivestis;
	std::cout <<"Iveskite varda" << std::endl;
	std::cin.sync();
	Stud.setFname(Tikrinti(tekstas));
	std::cout <<"Iveskite pavarde" << std::endl;
	std::cin.sync();
    Stud.setLname(Tikrinti(tekstas));
	bool gen = false;
	std::string generuoti;
	int randomSkaic;
	std::cout <<"Iveskite kiek namu darbu buvo atlikta (Bet koks simbolis isskyrus skaicius = galesite baigti kai irasysite - 0)" << std::endl;
	 std::cin.sync();
	 std::getline(std::cin, ivestis);
	 std::stringstream s(ivestis);
    if(s >> n){
    	std::cout<<"Ar norite skaicius generuoti?(egz ir n.d.) Pasirinkimai: (Taip arba Ne)" << std::endl;
    	std::cin>> generuoti;
    	while(generuoti!= "Taip" && generuoti !="Ne" && generuoti!= "taip" && generuoti !="ne"){
		std::cout<<"Ivestis neteisinga, bandykite dar karta: (Iveskite Taip arba Ne)" << std::endl;
		std::cin >> generuoti;
   }
    	if(generuoti == "Taip" || generuoti == "taip"){
    	 gen = true;
    	for(int i =1;i <=n; i++){
    		randomSkaic = genSK(genseed);
    	 Stud.setND(randomSkaic);
    	 suma = suma + randomSkaic;
    }
		}
		else{
			for(int i =1;i <=n; i++){
		std::cout <<"Iveskite nr " << i << " namu darbo rezultata (1-10)" << std::endl;
		std::cin.sync();
		laik = TikrintiSkaicius(tekstas);
		if(laik >10 || laik <0){
		  std::cout <<"Jus ivedete neimanoma rezultata, bandykite dar karta" << std::endl;
		  i= i-1;
		}
		else {
			Stud.setND(laik);
			suma = suma + laik;	
		}
        }
    }
    }
    else{
        while(laikina != 0){
			std::cout <<"Iveskite nr " << p+1 << " namu darbo rezultata (1-10) (0 = ivedimas baigiamas)" << std::endl;
			laikina = TikrintiSkaicius(tekstas);
			if(laikina >10 || laikina <0){
		  		std::cout <<"Jus ivedete neimanoma rezultata, bandykite dar karta" << std::endl;
		}
			else {
				if(laikina == 0) break;
				p++;
				Stud.setND(laikina);
				suma = suma + laikina;
			}
		}
	}
	int egzas = 0;
	if(gen == true){
		egzas = genSK(genseed);
	if(p>0)vidurkis = (double)suma/p;
	else vidurkis = (double)suma/n;
	galutinis = 0.4 * vidurkis + 0.6*egzas;
	Stud.setegzRez(galutinis);
	mediana = Mediana(Stud, n, p);
	Stud.setMediana(0.4 * mediana + 0.6*egzas);
	}
	else{
	std::cout <<"Iveskite egzamino rezultata" << std::endl;
	std::cin.sync();
	egzam = TikrintiSkaicius(tekstas); 
	if(egzam > 10 || egzam <1){
		while(egzam >10 || egzam < 1){
			std::cout <<"Jus ivedete neimanoma rezultata, bandykite dar karta" << std::endl;
			std::cout <<"Iveskite egzamino rezultata" << std::endl;
			std::cin >> egzam;
		}
	}
	else egzaminas = egzam;
	if(p>0)vidurkis = (double)suma/p;
	else vidurkis = (double)suma/n;
	galutinis = 0.4 * vidurkis + 0.6*egzaminas;
	Stud.setegzRez(galutinis);
	mediana = Mediana(Stud, n, p);
	Stud.setMediana(0.4 * mediana + 0.6*egzaminas);

}

return Stud;
}

double Mediana(Studentai Stud, int n, int p){
	double mediana;
	int f = 0;
	Vector<double> NaDa;
	NaDa = Stud.getND();
	std::sort(NaDa.begin(), NaDa.end());

	if(n!=0){
		if(n % 2 == 0) mediana = (NaDa[n/2-1] + NaDa[n/2]) / 2;
		else {
			if(n == 1) mediana = 1;
			else mediana = NaDa[n/2];
		}
	}
	else{
	if(p % 2 == 0)mediana = (NaDa[p/2-1] + NaDa[p/2]) / 2;
	 else {
	 	if(p == 1) mediana == 1;
	 	else mediana = NaDa[p/2];
	 }
}

return mediana;
}


