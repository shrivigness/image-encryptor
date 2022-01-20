#include <fstream>
#include <iostream>
using namespace std;

int cipher[2400][16],key[2400][16],data[1200][8];
void combine()
{
    int i,j,a,b;
    fstream K;
    K.open("final.dat");
    for(i=0;i<2400;i+=2)
    {
        a = i/2;
		for(j=0;j<16;j+=2)
        {
            b = j/2;
            //cout<<key[i][j]<<' '<<cipher[i][j+1]<<' '<<key[i+1][j+1]<<' '<<cipher[i+1][j]<<' '<<endl;
			if(key[i][j] == 1 && key[i+1][j+1] == 1 && cipher[i+1][j] == 1 && cipher[i][j+1] == 1)
                data[a][b] = 1;
            else if(key[i][j+1] == 1 && key[i+1][j] == 1 && cipher[i][j] == 1 && cipher[i+1][j+1] == 1)
                data[a][b] = 1;
			else 
                data[a][b] = 0;
                
            K<<data[a][b]<<" ";
    	}
    	K<<"\n";
	}
}

int main ()
{
    
   int data[1200][8],i,j;

   fstream cp,k; 
   cp.open("cipher.dat"); 
   k.open("key_2.dat"); 
 
    for(i=0;i<1200;i++)
    	for(j=0;j<8;j++)
    		data[i][j] = 0;
	
	for(i=0;i<2400;i++)
        for(j=0;j<16;j++)
            cp>>cipher[i][j];
    	
	for(i=0;i<2400;i++)
        for(j=0;j<16;j++)
            k>>key[i][j];

    combine();
      
}

