//mmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 17, 2022

#include "mmult.h"

using namespace std;

int main()
{
  Matrix A;
  Matrix B;
  A.MatrixImport("matrix-file-1.txt");
  B.MatrixImport("matrix-file-2.txt");
  if (Matrix::yesMultiply(A, B))
  {
    cout << "These matrices can be multiplied!" << endl;
    //initiate multiplication here
  }
  else
  {
    cout << "These matrices cannot be multiplied!" << endl;
  }
  //return 0;
  system("pause");
}