#include "Kraj.h"


Kraj::Kraj(Data* p_prveKolo, Data* p_druheKolo, int p_kodKraja, std::string p_nazovKraja): UzemnaJednotka(p_prveKolo,p_druheKolo,p_kodKraja,p_nazovKraja)
{
}


std::string Kraj::toString()
{
	return "Kod kraja: " + std::to_string(kod()) + " Nazov kraja: " + nazov() + "\nPrve kolo: " + prveKolo->toString() + "\nDruhe kolo: " + druheKolo->toString();
}

Kraj::~Kraj()
{
}
