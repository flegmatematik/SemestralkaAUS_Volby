#include "KriteriumVydaneObalky.h"
#include "../Volby/structures/heap_monitor.h"


KriteriumVydaneObalky::KriteriumVydaneObalky(int p_kolo)
	:kolo(p_kolo)
{

}

KriteriumVydaneObalky::~KriteriumVydaneObalky()
{
}

int KriteriumVydaneObalky::ohodnot(UzemnaJednotka* objekt)
{
	return objekt->pocetVydanychObalokVKole(kolo);
}
