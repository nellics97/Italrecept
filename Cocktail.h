#ifndef COCKTAIL_H_INCLUDED
#define COCKTAIL_H_INCLUDED
#include "Ingredient.h"
#include <iostream>
#include <vector>

class Cocktail
{
    std::string name;
    size_t ingnum;
    std::vector<Ingredient*> ing;
    double *amount;
public:
    Cocktail(std::string n) :name(n), ingnum(0), amount(NULL) {}
    size_t getIngnum()
    {
        return ingnum;
    }
    std::string getName()
    {
        return name;
    }
    double getVolume();

    void list(std::ostream &os);

    void add(Ingredient* in, double am);
    void delet();

    double alc_percent();
    double price();

    Ingredient* operator[] (size_t x);
    const Ingredient* operator[] (size_t x) const;
    ~Cocktail();
};
#endif // COCKTAIL_H_INCLUDED
