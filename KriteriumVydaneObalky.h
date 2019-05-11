#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

class KriteriumVydaneObalky : public Kriterium<int,UzemnaJednotka*>
{
private:
	int kolo;
public:
	
	KriteriumVydaneObalky(int p_kolo = 0);
	virtual ~KriteriumVydaneObalky();
	int ohodnot(UzemnaJednotka* objekt) override;
};

