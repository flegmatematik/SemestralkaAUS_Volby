#pragma once
#include <iostream>
#include "UzemnaJednotka.h"
#include "structures/table/sorted_sequence_table.h"
#include "Kriterium.h"
#include "FilterJedenParam.h"
#include "structures/table/unsorted_sequence_table.h"
#include "FilterDvaParam.h"

class Rozhranie
{
private:
	structures::SortedSequenceTable<int, UzemnaJednotka*>* ObceSequence;
	structures::SortedSequenceTable<int, UzemnaJednotka*>* OkresySequence;
	structures::SortedSequenceTable<int, UzemnaJednotka*>* KrajeSequence;
public:
	Rozhranie();

	void vyberMoznosti();
	void FiltrovaniePodlaKriteria();

	template <typename K, typename T, typename P, typename O>
	void FiltrujJedenParameter(P alfa, Kriterium<O, T*>* krit, structures::UnsortedSequenceTable<K,T*>& seqNaFilter);

	template <typename K, typename T, typename P, typename O>
	void FiltrujDvaParametre(P alfa, P beta, Kriterium<O, T*>* krit, structures::UnsortedSequenceTable<K, T*>& seqNaFilter);
	//void ZoradenieBezFiltrov();
	void ZoradenieSFitrami();
	~Rozhranie();
};

template <typename K, typename T, typename P, typename O>
void Rozhranie::FiltrujJedenParameter(P alfa, Kriterium<O, T*>* krit, structures::UnsortedSequenceTable<K, T*>& seqNaFilter)
{
	FilterJedenParam<P, T*>* filter_jeden = new FilterJedenParam<P, T*>(alfa);
	structures::UnsortedSequenceTable<K, T*>* pomocny = new structures::UnsortedSequenceTable<K, T*>;

	for (structures::TableItem<K,T*>* element : seqNaFilter)
	{
		pomocny->insert(element->getKey(), element->accessData());
	}

	seqNaFilter.clear();

	for (structures::TableItem<K,T*>* element : *pomocny)
	{
		if(filter_jeden->filtruj(element->accessData(),krit))
		{
			seqNaFilter.insert(element->getKey(), element->accessData());
		}
	}
	int p = 0;
}


template <typename K, typename T, typename P, typename O>
void Rozhranie::FiltrujDvaParametre(P alfa, P beta, Kriterium<O, T*>* krit, structures::UnsortedSequenceTable<K, T*>& seqNaFilter)
{
	FilterDvaParam<P, T*>* filter_dva = new FilterDvaParam<P, T*>(alfa,beta);
	structures::UnsortedSequenceTable<K, T*>* pomocny = new structures::UnsortedSequenceTable<K, T*>;

	for (structures::TableItem<K, T*>* element : seqNaFilter)
	{
		pomocny->insert(element->getKey(), element->accessData());
	}
	seqNaFilter.clear();

	for (structures::TableItem<K, T*>* element : *pomocny)
	{
		if (filter_dva->filtruj(element->accessData(), krit))
		{
			seqNaFilter.insert(element->getKey(), element->accessData());
		}
	}
}







