#include "HuffmanTree.h"
#include <queue>

struct Compare {
    bool operator()(std::shared_ptr<HuffmanNode> const& l, std::shared_ptr<HuffmanNode> const& r) {
        return l->freq > r->freq;
    }
};

std::unordered_map<char, int> calculateFrequency(const std::string& filename) {
    std::unordered_map<char, int> freq;
    std::ifstream file(filename, std::ios::binary);
    char ch;
    
    while (file.get(ch)) {
        freq[ch]++;
    }
    
    file.close();
    return freq;
}

std::shared_ptr<HuffmanNode> buildHuffmanTree(const std::unordered_map<char, int>& freq) {
    std::priority_queue<std::shared_ptr<HuffmanNode>, std::vector<std::shared_ptr<HuffmanNode>>, Compare> minHeap;
    
    for (auto& pair : freq) {
        minHeap.push(std::make_shared<HuffmanNode>(pair.first, pair.second));
    }
    
    while (minHeap.size() > 1) {
        auto left = minHeap.top(); minHeap.pop();
        auto right = minHeap.top(); minHeap.pop();
        
        auto sum = std::make_shared<HuffmanNode>('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        
        minHeap.push(sum);
    }
    
    return minHeap.top();
}

void generateHuffmanCodes(std::shared_ptr<HuffmanNode> root, const std::string& str, std::unordered_map<char, std::string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    
    generateHuffmanCodes(root->left, str + "0", huffmanCode);
    generateHuffmanCodes(root->right, str + "1", huffmanCode);
}
