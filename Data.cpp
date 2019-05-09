#include "Data.h"


Data::Data(int p_pocetVolicov, int p_vydaneObalky, double p_ucast, int p_odovzdaneObalky, int p_platneDokopy):
		pocetVolicov(p_pocetVolicov), vydaneObalky(p_vydaneObalky),ucast(p_ucast), odovzdaneObalky(p_odovzdaneObalky),platneDokopy(p_platneDokopy)
{
}

int Data::getPocetVolicov()
{
	return pocetVolicov;
}

int Data::getVydaneObalky()
{
	return vydaneObalky;
}

double Data::getUcast()
{
	return ucast;
}

int Data::getOdovzdaneObalky()
{
	return odovzdaneObalky;
}

int Data::getPlatneDokopy()
{
	return platneDokopy;
}


std::string Data::toString()
{
	return "Pocet volicov: " + std::to_string(pocetVolicov) + " Vydane obalky: " + std::to_string(vydaneObalky) + " Ucast: " + std::to_string(ucast)
	+ " Odovzdane obalky: " + std::to_string(odovzdaneObalky) + " Platne hlasy: " + std::to_string(platneDokopy);
}
