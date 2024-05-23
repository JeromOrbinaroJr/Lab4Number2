#include "TextFileProcessor.h"
#include <iostream>
#include <fstream>
#include <algorithm>

TextFileProcessor::TextFileProcessor(const std::string& filename) :
	m_filename(filename) {}

TextFileProcessor::~TextFileProcessor() {}

void TextFileProcessor::createFile(const std::vector<int>& numbers) {
    std::ofstream outputFile(m_filename);
    try {
        if (!outputFile.is_open()) { throw std::runtime_error("Unable to open file: " + m_filename); }

        for (int num : numbers) {
            outputFile << num << std::endl;
        }
        outputFile.close();
        std::cout << "File " << m_filename << " created successfully" << std::endl;
    }
    catch (const std::ofstream::failure& ex) {
        std::cout << "Error opening/creating a file: " << ex.what() << std::endl;
    }
}

void TextFileProcessor::displayFile() const {
    std::ifstream inputFile(m_filename);
    try {
        if (!inputFile.is_open()) { throw std::runtime_error("Unable to open file: " + m_filename); }
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    }
    catch (const std::ofstream::failure& ex) {
        std::cout << "Error opening/creating a file: " << ex.what() << std::endl;
    }
}

void TextFileProcessor::appendToFile(int number) {
    std::ofstream outputFile(m_filename, std::ofstream::app);
    try {
        if (!outputFile.is_open()) { throw std::runtime_error("Unable to open file: " + m_filename); }

        outputFile << number << std::endl;
        outputFile.close();
        std::cout << "Number " << number << " appended to file " << m_filename << std::endl;
    }
    catch (const std::ofstream::failure& ex) {
        std::cout << "Error opening/creating a file: " << ex.what() << std::endl;
    }
}

void TextFileProcessor::processAndCreateNewFile() const {
    std::ifstream inputFile(m_filename);

    try {
        if (!inputFile.is_open()) { throw std::runtime_error("Unable to open file: " + m_filename); }

        std::vector<int> numbers;
        int number;
        while (inputFile >> number) {
            numbers.push_back(number);
        }
        inputFile.close();

        if (numbers.empty()) { throw std::runtime_error("File " + m_filename + " is empty!"); }

        int minNumber = *std::min_element(numbers.begin(), numbers.end());

        std::ofstream outputFile("new_" + m_filename);
        if (!outputFile.is_open()) { throw std::runtime_error("Unable to create new file: " + m_filename); }

        for (int num : numbers) {
            outputFile << num / minNumber << std::endl;
        }
        outputFile.close();
        std::cout << "New file created successfully" << std::endl;
    }
    catch (const std::ofstream::failure& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
    }
}

