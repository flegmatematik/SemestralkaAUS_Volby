#pragma once
template <typename T, typename O>
class Kriterium
{
public:
	virtual T ohodnot(O &objekt) = 0;
protected:
	Kriterium();
	~Kriterium();
};

template <typename T, typename O>
Kriterium<T, O>::Kriterium()
{

}

template <typename T, typename O>
Kriterium<T, O>::~Kriterium()
{

}

