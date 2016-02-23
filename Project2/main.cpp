#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
int asize = 10; //global variables swagggG
int iter = 0;
void printtofile(char**& words, int**& pages, char* file){//prints while ignoring duplicates
	ofstream output (file);
	output << "[" << **words << "]" << endl << *(words + iter -1) << ": " << **(pages + iter - 1);
	for(int i = iter -2; i >= 0; i--){
		if(**(words + i + 1) != **(words + i))
			output << endl << "[" << **(words + i) << "]";
		if(strcmp(*(words + i), *(words + i +1)) == 0) { //checks if adjacent cstrings are equal
			if(**(pages + i) != **(pages + i + 1)){ //check if page number is equal, if not print
				output << " " << **(pages + i);
			}
		}
		else{
			output << endl << *(words + i) << ": " << **(pages + i);
		}
	}
}
void parallelSort(char**& words, int**& pages){//sorts the words in alpha order keeping the pages in parallelSortel indexes.
	int j;
	char* tmp;
	int* tmpi;
	for(int i = 1; i < iter; i++){ //iterates for all elements
		j=i;
		while (j > 0 && strcmp(*(words + j), *(words + j - 1)) > 0){
			tmp = *(words+j);
			*(words+j) = *(words+j - 1);
			*(words+j-1) = tmp;
			tmpi = *(pages+j);
			*(pages+j) = *(pages+j -1);
			*(pages+j-1) = tmpi;
			j--;
			for(int a = 0; a < iter; a++){
				cout << *(words+a) << " ";
			}
			cout << endl;
		}
	}
	cout << "end sorting" << endl;
}
void add(char**& words, char* word, int wordSize, int**& pages, int page){//adds the word to array words and adds the integer to pages and resizes if needed pointers are passed by reference so they can be changed.
	cout<< "number of words is at: " << iter << endl;

	if(iter > asize - 1){ //if the iter is larger than the arraysize, then resize the words and pages array
		cout << "resizing" << endl;
		char** temp = new char* [asize + 10]; //new array of asize + 10 pointers to characters
		int** tempi = new int* [asize + 10];
		for(int i = 0; i < asize; i++){ //copies the pointers of words into temp and pointers of pages into tempi
			*(temp+i) = *(words+i);
			cout << *(temp + i) << endl << *(words + i) << endl << i << endl;
			*(tempi + i) = *(pages + i);
		}
		cout << "deleting" << endl;
		delete [] words; //deletes array of pointers
		delete [] pages;
		cout << "delete complete" << endl;
		cout << "reassigning array" << endl;
		words = temp; //make point to newly allocated and larger array
		pages = tempi;
		cout << "reassigning complete" << endl;
		asize = asize + 10; //let the outside know arraysize is larger
		cout << "size of array is now " << asize << endl;
	}

	cout << "adding word: " << word << endl << "adding page: " << page << endl;
	*(words + iter) = new char [wordSize];
	*(pages + iter) = new int;
	**(words + iter) = wordSize;
	for(int i = 0; i < wordSize; i++){
		if(word[i] >= 65 && word[i] <=90){//if upper move to lower
			word[i] = word[i] + 32; 
		}
		*(*(words + iter) + i) = word[i];
	}
	**(pages + iter) = page;
	cout << "word added: " << *(words + iter) << endl << "page added: " << **(pages + iter) << endl;
	iter++;
}

char** read(char* fileName, char**& words, int**& pages){ //takes the input file and outputs the results to the words and pagenumber arrays.
	ifstream input (fileName);
	stringstream iss;
	stringstream iss2;
	char* phrase;
	char* temp = new char[40];
	int pagenumber;
	int wordSize;
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
       		    while(iss2.getline(word, 40, ' ')){ //reads words from lines note that the space is taken out
       		    	cout << word << endl;
       		    	if(*word == '['){ //adds the whole phrase in brackets as a word
       		    		strcpy(temp, word);
       		    		temp = (temp + 1); //take out [
       		    		*(temp + strlen(temp)) = ' '; //add space after word
       		    		*(temp + strlen(temp)) = '\0'; //null terminated
       		    		cout << temp << endl;
       		    		iss2.getline(word,40, ']'); //read rest of phrase until ]
						cout << "the getline " << word << endl;
						strcat(temp, word);
						cout << temp << endl;
						strcpy(word, temp);
						iss2.getline(temp,40, ' '); //leaves behind a space. Need to go over another space to continue normally
       		    	}
       		    	wordSize = strlen(word);
       		    	add(words,word,wordSize, pages, pagenumber);
       		    }
       		    iss2.clear();
       		}
   	   iss.clear();
	}
	/*delete[] temp;
	delete[] page;
	delete[] line;
	delete[] word;*/ //deletes are giving strange errors
   	cout << "finished reading" << endl;
}

int main(int argc, char** argv){ // takes in 2 commandline arguements. First is the input file. Second is the output file

	char** words = new char*[10]; //pointer to ARRAY of pointers to ARRAYS of characters
	int** pages = new int* [10]; //pointer to ARRAY of pointers to integers 

	read(argv[1],words,pages);
	cout << "attempting to print the words and pages" << endl;
	cout << *words << endl;
	for(int i = 0; i < iter; i++){
		cout << *(words + i)  << endl << **(pages + i) << endl;
	}
	parallelSort(words,pages);
	printtofile(words, pages, argv[2]);
}
