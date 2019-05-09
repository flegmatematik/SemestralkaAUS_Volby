#pragma once
#include "UzemnaJednotka.h"

class Obec : public UzemnaJednotka
{
private:
	UzemnaJednotka* vyssia;
public:
	Obec(Data *p_prveKolo, Data *p_druheKolo,
		int p_kodObce,
		std::string p_nazovObce,
		UzemnaJednotka* vyssiCelok = nullptr);
	bool patriDoVyssiehoCelku(std::string nazovVyssiehoCelku);
	std::string toString() override;
	~Obec();
};

