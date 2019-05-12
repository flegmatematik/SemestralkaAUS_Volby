#include "Rozhranie.h"
#include "../Volby/structures/heap_monitor.h"
#include "CitanieDat.h"
#include "KriteriumNazov.h"
#include "KriteriumPrislusnostObce.h"
#include "KriteriumVolici.h"
#include "KriteriumOdovzdaneObalky.h"
#include "KriteriumUcast.h"
#include "KriteriumVydaneObalky.h"

Rozhranie::Rozhranie() : 
ObceSequence(new structures::SortedSequenceTable<int,UzemnaJednotka*>),
OkresySequence(new structures::SortedSequenceTable<int, UzemnaJednotka*>),
KrajeSequence(new structures::SortedSequenceTable<int, UzemnaJednotka*>)
{
	std::cout << "\n--------------------------------------------------------------\n";
	std::cout << "Vitajte v programe na pracu s vysledkami prezidentskych volieb 2019. \n";
	std::cout << "Stlacenim klavesy 'Enter' nacitate databazu do systemu. \n";
	std::cin.ignore();
	CitanieDat* nacitanie = new CitanieDat(*KrajeSequence,*OkresySequence,*ObceSequence);
	std::cout << "Data uspesne nacitane. \n";
	vyberMoznosti();
	delete nacitanie;
}

void Rozhranie::vyberTypUzemnejJednotky(structures::UnsortedSequenceTable<int, UzemnaJednotka*>& seqNaNaplnenie)
{	
	int typUzemnejJednotky;
	std::cout << "\n--------------------------------------------------------------\n";
	std::cout << "Ktore Uzemne Jednotky chcete filtrovat? \n";
	std::cout << "1. Obce \n2. Okresy \n3.Kraje \n";
	std::cin >> typUzemnejJednotky;

	switch (typUzemnejJednotky)
	{
	case 1:
		for (structures::TableItem<int, UzemnaJednotka*>* element : *ObceSequence)
		{
			seqNaNaplnenie.insert(element->getKey(), element->accessData());
		}
		break;
	case 2:
		for (structures::TableItem<int, UzemnaJednotka*>* element : *OkresySequence)
		{
			seqNaNaplnenie.insert(element->getKey(), element->accessData());
		}
		break;
	case 3:
		for (structures::TableItem<int, UzemnaJednotka*>* element : *KrajeSequence)
		{
			seqNaNaplnenie.insert(element->getKey(), element->accessData());
		}
		break;
	default:
		break;
	}
}


void Rozhranie::vyberMoznosti()
{
	std::cout << "\n--------------------------------------------------------------\n";
	std::cout << "Vyberte z moznosti: \n";
	std::cout << "1. Filtrovanie podla Kriteria. \n";
	std::cout << "2. Zoradenie podla Kriteria bez Filtrov \n";
	std::cout << "3. Zoradenie podla Kriteria s Filtrami \n";
	std::cout << "0. Ukoncit. \n";

	int vyber = 0;
	std::cin >> vyber;

	switch (vyber)
	{
	case 1:
	{
		structures::UnsortedSequenceTable<int, UzemnaJednotka*>* p = new structures::UnsortedSequenceTable<int, UzemnaJednotka*>;
		vyberTypUzemnejJednotky(*p);
		FiltrovaniePodlaKriteria(*p);
		delete p;
	}
		break;
	case 2:
		//ZoradenieBezFiltrov();
		break;
	case 3:
		ZoradenieSFitrami();
		break;
	default:
		return;
	}
	vyberMoznosti();

}


