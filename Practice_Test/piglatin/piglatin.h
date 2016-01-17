#ifndef PIGLATIN_H
#define PIGLATIN_H

#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;
int findFirstVowel(char* word);
bool isVowel(char ch, int position, int length);
void translateWord(char english[], char piglatin[]);
void translateStream(istream& in, ostream& out);



#endif
