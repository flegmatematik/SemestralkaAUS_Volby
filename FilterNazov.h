#pragma once
#include "FilterJedenParam.h"
#include <string>
#include "UzemnaJednotka.h"
#include "../Volby/structures/heap_monitor.h"

class FilterNazov : public FilterJedenParam<std::string,UzemnaJednotka>
{
public:
	FilterNazov(std::string p_nazovUzemnejJednotky);
	~FilterNazov();
};

