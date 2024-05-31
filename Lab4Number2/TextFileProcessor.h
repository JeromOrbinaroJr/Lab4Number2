#pragma once
#include <string>
#include <vector>

//онлемърэ ондунд я оепедювеи гмювемхи б астеп

class TextFileProcessor {
public:
	TextFileProcessor();
	TextFileProcessor(const std::string& filename);
	~TextFileProcessor();

	//Methods
	void createFile(const std::vector<int>& numbers);
	void displayFile() const;
	void appendToFile(int number);
	void processAndCreateNewFile();
	int minNumber(const std::vector<int>&numbers);

	std::vector<int> readFileToBuffer() const;
	void writeBufferToFile(const std::vector<int>& buffer, const std::string& filename) const;

private:
	std::string m_filename;
};