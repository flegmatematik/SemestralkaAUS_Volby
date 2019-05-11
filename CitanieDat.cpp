#include "CitanieDat.h"
#include <iostream>
#include "Kraj.h"
#include "Filter.h"
#include "structures/tree/multi_way_tree.h"
#include "KriteriumNazov.h"
#include "structures/table/unsorted_sequence_table.h"
#include "FilterJedenParam.h"
#include "FilterNazov.h"
#include "structures/table/sorting/heap_sort.h"


CitanieDat::CitanieDat()
{
	std::string obcekolo1 = "PRE_2019_KOLO1_obce_korektne.csv";
	std::string obcekolo2 = "PRE_2019_KOLO2_obce_korektne.csv";
	std::string okresykolo1 = "PRE_2019_KOLO1_okresy_korektne.csv";
	std::string okresykolo2 = "PRE_2019_KOLO2_okresy_korektne.csv";
	std::string krajekolo1 = "PRE_2019_KOLO1_kraje_korektne.csv";
	std::string krajekolo2 = "PRE_2019_KOLO2_kraje_korektne.csv";

	structures::UnsortedSequenceTable<int, UzemnaJednotka*>* obseq = new structures::UnsortedSequenceTable<int, UzemnaJednotka*>;
	structures::BinarySearchTree<int, UzemnaJednotka*> ObceStrom_;
	structures::BinarySearchTree<int, UzemnaJednotka*> OkresyStrom_;
	structures::BinarySearchTree<int, UzemnaJednotka*> KrajeStrom_;


	std::ifstream citacObce1(obcekolo1);
	std::ifstream citacObce2(obcekolo2);
	std::ifstream citacOkresy1(okresykolo1);
	std::ifstream citacOkresy2(okresykolo2);
	std::ifstream citacKraje1(krajekolo1);
	std::ifstream citacKraje2(krajekolo2);

	if(citacKraje1.is_open() && citacKraje2.is_open())
	{
		std::string p_kodKraja;
		std::string p_nazovKraja;
		std::string pocet_volicov;
		std::string obalky_vydane;
		std::string ucast_volicov;
		std::string obalky_odovzdane;
		std::string platne_dokopy;

		while(!citacKraje1.eof() || !citacKraje2.eof())
		{
			std::getline(citacKraje1,p_kodKraja , ';');
			std::getline(citacKraje1,p_nazovKraja , ';');
			std::getline(citacKraje1, pocet_volicov, ';');
			std::getline(citacKraje1, obalky_vydane, ';');
			std::getline(citacKraje1,ucast_volicov , ';');
			std::getline(citacKraje1, obalky_odovzdane, ';');
			std::getline(citacKraje1, platne_dokopy, '\n');

			Data *koloJedna = new Data(stoi(pocet_volicov), stoi(obalky_vydane), stod(ucast_volicov), stoi(obalky_odovzdane), stoi(platne_dokopy));
		
			std::getline(citacKraje2, p_kodKraja, ';');
			std::getline(citacKraje2, p_nazovKraja, ';');
			std::getline(citacKraje2, pocet_volicov, ';');
			std::getline(citacKraje2, obalky_vydane, ';');
			std::getline(citacKraje2, ucast_volicov, ';');
			std::getline(citacKraje2, obalky_odovzdane, ';');
			std::getline(citacKraje2, platne_dokopy, '\n');

			Data *koloDva = new Data(stoi(pocet_volicov), stoi(obalky_vydane), stod(ucast_volicov), stoi(obalky_odovzdane), stoi(platne_dokopy));
			Kraj *kraj = new Kraj(koloJedna, koloDva, stoi(p_kodKraja), p_nazovKraja);
			KrajeStrom_.insert(stoi(p_kodKraja),kraj);

		}
	}
	citacKraje1.close();
	citacKraje2.close();

	if(citacOkresy1.is_open() && citacOkresy2.is_open())
	{
		std::string p_kodKraja;
		std::string p_kodOkresu;
		std::string p_nazovOkresu;
		std::string pocet_volicov;
		std::string obalky_vydane;
		std::string ucast_volicov;
		std::string obalky_odovzdane;
		std::string platne_dokopy;

		while(!citacOkresy1.eof() || !citacOkresy2.eof())
		{
			std::getline(citacOkresy1, p_kodKraja, ';');
			std::getline(citacOkresy1, p_kodOkresu, ';');
			std::getline(citacOkresy1, p_nazovOkresu, ';');
			std::getline(citacOkresy1, pocet_volicov, ';');
			std::getline(citacOkresy1, obalky_vydane, ';');
			std::getline(citacOkresy1, ucast_volicov, ';');
			std::getline(citacOkresy1, obalky_odovzdane, ';');
			std::getline(citacOkresy1, platne_dokopy, '\n');

			Data *koloJedna = new Data(stoi(pocet_volicov), stoi(obalky_vydane), stod(ucast_volicov), stoi(obalky_odovzdane), stoi(platne_dokopy));

			std::getline(citacOkresy2, p_kodKraja, ';');
			std::getline(citacOkresy2, p_kodOkresu, ';');
			std::getline(citacOkresy2, p_nazovOkresu, ';');
			std::getline(citacOkresy2, pocet_volicov, ';');
			std::getline(citacOkresy2, obalky_vydane, ';');
			std::getline(citacOkresy2, ucast_volicov, ';');
			std::getline(citacOkresy2, obalky_odovzdane, ';');
			std::getline(citacOkresy2, platne_dokopy, '\n');

			Data *koloDva = new Data(stoi(pocet_volicov), stoi(obalky_vydane), stod(ucast_volicov), stoi(obalky_odovzdane), stoi(platne_dokopy));

			Okres *okres = new Okres(koloJedna, koloDva,stoi(p_kodOkresu), p_nazovOkresu, KrajeStrom_[std::stoi(p_kodKraja)]);
			OkresyStrom_.insert(stoi(p_kodOkresu),okres);
		}
	}

	citacOkresy1.close();
	citacOkresy2.close();

	if (citacObce2.is_open() && citacObce1.is_open())
	{

		std::string p_kodOkresu;
		std::string p_kodObce;
		std::string p_nazovObce;
		std::string pocet_volicov;
		std::string obalky_vydane;
		std::string ucast_volicov;
		std::string obalky_odovzdane;
		std::string platne_dokopy;

		while (!citacObce2.eof() || !citacObce1.eof())
		{
			std::getline(citacObce1, p_kodOkresu, ';');
			std::getline(citacObce1, p_kodObce, ';');
			std::getline(citacObce1, p_nazovObce, ';');
			std::getline(citacObce1, pocet_volicov, ';');
			std::getline(citacObce1, obalky_vydane, ';');
			std::getline(citacObce1, ucast_volicov, ';');
			std::getline(citacObce1, obalky_odovzdane, ';');
			std::getline(citacObce1, platne_dokopy, '\n');

			Data *koloJedna = new Data(stoi(pocet_volicov),stoi(obalky_vydane),stod(ucast_volicov),stoi(obalky_odovzdane), stoi(platne_dokopy));
			
			std::getline(citacObce2, p_kodOkresu, ';');
			std::getline(citacObce2, p_kodObce, ';');
			std::getline(citacObce2, p_nazovObce, ';');
			std::getline(citacObce2, pocet_volicov, ';');
			std::getline(citacObce2, obalky_vydane, ';');
			std::getline(citacObce2, ucast_volicov, ';');
			std::getline(citacObce2, obalky_odovzdane, ';');
			std::getline(citacObce2, platne_dokopy, '\n');

			Data *koloDva = new Data(stoi(pocet_volicov), stoi(obalky_vydane), stod(ucast_volicov), stoi(obalky_odovzdane), stoi(platne_dokopy));
			
			Obec *obec = new Obec(koloJedna, koloDva, std::stoi(p_kodObce), p_nazovObce,OkresyStrom_[stoi(p_kodOkresu)]);
			//std::cout << obec->nazov() << "\n";
			//ObceStrom_.insert(std::stoi(p_kodObce), obec);
			obseq->insert(std::stoi(p_kodObce), obec);
		}
		citacObce1.close();
		citacObce2.close();

		
		KriteriumNazov *p = new KriteriumNazov();
		//FilterNazov *f = new FilterNazov("Martin");
		FilterJedenParam < std::string, UzemnaJednotka*>* fjp = new FilterJedenParam<std::string, UzemnaJednotka*>("Martin");
		/*
		for (structures::TableItem<int, UzemnaJednotka*>*  element : ObceStrom_)
		{
			std::cout << p->ohodnot(*element->accessData());
		}
		*/
		for ( structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			p->ohodnot(element->accessData());
		}
		/*
		for (structures::TableItem<int, UzemnaJednotka*>* element : ObceStrom_)
		{
			fjp->filtruj(*element->accessData(), *p);
			//std::cout << f->filtruj(*element->accessData(), *p);
		}
		*/
		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			fjp->filtruj(element->accessData(), p);
			//std::cout << f->filtruj(*element->accessData(), *p);
		}
		
		structures::HeapSort<int, UzemnaJednotka,std::string> *sorter = new structures::HeapSort<int, UzemnaJednotka, std::string>;
		sorter->sortMoj(obseq, p, true);

		int o = 1;

		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			std::cout << o;
			std::cout << element->accessData()->nazov();
			std::cout << "\n";
			o++;
		}

	}
}
