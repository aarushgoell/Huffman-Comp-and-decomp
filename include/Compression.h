#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <unordered_map>
#include <string>

// Function to compress the input file using the generated Huffman codes
void compressFile(const std::string& inputFilename, const std::string& outputFilename, const std::unordered_map<char, std::string>& huffmanCode);

#endif // COMPRESSION_H
