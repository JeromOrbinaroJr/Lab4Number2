#pragma once
#include <string>
#include <vector>

template <typename T>
class TextFileProcessor {
public:
    // Constructors
    TextFileProcessor();
    TextFileProcessor(const std::string& filename);
    ~TextFileProcessor();

    // Methods
    void createFile(const std::vector<T>& numbers);
    void displayFile() const;
    void appendToFile(T number);
    T minNumber(const std::vector<T>& numbers);
    void processAndWriteToNewFile();
    std::vector<T> readNumbersToBuffer() const;

private:
    std::string m_filename;
};
