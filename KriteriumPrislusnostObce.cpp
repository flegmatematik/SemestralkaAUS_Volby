#include "KriteriumPrislusnostObce.h"


KriteriumPrislusnostObce::KriteriumPrislusnostObce(std::string p_nazovVyssiehoCelku)
	:nazovVyssiehoCelku(p_nazovVyssiehoCelku)
{
}

KriteriumPrislusnostObce::~KriteriumPrislusnostObce()
{
}

bool KriteriumPrislusnostObce::ohodnot(Obec* objekt)
{
	return objekt->patriDoVyssiehoCelku(nazovVyssiehoCelku);
}
