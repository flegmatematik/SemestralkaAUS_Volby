#pragma once
#include "FilterJedenParam.h"
#include <string>
#include "UzemnaJednotka.h"

class FilterNazov : public FilterJedenParam<std::string,UzemnaJednotka>
{
public:
	FilterNazov(std::string p_nazovUzemnejJednotky);
	~FilterNazov();
};

