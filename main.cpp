#include <algorithm>
#include "memtrace.h"
#include "Extras.h"
#include "Ingredient.h"
#include "Cocktail.h"



using namespace std;

int main()
{

    string userin;
    vector<Cocktail*> database;
    comments();


    while(1==1)
    {
        cin>>userin;
        std::transform(userin.begin(), userin.end(), userin.begin(), ::tolower);

        if(userin == "createcocktail")
        {
            string name;
            cout << "\n Name: ";
            cin >> name;
            database.push_back(new Cocktail(name));
            cout << "\n Receipt for " << name << " has been created.\n";
        }

        else if(userin =="addingredient")
        {
            string cockname;
            cout <<"Name of the cocktail you would like to add the ingredient: ";
            cin >> cockname;
            bool found=0;
            size_t x;
            for(size_t i=0; i<database.size(); i++)
                if(database[i]->getName()==cockname)
                {
                    found =1;
                    x=i;
                }
            if(!found) cout << "The cocktail you typed does not exist.\n";

            if(found)
            {
                string answer;
                cout << "Is it a liquid? (type Y/N)\n";
                cin >> answer;
                if(answer=="N" || answer =="n")
                {
                    string name;
                    double amount;
                    string unit;
                    double price;

                    cout << "Name: ";
                    cin >> name;
                    cout << "Amount: ";
                    cin >> amount;
                    cout << "Unit (example: pc): ";
                    cin >> unit;
                    cout << "Price : (Ft//" << amount << " ):";
                    cin >> price;

                    database[x]->add(new Ingredient(name,unit,price),amount);

                    cout <<  amount << ' ' << unit << ' '<< name << " has been added to " << cockname << endl;
                }

                if(answer=="Y" || answer =="y")
                {
                    string alc_answer;
                    cout << "Is it alcoholic?(type Y/N )\n";
                    cin >> alc_answer;
                    if(alc_answer== "Y" || alc_answer == "y")
                    {
                        string name;
                        double amount;
                        string unit;
                        double alc;
                        double price;

                        cout << "Name: ";
                        cin >> name;
                        cout << "Amount: ";
                        cin >> amount;
                        cout << "Unit (example: dl, cl): ";
                        cin >> unit;
                        cout << "Alcohol content (%): ";
                        cin >> alc;
                        cout << "Price (Ft/cl) : ";
                        cin >> price;

                        database[x]->add(new Alcohol(name, unit, price, alc),amount);
                          cout <<  amount << ' ' << unit << ' '<< name << " has been added to " << cockname << endl;
                    }
                     if(alc_answer== "N" || alc_answer == "n")
                    {
                        string name;
                        double amount;
                        string unit;
                        string carb;
                        bool carbonated=0;
                        double price;

                        cout << "Name: ";
                        cin >> name;
                        cout << "Amount: ";
                        cin >> amount;
                        cout << "Unit (example: dl, cl): ";
                        cin >> unit;
                        cout << "Is it carbonated? (type Y/N): ";
                        cin >> carb;
                        cout << "Price (Ft/cl) : ";
                        cin >> price;

                        if(carb=="Y" || carb == "y")
                            carbonated=1;


                        database[x]->add(new NonAlcohol(name, unit, price, carbonated),amount);
                          cout <<  amount << ' ' << unit << ' '<< name << " has been added to " << cockname << endl;
                    }


                }
            }
        }

        else if(userin == "deletecocktail")
        {

            bool found = 0;
            string name;
            cout << "\n Name of the cocktail you would like to delete: ";
            cin >> name;

            for (std::vector< Cocktail* >::iterator it = database.begin() ; it != database.end();)
            {
                if(name == (*it)->getName())
                {
                    delete (*it);
                    it = database.erase(it);
                    found =1;
                }
                else
                it++;
            }

            if (!found) cout << "The cocktail does not exist";

        }

        else if(userin == "list")
        {
            bool found =0;
            string cockname;
            cout << "\n Which cocktails ingredients would you like to list? ";
            cin >> cockname;

            for(size_t i=0;i<database.size();i++)
                if(cockname == database[i]->getName())
                {
                    database[i]->list(cout);
                    found =1;
                }
            if(!found) cout << "The cocktail does not exist.";
        }

        else if(userin == "save")
        {
            string cockname;
            cout << "Which cocktails would you like to save? ";
            cin >> cockname;
            writeToFile(cockname, database);
        }

        else if(userin == "openbook")
        {
            readFromFile();
        }

        else if(userin =="commands")
        {
                comments();
        }


        else if (userin== "exit" )
            break;

         else cout << "Unknown command\n";
    }

    freeMemory(database);
    return 0;
}
