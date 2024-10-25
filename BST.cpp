#include "BST.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

/**************************************************************/
/* These are the methods you are to write for a BST           */
/* More Detailed Instructions can be found in the doc and in  */
/* the BST.hpp file                                           */
/**************************************************************/

BST::BST(string n, string st, string descr, bool Xtra) {
	 root = new BSTNode(n, st, descr);
	 Xt = Xtra;
//you write
}

bool BST::insert(string n, string st, string descr) {
	BSTNode *newest = new BSTNode(n, st, descr);
	BSTNode *last = root;
	if (root == NULL) {
		root = newest;
	} else {
		while (last->right != NULL || last->left != NULL) {
			if (last->left == NULL && newest->animal->name < last->animal->name) {
				break;
			} else if (last->right == NULL && newest->animal->name > last->animal->name) {
				break;
			}
			if (last->animal->name > newest->animal->name) {
				last = last->left;

			} else if (last->animal->name < newest->animal->name) {
				last = last->right;
			}
		}
	}

	if (last != NULL) {
		if (newest->animal->name < last->animal->name) {
			last->left = newest;
			newest->parent = last;
		} else if (newest->animal->name > last->animal->name) {
			last->right = newest;
			newest->parent = last;
		}
	}
	setHeight(newest);
	return true;
// you write
}

BSTNode *BST::find(string n) {
	BSTNode *last = root;
	int found = 0;
	if (root == NULL) {
		return NULL;
	} else {
		while (last->right != NULL || last->left != NULL) {
			if (n == last->animal->name) {
				found = 1;
				break;
			} else if (n < last->animal->name && last->left == NULL) {
				break;
			} else if (n > last->animal->name && last->right == NULL) {
				break;
			} else if (n < last->animal->name) {
				last = last->left;
			} else if (n > last->animal->name) {
				last = last->right;
			}
		}
	}
	if (last->animal->name == n) {
		found = 1;
	}
	if (found == 1) {
		cout << "Found:" << last->animal->name << endl;
		cout << "Status:" << last->animal->status << endl;
		return last;
	} else {
		cout << n << ":Not found" << endl;
		return NULL;
	}
//you write
}

void BST::updateStatus(string name, string st) {
// you write
	find(name)->animal->status = st;
}

void BST::printTreeIO(BSTNode *tmp) {
// you write
	if (tmp == NULL) {
		return;
	} else {
		printTreeIO(tmp->left);
		tmp->printNode(false);
		printTreeIO(tmp->right);
	}
}


void BST::printTreePre(BSTNode *tmp) {
// you write
	if (tmp == NULL) {
		return;
	} else {
		tmp->printNode(false);
		printTreePre(tmp->left);
		printTreePre(tmp->right);
	}
}



void BST::printTreePost(BSTNode *tmp) {
//you write
	if (tmp == NULL) {
		return;
	} else {
		printTreePre(tmp->left);
		printTreePre(tmp->right);
		tmp->printNode(false);
	}
}
void BST::setHeight(BSTNode *tmp) {
	while (tmp != NULL) {
		if (tmp->right == NULL && tmp->left == NULL) {
			tmp->height = 1;
		} else if (tmp->right == NULL && tmp->left != NULL) {
			tmp->height = tmp->left->height+1;
		} else if (tmp->right != NULL && tmp->left == NULL) {
			tmp->height = tmp->right->height+1;
		} else if (tmp->right->height >= tmp->left->height) {
			tmp->height = tmp->right->height+1;
		} else {
			tmp->height = tmp->left->height+1;
		}
		tmp = tmp->parent;
	}
// you write
}

BSTNode *BST::removeNoKids(BSTNode *tmp) {
	if (tmp != root) {
		if (tmp->parent->left == tmp) {
			tmp->parent->left = NULL;
		} else {
			tmp->parent->right = NULL;
		}
	}
	delete tmp;
	return NULL;
// you write
}

BSTNode *BST::removeOneKid(BSTNode *tmp,bool leftFlag) {
	if (leftFlag) {
		// left is null
		if (tmp->parent->animal->name > tmp->animal->name) {
			tmp->right->parent = tmp->parent;
			tmp->parent->left = tmp->right;
		} else {
			tmp->right->parent = tmp->parent;
			tmp->parent->right = tmp->right;
		}
	} else {
		if (tmp->parent->animal->name > tmp->animal->name) {
			tmp->left->parent = tmp->parent;
			tmp->parent->right = tmp->left;
		} else {
			tmp->left->parent = tmp->parent;
			tmp->parent->left = tmp->left;
		}
	}
	delete tmp;
	return NULL;
// you write
}
BSTNode *BST::remove(string s) {
	BSTNode *last = root;
	int found = 0;
	if (root == NULL) {
		return NULL;
	} else {
		while (last->right != NULL || last->left != NULL) {
			if (s == last->animal->name) {
				found = 1;
				break;
			} else if (s < last->animal->name && last->left == NULL) {
				break;
			} else if (s > last->animal->name && last->right == NULL) {
				break;
			} else if (s < last->animal->name) {
				last = last->left;
			} else if (s > last->animal->name) {
				last = last->right;
			}
		}
	}
	if (last->animal->name == s) {
		found = 1;
	}
	if (found == 1) {
	//last now equals the node to be removed
		if (last->left == NULL && last-> right == NULL) {
			removeNoKids(last);
		} else if (last->left != NULL && last->right == NULL) {
			removeOneKid(last, false);
		} else if (last->left == NULL && last->right != NULL) {
			removeOneKid(last, true);
		} else {
			BSTNode *temp = last;
			temp = last->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			//temp now equals leftmost node from right child
			last->animal->name = temp->animal->name;
			last->animal->status = temp->animal->status;
			last->animal->info = temp->animal->info;
			BSTNode *copy = temp->parent;
			delete temp;
			setHeight(copy);
		}
	}
	return NULL;
// you write
}

/**************** Written for you  ***********************/

BST::BST(bool Xtra) {
	root = NULL;
	Xt = Xtra;
}


void BST::clearTree() {
	if (root == NULL) {
		cout << "Tree already empty" << endl;
	}
	else {
		cout << endl << "Clearing Tree:" << endl;
		clearTree(root);
		root = NULL;
	}
}
void BST::clearTree(BSTNode *tmp) {
	if (tmp == NULL) {
		return;
	} else {
		clearTree(tmp->left);
		clearTree(tmp->right);
		tmp->printNode(Xt);
		delete(tmp);
	}
}
void BST::printTreePost() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PostOrder:" <<endl;
		printTreePost(root);
	}
}

void BST::printTreePre() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing PreOrder:" <<endl;
		printTreePre(root);
	}
}

void BST::printTreeIO() {
	if (root == NULL ) {
		cout << "Empty Tree" << endl;
	}
	else {
		cout << endl<<"Printing In Order:" <<endl;
		printTreeIO(root);
	}
}
