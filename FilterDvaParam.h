#pragma once
#include "Filter.h"

template<typename T, typename O>
class FilterDvaParam :public Filter<T,O>
{
private:
	T alfa;
	T beta;
protected:
	FilterDvaParam(T p_alfa, T p_beta);
	~FilterDvaParam() = default;
public:
	bool filtruj( O& objekt,  Kriterium<T, O>& krit) override
	{
		T vysledok = krit.ohodnot(objekt);
		return vysledok >= alfa && vysledok <= beta;
	}
};

template <typename T, typename O>
FilterDvaParam<T, O>::FilterDvaParam(T p_alfa, T p_beta): alfa(p_alfa),beta(p_beta)
{
}
