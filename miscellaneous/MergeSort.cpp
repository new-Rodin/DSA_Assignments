#include<iostream>
using namespace std;
void merge(int p[],int q[],int r[],int m,int n)
{
   int i=0;int j=0;int k =0;
    while(i < m && j < n )
    {
        if(p[i]>=q[j]){
        r[k] = q[j];
        k++;j++;
        }
        else{
            r[k] = p[i];
            i++;k++;
        }
    }
    while(i<m)
    {
        r[k]=p[i];
        i++;k++;
    }
    while(j<n)
    {
        r[k]=q[j];
        j++;k++;
    }
}
void mergesort(int a[],int low,int high)
{
    if(low == high) return;
    else{
        int mid = (low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        int i=low,m=0,n=0;
        int j = mid +1;
        int p[1000];
        int q[1000];
        int r[1000];
        while(i<=mid)
        {
            p[m]=a[i];
            i++;m++;
        }
        while(j<=high)
        {
            q[n]=a[j];
            j++;n++;
        }
        merge(p,q,r,m,n);
        int l = low,k=0;
        while(l<=high){
            a[l] = r[k];l++;k++;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int i;
    int a[n];
    cout<<"Enter "<<n<<" numbers in the array"<<endl;
    for(i=0;i<n;i++)
    cin>>a[i];
    mergesort(a,0,n-1);
    cout<<"The sorted array is: "<<endl;
    for(i=0;i<n;i++)
    cout<<a[i]<<"  ";
}