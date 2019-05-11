#pragma once
#include "Filter.h"

template<typename P, typename T>
class FilterDvaParam :public Filter<P,T>
{

protected:
	P alfa;
	P beta;
	FilterDvaParam(P p_alfa, P p_beta);
	~FilterDvaParam() = default;
public:

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
