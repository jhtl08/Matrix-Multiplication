//mmult.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 10, 2022

#include "mmult.h"
#include <sstream>

using namespace std;

Matrix::Matrix()
{

}

Matrix::Matrix(string fileName)
{
  string line;
  vector <double> temp_vector={};
  double temp;
  int rownum=0;

  ifstream imFile;
  imFile.open(fileName);
  if (!imFile.is_open())
  {
    cout<<"Error: The matrix import files cannot be opened."<<endl;
    cout<<"Check if the files exists and try again."<<endl;
    //make it so that it asks for the user input again in main
  }

  while(getline(imFile, line))
  {
    std::stringstream linestream(line);
    while(linestream>>temp)
    {
      temp_vector.push_back(temp);
    }
    elements.push_back(temp_vector);
    temp_vector.clear();
  }
  imFile.close();

  //this part is for testing/debgging only
  //seems to bug out if you dont express in terms of rows/columns since it counts it as outside the vector already - paolo
  for (int i = 0;i < 3;i++) {
    for (int j = 0; j < 4;j++) {
      cout << elements[i][j] << " ";
    }
    cout << endl;
  }
}

void Matrix::MatrixExport(Matrix mOutput, string fileName)
{// in progress
  if (fileName=="")
  {
    fileName="mproduct.txt";
  }
  ofstream omFile;
  omFile.open(fileName);
  if (!omFile.is_open())
  {
    cout<<"Error: The matrix export file cannot be opened."<<endl;
  }
  //for loop omFile<<mOutput[0][0]
  omFile.close();
}