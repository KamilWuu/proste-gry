#include<iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
    int liczba;
    int losowa;
    int i =0;
    srand(time(0));
    losowa = rand() % 101;

    cout << "Wylosowalem liczbe od 0 do 100\n";

    while(true){
        i++;
        cout << "sproboj zgadnac>>    ";
        cin >> liczba;
        cout << "\n";
        if(liczba > losowa){
            cout<< "wylosowalem mniejsza \n";
        }
        else if(liczba < losowa){
            cout << "wylosowalem wieksza \n";
        }
        else if(liczba == losowa){
            cout << "brawo wygrales w " << i << "probie \n";
            break;
        }
    }

    return 0;
}