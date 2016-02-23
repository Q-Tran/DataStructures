#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "sortingcompetition.h"
#include <chrono>
#include <ctime>


void SortingCompetition::quick(std::vector<std::string>& arr, int left, int right) { //http://www.algolist.net/Algorithms/Sorting/Quicksort
      int i = left, j = right;
      int ilength;
      int jlength;
      std::string tmp;
      std::string pivot = arr[(left + right) / 2]; //takes middle number as pivot
      int plength = pivot.length();
      /* partition */
      while (i <= j){
            while ((arr[i].length() < plength) || ((arr[i].length() == plength) && arr[i].compare(pivot) < 0))
                i++;
            while ((arr[j].length() > plength) || ((arr[j].length() == plength) && arr[j].compare(pivot) > 0))
                j--;
            if (i <= j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
      	}
 
      /* recursion */
      if (left < j)
            quick(arr, left, j);
      if (i < right)
            quick(arr, i, right);
}
SortingCompetition::SortingCompetition(){}
SortingCompetition::SortingCompetition(const std::string& inputFileName){
	fileName = inputFileName;
}
void SortingCompetition::setFileName(const std::string& inputFileName){
	fileName = inputFileName;
}
 
	//read the data from the file and store it in
	//a linear data structure.
	//No sorting actions can be done in this method.
		//This includes no duplicate removal or anything else
	//that could make your sorting more efficient later.
	//Literally, the 5th word in the file should be 
	//in the 5th place in your structure. 
bool SortingCompetition::readData(){
	std::ifstream input (fileName);
	std::stringstream ss;
	std::string line;
	std::string word;
	std::cout << "Reading file" << std::endl;
	while(getline(input, line)){ //get line from file
		ss << line;
		while(getline(ss, word, ' ')){ //get word from line
			words.push_back(word); //add words to vector
		}
		ss.clear();
	}
	words.shrink_to_fit();
	std::cout << " Finished reading file" << std::endl;
}

 
	//copy the data from the original data structure
	//into a second location that will be used for sorting.
	//This will allow you to sort the same data set (with
	//the same starting order of elements) multiple times.
	//You can then calculate the average of execution times for 
	//one data set against one algorithm. 
	//No sorting actions can be done in this method.
bool SortingCompetition::prepareData(){ //make a copy of the vector
	std::cout << "Making copy of vector" << std::endl;
	vcopy = words;
	std::cout << "Finished making copy of vector" << std::endl;
}
 
	//sort the data based on the criteria set forth in the
	//hand out.
	//THIS IS THE FUNCTION THAT WILL BE TIMED.
void SortingCompetition::sortData(){
	quick(vcopy, 0, vcopy.size()-1);
}
 
	//using outputFileName, write the "sorted" data structure
	//to the file as a newline-delimited list. This will be used to test the //validity of your sorting algorithm (in other words, did it sort 
	//properly?).
void SortingCompetition::outputData(const std::string& outputFileName){
	std::cout << "Output sorted results to file" << std::endl;
	std::ofstream output (outputFileName);
	int size = vcopy.size();
	for(int i = 0; i < size; i++){
		output << vcopy[i] << std::endl;
	}
	std::cout << "Finished outputing results to file" << std::endl;
}