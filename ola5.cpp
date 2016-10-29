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
    //////////////////////////////////////////////////
    //Add your code here
    //////////////////////////////////////////////////
    return 0;
}

