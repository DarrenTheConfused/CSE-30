#include <igloo/igloo.h>
#include <Arrays.h>

using namespace igloo;

Context(DefaultConstructorTest){
	Spec(InitialSizeAndCounterTest){
		ResizableArray arr;

		Assert::That(arr.size, Equals(1));
		Assert::That(arr.counter, Equals(0));
	}
};

Context(CopyConstructorTest){
	Spec(EmptyArraysMatch){
		ResizableArray one;
		ResizableArray two;

		Assert::That(one == two, IsTrue());
	}
};

Context(AppendFunctionTest){
	Spec(AppendFiveToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 2;
		expected.counter = 1;
		delete[] expected.data;
		expected.data = new int[2];
		expected.data[0] = 5;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}

	Spec(AppendFiveAndSevenToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 4;
		expected.counter = 2;
		delete[] expected.data;
		expected.data = new int[4];
		expected.data[0] = 5;
		expected.data[1] = 7;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);
		actual.append(7);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}

	Spec(AppendFiveSevenAndOneToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 4;
		expected.counter = 3;
		delete[] expected.data;
		expected.data = new int[4];
		expected.data[0] = 5;
		expected.data[1] = 7;
		expected.data[2] = 1;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);
		actual.append(7);
		actual.append(1);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}
	Spec(AppendFiveSevenOneAndSixToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 8;
		expected.counter = 4;
		delete[] expected.data;
		expected.data = new int[8];
		expected.data[0] = 5;
		expected.data[1] = 7;
		expected.data[2] = 1;
		expected.data[3] = 6;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);
		actual.append(7);
		actual.append(1);
		actual.append(6);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}
};

Context(InsertFunctionTest){
	Spec(InsertFiveIntoEmptyAtPositionZero){
		ResizableArray expected;
		expected.append(5);

		ResizableArray actual;
		actual.insert(0, 5);

		Assert::That(actual, Equals(expected));
	}

	Spec(InsertFiveIntoOccupiedSpace){
		ResizableArray expected;
		expected.data[] = {4};
		expected.append(5);

		ResizableArray actual;
		actual.data[] = {4};
		actual.insert(0, 5);

		Assert::That(actual, Equals(expected));
	}

	

	// Write some more tests here to convince us that your implementation is correct

};


int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
