//mmult.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 24, 2022

#ifndef MMULTHEADERDEF
#define MMULTHEADERDEF

#include <fstream>
#include <iostream>
#include <vector>

class Matrix
{
  private:
    int rows;
    int columns;
    double **elements;
    
  public:
  //constructor
    Matrix();
  
  //import function
    void MatrixImport(std::string fileName);

  //export function
    void MatrixExport(std::string fileName);
  //determines if matrices can be multiplied
    static bool validMult(Matrix x, Matrix y); //not sure if I can put static here but if I remove it it gives me an error
  //operator* overload
    Matrix operator*(Matrix secondMatrix);


  //add overloaded assignment operator
  //add overloaded multiplication operator
  //add detection of invalid operation
  //provide feedback on matrix sizes, imported and exported
  //take input from terminal
};

#endif