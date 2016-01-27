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


    static void Process(istream& in, int argc, char *argv[])
    {
		
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
