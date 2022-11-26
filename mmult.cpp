//mmult.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 24, 2022

#include "mmult.h"
#include <sstream>

using namespace std;

Matrix::Matrix()
{
  rows = 0;
  columns = 0;
}

bool Matrix::MatrixImport(string fileName)
{
  string line;
  vector<vector<double>> vect_elements;
  vector <double> temp_vector={};
  double temp;
  int countperrow;

//opens and checks the file
  ifstream imFile;
  imFile.open(fileName);
  if (!imFile.is_open())
  {
    cout<<"Error: The matrix import files cannot be opened."<<endl;
    cout<<"Check the files and try again."<<endl;
    imFile.close();
    return false;
  }

//extracting elements line per line
  while(getline(imFile, line))
  {
    countperrow=0;
    stringstream linestream(line);
    while(linestream.rdbuf()->in_avail())
    {
      if (linestream>>temp)
      {
        countperrow++;
        if (rows==0)
        {//sets column count to the number of elements in first row
          columns++;
        }
        else if (countperrow>columns)
        {//only gets up to "columns" number of elements per row
          continue;
        }
        temp_vector.push_back(temp);
      }
      else
      {
        cout<<"Non-floating point numbers detected.\n"<<
        "Make sure file contains only floating point numbers.\n";
        imFile.close();
        return false;
      }
    }
    vect_elements.push_back(temp_vector);
    temp_vector.clear();
    rows++; //counts row 
  }
  imFile.close();

//converting vect_elements into an array
  //allocate the memory for the array
  elements = new double*[rows];
  for (int i=0; i<rows; i++)
  {
    elements[i] = new double[columns];
  }

  //copy the values
  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<columns; j++)
    {
      elements[i][j]=vect_elements[i][j];
    }
  }

  return true;
}

void Matrix::MatrixExport(string fileName)
{
//creates or open, then checks the file
  if (fileName == "")
  {
    fileName="mproduct.txt";
  }
  ofstream omFile;
  omFile.open(fileName);
  if (!omFile.is_open())
  {
    cout<<"Error: The matrix export file cannot be opened."<<endl;
    cout<<"Check the files and try again."<<endl;
    return;
  }

//prints all elements into the txt file
  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<columns; j++)
    {
      omFile<<elements[i][j]<<" ";
    }
    omFile<<"\n";
  }
  omFile.close();
}

bool Matrix::validMult(Matrix x, Matrix y)
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

/*
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
*/