//mmult.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 17, 2022

#include "mmult.h"
#include <sstream>

using namespace std;

void Matrix::MatrixImport(string fileName)
{
  string line;
  vector <double> temp_vector={};
  double temp;
  int totalnum = 0;

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
      totalnum++;
    }
    elements.push_back(temp_vector);
    temp_vector.clear();
    rows++;
  }
  imFile.close();
  columns = totalnum / rows;

  //this part is for testing/debgging only
  for (int i = 0;i < rows;i++)
  { 
    for (int j = 0; j < columns;j++) 
    {
      cout << elements[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  elements.clear();
}



void Matrix::MatrixExport()
{// in progress
  for (int i = 0;i < rows;i++)
  {
    for (int j = 0; j < columns;j++)
    {
      cout << elements[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  /*if (fileName == "")
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
  omFile.close();*/
}

bool Matrix::yesMultiply(Matrix x, Matrix y)
{
  if (x.columns == y.rows)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Matrix Matrix::operator*(Matrix secondMatrix)
{ //haven't tested this yet
  Matrix product;
  double currentsum = 0;
  product.rows = rows;
  product.columns = secondMatrix.columns;
  for (int i = 0;i < product.rows;i++) //1
  {
    for (int j = 0; j < product.columns;j++) //3
    {
      for (int k = 0; k < columns; k++)
      {
        currentsum += elements[i][k] * secondMatrix.elements[k][j];
      }
      //product.elements.push_back(currentsum); <---- i dont get why this gives me an error
    }
  }
  return product;
}