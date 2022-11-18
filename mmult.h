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
    int rows;
    int columns;
  public:
  
  //import function
    void MatrixImport(std::string fileName);

  //export function
    void MatrixExport(std::string fileName);


  //add overloaded assignment operator
  //add overloaded multiplication operator
  //add detection of invalid operation
  //provide feedback on matrix sizes, imported and exported
  //whether or not the matrices could be multiplied
  //whether or not the files could be read or written to.
};

#endif