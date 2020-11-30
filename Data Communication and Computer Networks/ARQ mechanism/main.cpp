#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

// Go Back N
// implementation of sliding window protocol

void GoBackN(int nf, int N){
	int i=1, no_tr=0;;
	while(i<=nf)
	{
	    int x=0;
	    for(int j = i; j < i+N && j <= nf; j++)
	    {
	        cout<<"Frame Sent"<<j<<endl;
	        no_tr++;
	    }
	    for(int j=i;j<i+N && j<=nf;j++)
	    {
	        int flag = rand()%2;
	        if(!flag)
	            {
	                cout<<"Acknowledgment for Frame "<<j<<endl;
	                x++;
	            }
	        else
	            {   cout<<"Frame "<<j<<" Not Received"<<endl;
	                cout<<"Retransmitting Window"<<endl;
	                break;
	            }
	    }
	    cout<<endl;
	    i+=x;
	}
	
	cout<<"Total number of transmissions : "<<no_tr<<endl;
	
	return; 
}

int main()
{
	int frames,winSize;
	int no_tr=0;
	
	// srand(): random number generator
	// time(NULL): returns the number of seconds elapsed since 00:00:00
	srand(time(NULL));
	
	cout<<"Enter the number of frames : ";
	cin>>frames;
	cout<<"Enter the Window Size : ";
	cin>>winSize;
	 
	
	// the sending process continues to send frames (window size) even without receiving an acknowledgment
	//  transmit N frames to the destination 

	GoBackN(frames, winSize);
	return 0;
}
