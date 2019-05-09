#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

class KriteriumUcast : public Kriterium<double,UzemnaJednotka>
{
private:
	int kolo;
public:
	KriteriumUcast(int p_kolo = 0);
	virtual ~KriteriumUcast();
	double ohodnot(UzemnaJednotka& objekt) override;
};

