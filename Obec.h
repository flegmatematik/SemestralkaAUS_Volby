#pragma once
#include "UzemnaJednotka.h"

class Obec : public UzemnaJednotka
{
public:
	Obec(Data *p_prveKolo, Data *p_druheKolo,
		int p_kodObce,
		std::string p_nazovObce,
		UzemnaJednotka* vyssiCelok);
	bool patriDoVyssiehoUzemnehoCelku(std::string nazov) override;
	std::string toString() override;
	~Obec();
	
};

