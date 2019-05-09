#include "Obec.h"

Obec::Obec(Data* p_prveKolo, Data* p_druheKolo, int p_kodObce, std::string p_nazovObce, UzemnaJednotka *vyssi):
	UzemnaJednotka(p_prveKolo,p_druheKolo,p_kodObce,p_nazovObce), vyssia(vyssi)
{
}

bool Obec::patriDoVyssiehoCelku(std::string nazovVyssiehoCelku)
{
	return nazovVyssiehoCelku == vyssia->nazov() || nazovVyssiehoCelku == vyssia->dajVyssie()->nazov();
}

std::string Obec::toString()
{
	return "Kod Obce: " + std::to_string(kod()) + " Nazov obce: " + nazov() + "\nPrve kolo: " + prveKolo->toString() + "\nDruhe kolo: " + druheKolo->toString();
}


Obec::~Obec()
{
}
