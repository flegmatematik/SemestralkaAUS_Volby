#pragma once
template <typename P, typename T>
class Kriterium
{
public:
	virtual P ohodnot(T objekt) = 0;
protected:
	Kriterium();
	~Kriterium();
};

template <typename P, typename T>
Kriterium<P, T>::Kriterium()
{

}

template <typename P, typename T>
Kriterium<P, T>::~Kriterium()
{

}

