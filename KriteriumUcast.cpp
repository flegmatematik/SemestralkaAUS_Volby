#include "KriteriumUcast.h"
#include "../Volby/structures/heap_monitor.h"

KriteriumUcast::KriteriumUcast(int p_kolo)
	:kolo(p_kolo)
{
}

KriteriumUcast::~KriteriumUcast()
{
}

double KriteriumUcast::ohodnot( UzemnaJednotka* objekt)
{
	return objekt->ucastVolicovVKole(kolo); 
}
