/*
 File name: enigma.cpp
 Author: Colman Yau
 Last update: 23-November 1638
 
 enigma.cpp is the implementation files of the helper functions assisting in the main.cpp file.
 Further information of the functions is contained in the enigma.h files
 */

#include <iostream>
#include <cmath>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include "enigma.h"
using namespace std;

//
bool config_open(int _n, char **_file){
	for(int i=1;i<_n; i++){
		ifstream test;
		test.open(_file[i]);
		if(test.fail()){
			return 0;
		}
		test.close();
	}
	return 1;
}

int mod26(int num){
    int k=num%26;
    if(k<0){
        return k+26;
    }else{
        return k;
    }
}

//
int plugboard_check(char *_pb){
	ifstream pb_char(_pb);
	ifstream pb_int(_pb);
	int occur[26]={0};
	char ch;
	int mapping;
	int count=0;
	pb_char>>ws>>ch;
	pb_int>>mapping;
	while(!pb_char.eof()){
		while(!pb_int.eof()){
			do{
				if(ch<'0'||ch>'9'){
					return 4;
				}
				pb_char>>ch;
				if(pb_char.eof()){
					break;
				}
            }while(ch!=' ');
            if(!pb_char.eof()){
					pb_char>>ws>>ch;
            }
			if(mapping>25||mapping<0){
				return 3;
			}
			occur[mapping]++;
			count++;
			if(count>26){
			  return 6;
			    }
			if(occur[mapping]==2){
                return 5;
			}
			pb_int>>mapping;
		}
	}
    pb_int.close();
    pb_char.close();
	if(count%2==1){
		return 6;
    }
	return 0;
}

//
int rotor_check(char *_rt){
    ifstream rt_char(_rt);
    ifstream rt_int(_rt);
    int occur[26]={0};
    char ch;
    int mapping;
    int count=0;
    
    rt_char>>ws>>ch;
    rt_int>>mapping;
    
    while(!rt_char.eof()){
        while(!rt_int.eof()){
            do{
                if(ch<'0'||ch>'9'){
                    return 4;
                }
                rt_char>>ch;
                if(rt_char.eof()){
                    break;
                }
            }while(ch!=' ');
            
            if(!rt_char.eof()){
                rt_char>>ws>>ch;
            }
            if(mapping>25||mapping<0){
                return 3;
            }
            occur[mapping]++;
            if(occur[mapping]==2){
                return 7;
            }
            count++;
            if(count==26){
                for(int j=0;j<=25;j++){
                    occur[j]=0;
                }
            }
            rt_int>>mapping;
        }
    }
    if(count<26){
        return 7;
    }
    rt_char.close();
    rt_int.close();
    return 0;
}

//
int reflector_check(char *_rf){
    ifstream rf_char(_rf);
    ifstream rf_int(_rf);
    int occur[26]={0};
    char ch;
    int mapping;
    int count=0;
    
    rf_char>>ws>>ch;
    rf_int>>mapping;
    
    while(!rf_char.eof()){
        while(!rf_int.eof()){
            do{
                if(ch<'0'||ch>'9'){
                    return 4;
                }
                rf_char>>ch;
                if(rf_char.eof()){
                    break;
                }
            }while(ch!=' ');
            if(!rf_char.eof()){
                rf_char>>ws>>ch;
            }
            if(mapping>25||mapping<0){
                return 3;
            }
            occur[mapping]++;
	    count++;
            if (count>26){
                return 10;
            }
            if(occur[mapping]==2){
                return 9;
            }
            rf_int>>mapping;
        }
    }
    rf_int.close();
    rf_char.close();
    if(count!=26){
        return 10;
    }
    return 0;
}

//
int rotor_start_check(char *_pb){
    ifstream rts_char(_pb);
    ifstream rts_int(_pb);
    char ch;
    int start;
    
    rts_char>>ws>>ch;
    rts_int>>start;
    
    while(!rts_char.eof()){
        while(!rts_int.eof()){
            do{
                if(ch<'0'||ch>'9'){
                    return 4;
                }
                rts_char>>ch;
                if(rts_char.eof()){
                    break;
                }
            }while(ch!=' ');
            
            if(!rts_char.eof()){
                rts_char>>ws>>ch;
            }
            if(start>25||start<0){
                return 3;
            }
            rts_int>>start;
        }
    }
    rts_int.close();
    rts_char.close();
    return 0;
}

