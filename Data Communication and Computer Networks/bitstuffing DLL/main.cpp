#include<stdio.h>
#include<string.h>
#include<iostream>

using namespace std;

void bitstuff(int frame[], int n){

    int k, i=0, j=0, count=1;
    int stuff[n];

    while(i<n)
	{
	    if(frame[i]==1)
	    {
	        stuff[j]=frame[i];
	        for(k=i+1;frame[k]==1 && k<n && count<5;k++)
	        {
	            j++;
	            stuff[j]=frame[k];
	            count++;
	            if(count==5)
	            {
	                j++;
	                stuff[j]=0;
	                count = 1;
	            }
	                i=k;
	        }
	    }
	    else
	        stuff[j]=frame[i];
	
	    i++;
	    j++;
    }

    cout<<"After stuffing the frame is:";
    for(i=0;i<j;i++)
        cout<<stuff[i];

    return;
}

int main()
{
    int n;

    cout<<"Enter frame length:";
    cin>>n;
    int frame[n];

    cout<<"Enter input frame (0's & 1's only):";
    for(int i=0;i<n;i++)
        cin>>frame[i];

    bitstuff(frame, n);

    return 0;
}
