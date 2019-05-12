#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"
#include "../Volby/structures/heap_monitor.h"

class KriteriumNazov: public Kriterium<std::string,UzemnaJednotka*>
{
public:
	KriteriumNazov();
	virtual ~KriteriumNazov();
	std::string ohodnot(UzemnaJednotka* objekt) override;
};

