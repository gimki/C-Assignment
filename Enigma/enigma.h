/*
 File name: enigma.h
 Author: Colman Yau
 Last update: 23-November 1638
 
 enigma.h is the header file of enigma.cpp
 Information of the functions is contained here (including the class declaration) 
 */

#ifndef ENIGMA_H_
#define ENIGMA_H_

#include "errors.h"

//boolean function that will return 1 if the files in argv[] can be opened
bool config_open(int _n, char **_file);

//function for checking whether the configuration of the plugboard is valid or not and will return
//the corresponding error code.
int plugboard_check(char *_pb);

//function for checking whether the configuration of the rotor is valid or not and will return
//the corresponding error code
int rotor_check(char *_rt);

//function for checking whether the configuration of the reflector is valid or not and will return
//the corresponding error code
int reflector_check(char *_rf);

//message check, take in a character and check whether it is a valid input for a message or not:
//1 means valid
bool message_character_check(char ch);

//rotor starting position validity check and return corresponding error code
int rotor_start_check(char *_pb);

//mod26 will give a positive value of modulo 26;
int mod26(int num);


//class for plugboard
class Plugboard{
private:
    int plugboard[26];
public:
    Plugboard(char *_pb);
    int plugboard_return(int ind);
};

//class for rotors
class Rotor{
private:
    int starting_pos;
    int rotor[26];
    int rotor_rev[26];
    int notch[26];
    int num_of_rotation;
public:
    int rotor_setup(char*_rt);
    int rotor_return(int ind);
    int rotor_rev_return(int ind);
    bool notch_return(int ind);
    void rotate();
    void starting_pos_setup(int s);
    int rotor_num_of_rotation();
    
};
class Reflector{
private:
    int reflector[26];
    
public:
    Reflector(char *_rf);
    int reflector_return(int ind);
};


//encrypt function
char encrpt(char ch, Plugboard *_pb, Reflector *_rf, Rotor **_rt, int _rotnum);
char encrpt(char ch,Plugboard *_pb, Reflector *_rf);
#endif /* ENIGMA_H_ */
