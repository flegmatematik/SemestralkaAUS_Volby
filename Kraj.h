#pragma once
#include "UzemnaJednotka.h"
#include "../Volby/structures/heap_monitor.h"

class Kraj : public UzemnaJednotka
{
public:
	Kraj(Data *p_prveKolo, Data *p_druheKolo, int p_kodKraja, std::string p_nazovKraja);
	std::string toString() override;
	bool patriDoVyssiehoUzemnehoCelku(std::string nazov) override;
};

