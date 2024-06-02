#include "TextFileProcessorTemplate.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// Constructors
template <typename T>
TextFileProcessor<T>::TextFileProcessor() : m_filename("file.txt") {}

template <typename T>
TextFileProcessor<T>::TextFileProcessor(const std::string& filename) : m_filename(filename) {}

template <typename T>
TextFileProcessor<T>::~TextFileProcessor() {}

// Methods
template <typename T>
void TextFileProcessor<T>::createFile(const std::vector<T>& numbers) {
    std::ofstream outputFile(m_filename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }

    for (T num : numbers) {
        outputFile << num << std::endl;
    }
    outputFile.close();

    std::cout << "File " << m_filename << " created successfully" << std::endl;
}

template <typename T>
void TextFileProcessor<T>::displayFile() const {
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

template <typename T>
void TextFileProcessor<T>::appendToFile(T number) {
    std::ofstream outputFile(m_filename, std::ofstream::app);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }

    outputFile << number << std::endl;
    outputFile.close();

    std::cout << "\nNumber " << number << " appended to file " << m_filename << std::endl;
}

template <typename T>
T TextFileProcessor<T>::minNumber(const std::vector<T>& numbers) {
    return *std::min_element(numbers.begin(), numbers.end());
}

template <typename T>
std::vector<T> TextFileProcessor<T>::readNumbersToBuffer() const {
    std::ifstream inputFile(m_filename);
    std::vector<T> buffer;

    if (!inputFile.is_open()) {
        throw std::runtime_error("Unable to open file: " + m_filename);
    }

    T number;
    while (inputFile >> number) {
        buffer.push_back(number);
    }
    inputFile.close();

    return buffer;
}

template <typename T>
void TextFileProcessor<T>::processAndWriteToNewFile() {
    std::vector<T> buffer = readNumbersToBuffer();

    if (buffer.empty()) {
        throw std::runtime_error("File " + m_filename + " is empty!");
    }

    T minNum = minNumber(buffer);
    std::vector<T> processedBuffer;

    for (T num : buffer) {
        processedBuffer.push_back(num / minNum);
    }

    std::ofstream outputFile("new_" + m_filename);
    if (!outputFile.is_open()) {
        throw std::runtime_error("Unable to open file: new_" + m_filename);
    }

    for (T num : processedBuffer) {
        outputFile << num << std::endl;
    }
    outputFile.close();

    std::cout << "\nNew file created successfully" << std::endl;
}
