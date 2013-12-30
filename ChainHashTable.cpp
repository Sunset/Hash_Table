#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include "ChainHashTable.h"
using namespace std;

//creats the empty blank linked table with the empty linked lists. The constructor
ChainHashTable::ChainHashTable(int x){
	p = x;
	list <int> L1;
	for(int j = 0; j<p; j++)
	{
		vect.push_back(L1);			//complete blanked linked list
	}
}

//hashing the values into the correct slots and then chaining them to the linked list
//We are using the chained hash-insert
void ChainHashTable::insert(int k)
{
		int slot = k % p;
		vect.at(slot).push_front(k);
}

//searches through the table to find the slot where the key is located at
//will return null if value is not found
//we are using the chained hash-search
int ChainHashTable::search(int k1)
{
		int slot = k1 % p;
		//using iterators
		list<int> ::iterator start = vect.at(slot).begin();
		list<int> ::iterator end = vect.at(slot).end();

		//checking through the linked list to find the k1 value
		while(start!=end){
			if(*start == k1)
			{
				return slot;
			}
			start++;
		}return NULL;
}

//We are printing the table of the hash and the chained linked list within each slot
void ChainHashTable::print(int k1){
	FILE * F = fopen("Chained Hash.txt","w");
	
	//prints the tables
	for(int i = 0; i < p; i++)
	{
		fprintf(F, "%d: ",i);
	
		list<int> ::iterator start = vect.at(i).begin();
		list<int> ::iterator end = vect.at(i).end();

		while(start!=end){

			fprintf(F, "%d ", *start);
			start++;
		}
		fprintf(F, "\n");
	}

	//prints the slot
	int value=search(k1);
	fprintf(F, "%d\n", value);
	fclose(F);
}