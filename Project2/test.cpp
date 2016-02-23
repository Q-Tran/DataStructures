#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main(int argc, char** argv){
	ifstream input (argv[1]);
	cout << argv[1] << endl;
	int wordSize;
	int pagenumber;
	stringstream iss;
	stringstream iss2;
	char* page = new char [50000];
	char* line = new char [1024];
	char* word = new char [40];
	input.getline(page, 50000, '<'); //(need to throw away first entry to get consistent results)
	while(input.getline(page, 50000, '<')){ // reads pages from file
     		iss<<page;
     		iss.getline(line, 1024, '>'); //first line of file is going to be 'pagenumber>' so get rid of the >
     		pagenumber = atoi(line); //check if works
   		    while(iss.getline(line, 1024)){ //reads lines from pages
   	   		 	iss2<<line;
       		    while(iss2.getline(word, 40, ' ')){ //reads words from lines
       		    	cout << word << endl;
       		    	int wordSize = strlen(word);
       		    }
       		    iss2.clear();
       		}
   	   iss.clear();
	}
}