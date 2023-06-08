#include<iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

bool check_actual_key(const string key, string &actual, char letter)
{ 
    bool letter_check = false;
    for(int i = 0; i < actual.size(); i++)
    {
        if(key[i] == letter){
            actual[i] = letter;
            letter_check = true;
        }
    }
    if(letter_check){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    vector<string> passwords;
    vector<char> used_letters;
    string line;
    string game_key;
    char actual_letter;
    string actual_key;
    int fails = 0;

    ifstream Pfile("wisielec_slowa.txt");
    if (!Pfile) {
        cout << "Nie można otworzyć pliku." << endl;
        return 1;
    }
    
    while(getline(Pfile, line)){
        passwords.push_back(line);
    }

    srand(time(0));
    int random = rand() % (passwords.size() + 1);
    game_key = passwords[random];
    actual_key = game_key;
    for(int i = 0; i < actual_key.size(); i++)
    {
        actual_key[i] = '_';
    }



    while(true){
        system("cls");
        cout << "moje slowo: "<< game_key << "\n";
        cout << "Twoje slowo: "<< actual_key << "\n";

        cout <<"Uzyte litery: "; 
        for (const auto& letter : used_letters) {
        std::cout << letter << ",";
        }
        cout << "\n";

        cout << "ilosc bledow: " << fails << endl;

        cout << "podaj litere: ";
        cin >>  actual_letter;
        used_letters.push_back(actual_letter);
        if(!check_actual_key(game_key, actual_key, actual_letter)){
            fails++;
        }
        if(actual_key == game_key){
            system("cls");
        cout << "moje slowo: "<< game_key << "\n";
        cout << "Twoje slowo: "<< actual_key << "\n";

        cout <<"Uzyte litery: "; 
        for (const auto& letter : used_letters) {
        std::cout << letter << ",";
        }
        cout << "\n";

        cout << "ilosc bledow: " << fails << endl;

            cout << "brawo wygrales!" <<endl;
            break;
        }
        
    }
   

    return 0;
}