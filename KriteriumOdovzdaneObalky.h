#pragma once
#include "Kriterium.h"
#include "UzemnaJednotka.h"

class KriteriumOdovzdaneObalky : public Kriterium<int,UzemnaJednotka*>
{
private:
	int kolo;
public:
	KriteriumOdovzdaneObalky(int p_kolo = 0);
	virtual ~KriteriumOdovzdaneObalky();
	int ohodnot(UzemnaJednotka *objekt) override;
};

