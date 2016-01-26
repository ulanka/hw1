#include <iostream>
#include "functions.h"
#include <fstream>
#include <string>
#include <cstdio> 
#include <sstream>
    using namespace std;

	void logme(const std::string val){
		std::cout<<val;
	}
	
//	void logmec(char *val){
//		std::cout<<val;
//	} 
    static
    void Process(istream& in, int argc, char *argv[])
    {
	if (argc==2){
	//logme("I am here argc equal to 2");	
	//	logme("argv[1]:");
	//	logme(argv[1]);
	}        

	string buf;
        getline(in, buf);
	for (int i=0; i<100;i++){
		std::printf("%.6x\n",i*16);
	}
//std::printf()
	int line_counter = 0;        
	while (!in.eof()) {
		
		for (int i =0; i<buf.length(); i++){
		//char ch = 0x10;	
 		 char ch = buf[i];
//-----
//http://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
	if ((0x20<=ch)&&(ch<=0x7e)){
		std::cout<<hex<<(int)ch;//previous link only this line

		
std::printf("%#x\n",ch);//http://en.cppreference.com/w/cpp/io/c/fprintf 

	}
	else
	{
	if ((ch<=0x1f)||(ch==0x7f)){
		std::cout<<".";
	}
	else{
		std::cout<<"~";
	}
	}	
	//std::cout<<hex<< (int)ch;
//----	
			
			if(line_counter<16)
			{	std::cout<<" ";
				i++;
			
			} else{ 
				std::cout<<endl;
//				adsfjklasjflasjlf;jl;asjlfdjlasjlfdjlsajdfljsljfaljfoiwuroquprijfksn,vncxnz.,nv,zxnv,shlfsjfkjhsfk
				i=0;
			}

		//	std::cout<<&ch<<endl;
		} 
        getline(in, buf);
        }
	

    }
 


    int main(int argc, char *argv[])
    {
    //print_hello();
    //std::cout << std::endl;
    //std::cout << "The factorial of 5 is " << factorial(5) << std::endl;
        bool reading_from_file=false;
//	std::cout << argc<<endl;
//	std::cout << argv[0]<<endl;
//	std::cout << argv[1]<<endl;

	//for (int i=0; i<10;i++){
	//	std::cout << "here:"<< argv[i]<<endl;
	//}
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
            in.open(argv[2]);
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
