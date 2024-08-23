#ifndef DECOMPRESSION_H
#define DECOMPRESSION_H

#include "HuffmanTree.h"
#include <string>

// Function to decompress the file using the Huffman Tree
void decompressFile(const std::string& inputFilename, const std::string& outputFilename, std::shared_ptr<HuffmanNode> root);

#endif // DECOMPRESSION_H
