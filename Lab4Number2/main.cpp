#include <iostream>
#include "TextFileProcessor.h"

int main() {
    TextFileProcessor processor("file.txt");

    // Display content of text file
    std::cout << "Original file content:" << std::endl;
    processor.displayFile();

    // Append new record to file
    processor.appendToFile(70);

    // Display content of text file after appending
    std::cout << "File content after appending:" << std::endl;
    processor.displayFile();

    // Process and create new file
    processor.processAndCreateNewFile();

    // Display content of the new text file
    TextFileProcessor newProcessor("new_file.txt");
    std::cout << "New file content:" << std::endl;
    newProcessor.displayFile();

    return 0;
}
