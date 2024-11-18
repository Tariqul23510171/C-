#include <iostream>
using namespace std;

struct Node {
  char ch;
  int freq;
  Node* left;
  Node* right;
};

Node* getNode(char ch, int freq, Node* left, Node* right) {
  Node* node = new Node();
  node->ch = ch;
  node->freq = freq;
  node->left = left;
  node->right = right;
  return node;
}

struct comp {
  bool operator()(Node* l, Node* r) {
    return l->freq > r->freq;
  }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
  if (root == nullptr) return;

  if (!root->left && !root->right) {
    huffmanCode[root->ch] = str;
  }
  encode(root->left, str + "0", huffmanCode);
  encode(root->right, str + "1", huffmanCode);
}

void buildHuffmanTree(unordered_map<char, int>& freq) {
  priority_queue<Node*, vector<Node*>, comp> pq;

  for (auto pair : freq) {
    pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
  }

  while (pq.size() != 1) {
    Node* left = pq.top();
    pq.pop();
    Node* right = pq.top();
    pq.pop();


    int sum = left->freq + right->freq;
    pq.push(getNode('\0', sum, left, right));
  }

  Node* root = pq.top();

  unordered_map<char, string> huffmanCode;
  encode(root, "", huffmanCode);

  int totalBits = 0;
  for (auto pair : freq) {
    totalBits += pair.second * huffmanCode[pair.first].length();
  }

  cout << "Huffman Codes:\n";
  for (auto pair : huffmanCode) {
    cout << pair.first << " " << pair.second << "\n";
  }

  cout << "\nTotal bits required: " << totalBits << endl;
}

int main() {
  unordered_map<char, int> freq;
  freq['A'] = 6;
  freq['B'] = 6;
  freq['C'] = 4;
  freq['D'] = 5;
  freq['E'] = 3;
  buildHuffmanTree(freq);
  return 0;
}
