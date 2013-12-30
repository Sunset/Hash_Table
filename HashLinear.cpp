#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include "HashLinear.h"
using namespace std;

//Constructor for the hashlinear file. makes the empty table
HashLinear::HashLinear(int x)
{
	p = x;
	for(int j = 0; j<p;j++)
	{
		vect1.push_back(NULL);
	}
}

//inserts k through the mod function and inserts it at the slot
//we are doing a hash insert linear procedure
void HashLinear::insert(int k){
int slot = k % p;
//checks if the location is taken, if it is, it'll go on to the next slot and mod it again with p to find a new location
while (vect1.at(slot) != NULL)
{
	slot = (slot + 1)%p;
}
	vect1.at(slot) =k;
}

//goes through the table to find the key
//we are doing a hash search linear procedure
 vector<int> HashLinear::search(int k1)
{
	vector <int> Vektor;
	int slot = k1 % p;
	int i = 0;
	
	//if the location of the supposed slot is taken
	while (vect1.at(slot) != NULL && i < p)
	{
		//if the value at the slot IS equal, return the vector
		if (k1 == vect1.at(slot))
		{
			Vektor.push_back(slot);
			return Vektor;
		}
		//if the value at that slot is not equal, add the value of the slot to a vector
		//and continue one to the next slot
		else
		{
			Vektor.push_back(slot);
		}
		slot = (slot + 1)%p;
		i++;
	}
}

 //prints the table
void HashLinear::print1(int k1){
	FILE * F = fopen("Linear Hash.txt","w");
	
	//prints the table numbers
	for(int i = 0; i < p; i++)
	{
		fprintf(F, "%d: ",i);
		//prints the value at their specific spots of the table
		if(vect1.at(i) != NULL){
			fprintf(F, "%d ", vect1.at(i));
		}
		fprintf(F, "\n");
	}
	//prints the slots that was probed to find the k1 value
	vector<int> vec = search(k1);
	for(int j = 0; j<vec.size(); j++)
	{
		fprintf(F, "%d ", vec.at(j));
	}
	fclose(F);
}