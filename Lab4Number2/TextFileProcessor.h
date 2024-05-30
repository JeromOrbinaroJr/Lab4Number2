#pragma once
#include <string>
#include <vector>

class TextFileProcessor {
public:
	TextFileProcessor(const std::string& filename);
	~TextFileProcessor();

	//Methods
	void createFile(const std::vector<int>& numbers);
	void displayFile() const;
	void appendToFile(int number);
	void processAndCreateNewFile();
	int minNumber(const std::vector<int>&numbers);

private:
	std::string m_filename;
};