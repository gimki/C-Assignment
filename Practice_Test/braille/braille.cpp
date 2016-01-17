#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int encode_character(char ch, char* braille){
  if(ispunct(ch)){
    switch(ch){
    case '.':strcpy(braille,".0..00");
      return 6;
    case ',':strcpy(braille,".0....");
      return 6;
    case ';':strcpy(braille,".00...");
      return 6;
    case '-':strcpy(braille,"..0..0");
      return 6;
    case '!':strcpy(braille,".00.0.");
      return 6;
    case '?':strcpy(braille,".00..0");
      return 6;
    case '(':
    case ')':strcpy(braille,".00.00");
      return 6;
    default:strcpy(braille,"......");
      return 6;
    }
  }

  if(isdigit(ch)){
    switch(ch){
    case '1':strcpy(braille,"..00000.....");
      return 12;
    case '2':strcpy(braille,"..000000....");
      return 12;
    case '3':strcpy(braille,"..00000..0..");
      return 12;
    case '4':strcpy(braille,"..00000..00.");
      return 12;
    case '5':strcpy(braille,"..00000...0.");
      return 12;
    case '6':strcpy(braille,"..000000.0..");
      return 12;
    case '7':strcpy(braille,"..000000.00.");
      return 12;
    case '8':strcpy(braille,"..000000..0.");
      return 12;
    case '9':strcpy(braille,"..0000.0.0..");
      return 12;
    case '0':strcpy(braille,"..0000.0.00.");
      return 12;
    default:strcpy(braille,"......");
      return 6;
    }
  }
  if(isalpha(ch)){
    int result;
    if(isupper(ch)){
      strcpy(braille,".....0");
      result=6;
    }else{
      strcpy(braille,"");
      result=0;
    }
    
    char lowercase=tolower(ch);
    switch(lowercase){
    case 'a':strcat(braille,"0.....");
      break;
    case 'b':strcat(braille,"00....");
      break;
    case 'c':strcat(braille,"0..0..");
      break;
    case 'd':strcat(braille,"0..00.");
      break;
    case 'e':strcat(braille,"0...0.");
      break;
    case 'f':strcat(braille,"00.0..");
      break;
    case 'g':strcat(braille,"00.00.");
      break;
    case 'h':strcat(braille,"00..0.");
      break;
    case 'i':strcat(braille,".0.0..");
      break;
    case 'j':strcat(braille,".0.00.");
      break;
    case 'k':strcat(braille,"0.0...");
      break;
    case 'l':strcat(braille,"000...");
      break;
    case 'm':strcat(braille,"0.00..");
      break;
    case 'n':strcat(braille,"0.000.");
      break;
    case 'o':strcat(braille,"0.0.0.");
      break;
    case 'p':strcat(braille,"0000..");
      break;
    case 'q':strcat(braille,"00000.");
      break;
    case 'r':strcat(braille,"000.0.");
      break;
    case 's':strcat(braille,".000..");
      break;
    case 't':strcat(braille,".0000.");
      break;
    case 'u':strcat(braille,"0.0..0");
      break;
    case 'v':strcat(braille,"000..0");
      break;
    case 'w':strcat(braille,".0.000");
      break;
    case 'x':strcat(braille,"0.00.0");
      break;
    case 'y':strcat(braille,"0.0000");
      break;
    case 'z':strcat(braille,"0.0.00");
      break;
    default:strcat(braille,"......");
      return (result+6);
    }
    return (result+6);
  }
  
strcpy(braille,"......");
return 6;

}


void encode(char* plaintext,char* braille){

  int length=encode_character(*(plaintext),braille);
  if(*(plaintext+1)!='\0'){
    encode(plaintext+1,braille+length);
  }else{
    *(braille+length)='\0';
  }
  
}

void print_braille(char* plaintext,ostream& os){
    char braille[1000];
    encode(plaintext,braille);
    int length=strlen(braille);
    int count_row1=0;
    while(count_row1<length){
        os<<braille[count_row1]<<braille[count_row1+3]<<" ";
        count_row1+=6;
    }
    os<<endl;
    int count_row2=1;
    while(count_row2<length){
        os<<braille[count_row2]<<braille[count_row2+3]<<" ";
        count_row2+=6;
    }
    os<<endl;
    int count_row3=2;
    while(count_row3<length){
        os<<braille[count_row3]<<braille[count_row3+3]<<" ";
        count_row3+=6;
    }
    os<<endl;
    
    int count=0;
    char vir_holder[100];
    while(*(plaintext+count)!='\0'){
        int char_length=encode_character(*(plaintext+count),vir_holder);
        if(char_length==6){
            cout<<*(plaintext+count)<<"  ";
        }else if(char_length==12){
            cout<<"   "<<*(plaintext+count)<<"  ";
        }
        count++;
    }
}











