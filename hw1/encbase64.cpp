//
//  encbase64.cpp
//  hw1
//
//  Created by Ulan Korabay on 1/29/16.
//  Copyright (c) 2016 Ulan Korabay. All rights reserved.
//

#include <stdio.h>
#include "dd.h"
 void Processencbase64(std::istream& in){
    //abcdefghijklmnopqrstuvwxyz
    //<<(char)c
    (void)in;
    std::bitset<8> xx;
    int i=0;
    int fin=0;
    int n1=0, n2=0;//need 1 or 2
    std::bitset<8> x;//(c>>(8-8))
    std::bitset<8> x1;//(c>>(8-8))
    std::bitset<8> x2;//(c>>(8-8))
    std::bitset<8> r1;
    std::bitset<8> r2;
    std::bitset<8> r3;
    std::bitset<8> r4;
    int ri1, ri2,ri3,ri4;
    //in.ignore('\n');
    //std::string
    int chline=0;
    while (!in.eof()) {
        int c = in.get();
        
        //while (c!=-1) {
        //if (c==10) {
        //	c='\n';
        //}
        //r1[1]=0;
        //
        //std::cout<<c;
        //next byte
        if (c==-1) {// if not enough bit to 24
            if (i==1) {//need 2 more bytes(16bits)
                n2=1;//add 2
                i=3;
                //n1=0;
            }
            if (i==2) {//need 1 more byte
                n1=1;
                i=3;
                
            }
            //break;
        }
        //cwoJ aWYgKGFyZ2 MgPT0gMil7 CgkJc3RkOj pzdHJpbmcg YXJndjEgPS Bhcmd2WzFd
        
        switch (i){
            case 0:{
                //i0=c;
                std::bitset<8> xf(c);
                x=xf;
                //std::cout<<"i0:"<<i0;
                i++;
                break;
            }
            case 1:{
                //i1=c;
                std::bitset<8> xf(c);
                x1=xf;
                //std::cout<<"i1:"<<i1;
                i++;
                break;
            }
            case 2:{
                //i2=c;
                std::bitset<8> xf(c);
                x2=xf;
                //std::cout<<"i2:"<<i2;
                i++;
                break;
                
            }
                
        }
        if (i==3){
            if (n2==1) {
                for (int ni=0; ni<8; ni++) {
                    x1.set(ni, 0);x2.set(ni,0);
                }
                
            }
            if (n1==1){
                for (int ni=0; ni<8; ni++)
                    x2[ni]=0;
            }
            r1.set(7,0);
            r1.set(6,0);
            r2.set(7,0);
            r2.set(6,0);
            r3.set(7,0);
            r3.set(6,0);
            r4.set(7,0);
            r4.set(6,0);
            //std::cout<<"x:"<<x<<endl;
            //for (int mi=3;mi<9;mi++) r1.set(8-mi,x.test(8-mi+2));
            r1.set(5,x.test(7));
            r1.set(4,x.test(6));
            r1.set(3,x.test(5));
            r1.set(2,x.test(4));
            r1.set(1,x.test(3));
            r1.set(0,x.test(2));
            
            r2.set(5,x.test(1));
            r2.set(4,x.test(0));
            r2.set(3,x1.test(7));
            r2.set(2,x1.test(6));
            r2.set(1,x1.test(5));
            r2.set(0,x1.test(4));
            
            r3.set(5,x1.test(3));
            r3.set(4,x1.test(2));
            r3.set(3,x1.test(1));
            r3.set(2,x1.test(0));
            r3.set(1,x2.test(7));
            r3.set(0,x2.test(6));
            
            r4.set(5,x2.test(5));
            r4.set(4,x2.test(4));
            r4.set(3,x2.test(3));
            r4.set(2,x2.test(2));
            r4.set(1,x2.test(1));
            r4.set(0,x2.test(0));
            ri1=(int)r1.to_ulong();
            ri2=(int)r2.to_ulong();
            ri3=(int)r3.to_ulong();
            ri4=(int)r4.to_ulong();
            if (ri1>=0  && ri1<=25) ri1+=65;
            if (ri1>=26 && ri1<=51) ri1+=71;
            if (ri1>=52 && ri1<=61) ri1-=4;
            if (ri1==62) ri1=43;
            if (ri1==63) ri1=47;
            
            if (ri2>=0  && ri2<=25) ri2+=65;
            if (ri2>=26 && ri2<=51) ri2+=71;
            if (ri2>=52 && ri2<=61) ri2-=4;
            if (ri2==62) ri2=43;
            if (ri2==63) ri2=47;
            
            if (ri3>=0  && ri3<=25) ri3+=65;
            if (ri3>=26 && ri3<=51) ri3+=71;
            if (ri3>=52 && ri3<=61) ri3-=4;
            if (ri3==62) ri3=43;
            if (ri3==63) ri3=47;
            
            if (ri4>=0  && ri4<=25) ri4+=65;
            if (ri4>=26 && ri4<=51) ri4+=71;
            if (ri4>=52 && ri4<=61) ri4-=4;
            if (ri4==62) ri4=43;
            if (ri4==63) ri4=47;
            //std::cout<<"xs:"<<char(x.to_ullong())<<char(x1.to_ullong())<<char(x2.to_ullong())<<endl;
            
            std::cout<<(char)ri1<<(char)ri2;
            if (n1==1) {
                std::cout<<(char)ri3<<"=";//<<endl;
                //n1=0;
                fin=1;
                break;
            }
            else{
                if (n2==1) {
                    std::cout<<"==";//<<endl;
                    fin=1;
                    break;
                }
                else{
                    std::cout<<(char)ri3<<(char)ri4;
                    //if (c==-1)std::cout<<endl;
                    fin=1;
                }
            }
            chline+=4;
            x=xx;x1=xx;x2=xx;r1=xx;r2=xx;r3=xx;r4=xx;n1=0;n2=0;i=0;
        }
        
        /*
         for (int iii=0;iii<128;iii++)
         {
         bitset<8> mmx(iii>>(8-8));
         if (mmx.test(7)==0&&mmx.test(6))
         std::cout<<iii<<char(mmx.to_ullong())<<endl;
         }
         */
        if (chline==64) {
            std::cout<<std::endl;
            chline=0;
        }
    }
    if(fin==1)
        std::cout<<std::endl;
    
}









