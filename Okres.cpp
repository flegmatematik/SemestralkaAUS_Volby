#include "Okres.h"


Okres::Okres(Data* kolo1, Data* kolo2, int p_kodOkresu, std::string nazovOkresu, UzemnaJednotka* p_vyssiCelok) :
	UzemnaJednotka(kolo1, kolo2, p_kodOkresu, nazovOkresu), vyssiCelok(p_vyssiCelok)
{
}

std::string Okres::toString()
{
	return "Kod okresu: " + std::to_string(kod()) + " Nazov Okresu: " + nazov() + "\nPrve kolo: " + prveKolo->toString() + "\nDruhe kolo: " + druheKolo->toString();
}

Okres::~Okres()
{
}
