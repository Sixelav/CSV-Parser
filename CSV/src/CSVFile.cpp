#include "CSVFile.h"

#include <stdexcept>

// CONSTRUCTORS & DESTRUCTORS

// SETTERS

// GETTERS

// METHODS
void		CSVFile::addColumnAtBack(const CSVColumn& cols, bool checkDiff) {
	if (!checkDiff) {
		if (_rows.empty()) {
			for (size_t i = 0; i < cols.size(); i++) {
				_rows.emplace_back(cols[i].data());
			}
			addHeader(cols.getHeader().data());
		} else {
			//TODO: HANDLE THIS CASE
		}
	}
	
	//TODO: MANAGE CHECKDIFF
}

void		CSVFile::addRow(const std::string& str) {
	_rows.emplace_back(str);
}

void		CSVFile::addRow(const CSVRow& row) {
	_rows.emplace_back(row);
}

void		CSVFile::addHeader(const std::string& str) {
	_header = str;
}

CSVColumn	CSVFile::getColumn(const int idx) {
	if (idx < _rows.size()) {
		std::vector<CSVData>	cols;
		for (size_t i = 0; i < _rows.size(); ++i) {
			cols.emplace_back(_rows[i][idx]);
		}
		return CSVColumn(cols, _header[idx]);
	} else {
		throw std::invalid_argument("Index out of bound");
	}
}
	
// OVERLOADS
CSVRow&		CSVFile::operator[](const size_t idx) {
	if (idx < _rows.size())
		return _rows[idx];
	else
		throw std::invalid_argument("Index out of bound");
}

const CSVRow&	CSVFile::operator[](const size_t idx) const {
	if (idx < _rows.size())
		return _rows[idx];
	else
		throw std::invalid_argument("Index out of bound");
}