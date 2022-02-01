#include <iostream>
#include <cstdlib>
#include "Sort.h"

int main() {

	Sort testObj;
	int counter = 0;

// generate 1000
	std::cout << "Sorting for 1,000 numbers" << std::endl;
	testObj.generateDataSet(1000);
	std::vector<int> dataSet = testObj.getDataSet();

	for(counter = 0; counter < 10; counter++) {
		dataSet = testObj.getDataSet();
		testObj.bubbleSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Bubble Sort Results" << std::endl;
	testObj.avg(10);
	std::cout << std::endl;

	for(counter = 0; counter < 10; counter++) {
		dataSet = testObj.getDataSet();
		testObj.quickSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Quick Sort Results" << std::endl;
	testObj.avg(10);
	std::cout << std::endl;

	std::cout << std::endl;
	testObj.clearDataSet();
	dataSet = testObj.getDataSet();
	

// sorted 1000
	std::cout << "Testing sorted 1,000 list" << std::endl;
	for(counter = 0; counter < 10; counter++) {
		testObj.bubbleSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Bubble Sort Results" << std::endl;
	testObj.avg(10);
	std::cout << std::endl;

	for(counter = 0; counter < 10; counter++) {
		testObj.quickSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Quick Sort Results" << std::endl;
	testObj.avg(10);
	std::cout << std::endl;


// generate 10000
	std::cout << "Sorting for 10,000 numbers" << std::endl;
	testObj.generateDataSet(10000);
	dataSet = testObj.getDataSet();

	for(counter = 0; counter < 10; counter++) {
		testObj.bubbleSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Bubble Sort Results" << std::endl;
	dataSet = testObj.getDataSet();
	testObj.avg(10);
	std::cout << std::endl;

	for(counter = 0; counter < 10; counter++) {
		testObj.quickSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Quick Sort Results" << std::endl;
	dataSet = testObj.getDataSet();
	testObj.avg(10);
	std::cout << std::endl;
	testObj.clearDataSet();
	testObj.clearTotals();


// sorted 10000
	std::cout << "Testing sorted 10,000 list" << std::endl;
	for(counter = 0; counter < 10; counter++) {
		testObj.bubbleSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Bubble Sort Results" << std::endl;
	testObj.avg(10);
	std::cout << std::endl;

	for(counter = 0; counter < 10; counter++) {
		testObj.quickSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Quick Sort Results" << std::endl;
	testObj.avg(10);
	std::cout << std::endl;


//generate 100000
	std::cout << "Sorting for 100,000 numbers" << std::endl;
	testObj.generateDataSet(100000);
	dataSet = testObj.getDataSet();

	for(counter = 0; counter < 1; counter++) {
		testObj.bubbleSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Bubble Sort Results" << std::endl;
	dataSet = testObj.getDataSet();
	testObj.avg(1);
	std::cout << std::endl;

	for(counter = 0; counter < 1; counter++) {
		testObj.quickSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Quick Sort Results" << std::endl;
	testObj.avg(1);
	std::cout << std::endl;
	testObj.clearDataSet();
	testObj.clearTotals();


// sorted 100000
	std::cout << "Testing sorted 100,000 list" << std::endl;
	for(counter = 0; counter < 10; counter++) {
		testObj.bubbleSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Bubble Sort Results" << std::endl;
	testObj.avg(1);
	std::cout << std::endl;

	for(counter = 0; counter < 10; counter++) {
		testObj.quickSort(dataSet, 0, dataSet.size());
	}
	std::cout << "Quick Sort Results" << std::endl;
	testObj.avg(1);
	std::cout << std::endl;

	return 0;
}

