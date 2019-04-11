#include <iostream>

#include "CSVParser.h"

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

		#ifdef WINDOWS
			std::cin.get();
		#endif

		return 0;
	}
}