#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

class KriteriumVolici : public Kriterium<int,UzemnaJednotka*>
{
private:
	int kolo;
public:
	KriteriumVolici(int p_kolo = 0);
	virtual ~KriteriumVolici();
	int ohodnot(UzemnaJednotka* objekt) override;
};

