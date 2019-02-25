#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Cocktail.h"

void comments();
void freeMemory(std::vector<Cocktail*> v);
void readFromFile();
void writeToFile(std::string name, std::vector<Cocktail*> v);


#endif // EXTRAS_H_INCLUDED
