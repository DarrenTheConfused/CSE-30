#ifndef MemoryStuff_h
#define MemoryStuff_h

#include <string>
#include <sstream>

// A helper function to convert an integer (decimal value)
// to a hexadecimal representaion saved as a string
std::string decToHex(int x){
	std::stringstream ss;
	ss << std::hex << x;
	std::string res ( ss.str() );

	// Convert the result to upper case so hex values look better
	for (int i = 0; i< res.length(); ++i){
		res[i] = std::toupper(res[i]);
	}
    	
	// If the result is only one digit, add a zero to the front
	// Example: the number 10 in hexadecimal is A
	// so this function will return 0A, which is the same thing
    if (res.size() == 1){
        res = "0" + res;
    }

	return res;
}
std::string hexa[4];

std::string memoryContents(int x){
	int *place = &x;

	for (int i = 0; i < 4; i++){
		hexa[i] = decToHex(*(place + i));
	}

	std::string newHex;

	for (int j = 0; j < 4; j++){
		if(j == 3){
			newHex += hexa[j];
		}
		else{
			newHex += hexa[j] + "::";
		}
		
	}

    return newHex;
	// The return value above is just a placeholder.
	// Make the function return the appropriate string value.
}

#endif
