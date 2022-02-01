#include <iostream>
#include <vector>

class Sort {
	public:
		void generateDataSet(int);
		void clearDataSet();
		void bubbleSort(std::vector<int>&, int, int);
		void quickSort(std::vector<int>, int, int);
		void avg(int);
		void clearTotals();

		std::vector<int> getDataSet();

	private:
		std::vector<int> dataSet;
		std::vector<double> sortTimes;
		std::vector<int> totalComparisons;
		std::vector<double> totalSwaps;

		int partition(std::vector<int>&, int, int, int&, double&);
		void sortFirstMiddleLast(std::vector<int>&, int, int, int, int&, double&);
		void quickSort(std::vector<int>&, int, int, int&, double&);
};
