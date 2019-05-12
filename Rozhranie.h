#pragma once
#include <iostream>
#include "UzemnaJednotka.h"
#include "structures/table/sorted_sequence_table.h"
#include "Kriterium.h"
#include "FilterJedenParam.h"
#include "structures/table/unsorted_sequence_table.h"
#include "FilterDvaParam.h"
#include "structures/table/sorting/heap_sort.h"
#include "../Volby/structures/heap_monitor.h"

class Rozhranie
{
private:
	structures::SortedSequenceTable<int, UzemnaJednotka*>* ObceSequence;
	structures::SortedSequenceTable<int, UzemnaJednotka*>* OkresySequence;
	structures::SortedSequenceTable<int, UzemnaJednotka*>* KrajeSequence;
public:
	Rozhranie();
	void vyberTypUzemnejJednotky(structures::UnsortedSequenceTable<int, UzemnaJednotka*>& seqNaNaplnenie);
	void vyberMoznosti();
	void vyberSortu(structures::UnsortedSequenceTable<int, UzemnaJednotka*>* seqNaSort);
	void FiltrovaniePodlaKriteria(structures::UnsortedSequenceTable<int, UzemnaJednotka*>& seqNaFilter);

	template <typename K, typename T, typename P, typename O>
	void FiltrujJedenParameter(P alfa, Kriterium<O, T*>* krit, structures::UnsortedSequenceTable<K,T*>& seqNaFilter);

	template <typename K, typename T, typename P, typename O>
	void FiltrujDvaParametre(P alfa, P beta, Kriterium<O, T*>* krit, structures::UnsortedSequenceTable<K, T*>& seqNaFilter);

	void ZoradenieBezFiltrov();
	void ZoradenieSFitrami();

	template<typename K, typename T, typename P>
	void Sortovanie(structures::UnsortedSequenceTable<K,T*>* seqNaSort, Kriterium<P,T*>* krit);

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
	delete krit;
	delete pomocny;
	delete filter_jeden;

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
	delete krit;
	delete pomocny;
	delete filter_dva;
}

template <typename K, typename T, typename P>
void Rozhranie::Sortovanie(structures::UnsortedSequenceTable<K, T*>* seqNaSort, Kriterium<P, T*>* krit)
{
	structures::HeapSort<K, T, P>* sort = new structures::HeapSort<K, T, P>;
	sort->sortMoj(seqNaSort, krit);
	delete sort;
}






