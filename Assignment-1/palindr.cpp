//Write a program to check palindrome numbers from a given sequence of numbers being input externally continuously. The numbers may have an overlap too. Your program must be able to check 3, 4, 5 and 6 numbers palindromes. If you are able to give us a generalized program to check palindromes of all possible lengths (more than 6 too, practically no restrictions) in a given sequence, there might be a secret bonus to the student.

#include<iostream>
using namespace std;
bool isPalindrome(string s)
{
    int n = s.length();
    if(n == 1)
    {
        return true;
    }
    else{
        int u=n-1,l=0;
        while(l<u)
        {
            if(s[u]==s[l]) // Compares the first and last character of each word i.e each integer
            {
                u--;l++;
            }
            else
            return false;
        }
        return true;
    }
}
int main()
{
    cout<<"Enter a number to check if it is palindrome or not. Enter -1 to exit the programme"<<endl;
    while(true){
    int a;
    cin>>a;
    if(a==-1){
        cout<<"Program ends"<<endl;
    return 0;
    }
    else{
        if(isPalindrome(to_string(a)))
        cout<<a<<" is Palindrome"<<endl;
        else
        cout<<a<<" is not Palindrome"<<endl;
    }
    }
}