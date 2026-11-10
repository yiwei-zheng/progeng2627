#include <iostream>
#include <fstream>
// header fstream needed for working with text files

int main(){
    std::ifstream infile; 
    // we declare the object that will represent the text file
    // of type std::ifstream (infile is not a special name)

    infile.open("input.txt");
    // we associate the object called infile
    // to the text file called input.txt

    // now before we go any further it's important to check
    // whether the operation opening the file really worked
    // (if for example we misspell the name then the program
    // doesn't work and we don't know why

    // please note that difference between function open (above)
    // and function is_open (below)

    if(infile.is_open()){ 
        // if the operation was successful
        // we can read the content of the file
        // this is done in a remarkably 
        // similar way to using std::cin

        int tmp;

        infile >> tmp;
        std::cout << tmp << std::endl; 
        // this will read and then print 
        // the first number in the file
        // (which in the example above is 10)

        infile >> tmp;
        std::cout << tmp << std::endl;
        // this will read and then print 
        // the second number in the file
        // (which in the example above is 4)

        infile.close(); 
        // we close the file when we are done

    }
    else{
        std::cout << "error opening file" << std::endl;
    }

}