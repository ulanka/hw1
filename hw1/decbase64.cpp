//
//  decbase64.cpp
//  hw1
//
//  Created by Ulan Korabay on 1/29/16.
//  Copyright (c) 2016 Ulan Korabay. All rights reserved.
//

#include <stdio.h>
#include "dd.h"
std::string Get3for4(std::string s){
    std::string res="";//resulting string to return
    std::bitset<24> rbs;//bitset for 3
    int ri=0;
    for (int ii=0;ii<4;ii++){
        
        
        int myc = (int)s[ii];
        //convert from base64 char to num
        
        if (myc>=65&&myc<=90)
            myc-=65;
        else
            if (myc>=97&&myc<=122)
                myc-=71;
            else
                if (myc>=48&&myc<=57)
                    myc+=4;
                else
                    if (myc==43)
                        myc=62;
                    else
                        if (myc==47) myc=63;
        std::bitset<8> bs(myc);
        //take one num
        if ((int)s[ii]==(int)'=') {
            
            //std::cout<<"="<<myc<<bs.to;
        }
        
        for (int j=0; j<8; j++) {//cut 00
            if ((7-j)!=7&&(7-j)!=6) {//add all bits to rbs except first 2 bits in each char
                rbs[ri]=bs[7-j];
                ri++;
            }
        }
        if (s[3]=='=') {
            for (int zi=8;zi<24;zi++)rbs.set(zi,0);
        }
        if (s[3]=='='&&s[2]=='=') {
            for (int zi=16;zi<24;zi++)rbs.set(zi,0);
        }
    }
    //
    //std::cout<<"rrr"<<endl;
    //std::cout<<"rbs";
    //for (int ti=0;ti<24;ti++)std::cout<<rbs[ti];
    //std::cout<<"rrr"<<endl;
    int mui=7;
    std::bitset<8> tbs;
    
    for (int ii=0; ii<24; ii++) {
        
        
        tbs[mui]=rbs[ii];
        //std::cout<<" "<<mui<<" "<<ii<<endl;
        mui--;
        if (mui==-1){
            //std::cout<<endl;
            //for (int ti=0;ti<8;ti++)std::cout<<tbs[7-ti];//<<char(tbs.to_ulong());
            //std::cout<<" "<<(int)tbs.to_ulong()<<endl;
            if (!(tbs.none())) {
                res+= char(tbs.to_ulong());
            }
            
            mui=7;
            //std::cout<<res;
        }
        
        //convert here from to original
        //std::cout<<"ii="<<ii<<" "<<s[ii]<<endl;
        
        //int tbsi =tbs.to_ulong();
        //if (tbci)
        //std::cout<<tbs.to_ulong()<<" "<<char(tbs.to_ulong())<<endl;
        
    }
    
    return res;
}

void Processdecbase64(std::istream& in){
    std::string nextline;
    std::string result;
    int erro=0;
    while (!in.eof()) {
        getline(in, nextline);
        //std::cout<<nextline<<endl;
        std::string s;
        
        if (nextline.length()==64){
            
            for (int i=0; i<64; ++i) {
                
                int c =(int)nextline[i];
                if ((char)c=='\n') continue;
                if ((c>=65&&c<=90)||(c>=97&&c<=122)||(c>=48&&c<=57)||c==43||c==47||(char)c=='='){//if char is legal
                    s+=nextline[i];//take first 4 chars
                    if ((i+1)%4==0){//form 4 chars string
                        if (s[2]!='='&&s[3]!='=') {
                            result+=Get3for4(s);//send to make dec
                        }
                        else{
                            if (s[2]!='='&&s[3]=='='){
                                result+=Get3for4(s)[0]+Get3for4(s)[1];}
                            else{if(s[2]=='='&&s[3]=='=')
                                result+=Get3for4(s)[0];
                            }
                        }
                        s="";
                    }
                }
                else{
                    erro=1;
                    std::cerr<<"Error:Corrupted input"<<std::endl;
                    break;
                }
                
            }
            
        }
        else{
            if (nextline.length()%4==0) {//this is for last line
                for (int i=0; i<nextline.length(); ++i) {//not 64 chars
                    int c =(int)nextline[i];
                    if ((char)c=='\n') continue;
                    //std::cout<<"c="<<nextline.length();
                    if ((c>=65&&c<=90)||(c>=97&&c<=122)||(c>=48&&c<=57)||c==43||c==47||(char)c=='='){//if char is legal
                        s+=nextline[i];//take first 4 chars
                        if ((i+1)%4==0){//form 4 chars string
                            //							if (s[2]!='='&&s[3]!='=') {
                            result+=Get3for4(s);//send to make dec
                            //							}
                            //							else{
                            //								if (s[2]!='='&&s[3]=='='){
                            //									result+=Get3for4(s)[0]+Get3for4(s)[1];}
                            //								else{
                            //									if(s[2]=='='&&s[3]=='=')
                            //										result+=Get3for4(s)[0];
                            //									}
                            //							}
                            //send to make dec
                            s="";
                        }
                    }
                    else{
                        
                        erro=1;
                        std::cerr<<"Error:Corrupted input"<<std::endl;
                        break;
                    }
                    
                }
            }
            else{
                erro=1;
                std::cerr<<"Error:Corrupted input"<<std::endl;
                break;
            }
            //nextline
        }
        
        //for (int i=0; i<64; ++i) {
        //	std::cout<<nextline[i];
        //}
    }
    if (erro!=1) {
        std::cout<<result;
        if (result[result.length()-1]!='\n') {
            std::cout<<std::endl;
        }
        
    }
    else{
        exit(0);
    }
    
}