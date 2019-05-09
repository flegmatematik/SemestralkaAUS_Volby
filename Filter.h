#pragma once
#include "Kriterium.h"

template <typename T,typename O>
class Filter
{
public:
	virtual bool filtruj(O& objekt, Kriterium<T, O>& krit) = 0;
protected:
	Filter();
	~Filter();
};

template <typename T, typename O>
Filter<T, O>::Filter()
{
}

template <typename T, typename O>
Filter<T, O>::~Filter()
{
}


