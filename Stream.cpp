//
// Created by David Madden on 2/4/17.
//

#include "Stream.h"

void Stream::Read(istream &inFile, istream &keyFile) {
	char c;
	int bit;
	while (inFile.get(c)) {
		bit = (int) c;
		input.push_back(bit);
	}

	while (keyFile.get(c)) {
		bit = (int) c;
		key.push_back(bit);
	}
}

void Stream::Encryption(istream &inFile, istream &keyFile, string &outFile) {
	int spot = 0;
	for (int i = 0; i < (int) input.size(); ++i) {
        if (spot == ((int) key.size())) { spot = 0; }
        input[i] = input[i] ^ key[spot];
		spot++;
    }

	ofstream file;
	file.open(outFile);
	for (int j = 0; j < (int) input.size(); ++j) {
		file << (char) input[j];
	}
	file.close();
}

void Stream::Decryption(istream &inFile, istream &keyFile, string &outFile) {
    int spot = 0;
    for (int i = 0; i < (int) input.size(); ++i) {
        if (spot == (int) key.size()) { spot = 0; }
        input[i] = input[i] ^ key[spot];
        spot++;
    }

    ofstream file;
    file.open(outFile);
    for (int j = 0; j < (int) input.size(); ++j) {
        file << (char) input[j];
    }
    file.close();
}
