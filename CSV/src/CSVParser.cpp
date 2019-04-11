#include "CSVParser.h"

#include <fstream>
#include <iostream>
#include <exception>

CSVFile		CSVParser::ReadCSVFile(const std::string& filePath, const bool hasHeader, const char separator) {
	if (!filePath.empty()) {
		CSVFile		csvFile;
		std::ifstream	file(filePath.c_str());

		csvFile.setSeparator(separator);

		int cpt = 0;

		for (std::string str; std::getline(file, str);) {
			if (hasHeader && cpt == 0) {
				csvFile.addHeader(str);
			} else
				csvFile.addRow(str);
			cpt++;
		}
		return csvFile;

	} else {
		throw std::invalid_argument("filePath is NULL");
	}
}

void		CSVParser::ReadCSVFileOTF(const std::string& filePath, const std::function<void(const CSVRow&)>& func, const bool hasHeader, const char separator) {
	if (!filePath.empty()) {
		std::ifstream	file(filePath.c_str());

		int cpt = 0;
		for (std::string str; std::getline(file, str);) {
			func(CSVRow(str));
			cpt++;
		}

	} else {
		throw std::invalid_argument("filePath is NULL");
	}
}

void		CSVParser::WriteCSVFile(const CSVFile& file, const std::string& fileName, const std::string& filePath) {
	std::ofstream	csvFile(filePath + fileName);
	const char	separator = file.getSeparator();

	if (file.header()) {
		csvFile << file.getHeader().toString(separator) << std::endl;
	}

	for (size_t i = 0; i < file.size(); ++i) {
		csvFile << file[i].toString(separator) << std::endl;
	}
}