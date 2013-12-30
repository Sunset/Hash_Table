#include <vector>
#include <list>
using namespace std;

class ChainHashTable{
public:
	void insert(int);
	int search(int);
	ChainHashTable(int);
	void print(int);
private:
	int p;
	vector< list<int> > vect;
};

