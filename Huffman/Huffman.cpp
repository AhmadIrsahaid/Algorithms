#include <iostream>
#include <string>
#include <queue>
#include"HufffmanImp.h"
using namespace std;

int main() {
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    int occurrences[26] = { 0 };

    cout << "Character occurrences: " << endl;
    for (int i = 0; i < paragraph.length(); ++i) {
        char c = paragraph[i];
        if (isalpha(c)) {
            c = tolower(c);
            occurrences[c - 'a']++;
        }
    }

    char currentChar = 'a';
    for (int i = 0; i < 26; i++) {
        if (occurrences[i] > 0) {
            cout << currentChar << " : " << occurrences[i] << endl;
        }
        currentChar++;
    }

    cout << "- - - - - - - - - - -  - - - - - - -" << endl;

    string codes[26];
    priority_queue<Node*, vector<Node*>, compareNode> PriorityQueue;
    HuffmanCodes(paragraph, occurrences, codes, PriorityQueue);
    cout << "Huffman Codes: " << endl;
    for (int i = 0; i < 26; i++) {
        if (!codes[i].empty()) {
            cout << char('a' + i) << " : " << codes[i] << endl;
        }
    }
    cout << "- - - - - - - - - - -  - - - - - - -" << endl;

    string inputString;
    cout << "Enter a string to encode: ";
    getline(cin, inputString);
    string encodedString = encode(inputString, codes);
    cout << "Encoded string: " << encodedString << endl;
    cout << "Total bits needed: " << encodedString.length() << endl;

    cout << "- - - - - - - - - - -  - - - - - - -" << endl;

    cout << "Enter a binary sequence to decode: ";
    string binarySequence;
    cin >> binarySequence;
    string decodedText = decode(binarySequence, PriorityQueue.top());
    cout << "Decoded text: " << decodedText << endl;
}
