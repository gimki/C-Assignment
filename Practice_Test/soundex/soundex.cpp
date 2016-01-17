#include <iostream>
#include <cctype>

using namespace std;
// isalpha(char ch) non-zero if char
// toupper(char ch) gives uppercase of ch


//will not check if ch is a char but will return -1 if there is an error
char encode_char(char ch){
  char ch_upper=toupper(ch);

  switch(ch_upper){
  case 'B':
  case 'F':
  case 'P':
  case 'V': return '1';
  case 'C':
  case 'G':
  case 'J':
  case 'K':
  case 'Q':
  case 'S':
  case 'X':
  case 'Z': return '2';
  case 'D':
  case 'T': return '3';
  case 'L': return '4';
  case 'M':
  case 'N': return '5';
  case 'R': return '6';
  default: return '9';
  }
  
  return -1;
}

bool ignore_char(char ch){
  char upper_ch=toupper(ch);
  switch(upper_ch){
  case 'A':
  case 'E':
  case 'I':
  case 'O':
  case 'U':
  case 'H':
  case 'W':
  case 'Y': return 1;
  default: return 0;

  }

}


void encode(char* surname, char* soundex){
  if(!isalpha(*surname)){
    soundex="fail";
  }

  for(int i=0;i<4;i++){
    soundex[i]='0';
  }
  soundex[4]='\0';
  int fill=1;
  int count=1;

  char first_letter=toupper(*surname);
  *soundex=first_letter;
  int switcher=1;
  
  while(fill<4){
    if(*(surname+count)=='\0'){
      break;
    }
    if(ignore_char(*(surname+count))){
      switcher=0;
      count++;
      continue;
    }
    if((encode_char(*(surname+count))==*(soundex+fill-1))&&switcher==1){
      count++;
      continue;
    }
    *(soundex+fill)=encode_char(*(surname+count));
    switcher=1;
    fill++;
    count++;
  } 
}


bool compare(char* one, char* two){

  if(*one=='\0'){
    if(*two=='\0'){
      return 1;
    }else{
      return 0;
    }
  }
  
  
  if(*one==*two){
    if(compare(one+1,two+1)){
      return 1;
    }else{
      return 0;
    }
  }
}

int count(char* surname, const char* sentence){

  int sentence_length=strlen(sentence);
  char surname_code[5];
  encode(surname, surname_code);
  int result=0;
  int count=0;
  while(*(sentence+count)!='\0'){
    if(!(isalpha(*(sentence+count)))){
      count++;
      continue;
    }
    char other_surname_code[5];
    char other_surname[sentence_length];
    int i=0;
    while(isalpha(*(sentence+count))){
      other_surname[i]=*(sentence+count);
      count++;
      i++;
      if(!(isalpha(*(sentence+count)))){
	other_surname[i]='\0';
	break;
      }
    }
    encode(other_surname, other_surname_code);
    if(compare(other_surname_code,surname_code)){
      result++;
    }
    count++;
    
  }
  return result;
}
