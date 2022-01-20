#include <stdio.h>
#include <iostream>
using namespace std;
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include<fstream>

int key[1200][8];
int cipher[2400][16];
int rndm[8];

void zero(int x){
	int i,j;
	
	if(x==1){
		for(i=0;i<8;i++)
			rndm[i] = 0;
	}
	else if(x==2){
		for(i=0;i<1200;i++)
			for(j=0;j<8;j++)
				key[i][j] = 0;
 }
	
}

void bin(int a[8], int x){
	int i=0;
	long num, decimal_num, remainder, base = 1, binary = 0;
    decimal_num = x;
    while (x > 0)
    {
        remainder = x % 2;
        a[7-i] = remainder;
        binary = binary + remainder * base;
        x = x / 2;
        base = base * 10;
        i++;
    }
    
    
}

void bin(){
	srand(time(NULL)); 
	int i=0;
	int r = rand() % 256;
	long num, decimal_num, remainder, base = 1, binary = 0;
 	//printf("%d\n\n",r);
    decimal_num = r;
    while (r > 0)
    {
        remainder = r % 2;
        key[0][7-i] = rndm[7-i] = remainder;
        binary = binary + remainder * base;
        r = r / 2;
        base = base * 10;
        i++;
    }
    cout<<"Random Key :";
    for(i=0;i<8;i++)
    {
    	cout<<rndm[i];
	}
	cout<<"\n";
}

void print_arr(int x){
	int i,j;
	
	if(x==1){
		for(i=0;i<1200;i++){
			for(j=0;j<8;j++)
				printf("%d",key[i][j]);
			printf("\n");	
		}
	}
	else if(x==2){
		for(i=0;i<8;i++){
			printf("%d",rndm[i]);	
		}
	}
}

int CA(int x,int y,int z,int a[]){
	int i;

	//printf("\n\n");
	
	if(x == 0 && y == 0 && z == 0){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[0]<<endl;
		return a[0];
	}
	if(x == 0 && y == 0 && z == 1){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[1]<<endl;
		return a[1];
	}
	if( x == 0 && y == 1 && z == 0){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[2]<<endl;
		return a[2];
	}
	if( x == 0 && y == 1 && z == 1){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[3]<<endl;
		return a[3];
	}
	if( x == 1 && y == 0 && z == 0){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[4]<<endl;
		return a[4];
	}
	if( x == 1 && y == 0 && z == 1){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[5]<<endl;
		return a[5];
	}
	if( x == 1 && y == 1 && z == 0){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[6]<<endl;
		return a[6];
	}
	if( x == 1 && y == 1 && z == 1){
		//cout<<x<<' '<<' '<<y<<' '<<' '<<z<<' '<<a[7]<<endl;
		return a[7];
	}
}

void cellular (int a[]){
	int i,j;
	for(i=1;i<1200;i++){
		for(j=0;j<8;j++){
			if(j == 0){
				key[i][j] = CA(1,key[i-1][j],key[i-1][j+1],a);
				//printf("%d\n",key[i][j]);
			}
			else if(j == 7){
				key[i][j] = CA(key[i-1][j-1],key[i-1][j],1,a);
				//printf("%d\n",key[i][j]);
			}
			else{
				key[i][j] = CA(key[i-1][j-1],key[i-1][j],key[i-1][j+1],a);
				//printf("%d\n",key[i][j]);
			}
		}
	}
}

void encrypt_cipher(){
	int i,j,x,y;
	fstream infile;
    infile.open("ifile.dat"); 
	int image[1200][8];
	for(i=0;i<2400;i++)
		for(j=0;j<16;j++)
			cipher[i][j] = 0;	
   
    for(i=0;i<1200;i++)
    	for(j=0;j<8;j++)
    		infile>>image[i][j];

	i=0;
	for(j=0;j<8;j++)
	{
	cout<<image[i][j];
    cout<<"\n";
	}
	cout<<image[120][0];
	for(i=0;i<1200;i++)
    {
        x = 2*i;
        for(j=0;j<8;j++)
        {
            y = 2*j;
			if(image[i][j] == 1 && key[i][j] == 0)
            { 
                cipher[x][y]     = 0;
                cipher[x+1][y]   = 1;
                cipher[x][y+1]   = 1;
                cipher[x+1][y+1] = 0;
            }
            else if(image[i][j] == 0 && key[i][j] == 1)
            {
                cipher[x][y]     = 0;
                cipher[x+1][y]   = 1;
                cipher[x][y+1]   = 1;
                cipher[x+1][y+1] = 0;
            }
            else if(image[i][j] == 1 && key[i][j] == 1)
            {
            	cipher[x][y]     = 1;
                cipher[x+1][y]   = 0;
                cipher[x][y+1]   = 0;
                cipher[x+1][y+1] = 1;
			}
			else 
			{
				cipher[x][y]     = 1;
                cipher[x+1][y]   = 0;
                cipher[x][y+1]   = 0;
                cipher[x+1][y+1] = 1;
			}
        }
    }
		
	fstream c; 
    c.open("cipher.dat");
	for(i=0;i<2400;i++){
        for(j=0;j<16;j++)
            c<<cipher[i][j]<<' ';
    	c<<endl;
	}
}

void encrypt_key(){
	int i,j,x,y;
	fstream kfile;
	int a[1200][8],key_2[2400][16];
    kfile.open("key.dat"); 
	
	for(i=0;i<2400;i++)
		for(j=0;j<16;j++)
			key_2[i][j] = 0;
	
	for(i=0;i<1200;i++)
        for(j=0;j<8;j++)
            kfile>>a[i][j];
   
    for(i=0;i<1200;i++)
    {
        x = 2*i;
        for(j=0;j<8;j++)
        {
            y = 2*j;
            if(key[i][j] == 1)
            { 
                key_2[x][y]     = 0;
                key_2[x+1][y]   = 1;
                key_2[x][y+1]   = 1;
                key_2[x+1][y+1] = 0;
            }
            else if(key[i][j] == 0)
            {
                key_2[x][y]     = 1;
                key_2[x+1][y]   = 0;
                key_2[x][y+1]   = 0;
                key_2[x+1][y+1] = 1;
            }
        }
    }
		
	fstream c; 
    c.open("key_2.dat");
	for(i=0;i<2400;i++){
        for(j=0;j<16;j++)
            c<<key_2[i][j]<<' ';
    	c<<endl;
	}
}

int main(){
	int i,j;
	zero(1);
	zero(2);
	bin();
	int rule = 30;
		
	int a[8],b[8],c[8];
	for(i=0;i<8;i++)
		a[i] = 0;	
	bin(a,rule);
	cellular(a);
		
//	print_arr(1);			//key
	encrypt_key();			//encrypted key
	encrypt_cipher();		//encrypted cipher

	
	fstream k; 
    k.open("key.dat");
	
	for(i=0;i<1200;i++)
	{
        for(j=0;j<8;j++)
            k<<key[i][j]<<' ';
    k<<endl;
	}
} 
