#include <iostream>
#include <vector>
using namespace std;

vector<int> CreateFlatVector(vector<vector<vector<int>>>, int, int, int);
int IndexTo1D(int, int, int, int, int);



int main(int argc, char const *argv[])
{
    //n,m,p are the sizes of the matrix
    //n is the number of rows
    //m is the number of columns
    //p is the number of layers or depth of the matrix
    int n,m,p;
    //take sizes n,m and p from user
    cout << "Enter 3 intigers: n  m  p: ";
    cin >> n >> m >> p;

    //validate input
    if(n<=0 || m<=0 || p<=0)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    //create a vesctor matrix of size n*m*p and fill it with random numbers
    vector<vector<vector<int>>> matrix(n,vector<vector<int>>(m,vector<int>(p)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<p;k++)
            {
                matrix[i][j][k] = rand()%100;
            }
        }
    }
    //show the user the randomized matrix
    cout << "Matrix with random numbers from 0 to 99 : " << endl;
    for(int k=0;k<p;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //flatten the matrix
    vector<int> flat_matrix;
    flat_matrix = CreateFlatVector(matrix,n,m,p);

    //show the user the flattened matrix
    cout << "Flattened matrix : " << endl;
    for(int i=0;i<flat_matrix.size();i++)
    {
        cout << flat_matrix[i] << " ";
    }
    cout << endl;

    //Testing
    //Test the IndexTo1D function by asserting that the flattened matrix is the same as the original matrix
    vector<vector<vector<int>>> matrix_test(n,vector<vector<int>>(m,vector<int>(p)));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<p;k++)
            {
                matrix_test[i][j][k] = flat_matrix[IndexTo1D(i,j,k,n,m)];
            }
        }
    }
    cout << "Matrix Test : " << endl;
    //print the test matrix
    for(int k=0;k<p;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << matrix_test[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //make sure that matrix test is equal to the original matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<p;k++)
            {
                if(matrix[i][j][k] != matrix_test[i][j][k])
                {
                    cout << "Error in matrix test" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Matrix test passed" << endl;
    cout << "press any key to exit" << endl;
    //empty the input buffer
    cin.ignore();
    //pause the program
    cin.get();
    return 0;
}

//create a 1D vector to store flattened matrix
//parameters:
//matrix: the matrix to be flattened
//n: number of rows
//m: number of columns
//p: number of layers or depth of the matrix
//return: a 1D vector containing the flattened matrix
vector<int> CreateFlatVector (vector<vector<vector<int>>> matrix, int n, int m, int p)   
{
    vector<int> flat_vector(n*m*p);
    int index = 0;
   for(int k=0;k<p;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                flat_vector[index] = matrix[i][j][k];
                index++;
            }
        }
    }
    return flat_vector;
}

//convert 3D indexes (i,j,k) to 1D index y =  k*n*m + i*m + j
//parameters:
//i: row index
//j: column index
//k: layer index
//n: number of rows
//m: number of colums
//return: 1D index y
int IndexTo1D(int i, int j, int k, int n, int m)
{
    return k*n*m + i*m + j;
}
