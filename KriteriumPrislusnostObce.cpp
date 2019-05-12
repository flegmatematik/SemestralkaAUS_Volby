#include "KriteriumPrislusnostObce.h"
#include "../Volby/structures/heap_monitor.h"

KriteriumPrislusnostObce::KriteriumPrislusnostObce(std::string p_nazovVyssiehoCelku)
	:nazovVyssiehoCelku(p_nazovVyssiehoCelku)
{
}

KriteriumPrislusnostObce::~KriteriumPrislusnostObce()
{
}

bool KriteriumPrislusnostObce::ohodnot(UzemnaJednotka* objekt)
{
	return objekt->patriDoVyssiehoUzemnehoCelku(nazovVyssiehoCelku);
}

