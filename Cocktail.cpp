#include "Cocktail.h"
#include "Ingredient.h"
#include "memtrace.h"
#include <stdexcept>
#include <vector>

double Cocktail::getVolume()
{
    double total;
    for(size_t i=0; i<ingnum; i++)
    {
        if(ing[i]->getUnit()=="ml")
            total+=amount[i]*0.1;

        else if(ing[i]->getUnit()=="cl")
            total+=amount[i];

        else if(ing[i]->getUnit()=="dl")
            total+=amount[i]*10;
    }
    return total;
}


void Cocktail::list(std::ostream& os)
{
    bool carb=0;
    os<< "\n************************************\n";
    os << "Name of cocktail: " << name << std::endl << std::endl;
    os << "Ingredients:\n\n";
    for(size_t i=0; i<ingnum; i++)
    {
        os <<" - " << amount[i];
        os << " ";
        ing[i]->show(os);
        if(ing[i]->isCarbonated())
            carb=1;

    }

    if(carb)
        os <<"\n The cocktail is carbonated";

    os << "\n\nTotal volume: " << getVolume() << " cl\n";
    os << "Total alcohol percentage: " << alc_percent() << '%' << std::endl;
    os << "Price: " << price() << " Ft" << std::endl;
    os<< "\n************************************\n\n";
}


void Cocktail::add(Ingredient* in, double am)
{
    if (ingnum == 0)
    {
        amount=new double[1];
        amount[0]=am;
    }
    else
    {
        double *tmp = new double[ingnum+1];
        for (size_t i = 0; i < ingnum; i++) tmp[i] = amount[i];
        tmp[ingnum]=am;
        delete[] amount;
        amount = tmp;
    }

    ing.push_back(in);
    ingnum++;
}


void Cocktail::delet()
{
    this->~Cocktail();
}


double Cocktail::alc_percent ()
{
    double total =0, alc =0;
    for(size_t i=0; i <ingnum; i++)
    {
        if(ing[i]->getUnit()=="ml")
        {
            total+=amount[i]*0.1;
            alc+=ing[i]->getAlc()*amount[i]*0.1;
        }

        else if(ing[i]->getUnit()=="cl")
        {
            total+=amount[i];
            alc+=ing[i]->getAlc()*amount[i];
        }

        else if(ing[i]->getUnit()=="dl")
        {
            total+=amount[i]*10;
            alc+=(ing[i]->getAlc()*amount[i]*10);
        }

    }
    return alc/total;
}


double Cocktail::price()
{
    double total=0;
    for(size_t i=0; i<ingnum; i++)
    {
        if(ing[i]->getUnit()=="ml")
            total+=ing[i]->getPrice()*amount[i]*0.1;

        else if(ing[i]->getUnit()=="cl")

            total+=ing[i]->getPrice()*amount[i];


        else if(ing[i]->getUnit()=="dl")
            total+=ing[i]->getPrice()*amount[i]*10;

        else total+=ing[i]->getPrice();

    }
    return total;
}


Ingredient* Cocktail::operator[] (size_t x)
{   if (x>=ingnum) throw std::out_of_range("Tulindexeles");
    return ing[x];
}


const Ingredient* Cocktail::operator[] (size_t x) const
{   if (x>=ingnum) throw std::out_of_range("Tulindexeles");
    return ing[x];
}


Cocktail::~Cocktail()
{
    for (size_t i=0; i<ingnum; i++)
        delete ing[i];
    delete[] amount;
}
