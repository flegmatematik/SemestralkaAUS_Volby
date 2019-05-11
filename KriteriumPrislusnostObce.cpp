#include "KriteriumPrislusnostObce.h"


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

