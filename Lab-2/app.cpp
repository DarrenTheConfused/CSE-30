#include <iostream>
#include <MemoryStuff.h>

using namespace std;

int main(){
	int x;
    cout << "Please enter an integer: ";
    cin >> x;
	cout << "Displaying the memory contents for the giver integer" << memoryContents(x);
    return 0;
}
