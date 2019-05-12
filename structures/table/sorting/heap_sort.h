#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"
#include "../../../Kriterium.h"
#include <stack>

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T, typename P>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sortMoj(UnsortedSequenceTable<K, T*>* table ,Kriterium<P, T*>* krit);
	};

	template <typename K, typename T,typename P>
	void HeapSort<K, T, P>::sort(UnsortedSequenceTable<K, T>& table)
	{
		//TODO 12: HeapSort
		throw std::exception("este nie.");
	}

	template <typename K, typename T, typename P>
	void HeapSort<K, T, P>::sortMoj(UnsortedSequenceTable<K, T*>* table, Kriterium<P, T*>* krit)
	{
		//TODO 12: HeapSort
		int aktualny;
		bool vymena;
		for (int i = 1; i < table->size(); ++i)
		{
			aktualny = i;
			do
			{
				vymena = false;
				int otec = (aktualny - 1) / 2;

				if (aktualny > 0 && krit->ohodnot(table->getItemAtIndex(aktualny).accessData()) > krit->ohodnot(table->getItemAtIndex(otec).accessData()))
				{
					table->swap(table->getItemAtIndex(aktualny), table->getItemAtIndex(otec));
					aktualny = otec;
					vymena = true;
				}

			} while (vymena);
		}

		int max;
		// i> 0 alebo i > 1
		for (int i = table->size() - 1; i > 0; --i)
		{
			table->swap(table->getItemAtIndex(0), table->getItemAtIndex(i));
			aktualny = 0;
			do
			{

				vymena = false;
				int lavy = aktualny * 2 + 1;
				int pravy = aktualny * 2 + 2;
				if (lavy < i && pravy < i)
				{
					max = krit->ohodnot(table->getItemAtIndex(lavy).accessData()) > krit->ohodnot(table->getItemAtIndex(pravy).accessData()) ? lavy : pravy;

				}
				else
				{
					max = lavy < i ? lavy : pravy;

				}
				if (max < i && krit->ohodnot(table->getItemAtIndex(max).accessData()) > krit->ohodnot(table->getItemAtIndex(aktualny).accessData()))
				{
					table->swap(table->getItemAtIndex(max), table->getItemAtIndex(aktualny));
					aktualny = max;
					vymena = true;
				}

			} while (vymena);
		}
	}


}
