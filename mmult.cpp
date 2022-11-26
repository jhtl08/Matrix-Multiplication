//mmult.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//November 26, 2022

#include "mmult.h"
#include <sstream>

using namespace std;

Matrix::Matrix()
{
  rows = 0;
  columns = 0;
}

Matrix::Matrix(int inputRows, int inputColumns)
{
  rows=inputRows;
  columns=inputColumns;
  elements=new double*[rows];
  for (int i=0; i<rows; i++)
  {
    elements[i]=new double[columns];
  }
}

bool Matrix::MatrixImport(string fileName)
{
  string line;
  vector<vector<double>> vect_elements;
  vector <double> temp_vector={};
  double temp;
  int countperrow;
  string nonfloats;

//opens and checks the file
  ifstream imFile;
  imFile.open(fileName);
  if (!imFile.is_open())
  {
    imFile.close();
    cout<<fileName<<" cannot be opened."<<endl;
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
      {//if the next element is double
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
      else if(countperrow==0 && columns==0)
      {//if the first term is nonfloat
        cout<<"First element of "<<fileName<<" is invalid.\n";
        imFile.close();
        return false;
      }
      else
      {//if nonfloats are encountered
        linestream.clear();
        linestream>>nonfloats;
        break; //stops checking the row further and proceeds to next
      }
    }
    //discards extra rows with columns less than of the first row's
    if (countperrow<columns)
    {
      temp_vector.clear();
      continue;
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
      omFile<<elements[i][j]<<" \t";
    }
    omFile<<"\n";
  }
  omFile.close();
}

bool Matrix::canMultwith(Matrix y)
{
  if (columns == y.rows)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Matrix& Matrix::operator=(const Matrix& Matrix2)
{
  rows=Matrix2.rows;
  columns=Matrix2.columns;
  elements=Matrix2.elements;
  return *this;
}

Matrix Matrix::operator*(const Matrix& Matrix2) const
{
  //initialize the product matrix
  Matrix mProduct=Matrix(rows, Matrix2.columns);

  for (int i=0; i<rows; i++)
  {
    for (int j=0; j<Matrix2.columns; j++)
    {
      for (int k=0; k<columns; k++)
      {
        mProduct.elements[i][j] += elements[i][k]
        *Matrix2.elements[k][j];
      }
    }
  }
  return mProduct;
}

string Matrix::MatrixSize()
{
  string mSize;
  mSize = to_string(rows) + " x " + to_string(columns);
  return mSize; 
}