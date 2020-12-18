#include <iostream>
#include <Functions.h>

using namespace std;

int main(){
	bool x = true;
	x = even(0);
	if(x == false){
		cout << "Zero is not an even number." << endl;
	}
	else{
		cout << "Zero is an even number." << endl;
	}
	int y = 0;
	y = sum(100);
	cout << "The sum of 100 is: ";
    cout << y << endl;
    return 0;
}
