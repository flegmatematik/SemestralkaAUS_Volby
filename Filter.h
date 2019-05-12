#pragma once
#include "Kriterium.h"
#include "../Volby/structures/heap_monitor.h"
template <typename P,typename T>
class Filter
{
public:
	virtual bool filtruj(T objekt, Kriterium<P, T>* krit) = 0;
	Filter();
	virtual ~Filter();
};

template <typename P, typename T>
Filter<P, T>::Filter()
{
}

template <typename P, typename T>
Filter<P, T>::~Filter()
{
}


