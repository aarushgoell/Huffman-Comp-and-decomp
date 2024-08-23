#include "Decompression.h"
#include <bitset>
#include <fstream>

void decompressFile(const std::string& inputFilename, const std::string& outputFilename, std::shared_ptr<HuffmanNode> root) {
    std::ifstream inputFile(inputFilename, std::ios::binary);
    std::ofstream outputFile(outputFilename, std::ios::binary);
    
    int extraBits;
    inputFile >> extraBits;
    inputFile.get(); // To skip the newline or space after extraBits
    
    std::string encodedStr = "";
    char ch;
    
    while (inputFile.get(ch)) {
        std::bitset<8> byte(ch);
        encodedStr += byte.to_string();
    }
    
    encodedStr = encodedStr.substr(0, encodedStr.size() - extraBits);
    
    std::shared_ptr<HuffmanNode> currentNode = root;
    for (char bit : encodedStr) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }

        if (!currentNode->left && !currentNode->right) {
            outputFile.put(currentNode->ch);
            currentNode = root;
        }
    }
    
    inputFile.close();
    outputFile.close();
}
