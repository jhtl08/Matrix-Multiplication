//mmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 26, 2022

#include "mmult.h"

using namespace std;

int main(int argc, char* argv[])
{
  Matrix A;
  Matrix B;
  Matrix mProduct;
  string inputFileName1;
  string inputFileName2;
  string outputFileName="mproduct.txt";
  int importErrors=0;

  //extract the inputs from the command line
  inputFileName1=argv[1];
  inputFileName1+=".txt";
  inputFileName2=argv[2];
  inputFileName2+=".txt";
  if (argv[3])
  {
    outputFileName=argv[3];
    outputFileName+=".txt";
  }
  
  //check for validity of elements while attempting to import
  if (!A.MatrixImport(inputFileName1))
  {
    importErrors+=1; //allows for checking of second file
  }
  if (!B.MatrixImport(inputFileName2))
  {
    importErrors+=1;
  }
  if (importErrors>0)
  {
    cout<<"Check the file(s) and try again.\n";
    return 0;
  }

  //providing feedback about the matrices
  cout<<"\nMatrix A Size: "<<A.MatrixSize()<<endl;
  cout<<"Matrix B Size: "<<B.MatrixSize()<<"\n\n";

  //performing the multiplication
  if (A.canMultwith(B))
  {
    cout<<"Matrices can be multiplied.\n";
    mProduct=A*B;
    mProduct.MatrixExport(outputFileName);
    cout<<"Size of the Product of Matrices A and B: "
    <<mProduct.MatrixSize()<<endl;
  }
  else
  {
    cout << "Matrices cannot be multiplied."<<endl;
  }

  return 0;
}