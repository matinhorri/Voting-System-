#include "include/Display.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Display::Display(string outputTerminal_){
    outputTerminal = outputTerminal_;
}

void Display::overWrite(string newOutput){
    outputTerminal.clear();
    outputTerminal = newOutput;
 }

string Display::print(){
    return outputTerminal;
}