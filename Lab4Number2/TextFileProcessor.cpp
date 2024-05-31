#include "TextFileProcessor.h"
#include <iostream>
#include <fstream>
#include <algorithm>

TextFileProcessor::TextFileProcessor() : m_filename("file.txt") {}

TextFileProcessor::TextFileProcessor(const std::string& filename) : m_filename(filename) {}

TextFileProcessor::~TextFileProcessor() {}

void TextFileProcessor::createFile(const std::vector<int>& numbers) {
    std::ofstream outputFile(m_filename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }

    for (int num : numbers) {
        outputFile << num << std::endl;
    }
    outputFile.close();
    std::cout << "File " << m_filename << " created successfully" << std::endl;
}

void TextFileProcessor::displayFile() const {
    std::ifstream inputFile(m_filename);
    if (!inputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }
    inputFile.close();
}

void TextFileProcessor::appendToFile(int number) {
    std::ofstream outputFile(m_filename, std::ofstream::app);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }

    outputFile << number << std::endl;
    outputFile.close();
    std::cout << "Number " << number << " appended to file " << m_filename << std::endl;
}

int TextFileProcessor::minNumber(const std::vector<int>& numbers) {
    return *std::min_element(numbers.begin(), numbers.end());
}


//void TextFileProcessor::processAndCreateNewFile() {
//    std::ifstream inputFile(m_filename);
//
//    try {
//        if (!inputFile.is_open()) { throw std::runtime_error("Unable to open file: " + m_filename); }
//
//        std::vector<int> numbers;
//        int number;
//        while (inputFile >> number) {
//            numbers.push_back(number);
//        }
//        inputFile.close();
//
//        if (numbers.empty()) { throw std::runtime_error("File " + m_filename + " is empty!"); }
//        std::ofstream outputFile("new_" + m_filename);
//        if (!outputFile.is_open()) { throw std::runtime_error("Unable to create new file: " + m_filename); }
//
//        for (int num : numbers) {
//            outputFile << num / minNumber(numbers) << std::endl;
//        }
//        outputFile.close();
//        std::cout << "New file created successfully" << std::endl;
//    }
//    catch (const std::ofstream::failure& ex) {
//        std::cout << "Error: " << ex.what() << std::endl;
//    }
//}


std::vector<int> TextFileProcessor::readFileToBuffer() const {
    std::ifstream inputFile(m_filename);
    std::vector<int> buffer;

    if (!inputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }

    int number;
    while (inputFile >> number) {
        buffer.push_back(number);
    }
    inputFile.close();

    return buffer;
}

void TextFileProcessor::writeBufferToFile(const std::vector<int>& buffer, const std::string& filename) const {
    std::ofstream outputFile(filename);

    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    for (int num : buffer) {
        outputFile << num << std::endl;
    }
    outputFile.close();
}

void TextFileProcessor::processAndCreateNewFile() {
    std::vector<int> buffer = readFileToBuffer();

    if (buffer.empty()) {
        std::cerr << "Error: File " << m_filename << " is empty!" << std::endl;
        return;
    }

    int minNum = minNumber(buffer);
    std::vector<int> processedBuffer;

    for (int num : buffer) {
        processedBuffer.push_back(num / minNum);
    }

    writeBufferToFile(processedBuffer, "new_" + m_filename);
    std::cout << "New file created successfully" << std::endl;
}