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
  int colnum = 0;

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
    stringstream linestream(line);
    while(linestream>>temp)
    {
      temp_vector.push_back(temp);
      colnum++;
    }
    elements.push_back(temp_vector);
    temp_vector.clear();
    rownum++;
  }
  imFile.close();

  //this part is for testing/debgging only
  for (int i = 0;i < rownum;i++)
  { 
    for (int j = 0; j < colnum/rownum;j++) 
    {
      cout << elements[i][j] << " ";
    }
    cout << endl;
  }
  elements.clear();
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