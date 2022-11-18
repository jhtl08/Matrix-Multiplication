//mmult.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 10, 2022

#ifndef MMULTHEADERDEF
#define MMULTHEADERDEF

#include <fstream>
#include <iostream>
#include <vector>

class Matrix
{
  private:
    std::vector<std::vector<double>> elements;
    int nElements = 0;
  public:
    Matrix();
  //import function
    Matrix(std::string fileName);

  //export function
    void MatrixExport(Matrix mOutput, std::string fileName);


  //add overloaded assignment operator
    //takes input files names from user
  //add overloaded multiplication operator
    //takes output file name from user
  //add detection of invalid operation
  //provide feedback on matrix sizes, imported and exported
  //whether or not the matrices could be multiplied
  //whether or not the files could be read or written to.
};

#endif