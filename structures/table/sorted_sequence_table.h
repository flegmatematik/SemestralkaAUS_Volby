#pragma once

#include "../list/array_list.h"
#include "sequence_table.h"
#include <algorithm>

namespace structures
{

	/// <summary> Utriedena sekvencna tabulka. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class SortedSequenceTable : public SequenceTable<K, T>
	{
	public:
		/// <summary> Konstruktor. </summary>
		SortedSequenceTable();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> SortedSequenceTable, z ktorej sa prevezmu vlastnosti. </param>
		SortedSequenceTable(const SortedSequenceTable<K, T>& other);

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		Structure* clone() const override;

		/// <summary> Vlozi data s danym klucom do tabulky. </summary>
		/// <param name = "key"> Kluc vkladanych dat. </param>
		/// <param name = "data"> Vkladane data. </param>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>  
		void insert(const K& key, const T& data) override;
	protected:
		/// <summary> Najde prvok tabulky s danym klucom. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <returns> Prvok tabulky s danym klucom, ak neexistuje, vrati nullptr. </returns>
		TableItem<K, T>* findTableItem(const K& key) const override;
	private:
		/// <summary> Najde index prvku s danym klucom. Kontroluje rozsah [indexStart, indexEnd). Pracuje na principe bisekcie. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <param name = "indexStart"> Pociatocny index prehladavanej sekvencie. </param>
		/// <param name = "indexEnd"> Koncovy index prehladavanej sekvencie. </param>
		/// <param name = "found"> Vystupny parameter, ktory indikuje, ci sa kluc nasiel. </param>
		/// <returns> Index prvku s danym klucom. Ak sa kluc v tabulke nenachadza, vrati index, kde by sa mal prvok s takym klucom nachadzat. </returns>
		int indexOfKey(const K& key, int indexStart, int indexEnd, bool& found) const;
	};

	template<typename K, typename T>
	inline SortedSequenceTable<K, T>::SortedSequenceTable() :
		SequenceTable<K, T>(new ArrayList<TableItem<K, T>*>())
	{
	}

	template<typename K, typename T>
	inline SortedSequenceTable<K, T>::SortedSequenceTable(const SortedSequenceTable<K, T>& other) :
		SortedSequenceTable()
	{
		*this = other;
	}

	template<typename K, typename T>
	inline Structure * SortedSequenceTable<K, T>::clone() const
	{
		return new SortedSequenceTable<K, T>(*this);
	}

	template<typename K, typename T>
	inline void SortedSequenceTable<K, T>::insert(const K & key, const T & data)
	{
		//TODO 09: SortedSequenceTable
		// najprv najst pomocou indexOfkey, ak uz je tak logic error
		bool jeRovnaky;
		//ak tam nieje, vrati na ake miesto to moze vlozit
		int naKtoreMiesto = indexOfKey(key, 0, this->size(), jeRovnaky);

		if(!jeRovnaky)
		{
			TableItem<K, T>* novyPrvok = new TableItem<K, T>(key, data);
			this->list_->insert(novyPrvok, naKtoreMiesto);
		}
		else
		{
			throw std::logic_error("Prvok s danym klucom tu uz je.");
		}
	}

	template<typename K, typename T>
	inline TableItem<K, T>* SortedSequenceTable<K, T>::findTableItem(const K & key) const
	{
		//TODO 09: SortedSequenceTable
		// bisekcia uz v indexOfKey
		if(this->size() == 0)
		{
			return nullptr;
		}

		bool jeTam = false;
		int index = indexOfKey(key, 0, this->size(), jeTam);
		if(jeTam)
		{
			return (*this->list_)[index];
		}
		else
		{
			return nullptr;
		}

	}

	template<typename K, typename T>
	inline int SortedSequenceTable<K, T>::indexOfKey(const K & key, int indexStart, int indexEnd, bool & found) const
	{
		//TODO 09: SortedSequenceTable
		if(indexStart == this->size())
		{
			found = false;
			return this->size();
		}
		int stred = (indexStart + indexEnd) / 2;
		K klucVstrede = (*this->list_)[stred]->getKey();
		//bisekcia
		if((*this->list_)[stred]->getKey() == key)
		{
			found = true;
			return stred;
		}
		else
		{
			if(indexStart == indexEnd)
			{
				found = false;
				if (key < klucVstrede)
					return  stred;
				return  stred + 1;
			}
			else
			{
				if(klucVstrede < key)
				{
					indexStart = stred + 1;
				}
				else
				{
					indexEnd = stred;
				}
				//rekurzia
				return indexOfKey(key, indexStart, indexEnd, found);
			}
		}
	}
}
