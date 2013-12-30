#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include "ChainHashTable.h"
#include "HashLinear.h"
using namespace std;

int main(int argc, char * argv[]) {
	if (argc<2){
		printf("Error: include the name of the input file as an argument\n");
		getchar();
	}

	FILE * F = fopen(argv[1],"r");
	
	int number, p, numOfKeys, key, k1;
	float alpha;

	fscanf(F,"%d",&p); //p value

	fscanf(F,"%f",&alpha); //alpha value
	fscanf(F,"%d",&numOfKeys); //number of keys that need to be inserted into the hash table
	vector<int> vect;
	for (int i = 0; i <numOfKeys; i++)
	{
		fscanf(F,"%d",&key); //keys to hash into (reading in n inputs from previous number)
		vect.push_back(key);
	}
	fscanf(F,"%d",&k1); //value for k1
	fclose(F);

	ChainHashTable table(p);
	HashLinear table1(p);
	for(int j = 0; j < numOfKeys; j++){
		table.insert(vect.at(j));
		table1.insert(vect.at(j));
	}
	table.print(k1);

	table1.print1(k1);
getchar();
}