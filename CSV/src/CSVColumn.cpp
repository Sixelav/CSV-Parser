#include "CSVColumn.h"

#include <stdexcept>

// CONSTRUCTORS & DESTRUCTORS

// SETTERS

// GETTERS

// METHODS

// OVERLOADS
CSVData& CSVColumn::operator[](const size_t idx) {
	if (idx < _lines.size())
		return _lines[idx];
	else
		throw std::invalid_argument("Index out of bound");
}

const CSVData& CSVColumn::operator[](const size_t idx) const {
	if (idx < _lines.size())
		return _lines[idx];
	else
		throw std::invalid_argument("Index out of bound");
}

CSVColumn& CSVColumn::operator=(const CSVColumn& other) {
	_header = other._header;
	_lines = other._lines;

	return *this;
}