//
bool message_character_check(char ch){
    if(ch>'Z'||ch<'A'){
        return 0;
    }
    return 1;
}

//Plugboard Class
Plugboard::Plugboard(char *_pb){
	for(int i=0;i<=25;i++){
		plugboard[i]=i;
	}
	ifstream input(_pb);
	int mapping_a;
	int mapping_b;
	input>>mapping_a;
    
	while(!input.eof()){
		mapping_b=mapping_a;
		input>>mapping_a;
		plugboard[mapping_a]=mapping_b;
		plugboard[mapping_b]=mapping_a;
		input>>mapping_a;
	}
    input.close();
}
//
int Plugboard::plugboard_return(int ind){
	return plugboard[ind];
}

// Rotor Class
int Rotor::rotor_setup(char*_rt){
    ifstream input(_rt);
    num_of_rotation=0;
    int mapping_e;
    int count=0;
    input>>mapping_e;
    while(count<=25){
        rotor[count]=mapping_e;
        rotor_rev[mapping_e]=count;
        notch[count]=0;
        input>>mapping_e;
        count++;
    }
    if(input.eof()){
        return 7;
    }
    while(!input.eof()){
        notch[mapping_e]=1;
        input>>mapping_e;
    }
    input.close();
    return 0;
}
//
int Rotor::rotor_return(int ind){
    return rotor[ind];
}
//
int Rotor::rotor_rev_return(int ind){
    return rotor_rev[ind];
}
//
int Rotor::rotor_num_of_rotation(){
    return num_of_rotation;
}
//
void Rotor::starting_pos_setup(int s){
    starting_pos=s;
    num_of_rotation+=s;
}
//
bool Rotor::notch_return(int ind){
    if(notch[ind]==1){
        return 1;
    }
    return 0;
}
//
void Rotor::rotate(){
    num_of_rotation++;
}

//class for reflector
Reflector::Reflector(char *_rf){
	for(int k=0;k<=25;k++){
			reflector[k]=k;
	}
	ifstream input(_rf);
	int mapping_c;
	int mapping_d;
	input>>mapping_c;
	while(!input.eof()){
		mapping_d=mapping_c;
		input>>mapping_c;
		reflector[mapping_c]=mapping_d;
		reflector[mapping_d]=mapping_c;
		input>>mapping_c;
	}
	input.close();
}
//
int Reflector::reflector_return(int ind){
	return reflector[ind];
}

//encrypt function(overloading function catering for 0 or 1+ rotors)
char encrpt(char ch, Plugboard *_pb, Reflector *_rf, Rotor **_rt, int _rotnum){
    int ascii;
    ascii=ch-65;
    int a=_pb->plugboard_return(ascii);
    for(int i=_rotnum-1; i>=0;i--){
        a=mod26(_rt[i]->rotor_num_of_rotation()+a);
        a=_rt[i]->rotor_return(a);
        a=mod26(a-_rt[i]->rotor_num_of_rotation());
    }
    a=_rf->reflector_return(a);
    for(int i=0;i<_rotnum;i++){
        a=mod26(_rt[i]->rotor_num_of_rotation()+a);
        a=_rt[i]->rotor_rev_return(a);
        a=mod26(a-_rt[i]->rotor_num_of_rotation());
    }
    a=_pb->plugboard_return(a);
    char encrypt=a+65;
    return encrypt;
}
//encrypt function for no rotor
char encrpt(char ch,Plugboard *_pb, Reflector *_rf){
    int ascii;
    ascii=ch-65;
    int b;
    int a=_pb->plugboard_return(ascii);

    b=_rf->reflector_return(a);
    a=_pb->plugboard_return(b);
    
    char encrypt=a+65;
    return encrypt;
}


