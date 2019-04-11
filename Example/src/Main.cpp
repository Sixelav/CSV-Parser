#include <iostream>

#include "CSV/CSVParser.h"

int main(int argc, char** argv) {
	if (argc > 1) {
		/*CSVFile		myCSV = CSVParser::ReadCSVFile(argv[1], true);

		CSVParser::WriteCSVFile(myCSV, "copy.csv");*/

		int size = 0;

		auto lambda = [&](const CSVRow& row) { 
			std::cout << row.toString() << std::endl; 
			++size;
		};

		CSVParser::ReadCSVFileOTF(argv[1], lambda, true);

		std::cout << size << std::endl;

		std::cin.get();

		return 0;
	}
}