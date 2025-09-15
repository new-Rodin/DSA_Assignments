#include <bits/stdc++.h>
using namespace std;

int search(vector <int> v, int value)
{
    int i=0;
    while(true)
    {
        if(value == v[i])
        return i;
        if(v[i]==-1)
        return -1;
        if(value<v[i])
        i = i*2+1;
        else
        i = i*2+2;
    }
}
int main()
{
    int n,i,c=0;
    cout<<"Enter the number of nodes:"<<endl;
    cin>>n;
    vector <int> a(1000,-1); // All the vector values i.e the nodes are initialized with -1 to make it seem as if they are all empty and ready to be filled.
    int v[n];
    cout<<"Enter "<<n<<" values in the nodes:"<<endl; // First we store all the numbers in a simple array.
    for(i=0;i<n;i++)
    cin>>v[i];
    i=0;
    while(true)
    {
        if(c==n) //Checks if we have reached the end of the array v[i]
        break;
        if(a[i]!=-1)
        {
            if(v[c]<a[i]) //Traverses to the left if the element is smaller
            i = 2*i+1;
            else// Traverses to the right if the element is larger
            i = 2*i+2;
        }
        else{
        a[i]=v[c]; //If we arrive at a node that is empty then that is the point where we store them. 
        i=0;
        c++;
        }
    }
    c=0;
    i=0;

    cout<<"The elements stored are:"<<endl;
    while(true)
    {
        if(c==n)
        break;
        cout<<a[i]<<"  "; //During the printing of the values -1 depicts a void at the index i i.e it means there is no node present at that index.
        if(a[i]!=-1)
        c++;
        i++;
    }
    cout<<endl;

    cout<<"Enter the value to be searched:"<<endl;
    int value;
    cin>>value;
    int index = search(a,value);
    if(index == -1)
    cout<<"The value is not present!"<<endl;
    else
    cout<<"The value is at index "<<index<<endl;
}