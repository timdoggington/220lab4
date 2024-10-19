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
	while (root->right != NULL) {
		last = last->right;
	}
	last->right = newest;
// you write
}

BSTNode *BST::find(string n) {
//you write
}

void BST::updateStatus(string name, string st) {
// you write

}
void BST::printTreeIO(BSTNode *tmp) {
// you write
}

void BST::printTreePre(BSTNode *tmp) {
// you write
}


void BST::printTreePost(BSTNode *tmp) {
// you write
}

void BST::setHeight(BSTNode *tmp) {
// you write
}

BSTNode *BST::removeNoKids(BSTNode *tmp) {
// you write
}

BSTNode *BST::removeOneKid(BSTNode *tmp,bool leftFlag) {
// you write
}
BSTNode *BST::remove(string s) {
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
	}
	else {
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






