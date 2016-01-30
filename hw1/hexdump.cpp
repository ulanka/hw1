//
//  dd.cpp
//  hw1
//
//  Created by Ulan Korabay on 1/29/16.
//  Copyright (c) 2016 Ulan Korabay. All rights reserved.
//

#include "dd.h"
//
//  hexdump.cpp
//  hw1
//
//  Created by Ulan Korabay on 1/29/16.
//  Copyright (c) 2016 Ulan Korabay. All rights reserved.
//
    
void Processhexdump(std::istream& in){
    (void)in;
        std::string every_line;//  16 symbols
        int i=1;// number of charachter
        while (!in.eof()) {
            int c = in.get();//next byte
            if ((i-1)%16==0) std::printf("%.6x: ",i-1);//prints line number
            if (c==-1) {
                break;//prevents writing eof
            }
            if ((c>=32)&&(c<=126)){//one of ASCII
                every_line+= (char)c;
            }
            else
            {
                if ((c<=31)||(c==127)){//one of not
                    every_line+=".";
                }
                else{
                    if (c>=128) {
                        every_line+="~";
                    }
                }
            }
            printf("%02x ", c);//5 hex value
            if (i%8==0) std::printf(" ");//additional space after 8 hex
            if (i%16==0) {
                std::cout<< every_line<<std::endl;//line of ASCII and unreadable symbols
                every_line="";//errrase for nextline
            }
            i++;//next charachter
        }
        //this will work only for last line as it is outside while loop
        //adds with "-- " if less than 16 symbols in line
        if (every_line.length()!=0){
            for (long ii = every_line.length();ii<16;++ii){
                std::cout<<"-- ";
                every_line+= " ";
                if (ii==7) std::cout<<" ";
            }
            std::cout<<" "<<every_line;
        }
        std::cout<<'\n';
    }
