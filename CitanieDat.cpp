#include "../Volby/structures/heap_monitor.h"
#include "CitanieDat.h"

CitanieDat::CitanieDat(structures::SortedSequenceTable<int, UzemnaJednotka*>& p_kraje,
	structures::SortedSequenceTable<int, UzemnaJednotka*>& p_okresy,
	structures::SortedSequenceTable<int, UzemnaJednotka*>& p_obce)
{
	std::string obcekolo1 = "PRE_2019_KOLO1_obce_korektne.csv";
	std::string obcekolo2 = "PRE_2019_KOLO2_obce_korektne.csv";
	std::string okresykolo1 = "PRE_2019_KOLO1_okresy_korektne.csv";
	std::string okresykolo2 = "PRE_2019_KOLO2_okresy_korektne.csv";
	std::string krajekolo1 = "PRE_2019_KOLO1_kraje_korektne.csv";
	std::string krajekolo2 = "PRE_2019_KOLO2_kraje_korektne.csv";

	structures::SortedSequenceTable<int, UzemnaJednotka*>* obce = &p_obce;
	structures::SortedSequenceTable<int, UzemnaJednotka*>* okresy = &p_okresy;
	structures::SortedSequenceTable<int, UzemnaJednotka*>* kraje = &p_kraje;
	/*
	structures::UnsortedSequenceTable<int, UzemnaJednotka*>* obseq = new structures::UnsortedSequenceTable<int, UzemnaJednotka*>;
	structures::BinarySearchTree<int, UzemnaJednotka*> ObceStrom_;
	structures::BinarySearchTree<int, UzemnaJednotka*> OkresyStrom_;
	structures::BinarySearchTree<int, UzemnaJednotka*> KrajeStrom_;
	*/

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
			kraje->insert(stoi(p_kodKraja),kraj);

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

			Okres *okres = new Okres(koloJedna, koloDva,stoi(p_kodOkresu), p_nazovOkresu, (*kraje)[std::stoi(p_kodKraja)]);
			okresy->insert(stoi(p_kodOkresu),okres);
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
			
			Obec *obec = new Obec(koloJedna, koloDva, std::stoi(p_kodObce), p_nazovObce,(*okresy)[stoi(p_kodOkresu)]);
			//std::cout << obec->nazov() << "\n";
			//ObceStrom_.insert(std::stoi(p_kodObce), obec);
			//obseq->insert(std::stoi(p_kodObce), obec);
			obce->insert(std::stoi(p_kodObce), obec);
		}
		citacObce1.close();
		citacObce2.close();

		/*
		KriteriumNazov *p = new KriteriumNazov();
		KriteriumOdovzdaneObalky *odobalky = new KriteriumOdovzdaneObalky(0);
		KriteriumVolici* vol = new KriteriumVolici(0);
		KriteriumUcast* uca = new KriteriumUcast(1);
		//FilterNazov *f = new FilterNazov("Martin");
		FilterJedenParam < std::string, UzemnaJednotka*>* fjp = new FilterJedenParam<std::string, UzemnaJednotka*>("Martin");
		
		for (structures::TableItem<int, UzemnaJednotka*>*  element : ObceStrom_)
		{
			std::cout << p->ohodnot(*element->accessData());
		}
		*/
		
		/*
		for (structures::TableItem<int, UzemnaJednotka*>* element : ObceStrom_)
		{
			fjp->filtruj(*element->accessData(), *p);
			//std::cout << f->filtruj(*element->accessData(), *p);
		}
		
		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			p->ohodnot(element->accessData());
		}
		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			fjp->filtruj(element->accessData(), p);
			//std::cout << f->filtruj(*element->accessData(), *p);
		}
		
		for (structures::TableItem<int, UzemnaJednotka*>* element : *sorObce)
		{
			p->ohodnot(element->accessData());
		}
		for (structures::TableItem<int, UzemnaJednotka*>* element : *sorObce)
		{
			fjp->filtruj(element->accessData(), p);
			//std::cout << f->filtruj(*element->accessData(), *p);
		}

		structures::UnsortedSequenceTable<int, UzemnaJednotka*> * pomocny = new structures::UnsortedSequenceTable<int, UzemnaJednotka*>;
		for (structures::TableItem<int,UzemnaJednotka*>* element : *sorObce)
		{
			pomocny->insert(element->getKey(), element->accessData());
		}

		structures::HeapSort<int, UzemnaJednotka, std::string> *sorterString = new structures::HeapSort<int, UzemnaJednotka, std::string>;
		sorterString->sortMoj(pomocny, p, true);

		int o = 1;
		for (structures::TableItem<int, UzemnaJednotka*>* element : *pomocny)
		{
			std::cout << o;
			std::cout << element->accessData()->nazov();
			std::cout << "\n";
			o++;
		}

		/*
		structures::HeapSort<int, UzemnaJednotka,std::string> *sorterString = new structures::HeapSort<int, UzemnaJednotka, std::string>;
		sorterString->sortMoj(obseq, p, true);

		int o = 1;
		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			std::cout << o;
			std::cout << element->accessData()->nazov();
			std::cout << "\n";
			o++;
		}

		structures::HeapSort<int, UzemnaJednotka, int> *sorterInt = new structures::HeapSort<int, UzemnaJednotka, int>;		
		sorterInt->sortMoj(obseq, odobalky, true);

		o = 1;
		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			std::cout << o;
			std::cout << element->accessData()->nazov() << " " ;
			std::cout << element->accessData()->pocetOdovzdanychObalokVKole(0);
			std::cout << "\n";
			o++;
		}

		structures::HeapSort<int, UzemnaJednotka, double> *sorterDouble = new structures::HeapSort<int, UzemnaJednotka, double>;
		sorterDouble->sortMoj(obseq, uca, true);

		o = 1;
		for (structures::TableItem<int, UzemnaJednotka*>* element : *obseq)
		{
			std::cout << o;
			std::cout << element->accessData()->nazov() << " ";
			std::cout << element->accessData()->ucastVolicovVKole(1);
			std::cout << "\n";
			o++;
		}
		
		*/
		


	}
}

CitanieDat::~CitanieDat()
{

}
