#include "memtrace.h"
#include "Ingredient.h"

void Ingredient::show(std::ostream &os)
{
    os << unit << ' ' << name << " ( " << price << "Ft/" << unit << " )" << std::endl;
}


void Alcohol::show(std::ostream &os)
{
    os << unit << ' ' << name << " ( Alcohol percentage: " << alc_content << "%, " << price <<"Ft/cl )" << std::endl;
}


void NonAlcohol::show(std::ostream &os)
{
    if(carbonated)
        os << unit << ' ' << name << " ( Carbonated, " << price <<"Ft/cl)" << std::endl;
    else
        os << unit << ' ' << name << " ( Non-carbonated, " << price <<"Ft/cl)" << std::endl;

}
