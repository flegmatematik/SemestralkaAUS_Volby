#pragma once
#include "../Volby/structures/heap_monitor.h"

template <typename P, typename T>
class Kriterium
{
public:
	virtual P ohodnot(T objekt) = 0;
	Kriterium();
	virtual ~Kriterium();
};

template <typename P, typename T>
Kriterium<P, T>::Kriterium()
{

}

template <typename P, typename T>
Kriterium<P, T>::~Kriterium()
{

}

