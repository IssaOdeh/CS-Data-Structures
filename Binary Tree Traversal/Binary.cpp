#include <iostream>
#include <fstream>
#include <algorithm>
#include "Binary.h"


BinaryNode::BinaryNode() {

	this->item = 0;

	this->leftChildPtr = NULL;

	this->rightChildPtr = NULL;

}


BinaryNode::BinaryNode(const int& anItem) {

	this->item = anItem;

	this->leftChildPtr = NULL;

	this->rightChildPtr = NULL;

}


BinaryNode::BinaryNode(const int& anItem, BinaryNode* leftPtr, BinaryNode* rightPtr) {

	this->item = anItem;

	this->leftChildPtr = leftPtr;

	this->rightChildPtr = rightPtr;

}


void BinaryNode::setItem(const int& anItem) {

	this->item = anItem;

}


int BinaryNode::getItem() const {

	return this->item;

}


bool BinaryNode::isLeaf() const {

	return (this->getLeftChildPtr() == NULL) && (this->getRightChildPtr() == NULL);

}


BinaryNode* BinaryNode::getLeftChildPtr() const {

	return this->leftChildPtr;

}


BinaryNode* BinaryNode::getRightChildPtr() const {

	return this->rightChildPtr;

}


void BinaryNode::setLeftChildPtr(BinaryNode* leftPtr) {

	this->leftChildPtr = leftPtr;

}


void BinaryNode::setRightChildPtr(BinaryNode* rightPtr) {

	this->rightChildPtr = rightPtr;

}


BinarySearchTree::BinarySearchTree() {

	this->rootPtr = NULL;

}


BinarySearchTree::BinarySearchTree(const int& rootItem) {

	this->rootPtr = new BinaryNode(rootItem);

}


BinarySearchTree::BinarySearchTree(const BinarySearchTree& tree) {

	this->rootPtr = copyTree(tree.rootPtr);

}


BinarySearchTree::~BinarySearchTree() {

	this->rootPtr = NULL;

}


void BinarySearchTree::clear() {

	this->rootPtr = NULL;

}


bool BinarySearchTree::isEmpty() const {

	return this->rootPtr == NULL;

}


int BinarySearchTree::getHeight() const {

	return getHeightHelper(this->rootPtr);

}


int BinarySearchTree::getNumberOfNodes() const { 

	return getNumberOfNodesHelper(this->rootPtr);

}


int BinarySearchTree::getRootData() const {

	return rootPtr->getItem();

}


void BinarySearchTree::setRootData(const int& newData) {

	rootPtr->setItem(newData);

}


void BinarySearchTree::preorderTraverse() const {

	preorder(rootPtr);

}


void BinarySearchTree::inorderTraverse() const {

	inorder(rootPtr);

}


void BinarySearchTree::postorderTraverse() const {

	postorder(rootPtr);

}


bool BinarySearchTree::contains(const int& anEntry) const {

	bool doesContain = false;

	containsHelper(anEntry, this->rootPtr, doesContain);

	return doesContain;

}


void BinarySearchTree::containsHelper(const int& anEntry, BinaryNode* treePtr, bool& doesContain) const {

	if(treePtr != NULL) {

		containsHelper(anEntry, treePtr->getLeftChildPtr(), doesContain);

		if(treePtr->getItem() == anEntry) {

			doesContain = true;

		}

		containsHelper(anEntry, treePtr->getRightChildPtr(), doesContain);

	}

}


void BinarySearchTree::preorder(BinaryNode* treePtr) const {

	if(treePtr != NULL) {

		int theItem = treePtr->getItem();

		std::cout << theItem << " " << std::endl;

		preorder(treePtr->getRightChildPtr());

		preorder(treePtr->getLeftChildPtr());

	}

}


void BinarySearchTree::inorder(BinaryNode* treePtr) const {

	if(treePtr != NULL) {

		inorder(treePtr->getLeftChildPtr());

		int theItem = treePtr->getItem();

		std::cout << theItem << " " << std::endl;

		inorder(treePtr->getRightChildPtr());

	}

}


void BinarySearchTree::postorder(BinaryNode* treePtr) const {

	if(treePtr != NULL) {

		postorder(treePtr->getLeftChildPtr());

		postorder(treePtr->getRightChildPtr());

		int theItem = treePtr->getItem();

		std::cout << theItem << " " << std::endl;

	}

}


