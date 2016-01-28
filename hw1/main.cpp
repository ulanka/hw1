#include <iostream>
#include "functions.h"
#include <fstream>
#include <string>
#include <cstdio> 
#include <sstream>
#include <bitset>
    using namespace std;
	void logme(const std::string val){
		std::cout<<val;
	}


static void Processencbase64(istream& in){
	//abcdefghijklmnopqrstuvwxyz
	//<<(char)c
	std::bitset<8> xx;
	int i=0;
	//int i0 = 0;//for 1-8
	//int i1 = 0;//for 9-16
	//int i2 = 0;//for 17-24
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
			}
			if (i==2) {//need 1 more byte
				n2=1;
				i=3;
			}
			//break;
		}

		
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
			if (ri1>=52 && ri1<61) ri1-=4;
			if (ri1==62) ri1=43;
			if (ri1==63) ri1=47;
			
			if (ri2>=0  && ri2<=25) ri2+=65;
			if (ri2>=26 && ri2<=51) ri2+=71;
			if (ri2>=52 && ri2<61) ri2-=4;
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
				break;
			}
			else{
				if (n2==1) {
					std::cout<<"==";//<<endl;
					break;
				}
				else{
					std::cout<<(char)ri3<<(char)ri4;
					//if (c==-1)std::cout<<endl;
				}
			}
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
		
	}
	
std::cout<<endl;
	
}


static void Processhexdump(istream& in){
	string every_line;//  16 symbols
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
			std::cout<< every_line<<endl;//line of ASCII and unreadable symbols
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
	
}



    static void Process(istream& in, int argc, char *argv[])
    {
		std::string argv1 = argv[1];
		
		if ((argv1.compare("hexdump")==0)){
			Processhexdump(in);
		}
		if ((argv1.compare("enc-base64")==0)){
			Processencbase64(in);
			
		}
		if ((argv1.compare("dec-base64")==0)){
			Processhexdump(in);
		}
		
	}



    int main(int argc, char *argv[])
    {
         bool reading_from_file=false;
	// Checking if the user choose mode
        if (argc == 1){
	    fprintf(stderr,  "Error: You have to enter hexdump, enc-base64, or dec-base64 as the first argument\n");
	    return 0;
	}
	//Checking if the user choose one of the allowed modes
	if (argc == 2){
		std::string argv1 = argv[1];
		if ((argv1.compare("hexdump")!=0)
		  &&(argv1.compare("enc-base64")!=0)
		  &&(argv1.compare("dec-base64")!=0)){
			fprintf(stderr, "Error: The value of the second argument should be hexdump, enc-base64, or dec-base64. Please try again\n");
			return 0;
		}
	}

	//Checking if there are 3rd argument then read from file
	if (argc > 2) {
            reading_from_file = true;
        }
        ifstream in;
         if (reading_from_file) {
                in.open(argv[2],ios::binary | ios::in);
            
        if (in.fail()) {
                cerr << "Cannot open " << argv[2] << " for reading." << endl;
                return 0;
            }
            Process(in, argc, argv);
            in.close();
        } else {
           Process(cin, argc, argv);
        }
        return 0;
    }

//1 http://stackoverflow.com/questions/7496657/when-printing-hex-values-using-x-why-is-ffffff-printed-after-each-value
//2 http://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
//3 http://en.cppreference.com/w/cpp/io/c/fprintf
//4 //http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
//5 http://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work
//6 http://stackoverflow.com/questions/2967015/set-a-c-bitset-from-a-binary-input-steam
