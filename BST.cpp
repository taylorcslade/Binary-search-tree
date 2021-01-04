#include "Node.h"
#include "BST.h"
using namespace std;

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode() const{
		//cout << "getRootNode" << endl;
		return root;
	}

	bool BST::find(Node*& rooot, int value){
		if (rooot->data == value){
			return true;
		}

		if (value < rooot->data){
			if(rooot->leftChild == NULL){
				return false;
			}
			else {
				find(rooot->leftChild, value);
			}
		}

		else if (value > rooot->data){
			if(rooot->rightChild == NULL){
				return false;
			}
			else {
				find(rooot->rightChild, value);
			}
		}
	}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data){
		if (root == NULL){
			root = new Node(data);
			return true;
		}
		else if (find(root, data) == false){
	    return addFunction(root, data);
		}
		else {
			return false;
		}
	}

	bool BST::addFunction(Node*& rooot, int value){
		if (value < rooot->data){
			if(rooot->leftChild == NULL){
				Node *ptr = new Node(value);
				rooot->leftChild = ptr;
				return true;
			}
			else {
				addFunction(rooot->leftChild, value);
			}
		}
		else if (value > rooot->data){
			if(rooot->rightChild == NULL){
				Node *ptr = new Node(value);
				rooot->rightChild = ptr;
				return true;
			}
			else {
				addFunction(rooot->rightChild, value);
			}
		}
	}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data){
		if (find(root, data) == true){
			return removeFunction(root, data);
		}
		else {return false;}
	}

	bool BST::removeFunction(Node*& localRoot, int value){
		if(value < localRoot->data)
			removeFunction(localRoot->leftChild, value);
		else if (value > localRoot->data)
			removeFunction(localRoot->rightChild, value);
		else {
			Node *oldRoot = localRoot;
			if (localRoot->leftChild == NULL){
				localRoot = oldRoot->rightChild;
				delete oldRoot;
				return true;
			}
			else if (localRoot->rightChild == NULL){
				localRoot = oldRoot->leftChild;
				delete oldRoot;
				return true;
			}
			else {
				replace(oldRoot, localRoot->leftChild);
			}
		}
	}

	void BST::replace(Node*& oldRoot, Node *& localRoot){
		if (localRoot -> rightChild != NULL){
			replace(oldRoot, localRoot->rightChild);
		}
		else {
			oldRoot->data = localRoot->data;
			removeFunction(oldRoot->leftChild, localRoot->data);
		}
	}

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear(){
		if (root == NULL)
			return;
		else{
			clearFunction(root);
			root = NULL;
		}
	}

	void BST::clearFunction(Node* rooot){
		if(rooot->rightChild != NULL){
			clearFunction(rooot->rightChild);
		}
		if(rooot->leftChild != NULL){
			clearFunction(rooot->leftChild);
		}
		delete rooot;
	}