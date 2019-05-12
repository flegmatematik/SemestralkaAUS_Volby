#include "Obec.h"
#include "../Volby/structures/heap_monitor.h"

Obec::Obec(Data* p_prveKolo, Data* p_druheKolo, int p_kodObce, std::string p_nazovObce, UzemnaJednotka *vyssi):
	UzemnaJednotka(p_prveKolo,p_druheKolo,p_kodObce,p_nazovObce, vyssi)
{
}

bool Obec::patriDoVyssiehoUzemnehoCelku(std::string nazov)
{
	return nazov == vyssiaUzemnaJednotka->nazov() || nazov == vyssiaUzemnaJednotka->dajVyssie()->nazov();
}

std::string Obec::toString()
{
	return
	"Kraj: " + vyssiaUzemnaJednotka->dajVyssie()->nazov() + 
	" Okres: " + vyssiaUzemnaJednotka->nazov() +  " Obec: " + nazov() + 
		"\nPrve kolo: " + prveKolo->toString() + 
		"\nDruhe kolo: " + druheKolo->toString() + "\n";
}

Obec::~Obec()
{
	
}

