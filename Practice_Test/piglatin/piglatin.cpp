#include<iostream>
#include<cctype>
#include<fstream>
#include "piglatin.h"

using namespace std;

int findFirstVowel(char word[]){

  int word_length=strlen(word);
  for(int i=0;i<word_length;i++){
    if(isVowel(*(word+i),i,word_length)){
      return i;
    }
  }
  return -1;
}

bool isVowel(char ch, int position, int length){


  if(!isalpha(ch)){
    return 0;
  }

  
  if(ch=='y'&&(position!=0)&&(position!=(length-1))){
    return 1;
  }

  switch(ch){
  case 'a':
  case 'e':
  case 'i':
  case 'o':
  case 'u':return 1;
  default: return 0;
  }

}


void translateWord(char english[], char piglatin[]){

  if(!isalnum(*english)){
    cout<<"error"<<endl;
    return;

  }


  
  if(isdigit(*english)){
    strcpy(piglatin,english);
    return; 
  }


  if(findFirstVowel(english)==0){
    strcpy(piglatin, english);
    strcat(piglatin,"way");
    if(isupper(*english)){
      char first=toupper(*piglatin);
      *piglatin=first;
      //piglatin needs to have upper
    }
    return;
  }

  if(findFirstVowel(english)==-1){
    strcpy(piglatin, english);
    strcat(piglatin,"ay");
    
    if(isupper(*english)){
      char first=toupper(*piglatin);
      *piglatin=first;
      //piglatin needs to have upper
    }
    return;
  }

  int position=findFirstVowel(english);

  strcpy(piglatin,english+position);

  char* holder;
  for(int i=0;i<position;i++){
    *(holder+i)=english[i];
  }
  *(holder+position)='\0';

  strcat(piglatin,holder);
  int length=strlen(piglatin);

  if(*(piglatin+length-1)=='a'||*(piglatin+length-1)=='A'){
    strcat(piglatin,"y");
    if(isupper(*english)){
    char first=toupper(*piglatin);
    *piglatin=first;
    //piglatin needs to have upper

  }
    return;
  }else{
    strcat(piglatin,"ay");
    if(isupper(*english)){
    char first=toupper(*piglatin);
    *piglatin=first;
    //piglatin needs to have upper
  }
    return;
  }
}

void translateStream(istream& in, ostream& out){


  char s[60];
  char t[60];
  in>>s;
  if(!in.eof()){
    translateWord(s,t);
    out<<t<<" ";
    out<<"00000";
    translateStream(in,out);
  }

  return;
}
