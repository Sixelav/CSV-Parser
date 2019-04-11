#pragma once

#include "CSVRow.h"
#include "CSVColumn.h"

class CSVFile {
public:
	// CONSTRUCTORS & DESTRUCTORS
	CSVFile(const char separator = ',') 
		: _separator(separator) {}
	~CSVFile() {}

	// SETTERS
	void		setSeparator(const char separator) { _separator = separator; }

	// GETTERS
	char		getSeparator() const { return _separator; }
	CSVRow		getHeader() const { return _header; }

	// METHODS
	//void			addColumnAt(const CSVColumn& cols, const int pos, bool checkDiff = false);
	void			addColumnAtBack(const CSVColumn& cols, bool checkDiff = false);
	void			addRow(const std::string& str);
	void			addRow(const CSVRow& row);
	//void			addRows(const std::vector<CSVRow>& rows);
	void			addHeader(const std::string& str);
	bool			empty() const { return (_header.empty() && _rows.empty()) ? true : false; }
	CSVColumn		getColumn(const int idx);
	//CSVColumn		getColumn(const std::string& colName);
	bool			header() const { return !_header.empty(); }
	size_t			size() const { return _rows.size(); }

	// OVERLOADS
	CSVRow&		operator[](const size_t idx);
	const CSVRow&	operator[](const size_t idx) const;
private:
	char			_separator;
	CSVRow			_header;
	std::vector<CSVRow>	_rows;
};