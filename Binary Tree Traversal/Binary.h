#include <iostream>


class BinaryNode {

	public:

		BinaryNode();

		BinaryNode(const int& anItem);

		BinaryNode(const int& anItem, BinaryNode* leftPtr, BinaryNode* rightPtr);

		void setItem(const int& anItem);

		int getItem() const;

		bool isLeaf() const;

		BinaryNode* getLeftChildPtr() const;

		BinaryNode* getRightChildPtr() const;

		void setLeftChildPtr(BinaryNode* leftPtr);

		void setRightChildPtr(BinaryNode* rightPtr);


	private:

		int item;

		BinaryNode* leftChildPtr;

		BinaryNode* rightChildPtr;

};


class BinarySearchTree {

	public:

		BinarySearchTree();

		BinarySearchTree(const int& rootItem);

		BinarySearchTree(const BinarySearchTree& tree);

		~BinarySearchTree();

		bool isEmpty() const;

		int getHeight() const;

		int getNumberOfNodes() const;

		int getRootData() const;

		void setRootData(const int& newData);

		bool add(const int& newEntry);

		bool remove(const int& target);

		void clear();

		int getEntry(const int& anEntry);

		bool contains(const int& anEntry) const;

		void preorderTraverse() const;

		void inorderTraverse() const;

		void postorderTraverse() const;

		BinarySearchTree& operator=(const BinarySearchTree& rightHandSide);


	private:

		BinaryNode* rootPtr;

		BinaryNode* copyTree(const BinaryNode* tree);

		BinaryNode* placeNode(BinaryNode* subTreePtr, BinaryNode* newNode);

		BinaryNode* removeValue(BinaryNode* subTreePtr, const int& target, bool& isSuccessful);

		BinaryNode* removeNode(BinaryNode* rootPtr);

		BinaryNode* removeLeftmostNode(BinaryNode* treePtr, int& inorderSuccessor);

		BinaryNode* findNode(BinaryNode* treePtr, const int& target) const;

		int getHeightHelper(BinaryNode* subTreePtr) const;

		int getNumberOfNodesHelper(BinaryNode* subTreePtr) const;

		void containsHelper(const int&, BinaryNode*, bool&) const;

		void preorder(BinaryNode* treePtr) const;

		void inorder(BinaryNode* treePtr) const;

		void postorder(BinaryNode* treePtr) const;

};
