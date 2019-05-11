#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

class KriteriumNazov: public Kriterium<std::string,UzemnaJednotka*>
{
public:
	KriteriumNazov();
	virtual ~KriteriumNazov();
	std::string ohodnot(UzemnaJednotka* objekt) override;
};

