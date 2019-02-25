#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

class Ingredient
{
protected:
    std::string name;
    std::string unit;
    double price;
public:
    Ingredient(std::string name, std::string unit, double price)
        :name(name), unit(unit), price(price) {}
    std::string getName()
    {
        return name;
    }
    std::string getUnit()
    {
        return unit;
    }
    double getPrice()
    {
        return price;
    }
    virtual double getAlc()
    {
        return 0;
    }
    virtual bool isCarbonated()
    {
        return 0;
    }
    virtual void show(std::ostream &os);
    virtual ~Ingredient ()
    {
        std::cout<< name << " removed\n";
    }

};

class Alcohol: public Ingredient
{
    double alc_content;
public:
    Alcohol(std::string name, std::string unit, double price, double alc_content)
        :Ingredient(name, unit, price), alc_content(alc_content) {}
    double getAlc()
    {
        return alc_content;
    }
    void show(std::ostream &os);
    ~Alcohol() {}
};

class NonAlcohol: public Ingredient
{
    bool carbonated;
public:
    NonAlcohol(std::string name, std::string unit, double price, bool carbonated)
        :Ingredient(name, unit, price), carbonated(carbonated) {}
    bool isCarbonated()
    {
        return carbonated;
    }
    void show(std::ostream &os);
    ~NonAlcohol() {}
};


#endif // INGREDIENT_H_INCLUDED
