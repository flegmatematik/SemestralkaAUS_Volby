#pragma once
#include <string>

class Data
{
private:
	int pocetVolicov;
	int vydaneObalky;
	double ucast;
	int odovzdaneObalky;
	int platneDokopy;

public:
	Data(int p_pocetVolicov,int p_vydaneObalky, double p_ucast, int p_odovzdaneObalky, int p_platneDokopy);
	int getPocetVolicov();
	int getVydaneObalky();
	double getUcast();
	int getOdovzdaneObalky();
	int getPlatneDokopy();
	std::string toString();
};

