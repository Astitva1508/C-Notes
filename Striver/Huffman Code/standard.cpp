#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Define a structure for Huffman Tree Nodes
struct HuffmanNode
{
    char data;          // Symbol (e.g., character)
    int frequency;      // Frequency of the symbol
    HuffmanNode *left;  // Pointer to the left child node
    HuffmanNode *right; // Pointer to the right child node

    // Constructor for leaf nodes
    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue (min-heap)
struct CompareNodes
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->frequency > b->frequency;
    }
};

// Function to generate Huffman codes and store them in a map
void generateHuffmanCodes(HuffmanNode *root, string code, map<char, string> &huffmanCodes)
{
    if (root == nullptr)
    {
        return;
    }

    // Leaf node, store the code for the symbol
    if (!root->left && !root->right)
    {
        huffmanCodes[root->data] = code;
    }

    // Traverse left with '0'
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);

    // Traverse right with '1'
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode a string using Huffman codes
string encode(string input, map<char, string> &huffmanCodes)
{
    string encodedString = "";
    for (char c : input)
    {
        encodedString += huffmanCodes[c];
    }
    return encodedString;
}

// Function to decode a Huffman-encoded string
string decode(string encodedString, HuffmanNode *root)
{
    string decodedString = "";
    HuffmanNode *current = root;

    for (char bit : encodedString)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (!current->left && !current->right)
        {
            // Leaf node reached, append the symbol to the decoded string
            decodedString += current->data;
            current = root; // Reset to the root for the next symbol
        }
    }

    return decodedString;
}

int main()
{
    // Sample input string
    string inputString = "this is an example for huffman encoding";

    // Calculate symbol frequencies
    map<char, int> frequencies;
    for (char c : inputString)
    {
        frequencies[c]++;
    }

    // Create a priority queue (min-heap) of Huffman nodes
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodes> minHeap;
    for (const auto &pair : frequencies)
    {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (minHeap.size() > 1)
    {
        HuffmanNode *left = minHeap.top();
        minHeap.pop();
        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        HuffmanNode *internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    // The root of the Huffman tree
    HuffmanNode *root = minHeap.top();

    // Generate Huffman codes
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Encode the input string
    string encodedString = encode(inputString, huffmanCodes);
    cout << "Encoded String: " << encodedString << endl;

    // Decode the encoded string
    string decodedString = decode(encodedString, root);
    cout << "Decoded String: " << decodedString << endl;

    return 0;
}
