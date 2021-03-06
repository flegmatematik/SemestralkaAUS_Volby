#pragma once
#include "Kriterium.h"
#include "Obec.h"
#include "../Volby/structures/heap_monitor.h"

class KriteriumPrislusnostObce : public Kriterium<bool,UzemnaJednotka*>
{
private:
	std::string nazovVyssiehoCelku;
public:
	KriteriumPrislusnostObce(std::string p_nazovVyssiehoCelku);
	virtual ~KriteriumPrislusnostObce();
	bool ohodnot(UzemnaJednotka* objekt) override;
};

