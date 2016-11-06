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

int main( void )
{
	//Read each set of integers from “bst.txt” and construct a binary search trees by inserting them to an empty binary
	//search tree in the given order.
	fstream myFile;				//create file variable
	myFile.open(FileName);		//open bst.dat

	int index = 0;				//declare index variable for population loops
	int treeCounter = 1;			//tree counter to be used in output later

	while(myFile >> index)		//cycle through each set of data in bst.dat
	{
		BinarySearchTree<int>* tree = new BinarySearchTree<int>;			//create tree object

		int nodeTotal = 1;					//counter for nodes, initialize to 1 due to index being read at start of loop
		tree->searchTreeInsert(index);	//insert first node

		while (index != SentinelValue)		//while loop to populate tree with data set, terminated by SentinelValue
		{	
			myFile >> index;					//read data to be inserted
			if (index != SentinelValue)		//do not inserer SentinelValue
			{
				tree->searchTreeInsert(index);	//insert node
				nodeTotal++;						//increase node count
			}
		}


		cout << "The Tree No. " << treeCounter << endl;

		//display the total number of nodes in the BST
		cout << "Number of Tree nodes: " << nodeTotal << endl;		

		//calculate the total level of the BST
		float totalLevel = tree->totalLevel();
		cout << "Total levels of the tree: " << totalLevel << endl;

		//calculate the log(n) of the BST where n is the # of nodes in the BST
		cout << "The log(n) of the tree is " << log(nodeTotal) << endl;

		//calculate the average level, i.e. total level / # of nodes
		cout << "The average level is " << (totalLevel / nodeTotal) << endl;

		//calculate the expression: AverageLevel/log(n)
		cout << "AverageLevel/log(n) is " << (totalLevel / nodeTotal) / (log(nodeTotal)) << endl;

		cout << "-----------------------------------------------" << endl;

		//When done with the tree, it needs to be cleared before inserting the next set of integers to it.
		*tree = BinarySearchTree<int>();

		treeCounter++;

	}	//end while loop

	myFile.close();
    return 0;
}

