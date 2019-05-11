#include "Rozhranie.h"

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
	std::cout << "Vitajte v programe na pracu s vysledkami prezidentskych volieb 2019. \n";
	std::cout << "Stlacenim klavesy 'Enter' nacitate databazu do systemu. \n";
	std::cin.ignore();
	CitanieDat* nacitanie = new CitanieDat(*KrajeSequence,*OkresySequence,*ObceSequence);
	std::cout << "Data uspesne nacitane. \n";
	vyberMoznosti();

}

void Rozhranie::vyberMoznosti()
{
	std::cout << "Vyberte z moznosti:";
	std::cout << "1. Filtrovanie podla Kriteria. \n";
	std::cout << "2. Zoradenie podla Kriteria bez Filtrov \n";
	std::cout << "3. Zoradenie podla Kriteria s Filtrami \n";

	int vyber = 0;
	std::cin >> vyber;

	switch (vyber)
	{
	case 1:
		FiltrovaniePodlaKriteria();
		break;
	case 2:
		//ZoradenieBezFiltrov();
		break;
	case 3:
		ZoradenieSFitrami();
		break;
	default:
		std::cout << "Vyberte z moznosti 1,2 alebo 3. \n";
		vyberMoznosti();
	}
}


void Rozhranie::FiltrovaniePodlaKriteria()
{
	int typUzemnejJednotky;
	int typKriteria;

	std::cout << "Ktore Uzemne Jednotky chcete filtrovat? \n";
	std::cout << "1. Obce \n 2. Okresy \n 3.Kraje \n";
	std::cin >> typUzemnejJednotky;
	std::cout << "Ktore Kriterium chcete pouzit?  \n";
	std::cout << "1.Nazov \n2.Prislusnost \n3.PocetVolicov \n4.Pocet Vydanych Obalok \n5.Ucast \n6.PocetOdovzdanychObalok \n\n";
	std::cin >> typKriteria;
	structures::UnsortedSequenceTable<int, UzemnaJednotka*>* pomocna = new structures::UnsortedSequenceTable<int, UzemnaJednotka*>;

	switch(typUzemnejJednotky)
	{
	case 1:
		for (structures::TableItem<int, UzemnaJednotka*>* element : *ObceSequence)
		{
			pomocna->insert(element->getKey(), element->accessData());
		}
		break;
	case 2:
		for (structures::TableItem<int, UzemnaJednotka*>* element : *OkresySequence)
		{
			pomocna->insert(element->getKey(), element->accessData());
		}
		break;
	case 3:
		for (structures::TableItem<int, UzemnaJednotka*>* element : *KrajeSequence)
		{
			pomocna->insert(element->getKey(), element->accessData());
		}
		break;
	default:
		FiltrovaniePodlaKriteria();
	}

	switch(typKriteria)
	{
	case 1:
		{
			std::string nazov;
			std::cout << "Zadajte nazov vyhladavanych Uzemnych Jednotiek   ";
			std::cin.ignore();
			getline(std::cin, nazov);
			FiltrujJedenParameter(nazov, new KriteriumNazov, *pomocna);
			for (structures::TableItem<int, UzemnaJednotka*>* element : *pomocna)
			{
				std::cout << element->accessData()->toString();
			}
		}
		break;
	case 2:
		{
			std::string nazov;
			int patriace;
			std::cout << "Zadajte nazov Vyssej Uzemnej Jednotky   ";
			std::getline(std::cin, nazov);
			std::cout << "\nZadajte '1' ak chcete vyhladat jednotky patriace, a '0' ak nepatriace Vyssej Uzemnej Jednotke";
			std::cin >> patriace;
			if (patriace == 1)
			{
				FiltrujJedenParameter(true, new KriteriumPrislusnostObce(nazov), *pomocna);
			}
			else if (patriace == 0) 
			{

				FiltrujJedenParameter(false, new KriteriumPrislusnostObce(nazov), *pomocna);
			}
			for (structures::TableItem<int, UzemnaJednotka*>* element : *pomocna)
			{
				std::cout << element->accessData()->toString();
			}
			
		}
		break;
	case 3:
		{
			int kolo;
			int min;
			int max;
			std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
			std::cin >> kolo;
			std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Volici. \n";
			std::cin >> min;
			std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Volici \n";
			std::cin >> max;
			FiltrujDvaParametre(min, max, new KriteriumVolici(kolo), *pomocna);
			for (structures::TableItem<int, UzemnaJednotka*>* element : *pomocna)
			{
				std::cout << element->accessData()->toString();
			}
		}
		break;
	case 4:
		{
		int kolo;
		int min;
		int max;
		std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
		std::cin >> kolo;
		std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Vydane Obalky. \n";
		std::cin >> min;
		std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Vydane Obalky \n";
		std::cin >> max;
		FiltrujDvaParametre(min, max, new KriteriumVydaneObalky(kolo), *pomocna);
		for (structures::TableItem<int, UzemnaJednotka*>* element : *pomocna)
		{
			std::cout << element->accessData()->toString();
		}
		}
		break;
	case 5:
		{
		int kolo;
		double min;
		double max;
		std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho \n";
		std::cin >> kolo;
		std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Ucast <0;1>. \n";
		std::cin >> min;
		std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Ucast <0;1> \n";
		std::cin >> max;
		FiltrujDvaParametre(min, max, new KriteriumUcast(kolo), *pomocna);
		for (structures::TableItem<int, UzemnaJednotka*>* element : *pomocna)
		{
			std::cout << element->accessData()->toString();
		}
		}
		break;
	case 6:
		{
			int kolo;
			int min;
			int max;
			std::cout << "Zadajte '1' ak vas zaujimaju vysledky 1. kola, '2' ak druheho a '0' ak oboch \n";
			std::cin >> kolo;
			std::cout << "Zadajte najnizsiu prijatelnu hodnotu kriteria Odovzdane Obalky. \n";
			std::cin >> min;
			std::cout << "Zadajte najvyssiu prijatelnu hodnotu kriteria Odovzdane Obalky \n";
			std::cin >> max;
			FiltrujDvaParametre(min, max, new KriteriumOdovzdaneObalky(kolo), *pomocna);
			for (structures::TableItem<int,UzemnaJednotka*>* element : *pomocna)
			{
				std::cout << element->accessData()->toString();
			}

		}
		break;
	default:
		FiltrovaniePodlaKriteria();
	}

}

void Rozhranie::ZoradenieSFitrami()
{

}

Rozhranie::~Rozhranie()
{
	for (structures::TableItem<int,UzemnaJednotka*>* element : *ObceSequence)
	{
		delete element;
	}
	delete ObceSequence;
	for (structures::TableItem<int, UzemnaJednotka*>* element : *OkresySequence)
	{
		delete element;
	}
	delete OkresySequence;
	for (structures::TableItem<int, UzemnaJednotka*>* element : *KrajeSequence)
	{
		delete element;
	}
	delete KrajeSequence;
}
