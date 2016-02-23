#include "stack.h";
#include "linkedlist.h"
#include <fstream>
#include <string>
int main(int argc, char*argv[]){
	bool exists = 0;
	stringstream ss;
	bool notfinished = 1;
	string line;
	ifstream flightpaths (argv[1]);
	ifstream pathstocalculate (arg[2]);
	//read from both files
	getline(flightpaths, line);
	int count = line;
	string from[count];
	string to[count]; 
	int distance[count];
	string temp;
	int counter = 0;
	while(getline(flightpaths, line)){
		ss<<line;
		getline(ss, from[counter], '|');
		getline(ss, to[counter], '|');
		getline(ss, temp, '|');
		distance[counter] = stoi(temp);

		/*
		for(int i = 0; i < counter; i++){
			if(from.compare(cities[i]) == 0){
				exists = 1;
			}
		}
		if(!exists){
			cities[counter] = Nodes(from); //create the object from
		}
		exists = 0; //reset exists
		for(int i = 0; i < counter; i++){
			if(from.compare(cities[i]) == 0){
				exists = 1;
			}
		}
		if(!exists){
			cities[counter] = Nodes(to); //create the object to
		}
		//make from point to to
		//set distance
		counter++;
		*/
		ss.clear;
		counter++;
	}
	linkedlist* paths;
	linkedlist end;
	stack path;
	while(notfinished){
		if(paths.isexhausted()){
			path.pop();
		}
		else{
			//check the paths
			path.push(paths.gotonext());
		}
		if(path.peek() == end){
			notfinished = 0;
		}
	}
	cout << "route in reverse order: ";
	for(int i = 0; i < cstack; i++){
		cout << path.pop().getName() << endl;
	}
}