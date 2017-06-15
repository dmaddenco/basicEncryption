//
// Created by David Madden on 2/4/17.
//

#include "Block.h"

void Block::Read(istream &inFile, istream &keyFile) {
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

void Block::Encryption(istream &inFile, istream &keyFile, string &outFile) {
	//padding
	int pad = 128;
	while ((int) input.size() % 8 != 0) {
		input.push_back(pad);
	}

	//xor
	int spot = 0;
	for (int i = 0; i < (int) input.size(); ++i) {
		if (spot == 8) { spot = 0; }
		input[i] = input[i] ^ key[spot];
		spot++;
	}

	//swap
	bool swapDone = false;
	spot = 0;
	int end = (int) input.size() - 1;
	while (!swapDone) {
		for (int i = 0; i < (int) input.size(); ++i) {
			if (spot == 8) { spot = 0; }
			if (end <= i) { swapDone = true; break; }
			if (key[spot] % 2 != 0) {	//swap happens
				int temp = input[i];
				input[i] = input[end];
				input[end] = temp;
				end--;
			}
			spot++;
		}
	}

	//write output
	ofstream file;
	file.open(outFile);
	for (int j = 0; j < (int) input.size(); ++j) {
		file << (char) input[j];
	}
	file.close();
}

void Block::Decryption(istream &inFile, istream &keyFile, string &outFile) {
	//swap
	bool swapDone = false;
	int spot = 0;
	int end = (int) input.size() - 1;
	while (!swapDone) {
		for (int i = 0; i < (int) input.size(); ++i) {
			if (spot == 8) { spot = 0; }
			if (end <= i) { swapDone = true; break; }
			if (key[spot] % 2 != 0) {	//swap happens
				int temp = input[i];
				input[i] = input[end];
				input[end] = temp;
				end--;
			}
			spot++;
		}
	}

	//xor
	spot = 0;
	for (int i = 0; i < (int) input.size(); ++i) {
		if (spot == 8) { spot = 0; }
		input[i] = input[i] ^ key[spot];
		spot++;
	}

	vector<int> newInput;
	//remove padding
	for (int k = 0; k < (int) input.size(); ++k) {
//		cout<<input[k]<<" ";
		if (input[k] <= 127 && input[k] >= 0) {
			newInput.push_back(input[k]);
//			cout<<input[k]<<" ";
		}
		else {
			break;
		}
	}
//	cout<<endl;
//    cout<<input.size()<<endl;
//    cout<<newInput.size()<<endl;
//    cout<<newInput[55]<<endl;

	//write output
	ofstream file;
	file.open(outFile);
	for (int j = 0; j < (int) newInput.size(); ++j) {
		file << (char) newInput[j];
	}
	file.close();
}