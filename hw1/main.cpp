#include <iostream>
#include "dd.h"
#include <fstream>
#include <string>
#include <cstdio> 
#include <sstream>
#include <bitset>
   // using namespace std;
//using namespace __hw1__dd__;
	void logme(const std::string val){
		std::cout<<val;
	}


static void Process(std::istream& in, int argc, char *argv[])
{
	std::string argv1 = argv[1];
	
	if ((argv1.compare("hexdump")==0)){
		Processhexdump(in);
	}
	if ((argv1.compare("enc-base64")==0)){
		Processencbase64(in);
		
	}
	if ((argv1.compare("dec-base64")==0)){
		Processdecbase64(in);
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
	if (argc == 3) {
		std::string argv1 = argv[1];
		if ((argv1.compare("hexdump")!=0)
			&&(argv1.compare("enc-base64")!=0)
			&&(argv1.compare("dec-base64")!=0)){
			fprintf(stderr, "Error: The value of the second argument should be hexdump, enc-base64, or dec-base64. Please try again\n");
			return 0;
		}
            reading_from_file = true;
        }
		if (argc>3){
			std::cerr << "Error: To many arguments" << std::endl;
			return 0;
		}
        std::ifstream in;
         if (reading_from_file) {
                in.open(argv[2],std::ios::binary | std::ios::in);
            
        if (in.fail()) {
                std::cerr << "Cannot open " << argv[2] << " for reading." << std::endl;
                return 0;
            }
            Process(in, argc, argv);
            in.close();
        } else {
			Process(std::cin, argc, argv);
        }
        return 0;
		
    }

//1 http://stackoverflow.com/questions/7496657/when-printing-hex-values-using-x-why-is-ffffff-printed-after-each-value
//2 http://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
//3 http://en.cppreference.com/w/cpp/io/c/fprintf
//4 //http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
//5 http://stackoverflow.com/questions/4533063/how-does-ifstreams-eof-work
//6 http://stackoverflow.com/questions/2967015/set-a-c-bitset-from-a-binary-input-steam
