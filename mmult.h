//mmult.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 26, 2022

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
  //empty constructor
    Matrix();

  //non-empty constructor
    Matrix(int inputRows, int inputColumns);

  //import function
    bool MatrixImport(std::string fileName);

  //export function
    void MatrixExport(std::string fileName);

  //determines if matrices can be multiplied
    bool canMultwith(Matrix y);
  
  //operator= overload
    Matrix& operator=(const Matrix& Matrix2);

  //operator* overload
    Matrix operator*(const Matrix& secondMatrix) const;

  //provide feedback about matrix properties
    std::string MatrixSize();
};

#endif