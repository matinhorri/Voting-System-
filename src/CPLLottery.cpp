#include "ICPLLottery.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

CPLLottery::CPLLottery(std::vector<party>parties_){
    parties = parties_;
}

Party run(){
    int size = sizeof(parties);
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Generate a random number between 0 and size
    int randomNumber = std::rand() % size;
    result = parties[randomNumber];
    return result;
    };

Party run1000(){

    std::vector<std::string> myVector;
    string sample;
    int size = sizeof(parties);
    for(int i=0; i< 1000; i++){
         // Seed the random number generator
         std::srand(std::time(nullptr));
         // Generate a random number between 0 and size
         int randomNumber = std::rand() % size;
         sample = parties[randomNumber];
         myVector.push_back(sample);
    }
    
};