int BinarySearchTree::getNumberOfNodesHelper(BinaryNode* subTreePtr) const {

	if(subTreePtr == NULL) {

		return 0;

	} else {

		return 1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr()) + getNumberOfNodesHelper(subTreePtr->getRightChildPtr());

	}

}


int BinarySearchTree::getHeightHelper(BinaryNode* subTreePtr) const {

	if(subTreePtr == NULL) {

		return 0;

	} else {

		return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));

	}

}


BinaryNode* BinarySearchTree::copyTree(const BinaryNode* tree) {

	BinaryNode* newTreePtr = NULL;



	if(tree != NULL) {

		newTreePtr = new BinaryNode(tree->getItem(), NULL, NULL);



		newTreePtr->setLeftChildPtr(copyTree(tree->getLeftChildPtr()));

		newTreePtr->setRightChildPtr(copyTree(tree->getRightChildPtr()));

	}

	return newTreePtr;

}


bool BinarySearchTree::add(const int& newEntry) {

	BinaryNode* newNodePtr = new BinaryNode(newEntry);

	this->rootPtr = placeNode(rootPtr, newNodePtr);

	return true;

}


BinaryNode* BinarySearchTree::placeNode(BinaryNode* subTreePtr, BinaryNode* newNode) {

	BinaryNode* tempPtr;

	if(subTreePtr == NULL) {

		return newNode;

	} else if(subTreePtr->getItem() > newNode->getItem()) {

		tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNode);

		subTreePtr->setLeftChildPtr(tempPtr);

	} else {

		tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNode);

		subTreePtr->setRightChildPtr(tempPtr);

	}

	return subTreePtr;

}


BinaryNode* BinarySearchTree::removeValue(BinaryNode* subTreePtr, const int& target, bool& isSuccessful) {

	BinaryNode* tempPtr;

	if(subTreePtr == NULL) {

		isSuccessful = false;

	} else if(subTreePtr->getItem() == target) {

		subTreePtr = removeNode(subTreePtr);

		isSuccessful = true;

	} else if(subTreePtr->getItem () > target) {

		tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);

		subTreePtr->setLeftChildPtr(tempPtr);

	} else {

		tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);

		subTreePtr->setRightChildPtr(tempPtr);

	}

	return subTreePtr;

}


BinaryNode* BinarySearchTree::removeNode(BinaryNode* rootPtr) {

	BinaryNode* tempPtr;

	int newNodeValue = 0;

	if(rootPtr->isLeaf()) {

		rootPtr = NULL;

		return rootPtr;

	} else if(rootPtr->getLeftChildPtr() != NULL && rootPtr->getRightChildPtr() == NULL) {

		return rootPtr->getLeftChildPtr();

	} else if(rootPtr->getRightChildPtr() != NULL && rootPtr->getLeftChildPtr() == NULL) {

		return rootPtr->getRightChildPtr();

	} else {

		tempPtr = removeLeftmostNode(rootPtr->getRightChildPtr(), newNodeValue);

		rootPtr->setRightChildPtr(tempPtr);

		rootPtr->setItem(newNodeValue);

		return rootPtr;

	}

}


BinaryNode* BinarySearchTree::removeLeftmostNode(BinaryNode* treePtr, int& inorderSuccessor) {

	BinaryNode* tempPtr;

	if(treePtr->getLeftChildPtr() == NULL) {

		inorderSuccessor = treePtr->getItem();

		return removeNode(treePtr);

	} else {

		tempPtr = removeLeftmostNode(treePtr->getLeftChildPtr(), inorderSuccessor);

		treePtr->setLeftChildPtr(tempPtr);

		return treePtr;

	}

}


bool BinarySearchTree::remove(const int& target) {

	bool isSuccessful = false;

	this->rootPtr = removeValue(this->rootPtr, target, isSuccessful);

	return isSuccessful;

}


BinaryNode* BinarySearchTree::findNode(BinaryNode* treePtr, const int& target) const {

	if(treePtr == NULL) {

		return NULL;

	} else if(treePtr->getItem() == target) {

		return treePtr;

	} else if(treePtr->getItem() > target) {

		return findNode(treePtr->getLeftChildPtr(), target);

	} else {

		return findNode(treePtr->getRightChildPtr(), target);

	}

}