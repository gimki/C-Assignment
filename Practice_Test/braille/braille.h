#ifndef BRAILLE_H
#define BRAILLE_H


int encode_character(char ch, char* braille);
int encode(char* plaintext,char*braille);
void print_braille(char* plaintext,ostream& os);



#endif
