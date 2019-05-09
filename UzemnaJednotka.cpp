#include "UzemnaJednotka.h"

UzemnaJednotka::UzemnaJednotka(Data *p_prveKolo, Data *p_druheKolo, int p_kodUzemnejJednotky, std::string p_nazovUzemnejJednotky, UzemnaJednotka *vyssia)
	: prveKolo(p_prveKolo), druheKolo(p_druheKolo), nazovUzemnejJednotky(std::move(p_nazovUzemnejJednotky)), kodUzemnejJednotky(p_kodUzemnejJednotky), vyssiaUzemnaJednotka(vyssia)
{
}

std::string UzemnaJednotka::nazov()
{
	return nazovUzemnejJednotky;
}

int UzemnaJednotka::kod()
{
	return kodUzemnejJednotky;
}

UzemnaJednotka* UzemnaJednotka::dajVyssie()
{
	return vyssiaUzemnaJednotka;
}


int UzemnaJednotka::pocetZapisanychVolicovVKole(int kolo)
{
	switch(kolo)
	{
	case 1:
		return prveKolo->getPocetVolicov();
	case 2:
		return druheKolo->getPocetVolicov();
	default:
		return 0;
	}
}

int UzemnaJednotka::pocetVydanychObalokVKole(int kolo)
{
	switch (kolo)
	{
	case 1:
		return prveKolo->getVydaneObalky();
	case 2:
		return druheKolo->getVydaneObalky();
	default:
		return druheKolo->getVydaneObalky() + prveKolo->getVydaneObalky();
	}
}

double UzemnaJednotka::ucastVolicovVKole(int kolo)
{
	switch (kolo)
	{
	case 1:
		return prveKolo->getUcast();
	case 2:
		return druheKolo->getUcast();
	default:
		return 0;
	}
}

int UzemnaJednotka::pocetOdovzdanychObalokVKole(int kolo)
{
	switch (kolo)
	{
	case 1:
		return prveKolo->getOdovzdaneObalky();
	case 2:
		return druheKolo->getOdovzdaneObalky();
	default:
		return druheKolo->getOdovzdaneObalky() + prveKolo->getOdovzdaneObalky();
	}
}

int UzemnaJednotka::pocetPlatnych(int kolo)
{
	switch (kolo)
	{
	case 1:
		return prveKolo->getPlatneDokopy();
	case 2:
		return druheKolo->getPlatneDokopy();
	default:
		return druheKolo->getPlatneDokopy() + prveKolo->getPlatneDokopy();
	}
}

std::string UzemnaJednotka::toString()
{
	return nullptr;
}


UzemnaJednotka::~UzemnaJednotka()
{
	delete prveKolo;
	delete druheKolo;
}
