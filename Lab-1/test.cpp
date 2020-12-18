#include <Functions.h>
#include <iostream>
#include <igloo/igloo.h>

using namespace igloo;

Context(MaxFunctionTests){

	Spec(OneGreaterThanZero){
		Assert::That(max(1,0), Equals(1));
	}

	Spec(ZeroLessThanOne){
		Assert::That(max(0,1), Equals(1));
	}

	Spec(FiveGreaterThanTwo){
		Assert::That(max(5,2), Equals(5));
	}

	Spec(SevenLessThanNine){
		Assert::That(max(7,9), Equals(9));
	}
};
Context(EvenFunctionTests){

	Spec(TwoIsEven){
		Assert::That(even(2), Equals(true));
	}
	Spec(ThreeIsOdd){
		Assert::That(even(3), Equals(false));
	}

};

Context(SumFunctionTests){
	Spec(SumUpToTwo){
		Assert::That(sum(2), Equals(3));
	}
	Spec(SumUpToThree){
		Assert::That(sum(3), Equals(6));
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
