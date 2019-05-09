#pragma once
#include "Filter.h"

template<typename T, typename O>
class FilterJedenParam :public Filter<T, O>
{
protected:
	T alfa;

public:
	bool filtruj(O& objekt, Kriterium<T, O>& krit) override
	{
		return alfa == krit.ohodnot(objekt);
	}
	FilterJedenParam(T p_alfa);
	virtual ~FilterJedenParam() = default;
};

template <typename T, typename O>
FilterJedenParam<T, O>::FilterJedenParam(T p_alfa) : alfa(p_alfa)
{
}





