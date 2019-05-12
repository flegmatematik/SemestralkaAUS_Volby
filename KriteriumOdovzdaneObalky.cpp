#include "KriteriumOdovzdaneObalky.h"
#include "../Volby/structures/heap_monitor.h"

KriteriumOdovzdaneObalky::KriteriumOdovzdaneObalky(int p_kolo)
	:kolo(p_kolo)
{
}

KriteriumOdovzdaneObalky::~KriteriumOdovzdaneObalky()
{
}

int KriteriumOdovzdaneObalky::ohodnot(UzemnaJednotka* objekt)
{
	return objekt->pocetOdovzdanychObalokVKole(kolo);
}
