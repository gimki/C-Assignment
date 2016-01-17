#include<iostream>
#include "substring.h"
#include<cstring>

using namespace std;
/*
// is_prefix has 2 argument and check if the first argument is the prefix of the second.
bool is_prefix(char first_string[],char second_string[],int first_length, int second_length){

  if(first_length>second_length){
    return 0;
  }
  if(first_length==0){
    return 1;
  }

  if(first_string[0]==second_string[0]){

    char first_string_copy[first_length];
    char second_string_copy[second_length];

    for(int i=1;i<first_length;i++){
      first_string_copy[i-1]=first_string[i];
    }
    for(int j=1;j<second_length;j++){
      second_string_copy[j-1]=second_string[j];
    }

    first_string_copy[first_length]='\0';
    second_string_copy[second_length]='\0';
    if(is_prefix(first_string_copy,second_string_copy,first_length-1,second_length-1)){
      return 1;
    }else{
      return 0;
    }
    
  }
  
}
*/

bool is_prefix(char* first_string, char* second_string){

  int first_length=strlen(first_string);
  int second_length=strlen(second_string);
  if(first_length>second_length){
    return 0;
  }
  if(*first_string=='\0'){
    return 1;
  }

  if(*first_string==*second_string){
    if(is_prefix(first_string+1,second_string+1)){
      return 1;
    }else{
      return 0;
    }
  }else{
    return 0;
  }
}


int substring_position(char* first_string, char* second_string){

  if(is_prefix(first_string,second_string)){
    return 0;
  }
  
  //cout<<strlen(first_string)<<endl<<strlen(second_string)<<endl;
  if(strlen(first_string)==strlen(second_string)&&!(is_prefix(first_string,second_string))){
    return -1;
  }
  
  int result=substring_position(first_string,second_string+1);
  if(result>=0){
    return (result+1);
  }else{
    return -1;
  }
}
