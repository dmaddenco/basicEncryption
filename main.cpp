//
// Created by David Madden on 1/25/17.
//

/* commandline example: out B blockPlainText output blockKey E */

#include "Block.h"
#include "Stream.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;

int Error(char* arg0, int error) {
	cout << "!!!Error with Project!!!" << endl;
	if (error == 0){
		cout << "Not enough arguments." << endl;
	}
	else if (error == 1) { cout << "File does not exist." << endl ;}
	else if (error == 2) { cout << "Wrong cipher selection. Choose either 'B' or 'S'." << endl ;}
	else if (error == 3) { cout << "Wrong operation selection. Choose either 'E' or 'D'." << endl ;}
	return -1;
}

int main(int argc, char* argv[]) {
	if (argc != 6) {
		return Error(argv[0], 0);
	}
	char cipher = *argv[1];
	ifstream inFile(argv[2]);
	string outFile = argv[3];
	ifstream keyFile(argv[4]);
	if (inFile.fail() || /*outFile.fail() ||*/ keyFile.fail()) return Error(argv[0], 1);
	char operation = *argv[5];

	switch (cipher) {
		case 'B': {
//			cout << "its a block!" << endl;
			Block block;
			block.Read(inFile, keyFile);
			switch (operation) {
				case 'E':
					block.Encryption(inFile, keyFile, outFile);
//					cout << "its encryption!" << endl;
					break;
				case 'D':
                    block.Decryption(inFile, keyFile, outFile);
//					cout << "its decryption!" << endl;
					break;
				default:
					return Error(argv[0], 3);
			}
			break;
		}
		case 'S': {
//			cout << "its a stream!" << endl;
			Stream stream;
			stream.Read(inFile, keyFile);
			switch (operation) {
				case 'E':
					stream.Encryption(inFile, keyFile, outFile);
//					cout << "its encryption!" << endl;
					break;
				case 'D':
                    stream.Decryption(inFile, keyFile, outFile);
//					cout << "its decryption!" << endl;
					break;
				default:
					return Error(argv[0], 3);
			}
			break;
		}
		default:
			return Error(argv[0], 2);
	}

	return 0;
}