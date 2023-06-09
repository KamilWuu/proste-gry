#include<iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include "matrix.hpp"

using namespace std;

#define FAILS_TO_LOSE 7

void printTypicalAirStudent(int fails)
{
    Matrix picture(8,11);
    char frame = char(178);
    for(int i = 0; i <8;i++){
        for(int j = 0; j<11;j++){
            picture.setElement(i,j,' ');
        }
    }
    for(int i = 0; i < 8; i++)
    {
        picture.setElement(i,0,frame);
        picture.setElement(i,10,frame);
    }
    for(int i = 0; i < 11; i++)
    {
        picture.setElement(0,i,frame);
        picture.setElement(7,i,frame);
    }

    if(fails > 0){
        for(int i = 1; i < 10; i++){
            picture.setElement(1,i,'_');
        }    
    }
    if(fails > 1){
        picture.setElement(2,5,'|');
    }
    if(fails > 2){
        picture.setElement(3,5,2);
    }
    if(fails > 3){
        picture.setElement(4,5,'I');
    }
    if(fails > 4){
        picture.setElement(4,4,'/');
    }
    if(fails > 5){
        picture.setElement(4,6,92);
    }
    if(fails > 6){
        picture.setElement(5,4,'/');
    }
    if(fails > 7){
        picture.setElement(5,6,92);
    }

    picture.print();
}


void printGame(string actual_key, vector<char> used_letters, int fails, string game_key)
{
    system("cls");
       //cout << "Prawidlowe= " << game_key << endl;
       printTypicalAirStudent(fails);
        cout << "Twoje slowo: ";
        for (const auto& letter : actual_key) {
        std::cout << letter << " ";
        }
        cout <<"\nUzyte litery: "; 
        for (const auto& letter : used_letters) {
        std::cout << letter << ",";
        }
        cout << "\n";

        cout << "ilosc bledow: " << fails << endl;
        cout << "jesli chcesz podac pelne haslo wpisz '1' (bledna odpowiedz = przegrana)" << endl;

}

bool checkLetterIn(vector<char> letters, char searched_letter){ // true if jest ta litera
    for(char & letter : letters){
        if(letter == searched_letter){
            return true;
        }
        
    }
    return false;
}

bool checkActualKey(const string key, string &actual, char letter)
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
    string actual_key, full_answer;
    int fails = 0;
    string input;
    

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
        
        printGame(actual_key, used_letters, fails, game_key);
        cout << "podaj litere: ";
        if(actual_key != game_key){
            cin >>  input; 
        }
        if(input == "1"){
            cout << "Podaj haslo: ";
            cin >> full_answer;
            if(full_answer == game_key){
                actual_key = game_key;
                
            }
            else{
                cout << "to nie jest prawidlowe haslo!"<< endl;
                fails = FAILS_TO_LOSE;
            }
        }
        else{
            actual_letter = input[0];
        }
        if(actual_key == game_key){
        printGame(actual_key, used_letters, fails,game_key);

            cout << "brawo wygrales!" <<endl;
            break;
        }
        if(fails == FAILS_TO_LOSE)
        {   
            printGame(actual_key, used_letters, 8,game_key);
            
            cout << "PRZEGRYWASZ!!!!!" << "poprawnym haslem bylo: " << game_key <<endl;
            break;
        }
        while(checkLetterIn(used_letters, actual_letter)){
            printGame(actual_key, used_letters, fails,game_key);
            cout << "Ta litera zostala juz uzyta, podaj jeszcze raz: ";
            cin >>  actual_letter;
        }
        used_letters.push_back(actual_letter);
        if(!checkActualKey(game_key, actual_key, actual_letter)){
            fails++;
        }
        
       
    }
    
    return 0;
}