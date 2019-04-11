#include "CSVRow.h"

#include <stdexcept>


// CONSTRUCTORS & DESTRUCTORS
CSVRow::CSVRow(const CSVRow& other)
	: _columns(other._columns) {}

CSVRow::CSVRow(const char* str, const char separator) {
	std::string substr(str);
	for (size_t pos = 0; (pos = substr.find(separator)) != std::string::npos;) {
		_columns.emplace_back(substr.substr(0, pos));
		substr = substr.substr(pos + 1);
	}
	_columns.emplace_back(substr);
}

CSVRow::CSVRow(const std::string& str, const char separator) {
	std::string substr(str);
	for (size_t pos = 0; (pos = substr.find(separator)) != std::string::npos;) {
		_columns.emplace_back(substr.substr(0, pos));
		substr = substr.substr(pos + 1);
	}
	_columns.emplace_back(substr);
}

// SETTERS

// GETTERS

// METHODS
const std::string	CSVRow::toString(const char separator) const {
	std::string	ret;
	for (size_t i = 0; i < _columns.size(); ++i) {
		ret += _columns[i].data();
		if (i + 1 != _columns.size())
			ret += separator;
	}
	return ret;
}

// OVERLOADS
CSVData&	CSVRow::operator[](const size_t idx) {
	if (idx < _columns.size())
		return _columns[idx];
	else
		throw std::invalid_argument("Index out of bound");
}

const CSVData& CSVRow::operator[](const size_t idx) const {
	if (idx < _columns.size())
		return _columns[idx];
	else
		throw std::invalid_argument("Index out of bound");
}

CSVRow&		CSVRow::operator=(const CSVRow& other) {
	_columns = other._columns;

	return *this;
}