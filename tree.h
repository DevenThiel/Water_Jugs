/*************
*
* Deven Thiel
*
* Christopher Look
*
* 04.11.2015
*
* Tree data structure
*
*************/

#define TREE_H
#ifndef TREE_H

struct node
{
	//data
	int jug1 = -1;
	int jug2 = -1;
	
	//connections
	node *parent = NULL;
	node *sibling = NULL;
	node *child = NULL;
}

class Tree
{
    public:
		//default constructor
    	Tree ();
	
		//default destructor
        ~Tree ();
	
		//node functionality
		void setNodes (int);
		int getNodes ();
	
		void addNode (int, int);
		void addNode (int, int, int, int);
	
		void delNode (int, int);
	
		node * findNode (int, int);
	
		//tree functionality
	
		void displayTree ();
	
		node * bredthFirstSearch (int, int);
	
		node * depthFirstSearch (int, int);
	
	private;
		//node pointers
		node *root;
	
		//number of nodes in tree
		int nodes;
};

#endif