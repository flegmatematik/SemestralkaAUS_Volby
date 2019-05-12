#include "Okres.h"
#include "../Volby/structures/heap_monitor.h"


Okres::Okres(Data* kolo1, Data* kolo2, int p_kodOkresu, std::string nazovOkresu, UzemnaJednotka* p_vyssiCelok) :
	UzemnaJednotka(kolo1, kolo2, p_kodOkresu, nazovOkresu, p_vyssiCelok)
{
}

std::string Okres::toString()
{
	return "Kraj: " + vyssiaUzemnaJednotka->nazov() +" Okres: " + nazov() + "\nPrve kolo: " + prveKolo->toString() + "\nDruhe kolo: " + druheKolo->toString() + "\n";
}

bool Okres::patriDoVyssiehoUzemnehoCelku(std::string nazov)
{
	return nazov == vyssiaUzemnaJednotka->nazov();
}
