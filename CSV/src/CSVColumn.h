#pragma once

#include "CSVData.h"

#include <vector>

class CSVColumn {
public:
	// CONSTRUCTORS & DESTRUCTORS
	CSVColumn() {}
	CSVColumn(const CSVColumn& other)
		: _header(other._header), _lines(other._lines) {}
	CSVColumn(const std::vector<CSVData>& lines, const CSVData& header)
		: _header(header), _lines(lines) {}
	CSVColumn(const std::vector<CSVData>& lines, const std::string& header)
		: _header(header), _lines(lines) {}
	~CSVColumn() {}

	// SETTERS

	// GETTERS
	CSVData		getHeader() const { return _header; }

	// METHODS
	void		addLineAtEnd(const CSVData& data) { _lines.emplace_back(data); }
	void		addLineAtEnd(const std::string& data) { _lines.emplace_back(data); }
	//void		addLineAt(const CSVData& data, const int pos);
	bool		empty() const { return (_lines.empty()) ? true : false; }
	bool		header() const { return !_header.empty(); }
	size_t		size() const { return _lines.size(); }

	// OVERLOADS
	CSVData&	operator[](const size_t idx);
	const CSVData&	operator[](const size_t idx) const;
	CSVColumn&	operator=(const CSVColumn& other);
private:
	CSVData			_header;
	std::vector<CSVData>	_lines;
};

