#include <iostream>
#include <unordered_map>
#include "HuffmanTree.h"
#include "Compression.h"
#include "Decompression.h"

int main() {
    std::string inputFile = "data/input.txt";
    std::string compressedFile = "data/compressed.bin";
    std::string decompressedFile = "data/output.txt";

    // Step 1: Calculate the frequency of each character in the input file
    auto freq = calculateFrequency(inputFile);

    // Step 2: Build the Huffman Tree
    auto huffmanTreeRoot = buildHuffmanTree(freq);

    // Step 3: Generate Huffman codes for each character
    std::unordered_map<char, std::string> huffmanCode;
    generateHuffmanCodes(huffmanTreeRoot, "", huffmanCode);
    std::cout << "Starting compression..." << std::endl;
    compressFile(inputFile, compressedFile, huffmanCode);
    std::cout << "Compression completed." << std::endl;

    std::cout << "Starting decompression..." << std::endl;
    decompressFile(compressedFile, decompressedFile, huffmanTreeRoot);
    std::cout << "Decompression completed." << std::endl;

    std::cout << "Compression and Decompression completed." << std::endl;

    return 0;
}
