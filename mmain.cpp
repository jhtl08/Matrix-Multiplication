//mmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 10, 2022

#include "mmult.h"

using namespace std;

int main()
{
  Matrix A;
  Matrix B;
  A = Matrix("matrix-file-1.txt");
  cout << endl;
  B = Matrix("matrix-file-2.txt");
  
  //return 0;
  system("pause");
}