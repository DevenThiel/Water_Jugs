e e/*************
*
* Deven Thiel
*
* Christopher Look
*
* 04.11.2015
*
* Tree data structure implimentation
*
*************/

#include "tree.h"

//default constructor
Tree::Tree ()
{
	nodes = 0;
	root = NULL;
}
	
//default destructor
Tree::~Tree ()
{
	//delete all of the nodes recursively
	delNode(root->jug1, root->jug2);
}
	
//node functionality
void Tree::setNodes (int inint)
{
	nodes = inint;	
}

int Tree::getNodes ()
{
	return nodes;
}

void Tree::addNode (int nodeJug1, int nodeJug2)
{
	node * temp;
	
	if (root = null)
	{
		temp = new node;
		temp->jug1 = nodeJug1;
		temp->jug2 = nodeJug2;
		root = temp;
	}
	else
	{
		cout << "error, root already created";
	}
}
	
void Tree::addNode (int parJug1, int parJug2, int nodeJug1, int nodeJug2)
{
	//todo
	/*
	find parent
	add new node object as child or childs sibling
	*/
	node * parent;
	node * newNode;
	node * current;
	
	parent = findNode(parJug1, parJug2);
	
	newNode = new node;
	newNode->jug1 = nodeJug1;
	newNode->jug2 = nodeJug2;
	//point new node to parent
	newNode->parent = parent;
	
	//point parent to new node
	if (parent->child == NULL)
	{
		parent->child = newNode;
	}
	//or point sibling to new node
	else
	{
		current = parent->child;
		while(current->sibling != NULL)
		{
			current = current->sibling;
		}
		current->sibling = newNode;
	}
}
	
void Tree::delNode (int nodeJug1, int nodeJug2)
{
	node * target = NULL;
	node * current = NULL;
	target = findNode (nodeJug1, nodeJug2);
	//delete all children
	while (target->child !=NULL)
	{
		current = target->child;
		//find furthest linked sibling
		while(current->sibling != NULL)
		{
			current = current->sibling;
		}
		delNode(current->jug1, current->jug2);
	}
	//delete link from parent
	current = target->parent;
	if (current->child = target)
	{
		current->child = current->child->sibling;
	}
	//delete link from sibling
	else
	{
		current = target->parent->child;
		while (current->sibling != target)
		{
			current = current->sibling;
		}
		current->sibling = target->sibling;
	}
	//delete node
	delete target;
}
	
node * Tree::findNode (int nodeJug1, int nodeJug2)
{
	//todo	w/e traversal and find that shit
}
	
//tree functionality
void Tree::displayTree ()
{
	//todo	don't worry about this
}
	
node * Tree::bredthFirstSearch (int tarJar1, int tarJug2)
{
	//todo
}
	
node * depthFirstSearch (int tarJug1, int tarJug2)
{
	//todo
}
