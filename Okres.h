#pragma once
#include "UzemnaJednotka.h"

class Okres : public UzemnaJednotka
{
private:
	UzemnaJednotka* vyssiCelok;
public:
	Okres(Data *kolo1, Data *kolo2,
		int p_kodOkresu,
		std::string nazovOkresu,
		UzemnaJednotka* p_vyssiCelok = nullptr);
	std::string toString() override;
	~Okres();
};

