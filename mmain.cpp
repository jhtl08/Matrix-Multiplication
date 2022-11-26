//mmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 24, 2022

#include "mmult.h"

using namespace std;

int main()
{
  Matrix A;
  Matrix B;
  Matrix mMult;
  string fileName1;
  string fileName2;

  fileName1="matrix-file-1.txt";
  fileName2="matrix-file-2.txt";

  //check for validity of elements
  if (!A.MatrixImport(fileName1))
  {
    cout<<"Source of Error: "<<fileName1<<endl;
    return 0;
  }
  if (!B.MatrixImport(fileName2))
  {
    cout<<"Source of Error: "<<fileName2<<endl;
    return 0;
  }

  //mMult = A * B;
  if (Matrix::validMult(A, B))
  {
    cout << "These matrices can be multiplied!" << endl;
    //mMult.MatrixExport();
  }
  else
  {
    cout << "These matrices cannot be multiplied!" << endl;
  }
  A.MatrixExport("A-test-export.txt");
  
  return 0;
}