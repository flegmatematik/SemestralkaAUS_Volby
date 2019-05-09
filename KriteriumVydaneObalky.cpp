#include "KriteriumVydaneObalky.h"



KriteriumVydaneObalky::KriteriumVydaneObalky(int p_kolo)
	:kolo(p_kolo)
{

}

KriteriumVydaneObalky::~KriteriumVydaneObalky()
{
}

int KriteriumVydaneObalky::ohodnot(UzemnaJednotka& objekt)
{
	return objekt.pocetVydanychObalokVKole(kolo);
}
