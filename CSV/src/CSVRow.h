#pragma once

#include "CSVData.h"

#include <iostream>
#include <vector>

class CSVRow {
public:
	// CONSTRUCTORS & DESTRUCTORS
	CSVRow() {}
	CSVRow(const CSVRow& other);
	CSVRow(const char* str, const char separator = ',');
	CSVRow(const std::string& str, const char separator = ',');
	~CSVRow() {}

	// SETTERS

	// GETTERS

	// METHODS
	bool		empty() const { return (_columns.empty()) ? true : false; }
	size_t		size() const { return _columns.size(); }
	const std::string	toString(const char separator = ',') const;

	// OVERLOADS
	CSVData&	operator[](const size_t idx);
	const CSVData&	operator[](const size_t idx) const;
	CSVRow&		operator=(const CSVRow& other);
private:
	std::vector<CSVData>	_columns;
};

