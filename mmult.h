//mmult.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 17, 2022

#ifndef MMULTHEADERDEF
#define MMULTHEADERDEF

#include <fstream>
#include <iostream>
#include <vector>

class Matrix
{
  private:
    std::vector<std::vector<double>> elements;
    int rows = 0;
    int columns = 0;
  public:
  
  //import function
    void MatrixImport(std::string fileName);

  //export function
    void MatrixExport(std::string fileName);
  //determines if matrices can be multiplied
    static bool yesMultiply(Matrix x, Matrix y); //not sure if I can put static here but if I remove it it gives me an error
  //operator* overload
    Matrix operator*(Matrix secondMatrix);


  //add overloaded assignment operator
  //add overloaded multiplication operator
  //add detection of invalid operation
  //provide feedback on matrix sizes, imported and exported
  //whether or not the files could be read or written to.
};

#endif