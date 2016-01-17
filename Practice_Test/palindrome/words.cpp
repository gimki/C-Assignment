#include<iostream>
#include "words.h"
#include<cctype>;

//isalpha(char ch) returns 0 if not character
//toupper(char ch)


using namespace std;

void reverse(char* str1, char* str2){

  int string1_length=strlen(str1);
  for(int i=0;i<string1_length;i++){
    str2[i]=str1[string1_length-i-1];
  }
  
}

bool compare(char* one, char* two){


  
  int count_one=0, count_two=0;
  if(*(one+count_one)=='\0'){
    if(*(two+count_two)=='\0'){
	return 1;
    }else{
	return 0;
    }
  }
  while(!(isalpha(*(one+count_one)))){
    count_one++;
    if(*(one+count_one)=='\0'){
      break;
    }
  }
  while(!(isalpha(*(two+count_two)))){
    count_two++;
    if(*(two+count_two)=='\0'){
      break;
    }
  }

  
  if(*(one+count_one)=='\0'){
    if(*(two+count_two)=='\0'){
	return 1;
    }else{
	return 0;
    }
  }

  char one_upper=toupper(*(one+count_one));
  char two_upper=toupper(*(two+count_two));
  
  if(one_upper==two_upper){
    
    if(compare(one+count_one+1,two+count_two+1)){
      return 1;
    }else{
      return 0;
    }
  }else{
    return 0;
  }


}

bool palindrome(char* sentence){
  int sentence_length=strlen(sentence);
  char sentence_reverse[sentence_length+1];
  sentence_reverse[sentence_length]='\0';
  reverse(sentence, sentence_reverse);
  if(compare(sentence, sentence_reverse)){
    return 1;
  }else{
    return 0;
  }
}


bool anagram(char* str1, char* str2){

  int str1_length=strlen(str1);
  int str2_length=strlen(str2);

  char str1_sorted[str1_length+1];
  char str2_sorted[str2_length+1];

  sorting(str1, str1_sorted);
  sorting(str2, str2_sorted);

  if(compare(str1_sorted,str2_sorted)){
    return 1;
  }else{
    return 0;
  }

}
void sorting(char* str1, char* str2){

  int str1_length=strlen(str1);
  int str2_length=strlen(str2);
  char str1_letter_only[str1_length+1];
  letteronly(str1, str2);
  int count=0;
  int str1_letter_only_length=strlen(str2);

  /*
  while(*(str1_letter_only+count)!='\0'){
    int position=min_pos(str1_letter_only+count);
    swap(str1_letter_only[count], str1_letter_only[count+position]);
    cout<<position+count<<endl;
    cout<<str1_letter_only[count]<<str1_letter_only[count+position]<<endl;
    count++;


  }
  */
  
  for(; count<str1_letter_only_length;count++){
    int position=min_pos(str2+count);
    swap(str2[count],str2[position+count]);
  }
  
}

void swap(char& ch1, char& ch2){
  char temp;
  temp=ch2;
  ch2=ch1;
  ch1=temp;
  
}
int min_pos(char* str1){
  int min_index=0;
  int count=1;
  while(*(str1+count)!='\0'){
    if(*(str1+count)<*(str1+min_index)){
      min_index=count;
      count++;
      continue;
    }
    count++;
  }
  return min_index;
}

void letteronly(char* str1, char* str2){

  int fill=0, count=0;
  while(*(str1+count)!='\0'){
    if(!(isalpha(*(str1+count)))){
	  count++;
    }else{
      char letter_upper=toupper(*(str1+count));
      *(str2+fill)=letter_upper;
      fill++;
      count++;
    }
  }
  *(str2+fill)='\0';
    
}
