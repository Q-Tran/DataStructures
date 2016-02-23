#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
bool existsIn(int* array, int element, int end); //returns true if element exists in array
int points(int placeTagged); //returns points given the location hit
int main(int argc, char *argv[]){//takes 3 input file names, verbosity indicator, and output file
    //create filestreams
    string line;
    stringstream str;
    string subString;
    string teamAName;
    string teamBName;
    int highestScoreA = 0;
    int highestScoreB = 0;
    int highestScorerA = 0;
    int highestScorerB = 0;
    string teamAFile = argv[1];
    string teamBFile = argv[2];
    string matchFile = argv[3];
    string outputFile = argv[4];
    ifstream aFile (teamAFile);
    ifstream bFile (teamBFile);
    ofstream oFile (outputFile);
    getline(aFile, teamAName);
    getline(bFile, teamBName);
    //find the amount of students in the files to declare arrays
    getline(aFile, line);
    int numAStu = atoi(line.c_str());
    getline(bFile, line);
    int numBStu = atoi(line.c_str());
    //2 arrays of students
    string* aStudents = new string[numAStu];
    int* idAStudents = new int[numAStu];
    int counter = 0;
    //loop gets lines and then breaks lines into substrings to put data into respective arrays
    while(getline(aFile,line)){
        str<<line;
        while(getline(str, subString, ' ')){
            if(counter%2 == 0)
                idAStudents[counter/2] = atol(subString.c_str());
            else
                aStudents[counter/2] = subString;
            counter++;
        }
        str.clear();
    }



    string* bStudents = new string[numBStu];
    int* idBStudents = new int[numBStu];
    counter = 0;
    while(getline(bFile,line)){
        str<<line;
        while(getline(str, subString, ' ')){
            if(counter%2 == 0)
                idBStudents[counter/2] = atol(subString.c_str());
            else
                bStudents[counter/2] = subString;
            counter++;
        }
        str.clear();
    }
    //match information
    ifstream mFile;
    mFile.open(matchFile);
    getline(mFile, line);
    int numTags = atoi(line.c_str());
    int* idTagger = new int [numTags];
    int* idTagged = new int[numTags];
    int* locationTagged = new int[numTags];
    counter = 0;
    while(getline(mFile,line)){
        str<<line;
        while(getline(str, subString, ' ')){
            if(counter%4 == 0){
                idTagger[counter/4] = atoi(subString.c_str());
            }
            else if(counter %4 == 1){
                idTagged[counter/4] = atoi(subString.c_str());
            }
            else if(counter %4 == 3){
                locationTagged[counter/4] = atoi(subString.c_str());
            }
            counter++;
        }
        str.clear();
    }

    //find total amount of points
    int test = 0;
    int pointsA = 0;
    int pointsB = 0;

    for(int i = 0; i < numTags; i++){
        if(existsIn(idAStudents, idTagger[i], numAStu)){

            pointsA += points(locationTagged[i]);

        }
        else{
            pointsB += points(locationTagged[i]);
        }
    }

    //find winner
    string winner;
    if(pointsA > pointsB){
        winner = teamAName;
    }
    else if(pointsA == pointsB){
        winner = "tie";
    }
    else{
        winner = teamBName;
    }
    //print verbosities
    if(strcmp(argv[5], "vlow") == 0){
            oFile<< teamAName << ": " << pointsA << endl << teamBName << ": " << pointsB<< endl << "Overall Winners: " << winner << endl;
    }
    else if(strcmp(argv[5], "vhigh") == 0){
        oFile << teamAName << endl;
        for (int i = 0; i < numAStu; i++){
            for(int a = 0; a < numBStu; a++){
                counter = 0;
                for(int b = 0; b< numTags; b++){
                    if(idAStudents[i] == idTagger[b] && idBStudents[a] == idTagged[b])
                        counter++;
                }
                oFile << "   " << aStudents[i] + " tagged " + bStudents[a] << " " << counter << " times" << endl; //need to define times and change times to time if 1
            }
        }
        oFile<< teamAName << ": " << pointsA << endl;
        oFile << teamBName << endl;
        for (int i = 0; i < numBStu; i++){
            for(int a = 0; a < numAStu; a++){
                counter = 0;
                for(int b = 0; b< numTags; b++){
                    if(idBStudents[i] == idTagger[b] && idAStudents[a] == idTagged[b])
                        counter++;
                }
                oFile << "   " << bStudents[i] + " tagged " + aStudents[a] << " " << counter << " times" << endl; //need to define times and change times to time if 1
            }
        }
        oFile<< teamBName << ": " << pointsB<< endl << "Winners: "<< winner << endl;
    }
    else if(strcmp(argv[5],"vmed") == 0){
        oFile<< teamAName << endl;
        for(int i = 0; i < numAStu; i++){
            counter = 0;
            test = 0;
            for(int a = 0; a < numTags; a++){
                if(idTagger[a] == idAStudents[i]){
                    counter++;
                    test += points(locationTagged[a]);
                }
            }
            if(test > highestScoreA){
                highestScoreA = test;
                highestScorerA = i;
            }
            oFile << "   " << aStudents[i] << " had a total of "<< counter << " tags" <<endl;
        }
        oFile<< teamBName << endl;
        for(int i = 0; i < numBStu; i++){
            counter = 0;
            test = 0;
            for(int a = 0; a < numTags; a++){
                if(idTagger[a] == idBStudents[i]){
                    counter++;
                    test += points(locationTagged[a]);
                }
            }
            if(test > highestScoreB){
                highestScoreB = test;
                highestScorerB = i;
            }
            oFile << "   " << bStudents[i] << " had a total of "<< counter << " tags" <<endl;
        }
        oFile << "Best score from " << teamAName << ": " << aStudents[highestScorerA] << " (" << highestScoreA << " points)" << endl;
        oFile << "Best score from " << teamBName << ": " << bStudents[highestScorerB] << " (" << highestScoreB << " points)" << endl;

        oFile<< teamAName << ": " << pointsA << endl << teamBName << ": " << pointsB<< endl << "Overall Winners: " << winner << endl;

    }
    delete[] aStudents;
    delete[] idAStudents;
    delete[] bStudents;
    delete[] idBStudents;

}
//no deletes needed because memory is cleaned up by program termination

bool existsIn(int* array, int element, int end){
    for(int i = 0; i < end; i++){
        if(array[i] == element)
            return true;
    }
    return false;
}

int points(int placeTagged){
    if(placeTagged == 1){
        return 5;
    }
    else if(placeTagged == 2){
        return 8;
    }
    else if(placeTagged == 3){
        return 10;
    }
    else{
        return 15;
    }
}
