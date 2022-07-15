#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a=3,b=5,temp;
    cout<<"orignal are"<<a<<" "<<b<<endl;
    temp=a;
    a=b;
    b=temp;
    cout<<"swapped no.s are"<<a<<" "<<b;

}    
//***************************reverse a array************************
   /*  int arr[5]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    

    for(int i= len-1 ; i>=0 ; i--)
    {
        cout<< arr[i]<< " ";
    }
 */

//*************reverse a string*******************************************
/* string str = "Harsh";
string rev = "";
for(int i=str.length()-1;i>=0;i--)
{   
    rev= rev + str[i];
}
    cout<<rev;
 */


/* ***************reverse string usin reverse() method*****************
string str = "Harsh";
reverse(str.begin(),str.end());
cout<<str;

 */

//*****************************sum of an array***********************************************
/* int arr[5]={1,2,3,4,5};
int sum=0 ;
int n = 5;
int len=sizeof(arr)/sizeof(arr[0]);
    

    for (int i=0 ; i<n ; i++)
    {
        sum = sum + arr[i];
      
    }
  cout<< sum ;

 */


//**************************************max and min element in a array********************************  
/* int arr[5]={1,2,3,4,5};
int max , min ;
int n = 5 ;
max =arr[0];

for(int i =0 ; i<n ; i++)
{
    if (max<arr[i])
    {
       max=arr[i];
    }    
    
}

min=arr[0];
for(int i =0 ; i<n ; i++)
{
    if (min>arr[i])
    {
        min=arr[i];
    }    
    
}

cout << "Largest element" << max<<endl;
cout<<"smallest elemetn"<< min << endl ;

 */

//*********************Arrays and pointers****************************************

/* int main()
{
    // Declare an array
    int v[3] = {10, 100, 200};
 
    // Declare pointer variable
    int *ptr;
 
    // Assign the address of v[0] to ptr
    ptr = v;
 
    for (int i = 0; i < 3; i++)
    {
        printf("Value of *ptr = %d\n", *ptr);
        printf("Value of ptr = %p\n\n", ptr);
 
        // Increment pointer ptr by 1
        ptr++;
    }
}

 */
//*******************************prime prog***********************************************
/* int main()
{
    int n;
    cin>>n;
    bool flag=0;


    for (int i = 2; i < n; i++)
    {
        if(n%i==0)
        {
            cout<<"non-prime";
            flag=1;
            break;
        }  
    }

    if(flag==0)
    {
        cout<<"prime";
    }
    
}
 */

/* 
*********************REVERSING A NUMBER**********************************************
int main()
{
    int n;
    cout<<"enter a number"<<endl;
    cin>>n;

    int reverse =0;
    int lastdigit;
    while(n>0)
    {
        lastdigit = n%10;
        reverse = reverse *10 + lastdigit;
        n=n/10;
    }

cout<<"THE REVERSE IS "<<reverse;

} */


//*****************ARMSTRONG NUMBER******************************

/* int main()
{
    int n;
    cin>>n;
    int sum =0,temp;

    
    temp=n;
    while(n>0)
    {
        int lastdigit = n%10;
        sum=sum+(lastdigit*lastdigit*lastdigit);
        n=n/10;

    }

    if(sum==temp)
    {
        cout<<"armstrong";
    }
    else{
        cout<<"not armstrong";
    }

    return 0;
}

 */
/* *********************facatorial********************
int main()
{
    int n;
    cin>>n;
    int fact=1;
    for(int i=2;i<=n;i++)
    {
        fact=fact*i;
    }
  cout<<fact;
} */

//**********prime bw 2 nos******************

/* bool isprime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int a,b;
    cin >> a>> b;
    for(int i =a;i<b;i++)
    {
        if(isprime(i))
        {
            cout<<i<<endl;
        }
    }


} */

//***************************FIBONACCI*********************************************
/* void fib(int n)
{
    int t1=0;
    int t2=1;
    int nextTerm;
    for(int i=1;i<=n;i++)
    {
        cout<<t1<<" ";
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }

}

int main()
{
    int n;
    cin >>n;

    fib(n);
} */

/* *******************************************factorial**************************************************
int fact(int n)
{
    int j=1;
    for(int i=2;i<=n;i++)
    {
        j=j*i;
    }
    cout<<j;
}

int main()
{
    int n;
    cin>>n;
    fact(n);

} */

/* **********************************SUM OF NO.S BW 2 NO.S************************************************
int sum(int a,int b)
{
    int add=0;
    for(int i=a;i<=b;i++)
    {
        add=add+i;
    }
    cout<<add;
}

int main()
{
    int a,b;
    cin>>a>>b;

    sum(a,b);
} */


/* *************************PASCAL TRIANGLE********************************************* */
/* int fact(int n)
{
    int factorial=1;
    for(int i=2;i<=n;i++)
    {
        factorial=factorial*i;
    }
    return factorial;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<fact(i)/fact(j)*fact(i-j)<<" ";
        }
        cout<<endl;
    }


} */