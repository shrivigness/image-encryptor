#include <stdio.h>
#include <iostream>
using namespace std;
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include<fstream>
#include<string>
int main()
{
	int i,j;
	string num;
	fstream k,o;
	k.open("inputfile.dat");
	o.open("ifile.dat");
	for(i=0;i<1200;i++)
	{
	k>>num;
	cout<<num;
	for(j=0;j<8;j++)
	{
	o<<num[j]<<' ';
	}
	o<<"\n";
	}
	return 0;
	}
	
	


