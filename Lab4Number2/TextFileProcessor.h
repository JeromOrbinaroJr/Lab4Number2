#pragma once
#include <string>
#include <vector>

class TextFileProcessor {
public:
	//Constructors
	TextFileProcessor();
	TextFileProcessor(const std::string& filename);
	~TextFileProcessor();

	//Methods
	void createFile(const std::vector<int>& numbers);
	void displayFile() const;
	void appendToFile(int number);
	int minNumber(const std::vector<int>& numbers);
	std::vector<int> readNumbersToBuffer() const;
	void processAndWriteToNewFile();

private:
	std::string m_filename;
};

//void processAndCreateNewFile();
//void writeBufferToFile(const std::vector<int>& buffer, const std::string& filename) const;