/*
 File name: main.cpp
 Author: Colman Yau
 Last update: 23-November 1638
 
 main.cpp is the main file of the enigma project.
 It contained instruction to check the plugboard, rotors and reflectors file and run and encryption.
 This program takes in those configurations by the position of input but not by reading the extension of the file.
 Further information of most functions is contained in the enigma.h files
 */

#include <iostream>
#include <cmath>
#include <ctype.h>
#include <stdio.h>
#include <fstream>
#include "enigma.h"


using namespace std;

int main(int argc,char **argv){

	//check whether there are sufficient number of input
	if(argc<=2){
	  cerr<<"INSUFFICIENT_NUMBER_OF_PARAMETERS";
	  return INSUFFICIENT_NUMBER_OF_PARAMETERS;
	}

	//check whether there is an error opening the configuration files
	if(!config_open(argc, argv)){
	  cerr<<"ERROR_OPENING_CONFIGURATION_FILE";
        return ERROR_OPENING_CONFIGURATION_FILE;
	}

    //plugboard checking
	switch(plugboard_check(argv[1])){
	case 0: break;
	case 3:  cerr<<"plugboard: INVALID_INDEX";return INVALID_INDEX;
	case 4:  cerr<<"plugboard: NON_NUMERIC_CHARACTER";
	  return NON_NUMERIC_CHARACTER;
	case 5:  cerr<<"plugboard: IMPOSSIBLE_PLUGBOARD_CONFIGURATION";
            return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
	case 6:  cerr<<"plugboard: INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS";
	  return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
    
	default: break;
	};
    
    //rotor checking
	for(int i=3;i<=argc-2;i++){
	switch(rotor_check(argv[i])){
        case 0: break;
        case 3:  cerr<<"rotor "<<i-2<<" :INVALID_INDEX";
            return INVALID_INDEX;
        case 4:  cerr<<"rotor "<<i-2<<" :NON_NUMERIC_CHARACTER";
            return NON_NUMERIC_CHARACTER;
        case 7:  cerr<<"rotor "<<i-2<<" :INVALID_ROTOR_MAPPING";
            return INVALID_ROTOR_MAPPING;
	default: break;
	}
	}
    
    //rotor starting position checking
    switch(rotor_start_check(argv[argc-1])){
        case 0: break;
        case 3:  cerr<<"rotor starting position configuration: INVALID_INDEX";
            return INVALID_INDEX;
        case 4:  cerr<<"rotor starting position configuration: NON_NUMERIC_CHARACTER";
            return NON_NUMERIC_CHARACTER;
        default: break;
    }

    //reflector checking
	switch(reflector_check(argv[2])){
    case 0: break;
	case 3:  cerr<<"reflector: INVALID_INDEX";
            return INVALID_INDEX;
	case 4:  cerr<<"reflector: NON_NUMERIC_CHARACTER";
	  return NON_NUMERIC_CHARACTER;
	case 9:  cerr<<"reflector: INVALID_REFLECTOR_MAPPING";
            return INVALID_REFLECTOR_MAPPING;
	case 10:  cerr<<"reflector: INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS";
            return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
	default: break;
	}
    
    //input all the configuration after verifying them
    Plugboard plugboard(argv[1]);
    Reflector reflector(argv[2]);
    
    //input rotor(s)
    // rotor in the leftmost (last one) is presented first in command line
    int num_rot=argc-4;
    if(argc==3){
        num_rot=0;
    }
    Rotor **rotor=new Rotor*[num_rot];
    if(num_rot>0){
        
        for(int j=0;j<num_rot;j++){
            rotor[j]= new Rotor;
            if(rotor[j]->rotor_setup(argv[j+3])==7){
                cerr<<" rotor "<< j+1 <<" :do not have any notch. "<<endl;
                return INVALID_ROTOR_MAPPING;
            }
        }
    }
    //starting position input for rotor;
    //output no rotor starting position if there is insufficient number of starting position
    if(num_rot>0){
        
        ifstream starting_pos_input(argv[argc-1]);
        int starting_pos;
        int count_for_starting_pos=0;
        starting_pos_input>>starting_pos;
        if(starting_pos_input.eof()){
            cerr<<"rotor starting position configuration: NO_ROTOR_STARTING_POSITION";
            delete[] rotor;
            return NO_ROTOR_STARTING_POSITION;
        }
    while(count_for_starting_pos<num_rot){
        rotor[count_for_starting_pos]->starting_pos_setup(starting_pos);
        count_for_starting_pos++;
        starting_pos_input>>starting_pos;
        if(starting_pos_input.eof()){
            break;
        }
    }
    if(!starting_pos_input.eof()){
        cerr<<"number of rotor starting position > number of rotor: INSUFFICIENT_NUMBER_OF_PARAMETERS";
        return INSUFFICIENT_NUMBER_OF_PARAMETERS;
    }
    if(count_for_starting_pos<num_rot){
        cerr<<"rotor starting position configuration: NO_ROTOR_STARTING_POSITION";
        delete[] rotor;
        return NO_ROTOR_STARTING_POSITION;
    }
    }
    
    
    
    //Encryption begins; we will check each character before encrypting it.
    char mess;
    cin>>mess;
    while(!cin.eof()){
        int t=1;
        if(!message_character_check(mess)){
	  cerr<<"message: invalid input character in message";
            delete[] rotor;
            return INVALID_INPUT_CHARACTER;
        }
        if(num_rot!=0){
        rotor[num_rot-1]->rotate();
            while(rotor[num_rot-t]->notch_return(mod26(rotor[num_rot-t]->rotor_num_of_rotation()))){
                rotor[num_rot-t-1]->rotate();
                t++;
            }
        }
        if((num_rot)>0){
            cout<<encrpt(mess,&plugboard, &reflector, rotor, num_rot);
        }else{
        cout<<encrpt(mess,&plugboard, &reflector);
        }
        
        cin>>mess;
    }
    delete[] rotor;
    return NO_ERROR;
}
