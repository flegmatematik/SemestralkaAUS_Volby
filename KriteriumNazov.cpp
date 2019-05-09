#include "KriteriumNazov.h"



KriteriumNazov::KriteriumNazov()
{
}


KriteriumNazov::~KriteriumNazov()
{
}

std::string KriteriumNazov::ohodnot(UzemnaJednotka& objekt)
{
	return objekt.nazov();
}


	
