#include "CSVData.h"

#include <iostream>

// CONSTRUCTORS & DESTRUCTORS	

// SETTERS

// GETTERS

// METHODS

// OVERLOADS
char&		CSVData::operator[](const size_t idx) {
	if (idx < _data.size()) {
		return _data[idx];
	} else {
		throw std::invalid_argument("Index out of bound");
	}
}

CSVData&	CSVData::operator=(const CSVData& other) {
	_data = other._data;

	return *this;
}

CSVData& CSVData::operator=(const char* other) {
	_data = other;

	return *this;
}