#pragma once
#include  "UzemnaJednotka.h"
#include "Data.h"
#include <utility>

class UzemnaJednotka
{
private:
	std::string nazovUzemnejJednotky;
	int kodUzemnejJednotky;
	UzemnaJednotka * vyssiaUzemnaJednotka;
public:
	
	std::string nazov();
	int kod();
	UzemnaJednotka* dajVyssie();
	int pocetZapisanychVolicovVKole(int kolo);
	int pocetVydanychObalokVKole(int kolo);
	double ucastVolicovVKole(int kolo);
	int pocetOdovzdanychObalokVKole(int kolo);
	int pocetPlatnych(int kolo);
	virtual std::string toString();
	UzemnaJednotka(Data *p_prveKolo, Data *p_druheKolo, int p_kodUzemnejJednotky, std::string p_nazovUzemnejJednotky, UzemnaJednotka* p_vyssia = nullptr);
	~UzemnaJednotka();
protected:
	Data *prveKolo;
	Data *druheKolo;
	
};

