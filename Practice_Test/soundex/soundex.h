#ifndef SOUNDEX_H
#define SOUNDEX_H

char encode_char(char ch);
void encode(char* surname, char* soundex);
bool compare(char* one, char* two);
int count(char* surname, const char* sentence);

#endif
