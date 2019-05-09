#include "KriteriumVolici.h"



KriteriumVolici::KriteriumVolici(int p_kolo)
	:kolo(p_kolo)
{
}

KriteriumVolici::~KriteriumVolici()
{
}

int KriteriumVolici::ohodnot(UzemnaJednotka& objekt)
{
	return objekt.pocetZapisanychVolicovVKole(kolo);
}
