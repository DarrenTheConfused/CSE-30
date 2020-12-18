#include <iostream>
#include <RandomSupport.h>
#include <Array.h>
#include <LinkedList.h>

using namespace std;

int main(int argc, char* argv[]){

	randomizer device = new_randomizer();
	uniform_distribution dist = new_distribution(1, 10);

	long r = sample(dist, device);

	cout << endl << "The random number is: " << r << endl << endl;

	LinkedList linkedList;
	ResizableArray array;

	for (long i = 0; i < r; i++){
		linkedList.append(i);
		array.append(i);
	}

	cout << "Linked List: " << linkedList << endl;
	cout << "Array:       " << array << endl;

	return 0;
}
