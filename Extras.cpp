#include "Extras.h"

void comments()
{
    std::cout << "\nThe following commands are available:\n\n";
    std::cout << " createcocktail:    creates a new cocktail receipt\n";
    std::cout << " addingredient:     adds a new ingredient to an existing cocktail\n";
    std::cout << " deletecocktail:    deletes an existing cocktail\n";
    std::cout << " list:              lists an existing cocktail's ingredients\n";
    std::cout << " save:              saves a receipt of a cocktail to a file\n";
    std::cout << " openbook:          displays your saved receipts\n\n";

    std::cout << "You can always display these commands by typing 'Commands'\n\n";
}


void freeMemory(std::vector<Cocktail*> v)
{
    for (std::vector< Cocktail* >::iterator it = v.begin() ; it != v.end(); ++it)
    {
        delete (*it);
    }
    v.clear();
}


void readFromFile()
{
    std::cout << "\n     BOOK OF RECEIPTS\n\n";
    std::string line;
    std::ifstream myfile ("Book of receipts.txt");
    while ( getline (myfile,line) )
    {
        std::cout << line << '\n';
    }
    myfile.close();

}


void writeToFile(std::string name, std::vector<Cocktail*> v)
{
    bool found = 0;
    for(size_t i=0; i<v.size(); i++)
    {
        if(v[i]->getName()==name)
        {
            found =1;
            std::cout << "The receipt has been saved.\n";
            std::ofstream outfile;
            outfile.open("Book of receipts.txt", std::ios_base::app);
            v[i]->list(outfile);
        }

    }

    if(!found)  std::cout << "The cocktail does not exist.\n";

}
