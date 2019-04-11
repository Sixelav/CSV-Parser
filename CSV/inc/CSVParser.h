#pragma once

#include "CSVFile.h"

#include <functional>

class CSVParser {
public:
	CSVParser() = delete;
	~CSVParser() = delete;

	static CSVFile	ReadCSVFile(const std::string& filePath, const bool hasHeader = false, const char separator = ',');
	static void	ReadCSVFileOTF(const std::string& filePath, const std::function<void(const CSVRow&)>& func, const bool hasHeader = false, const char separator = ',');
	static void	WriteCSVFile(const CSVFile& file, const std::string& fileName, const std::string& filePath = "");
};

