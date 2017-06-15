//
// Created by David Madden on 2/4/17.
//

#ifndef PA1_BLOCK_H
#define PA1_BLOCK_H

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <fstream>
using std::ifstream;
using std::istream;
using std::ofstream;
#include <vector>
using std::vector;
#include <string>
using std::string;

class Block {
public:
	void Read(istream &inFile, istream &keyFile);
	void Encryption(istream& inFile, istream& keyFile, string& outFile);
	void Decryption(istream& inFile, istream& keyFile, string& outFile);

	vector<int> input;
	vector<int> key;
};

#endif //PA1_BLOCK_H
