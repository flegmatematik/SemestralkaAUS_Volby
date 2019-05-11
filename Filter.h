#pragma once
#include "Kriterium.h"

template <typename P,typename T>
class Filter
{
public:
	virtual bool filtruj(T objekt, Kriterium<P, T>* krit) = 0;
protected:
	Filter();
	~Filter();
};

template <typename P, typename T>
Filter<P, T>::Filter()
{
}

template <typename P, typename T>
Filter<P, T>::~Filter()
{
}


