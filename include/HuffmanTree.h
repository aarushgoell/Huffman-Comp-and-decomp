#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <unordered_map>
#include <string>
#include <memory>
#include <fstream>

// Structure for the Huffman Tree node
struct HuffmanNode {
    char ch;
    int freq;
    std::shared_ptr<HuffmanNode> left, right;

    HuffmanNode(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Function to calculate the frequency of each character in the input file
std::unordered_map<char, int> calculateFrequency(const std::string& filename);

// Function to build the Huffman Tree from the frequency map
std::shared_ptr<HuffmanNode> buildHuffmanTree(const std::unordered_map<char, int>& freq);

// Function to generate Huffman codes from the Huffman Tree
void generateHuffmanCodes(std::shared_ptr<HuffmanNode> root, const std::string& str, std::unordered_map<char, std::string>& huffmanCode);

#endif // HUFFMANTREE_H
