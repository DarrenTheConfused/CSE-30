#include <igloo/igloo.h>
#include <MemoryStuff.h>

using namespace igloo;

Context(DecimalToHexTest){
	Spec(Seven_07){
		// Check to see if we actually add a 0 in front of a single digit result
		Assert::That(decToHex(7), Equals("07"));
	}

	Spec(Fifteen_0F){
		// Check to see if hex symbols A-F are in upper case
		Assert::That(decToHex(15), Equals("0F"));
	}
	// I think the amount of tests are sufficient enough to justify the function.
	// The tests address the two main significant cases in the decimal to hex converter.
};

/*
Context(HexConverterStringTest){
	Spec(decToHexString){
		//Testing if my converter actually works
		//21312 is a random number
		Assert::That(testOutput(20), Equals(21312));
	}
};
*/

Context(MemoryContentFunctionTest){
	Spec(ThreeHundredFourteen_00_00_01_3A){
		Assert::That(memoryContents(314), Equals("3A:01:00:00")); 
	}
	
	// Your code here
	Spec(TwoThousandTwenty_What){
		Assert::That(memoryContents(2020), Equals("7E:04:00:00")); 
		// Put in the 4 correct values above in place of the xx
	}

	Spec(ZeroTest){
		//Test the format of the String
		Assert::That(memoryContents(0), Equals("00:00:00:00"));
	}

	Spec(DecToHexString){
		//Testing if my converter actually works
		//21312 is a random number
		Assert::That(testOutput(20), Equals(21312));
	}


};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
