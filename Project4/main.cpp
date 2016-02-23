#include "sortingcompetition.h"
#include <chrono>
#include <ctime>

int main(int argc, char *argv[]){ //first arguement is the input file, second is the output file
	char* input = argv[1];
	char* output = argv[2];
	std::chrono::time_point<std::chrono::system_clock> start, end;
	SortingCompetition c;
	c.setFileName(input);
	c.readData();
	c.prepareData();
	start = std::chrono::system_clock::now();
	c.sortData();
	end = std::chrono::system_clock::now();
	c.outputData(output);
}