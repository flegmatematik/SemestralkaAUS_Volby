#pragma once

#include "table.h"
#include "../list/list.h"
#include "../tree/binary_tree.h"
#include <stdexcept>
#include <chrono>

namespace structures
{

	/// <summary> Binarny vyhladavaci strom. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class BinarySearchTree : public Table<K, T>
	{
	public:
		typedef typename BinaryTreeNode<TableItem<K, T>*> BSTTreeNode;
	public:
		/// <summary> Konstruktor. </summary>
		BinarySearchTree();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> BinarySearchTree, z ktoreho sa prevezmu vlastnosti. </param>
		BinarySearchTree(const BinarySearchTree<K, T>& other);

		/// <summary> Destruktor. </summary>
		~BinarySearchTree();

		/// <summary> Operacia klonovania. Vytvori a vrati duplikat udajovej struktury. </summary>
		/// <returns> Ukazovatel na klon struktury. </returns>
		virtual Structure* clone() const;

		/// <summary> Vrati pocet prvkov v tabulke. </summary>
		/// <returns> Pocet prvkov v tabulke. </returns>
		size_t size() const override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Tabulka, z ktorej ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato tabulka nachadza po priradeni. </returns>
		Table<K, T>& operator=(const Table<K, T>& other) override;

		/// <summary> Operator priradenia. </summary>
		/// <param name = "other"> Binarny vyhladavaci strom, z ktoreho ma prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa tato tabulka nachadza po priradeni. </returns>
		virtual BinarySearchTree<K, T>& operator=(const BinarySearchTree<K, T>& other);

		/// <summary> Vrati adresou data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> Adresa dat s danym klucom. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak kluc nepatri do tabulky. </exception>  
		T& operator[](const K key) override;

		/// <summary> Vrati hodnotou data s daynm klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> Hodnota dat s danym klucom. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak kluc nepatri do zoznamu. </exception>  
		const T operator[](const K key) const override;

		/// <summary> Vlozi data s danym klucom do tabulky. </summary>
		/// <param name = "key"> Kluc vkladanych dat. </param>
		/// <param name = "data"> Vkladane data. </param>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka uz obsahuje data s takymto klucom. </exception>  
		void insert(const K& key, const T& data) override;

		/// <summary> Odstrani z tabulky prvok s danym klucom. </summary>
		/// <param name = "key"> Kluc prvku. </param>
		/// <returns> Odstranene data. </returns>
		/// <exception cref="std::logic_error"> Vyhodena, ak tabulka neobsahuje data s takymto klucom. </exception>  
		T remove(const K& key) override;

		/// <summary> Bezpecne ziska data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <param name = "data"> Najdene data (vystupny parameter). </param>
		/// <returns> true, ak sa podarilo najst a naplnit data s danym klucom, false inak. </returns>
		bool tryFind(const K& key, T& data) override;

		/// <summary> Zisti, ci tabulka obsahuje data s danym klucom. </summary>
		/// <param name = "key"> Kluc dat. </param>
		/// <returns> true, tabulka obsahuje dany kluc, false inak. </returns>
		bool containsKey(const K& key) override;

		/// <summary> Vymaze tabulku. </summary>
		void clear() override;

		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<TableItem<K, T>*>* getBeginIterator() const override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<TableItem<K, T>*>* getEndIterator() const override;
	protected:
		/// <summary> Najde vrchol binarneho vyhladavacieho stromu s danym klucom. </summary>
		/// <param name = "key"> Hladany kluc. </param>
		/// <param name = "found"> Vystupny parameter, ktory indikuje, ci sa kluc nasiel. </param>
		/// <returns> Vrchol binarneho vyhladavacieho stromu s danym klucom. Ak sa kluc v tabulke nenachadza, vrati otca, ktoreho by mal mat vrchol s takym klucom. </returns>
		typename BSTTreeNode* findBSTNode(const K& key, bool & found) const;
	protected:
		/// <summary> Binarny strom s datami. </summary>
		BinaryTree<TableItem<K, T>*>* binaryTree_;
		/// <summary> Pocet prvkov v binarnom vyhladavacom strome. </summary>
		size_t size_;

		/// <summary> Vlozi vrchol do stromu tak, aby nedoslo k naruseniu usporiadania BST. </summary>
		/// <param name = "node"> Vrchol stromu, ktory ma byt vlozeny. </param>
		/// <returns> true, ak sa podarilo vrchol vlozit (teda v strome nie je vrchol s rovnakym klucom), false inak. </returns>
		bool tryToInsertNode(BSTTreeNode* node);

		/// <summary> Bezpecne vyjme zo stromu vrchol stromu tak, aby nedoslo k naruseniu usporiadania BST. </summary>
		/// <param name = "node"> Vrchol stromu, ktory ma byt vyjmuty. </param>
		/// <remarks> Vrchol nebude zruseny, iba odstraneny zo stromu a ziadne vrcholy nebudu ukazovat na neho a ani on nebude ukazovat na ziadne ine vrcholy. </remarks>
		void extractNode(BSTTreeNode* node);
	};

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::BinarySearchTree():
		Table<K, T>(),
		binaryTree_(new BinaryTree<TableItem<K, T>*>()),
		size_(0)
	{
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::BinarySearchTree(const BinarySearchTree<K, T>& other):
		BinarySearchTree()
	{
		*this = other;
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>::~BinarySearchTree()
	{
		clear();
		delete binaryTree_;
	}

	template<typename K, typename T>
	inline Structure * BinarySearchTree<K, T>::clone() const
	{
		return new BinarySearchTree<K, T>(*this);
	}

	template<typename K, typename T>
	inline size_t BinarySearchTree<K, T>::size() const
	{
		return size_;
	}

	template<typename K, typename T>
	inline Table<K, T>& BinarySearchTree<K, T>::operator=(const Table<K, T>& other)
	{
		if (this != &other)
		{
			*this = dynamic_cast<const BinarySearchTree<K, T>&>(other);
		}
		return *this;
	}

	template<typename K, typename T>
	inline BinarySearchTree<K, T>& BinarySearchTree<K, T>::operator=(const BinarySearchTree<K, T>& other)
	{
		if (this != &other)
		{
			clear();
			Iterator<TableItem<K, T>*>* iterCurr = new Tree<TableItem<K, T>*>::LevelOrderTreeIterator(other.binaryTree_->getRoot());
			Iterator<TableItem<K, T>*>* iterKoniec = new Tree<TableItem<K, T>*>::LevelOrderTreeIterator(nullptr);


			while(*iterCurr != *iterKoniec)
			{
				TableItem<K, T>* item = *(*iterCurr);
				insert(item->getKey(), item->accessData());
				iterCurr->operator++();
			}
			delete iterCurr;
			delete iterKoniec;
		}
		return *this;

	}

	template<typename K, typename T>
	inline T & BinarySearchTree<K, T>::operator[](const K key)
	{
		//TODO 10: BinarySearchTree
		bool nasiel;
		BinaryTreeNode<TableItem<K,T>*> *item = findBSTNode(key, nasiel);
		

		if(nasiel)
		{
			return (*item).accessData()->accessData();
		}
		throw std::exception("neni to tu.");
	}

	template<typename K, typename T>
	inline const T BinarySearchTree<K, T>::operator[](const K key) const
	{
		//TODO 10: BinarySearchTree
		bool nasiel;
		BinaryTreeNode<TableItem<K, T>*> *item = findBSTNode(key, nasiel);


		if (nasiel)
		{
			return item->accessData()->accessData();
		}
		throw std::exception("neni to tu.");
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::insert(const K & key, const T & data)
	{
		//TODO 10: BinarySearchTree
		bool nasiel = false;
		//BSTTreeNode* rodic = findBSTNode(key, nasiel);
		BinaryTreeNode<TableItem<K,T>*> *item = findBSTNode(key, nasiel);


		if(!nasiel)
		{
			TableItem<K, T> *titem = new TableItem<K, T>(key, data);
			BinaryTreeNode<TableItem<K, T>*>* syn = new BinaryTreeNode<TableItem<K, T>*>(titem);
			if(size_ == 0)
			{
				binaryTree_->replaceRoot(syn);
			}
			else {
				if (syn->accessData()->getKey() > item->accessData()->getKey())
				{
					item->setRightSon(syn);
				}
				else
				{
					item->setLeftSon(syn);
				}
				size_++;
			}
		}
		throw std::exception("uz sa tu nachadza");
	}

	template<typename K, typename T>
	inline T BinarySearchTree<K, T>::remove(const K & key)
	{
		bool nasiel = false;
		BinaryTreeNode<TableItem<K,T>*> *najdeny = findBSTNode(key, nasiel);

		if(nasiel)
		{
			extractNode(najdeny);
			size_--;
			T data = najdeny->accessData()->accessData();
			delete najdeny->accessData();
			delete najdeny;
			return data;
		}
		throw std::exception("dany kluc sa tu nenachadza.");
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::tryFind(const K & key, T & data)
	{
		//TODO 10: BinarySearchTree
		bool najdeny = false;
		BinaryTreeNode<TableItem<K, T>*>* item = findBSTNode(key, najdeny);

		if(najdeny)
		{
			data = item->accessData()->accessData();
		}
		return najdeny;
		
	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::containsKey(const K & key)
	{
		//TODO 10: BinarySearchTree
		bool najdeny = false;
		findBSTNode(key, najdeny);
		return najdeny;
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::clear()
	{
		//TODO 10: BinarySearchTree
		for (TableItem<K,T> *item : *binaryTree_)
		{
			delete item;
		}
		binaryTree_->clear();
		size_ = 0;
	}

	template<typename K, typename T>
	inline Iterator<TableItem<K, T>*>* BinarySearchTree<K, T>::getBeginIterator() const
	{
		//inorder
		//TODO 10: BinarySearchTree
		//return new structures::BinaryTree<TableItem<K, T>*>::InOrderTreeIterator(binaryTree_->getRoot());
		return new typename BinaryTree<TableItem<K, T>*>::InOrderTreeIterator(binaryTree_->getRoot());
	}

	template<typename K, typename T>
	inline Iterator<TableItem<K, T>*>* BinarySearchTree<K, T>::getEndIterator() const
	{
		//TODO 10: BinarySearchTree
		return new BinaryTree<TableItem<K, T>*>::InOrderTreeIterator(nullptr);
	}

	template<typename K, typename T>
	inline typename BinarySearchTree<K,T>::BSTTreeNode* BinarySearchTree<K, T>::findBSTNode(const K & key, bool & found) const
	{
		//TODO 10: BinarySearchTree
		BSTTreeNode* uzol = (BSTTreeNode*)(binaryTree_->getRoot());
		BSTTreeNode* hladany = uzol;

		while(uzol != nullptr && uzol->accessData()->getKey() != key)
		{
			uzol = key < uzol->accessData()->getKey() ? uzol->getLeftSon() : uzol->getRightSon();
			if (uzol != nullptr)
				hladany = uzol; //posledny platny
		}
		found = (uzol != nullptr) && (uzol->accessData()->getKey() == key);
		return hladany;

	}

	template<typename K, typename T>
	inline bool BinarySearchTree<K, T>::tryToInsertNode(BSTTreeNode* node)
	{
		//TODO 10: BinarySearchTree
		throw std::exception("BinarySearchTree<K, T>::tryToInsertNode: Not implemented yet.");
	}

	template<typename K, typename T>
	inline void BinarySearchTree<K, T>::extractNode(BSTTreeNode* node)
	{
		//TODO 10: BinarySearchTree
		BSTTreeNode* parent = node->getParent();
		BSTTreeNode* replacenode = nullptr;

		switch (node->numberOfSons())
		{
		case 1:
			replacenode = node->hasLeftSon() ? node->changeLeftSon(nullptr) : node->changeRightSon(nullptr);
			break;
		case 2:
			replacenode = node->getRightSon();
			while (replacenode->hasLeftSon())
			{
				replacenode = replacenode->getLeftSon();
			}
			extractNode(replacenode);
			replacenode->setLeftSon(node->changeLeftSon(nullptr));
			replacenode->setRightSon(node->changeRightSon(nullptr));
		}
		//ak root
		if(parent == nullptr)
		{
			binaryTree_->replaceRoot(replacenode);
		}
		//syn
		else
		{
			if (node->isLeftSon())
				parent->setLeftSon(replacenode);
			else
				parent->setRightSon(replacenode);
			if (replacenode != nullptr)
				replacenode->setParent(parent);
		}
	}

}
