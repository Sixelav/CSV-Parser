#pragma once

#include <string>

class CSVData {
public:
	// CONSTRUCTORS & DESTRUCTORS
	CSVData() {}
	CSVData(const CSVData& other) { *this = other; }
	CSVData(const std::string& str)
		: _data(str) {}
	~CSVData() {}

	// SETTERS
	
	// GETTERS
	
	// METHODS
	const std::string	data() const { return _data; }
	bool			empty() const { return (_data.size() == 0) ? true : false; }
	size_t			size() const { return _data.size(); }

	// OVERLOADS
	char&		operator[](const size_t idx);
	CSVData&	operator=(const CSVData& other);
	CSVData&	operator=(const char* other);

private:
	std::string	_data;
};

