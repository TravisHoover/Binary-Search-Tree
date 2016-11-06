#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

#include "BST.h"

//The name of the file containing binary search trees
const string    FileName = "bst.dat";

//The value indicating the end of a binary search tree
// in the file FileName
const int       SentinelValue = -1;

//If you need to count the number of nodes in a Binary 
//Search Tree of integers, please traverse the tree by passing
//the following function as the parameter.
//Remember, every time you count the number of nodes,
//you have to initialize nodeCount by 0
int nodeCount = 0;
void nodeNum(int& nodeValue)
{
    nodeCount ++;
}


int main( void )
{
	
	//Read each set of integers from �bst.txt� and construct a binary search trees by inserting them to an empty binary
	//search tree in the given order.
	fstream myFile;
	myFile.open("bst.dat");

	int index = 0;
	int treeCounter = 1;

	while(myFile >> index)		//cycle through each set of data in bst.dat
	{
		BinarySearchTree<int>* tree = new BinarySearchTree<int>;
		int nodeTotal = 1;
		tree->searchTreeInsert(index);

		while (index != SentinelValue)
		{	
			myFile >> index;
			tree->searchTreeInsert(index);
			nodeTotal++;

		}

		nodeTotal--; //subtract one to compensate for while loop always executing nodeTotal+1 times

		cout << "The Tree No. " << treeCounter << endl;

		//For each constructed binary search tree, perform followings:
		//1.	calculate the total number of nodes in the BST
		cout << "Number of Tree nodes: " << nodeTotal << endl;		//total nodes should be equal to number of inputs from data set

		//2.	calculate the total level of the BST
		cout << "Total levels of the tree: " << tree->totalLevel() << endl;

		//3.	calculate the log(n) of the BST where n is the # of nodes in the BST
		float logN = log(tree->totalLevel());
		cout << "The log(n) of the tree is " << logN << endl;

		//4.	calculate the average level, i.e. total level / # of nodes
		float AverageLevel = (tree->totalLevel() / nodeTotal);
		cout << "The average level is " << AverageLevel << endl;

		//5.	calculate the expression: AverageLevel/log(n)*/
		cout << "AverageLevel/log(n) is " << AverageLevel / logN << endl;

		cout << "-----------------------------------------------" << endl;

		//When you are done with the tree, you need to clear it before inserting the next set of integers to it. You can use the
			//following statement for this purpose:
		*tree = BinarySearchTree<int>();

		treeCounter++;

	}	//end while loop

	myFile.close();
    return 0;
}

