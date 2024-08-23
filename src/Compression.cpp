#include "Compression.h"
#include <bitset>
#include <fstream>

void compressFile(const std::string& inputFilename, const std::string& outputFilename, const std::unordered_map<char, std::string>& huffmanCode) {
    std::ifstream inputFile(inputFilename, std::ios::binary);
    std::ofstream outputFile(outputFilename, std::ios::binary);
    
    std::string encodedStr = "";
    char ch;
    
    while (inputFile.get(ch)) {
        encodedStr += huffmanCode.at(ch);
    }
    
    // Pad the encoded string to make its length a multiple of 8
    int extraBits = 8 - encodedStr.size() % 8;
    for (int i = 0; i < extraBits; ++i) {
        encodedStr += "0";
    }

    outputFile << extraBits;  // Store the number of padding bits at the start
    
    for (size_t i = 0; i < encodedStr.size(); i += 8) {
        std::bitset<8> byte(encodedStr.substr(i, 8));
        outputFile.put(byte.to_ulong());
    }
    
    inputFile.close();
    outputFile.close();
}
