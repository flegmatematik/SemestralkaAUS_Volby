#pragma once
#include "UzemnaJednotka.h"

class Okres : public UzemnaJednotka
{
public:
	Okres(Data *kolo1, Data *kolo2,
		int p_kodOkresu,
		std::string nazovOkresu,
		UzemnaJednotka* p_vyssiCelok);

	std::string toString() override;
	bool patriDoVyssiehoUzemnehoCelku(std::string nazov) override;
	~Okres();
	
};