void Rozhranie::FiltrovaniePodlaKriteria(structures::UnsortedSequenceTable<int, UzemnaJednotka*>& seqNaFilter)
{
	int typKriteria;
	std::cout << "\n--------------------------------------------------------------\n";
	std::cout << "Ktore Kriterium Filtra chcete pouzit?  \n";
	std::cout << "1.Nazov \n2.Prislusnost \n3.PocetVolicov \n4.Pocet Vydanych Obalok \n5.Ucast \n6.PocetOdovzdanychObalok \n\n";
	std::cin >> typKriteria;

	switch(typKriteria)
	{
	case 1:
		{
			std::string nazov;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte nazov vyhladavanych Uzemnych Jednotiek   ";
			std::cin.ignore();
			getline(std::cin, nazov);
			FiltrujJedenParameter(nazov, new KriteriumNazov, seqNaFilter);
		}
		break;
	case 2:
		{
			std::string nazov;
			int patriace;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte nazov Vyssej Uzemnej Jednotky   ";
			std::cin.ignore();
			std::getline(std::cin, nazov);
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte '1' ak chcete vyhladat jednotky patriace, a '0' ak nepatriace Vyssej Uzemnej Jednotke";
			std::cin >> patriace;
			if (patriace == 1)
			{
				FiltrujJedenParameter(true, new KriteriumPrislusnostObce(nazov), seqNaFilter);
			}
			else if (patriace == 0) 
			{

				FiltrujJedenParameter(false, new KriteriumPrislusnostObce(nazov), seqNaFilter);
			}

			
		}
		break;
	case 3:
		{
			int kolo;
			int min;
			int max;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
			std::cin >> kolo;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Volici. \n";
			std::cin >> min;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Volici \n";
			std::cin >> max;
			FiltrujDvaParametre(min, max, new KriteriumVolici(kolo), seqNaFilter);

		}
		break;
	case 4:
		{
		int kolo;
		int min;
		int max;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
		std::cin >> kolo;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Vydane Obalky. \n";
		std::cin >> min;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Vydane Obalky \n";
		std::cin >> max;
		FiltrujDvaParametre(min, max, new KriteriumVydaneObalky(kolo), seqNaFilter);

		}
		break;
	case 5:
	{
		int kolo;
		double min;
		double max;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho \n";
		std::cin >> kolo;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Ucast <0;100>. \n";
		std::cin >> min;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Ucast <0;100> \n";
		std::cin >> max;
		FiltrujDvaParametre(min, max, new KriteriumUcast(kolo), seqNaFilter);
	}
		break;
	case 6:
		{
			int kolo;
			int min;
			int max;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
			std::cin >> kolo;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Odovzdane Obalky. \n";
			std::cin >> min;
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Odovzdane Obalky \n";
			std::cin >> max;
			FiltrujDvaParametre(min, max, new KriteriumOdovzdaneObalky(kolo), seqNaFilter);

		}
		break;
	default:
		FiltrovaniePodlaKriteria(seqNaFilter);
	}
	for (structures::TableItem<int, UzemnaJednotka*>* element : seqNaFilter)
	{
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << element->accessData()->toString();
	}
}

void Rozhranie::ZoradenieSFitrami()
{
	structures::UnsortedSequenceTable<int, UzemnaJednotka*>* filtrovana = new structures::UnsortedSequenceTable<int, UzemnaJednotka*>;
	vyberTypUzemnejJednotky(*filtrovana);
	std::cout << "\n--------------------------------------------------------------\n";
	std::cout << "Vyberte prvy filter. \n\n";
	FiltrovaniePodlaKriteria(*filtrovana);
	std::cout << "\n--------------------------------------------------------------\n";
	std::cout << "Vyberte druhy filter. \n\n";
	FiltrovaniePodlaKriteria(*filtrovana);
	std::cout << "Vyberte podla akeho kriteria chcete vysledky triedit. \n";
	int vyberKriteria;
	int vzostupne;
	std::cout << "1.Nazov \n2.PocetVolicov \n3.Ucast \n\n";
	std::cin >> vyberKriteria;
	std::cout << "Zvolte '1' ak vzostupne, a '0' ak zostupne \n\n";
	std::cin >> vzostupne;

	switch(vyberKriteria)
	{
	case 1:
	{
		KriteriumNazov* kritNazov = new KriteriumNazov;
		Sortovanie(filtrovana, kritNazov);
		delete kritNazov;
	}
		break;
	case 2:
	{
		int kolo_v;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
		std::cin >> kolo_v;
		KriteriumVolici* kritVolici = new KriteriumVolici(kolo_v);
		Sortovanie(filtrovana, kritVolici);
		delete kritVolici;
	}
		break;
	case 3:
	{
		int kolo_u;
		std::cout << "\n--------------------------------------------------------------\n";
		std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho. \n";
		std::cin >> kolo_u;
		KriteriumUcast* kritUcast = new KriteriumUcast(kolo_u);
		Sortovanie(filtrovana, kritUcast);
		delete kritUcast;
	}
		break;
	default:
		ZoradenieSFitrami();
	}


	if(vzostupne == 1)
	{
		for (int i = 0; i < filtrovana->size(); ++i)
		{
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << filtrovana->getItemAtIndex(i).accessData()->toString();
		}
	}
	else if(vzostupne == 0)
	{
		for (int i = filtrovana->size()-1; i >-1; --i)
		{
			std::cout << "\n--------------------------------------------------------------\n";
			std::cout << filtrovana->getItemAtIndex(i).accessData()->toString();
		}
	}
	delete filtrovana;
	
	
}

Rozhranie::~Rozhranie()
{
	for (structures::TableItem<int,UzemnaJednotka*>* element : *ObceSequence)
	{
		delete element->accessData();
	}
	delete ObceSequence;
	for (structures::TableItem<int, UzemnaJednotka*>* element : *OkresySequence)
	{
		delete element->accessData();
	}
	delete OkresySequence;
	for (structures::TableItem<int, UzemnaJednotka*>* element : *KrajeSequence)
	{

		delete element->accessData();
	}
	delete KrajeSequence;
}
