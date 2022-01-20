#include <stdio.h>
#include <iostream>
using namespace std;
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include<fstream>
#include<string>
int main()
{
	int i,j,temp,sum=0;
	int num;
	fstream k,o;
	k.open("final.dat");
	o.open("decimal.dat");
	o<<"[";
	for(i=0;i<1200;i++)
	{
	sum=0;
	for(j=0;j<8;j++)
	{
	k>>num;
	cout<<num;
	temp=7-j;
	sum=sum+num*pow(2,temp);	
	}
	cout<<"\n";
	o<<sum<<";";
	o<<"\n";
	}
	o<<"]";
	return 0;
	}
	
	


