#include "KriteriumNazov.h"
#include "../Volby/structures/heap_monitor.h"


KriteriumNazov::KriteriumNazov()
{
}


KriteriumNazov::~KriteriumNazov()
{
}

std::string KriteriumNazov::ohodnot(UzemnaJednotka* objekt)
{
	return objekt->nazov();
}


	
