#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <random>
#include <fstream>
#include "funkcijos.h"

std::string Tikrinti(std::string tekstas){
	std::string n;
	bool valid;
		std::cin.sync();
	 do
    {
        std::getline(std::cin,tekstas);
        std::stringstream s(tekstas);
        valid = true;
        if(s >> n){
        for(auto& i : tekstas)
        {
            if(!std::isalpha(i))
            {
                valid = false;
                std::cout << "Ivestis neteisinga. Bandykite dar karta tik su raidemis" << std::endl;
                break;
            }
        }
    }
    else{
    	valid = false;
    	std::cout << "Ivestis neteisinga. Bandykite dar karta tik su raidemis" << std::endl;
	}
    }while(!valid);
    return tekstas;
}
double TikrintiSkaicius(std::string tekstas){
		bool valid;
    std::string n;
	do
    {
        std::getline(std::cin,tekstas);
        std::stringstream s(tekstas);
        if(s >> n){
        valid = true;
        for(auto& i : tekstas)
        {
            if(!std::isdigit(i))
            {
                valid = false;
                std::cout << "Ivestis neteisinga. Bandykite dar karta tik su skaiciais" << std::endl;
                break;
            }
        }
    }
    else{
	     valid = false;
         std::cout << "Ivestis neteisinga. Bandykite dar karta tik su skaiciais" << std::endl;
}
    }while(!valid);
    return std::stoi(tekstas);
}
bool Lyginimas(const Studentai &a, const Studentai &b)
{
    return a.pavarde() < b.pavarde();
}
bool fileExists(const std::string& filename) {
  std::ifstream ifile(filename.c_str());
  return (bool)ifile;
}
