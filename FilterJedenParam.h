#pragma once
#include "Filter.h"
#include "../Volby/structures/heap_monitor.h"

template<typename P, typename T>
class FilterJedenParam :public Filter<P, T>
{
protected:
	P alfa;

public:
	FilterJedenParam(P p_alfa);
	~FilterJedenParam() = default;

	bool filtruj(T objekt, Kriterium<P, T>* krit) override
	{
		return alfa == krit->ohodnot(objekt);
	}
};

template <typename P, typename T>
FilterJedenParam<P, T>::FilterJedenParam(P p_alfa) : alfa(p_alfa)
{
}





