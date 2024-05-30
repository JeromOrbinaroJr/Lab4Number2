#include <iostream>
#include <vector>
#include "TextFileProcessor.h"

int main() {
    std::vector<int> numbers = { 5, 20, 30, 40, 50 }; // Example numbers
    TextFileProcessor processor("file.txt");

    // Create text file
    processor.createFile(numbers);

    // Display content of text file
    processor.displayFile();

    // Append new record to file
    processor.appendToFile(70);

    // Process and create new file
    processor.processAndCreateNewFile();

    return 0;
}