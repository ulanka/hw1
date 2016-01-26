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

std::istream& safeGetline(std::istream& is, std::string& t)
{//this function with it
    //http://stackoverflow.com/questions/6089231/getting-std-ifstream-to-handle-lf-cr-and-crlf
    t.clear();
    
    // The characters in the stream are read one-by-one using a std::streambuf.
    // That is faster than reading them one-by-one using the std::istream.
    // Code that uses streambuf this way must be guarded by a sentry object.
    // The sentry object performs various tasks,
    // such as thread synchronization and updating the stream state.
    
    std::istream::sentry se(is, true);
    std::streambuf* sb = is.rdbuf();
    
    for(;;) {
        int c = sb->sbumpc();
        switch (c) {
            case '\n':
                return is;
            case '\r':
                if(sb->sgetc() == '\n')
                    sb->sbumpc();
                return is;
            case EOF:
                // Also handle the case when the last line has no line ending
                if(t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char)c;
        }
    }
}
    static void Process(istream& in, int argc, char *argv[])
    {
//        if (argc==2){
//      logme("I am here argc equal to 2");
//		logme("argv[1]:");
//		logme(argv[1]);
//	}
        string buf;
        //safeGetline(in, buf);

//        int line_counter = 0;
        
        std::printf("%.6x: ",0); //prints 000000
        string every_line;//  16 symbols
        while (!safeGetline(in, buf).eof()) {
            
            
//            std::cout<<buf.length()<<endl;
            
            for (int i = 0; i<buf.length(); ++i){                //std::cout<<"i="<<i<<" buf[i]="<<buf[i]<<endl;
                unsigned char ch = buf[i];
//                std::cout<<hex<<(int)ch;
                printf("%02x",  (int)(*(unsigned char*)(&ch)) );//http://stackoverflow.com/questions/7496657/when-printing-hex-values-using-x-why-is-ffffff-printed-after-each-value
                if ((ch>=0x20)&&(ch<=0x7e)){
                    every_line+=buf[i];
                    //http://stackoverflow.com/questions/3381614/c-convert-string-to-hexadecimal-and-vice-versa
                   // std::printf("%#x\n",ch);//http://en.cppreference.com/w/cpp/io/c/fprintf

                }
                else
                {
                    if ((ch<=0x1f)||(ch==0x7f)){
                        every_line+=".";
                    }
                    else{
                        if (ch>=0x80) {
                            every_line+="~";
                        }
                        
                    }
                }
			
                if(every_line.length()<16)
                {
                    std::cout<<" ";
                    if (every_line.length()==8) {
                        std::cout<<" ";
                    }
                    //i++;
                }
                else
                {
                    std::cout<<"  "<< every_line<<"\n";
                    every_line="";
                    std::printf("%.6x: ",i+1);
			}

		} 
       // getline(in, buf);
            if (every_line.length()<>0){
                for (ii=every_line.length();ii<16;++ii){
                    every_line+= ""
                }
            }
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
