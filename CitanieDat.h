#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "../Volby/structures/table/binary_search_tree.h"
#include "../Volby/Data.h"
#include "UzemnaJednotka.h"
#include "structures/list/array_list.h"
#include "Obec.h"
#include "Okres.h"
#include "structures/table/sorted_sequence_table.h"

class CitanieDat
{
private:
public:
	CitanieDat(structures::SortedSequenceTable<int, UzemnaJednotka*>& kraje,
		structures::SortedSequenceTable<int, UzemnaJednotka*>& okresy,
		structures::SortedSequenceTable<int, UzemnaJednotka*>& obce);
	~CitanieDat();
};

