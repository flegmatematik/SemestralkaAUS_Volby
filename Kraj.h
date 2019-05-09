#pragma once
#include "UzemnaJednotka.h"

class Kraj : public UzemnaJednotka
{
public:
	Kraj(Data *p_prveKolo, Data *p_druheKolo, int p_kodKraja, std::string p_nazovKraja);
	std::string toString() override;
	~Kraj();
};

