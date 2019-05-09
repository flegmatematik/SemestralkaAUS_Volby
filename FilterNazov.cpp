#include "FilterNazov.h"


FilterNazov::FilterNazov(std::string p_nazovUzemnejJednotky): FilterJedenParam<std::string, UzemnaJednotka>(p_nazovUzemnejJednotky)
{
}


FilterNazov::~FilterNazov()
{
}

