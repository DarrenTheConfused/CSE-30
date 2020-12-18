#ifndef Functions_h
#define Functions_h
#include <iostream>

int max(int x, int y){
	if (x < y){
		return y;
	}
	if (x > y){
		return x;
	}
	return x;
}

bool even(int a){
	bool x = true;
	if((a % 2) == 0){
		return x;
	}
	else{
		x = false;
	}
	return x;
}

int sum(int b){
	int sum = 0;
	for (int i = 1; i <= b; i++){
		sum = i + sum;
	}
	return sum;
}

#endif
