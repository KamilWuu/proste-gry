#pragma once
#include <vector>
#include <iostream>

class Matrix {
private:
    int rows;            // liczba wierszy
    int cols;            // liczba kolumn
    std::vector<std::vector<char>> data;    // wektor przechowujący macierz

public:
    // Konstruktor
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) 
    {
        data.resize(rows, std::vector<char>(cols, 0));
    }

    void setElement(int row, int col, char value);  
    int getElement(int row, int col);
    void print();
    void moveLeft();
    
};

void Matrix::moveLeft() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols - 1; ++j) {
                data[i][j] = data[i][j + 1];
            }
            data[i][cols - 1] = 0;  // Wypełnienie ostatniego elementu wiersza zerem
        }
    }



void Matrix::setElement(int row, int col, char value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row][col] = value;
        } else {
            std::cout << "Błąd: Nieprawidłowe indeksy wiersza lub kolumny!" << std::endl;
        }
    }

 int Matrix::getElement(int row, int col){
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            return data[row][col];
        } else {
            std::cout << "Błąd: Nieprawidłowe indeksy wiersza lub kolumny!" << std::endl;
            return 0;  // Zwracamy zero w przypadku błędu
        }
    }

void Matrix::print(){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j];
            }
            std::cout << std::endl;
        }
    }

