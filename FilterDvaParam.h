#pragma once
#include "Filter.h"
#include "../Volby/structures/heap_monitor.h"
template<typename P, typename T>
class FilterDvaParam :public Filter<P,T>
{

protected:
	P alfa;
	P beta;

public:
	FilterDvaParam(P p_alfa, P p_beta);
	~FilterDvaParam() = default;
	bool filtruj(T objekt, Kriterium<P, T>* krit) override
	{
		P vysledok = krit->ohodnot(objekt);
		return vysledok >= alfa && vysledok <= beta;
	}
};

template <typename P, typename T>
FilterDvaParam<P, T>::FilterDvaParam(P p_alfa, P p_beta): alfa(p_alfa),beta(p_beta)
{
}
