//Matrix Multiplication of two TRULY RANDOM generated matrices A and B of order (M x N) and (N x P). Here your program must work for any M, N and P.

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    srand(time(NULL));
    int m,n,p;
    cout<<"Enter M N and P respectively as the order of the matrices A(MxN) and B(NxP)"<<endl;
    cin>>m>>n>>p;
    int i,j,k;
    int a[m][n];
    int b[n][p];
    int c[m][p];
    cout<<"Matrix 1:"<<endl<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++){
        a[i][j] = round(rand() % 99); // Generates a random matrix with all entries between 0 - 99  
        cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix 2:"<<endl<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<p;j++){
        b[i][j] = round(rand() % 99); // Generates a random matrix with all entries between 0 - 99  
        cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"The resulting matrix from their multiplication:"<<endl<<endl;
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            c[i][j]+= a[i][k]*b[k][j];
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
}