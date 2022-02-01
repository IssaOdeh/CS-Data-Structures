#include <iostream>
#include <random>
#include <vector>
#include "Binary.h"


void insertRandomNumbers(BinarySearchTree&, BinarySearchTree&, int);


int main() {

	BinarySearchTree bst1;

	BinarySearchTree bst2;

	std::vector<int> bst2Numbers;

	int counter = 0;

	insertRandomNumbers(bst1, bst2, 100);

	std::cout <<"Height of tree: " << bst1.getHeight() << std::endl;

	std::cout << std::endl;

	bst1.inorderTraverse();

	std::cout << std::endl;

	std::cout << "Pre-order, in-order, and postorder of BST2" << std::endl;

	bst2.preorderTraverse();

	std::cout << std::endl;

	bst2.inorderTraverse();

	std::cout << std::endl;

	bst2.postorderTraverse();

	std::cout << std::endl;

	for(counter = 0; counter < 200; counter++) {

		if(bst2.contains(counter)) {

			bst2Numbers.push_back(counter);

		}

	}

	for(counter = 0; counter < 10; counter++) {

		if(bst1.remove(bst2Numbers[counter])) {

			std::cout << "Removed " << counter+1 << " numbers from BST1" << std::endl;

		}

	}

	std::cout << std::endl;

	std::cout << "Height of modified BST1 " << bst1.getHeight() << std::endl;

	std::cout << std::endl;

	std::cout << "Number of nodes of BST1 " << bst1.getNumberOfNodes() << std::endl;

	std::cout << std::endl;

	std::cout << "In-order traverse of BST1" << std::endl;

	bst1.inorderTraverse();

	std::cout << std::endl;

	std::cout << "Is BST1 empty: " << bst1.isEmpty() << std::endl;

	std::cout << "Is BST2 empty: " << bst2.isEmpty() << std::endl;

	bst1.clear();

	bst2.clear();

	std::cout << "Cleared BST1 and BST2" << std::endl;

	std::cout << "Is BST1 empty: " << bst1.isEmpty() << std::endl;

	std::cout << "Is BST2 empty: " << bst2.isEmpty() << std::endl;

	return 0;

}


void insertRandomNumbers(BinarySearchTree& tree1, BinarySearchTree& tree2, int numberToGenerate) {

	int counter = 0;

	int numberOfAdds = 0;

	int numberToAdd = 0;

	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis1(1, 200);

	std::uniform_int_distribution<> dis2(0,1);

	for(counter = 0; counter < numberToGenerate; counter++) {

		numberToAdd = dis1(gen);

		tree1.add(numberToAdd);

		if(dis2(gen) && numberOfAdds < 10) {

			tree2.add(numberToAdd);

			numberOfAdds++;

		}

	}

}
