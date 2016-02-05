/*************
*
*	Deven Thiel
*
*	04.17.2015
*
*	WaterJug class to solve the classic problem
*
*************/

#ifndef WATERJUG_H
#define WATERJUG_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

struct node
{
	//data
	int jug1;
	int jug2;
	char input;
	
	//connections
	node *parent;
	node *child;
};

class WaterJugs
{
	public:
		//default constructor
		WaterJugs ();
	
		//build a problem from a file.
		WaterJugs (string);
	
		//default destructor
		~WaterJugs ();
	
		template <typename T>
		string toString(T);
	
		string stringChar (string, int);
	
		string padSpace(int);
	
		void fillCell (int,int, int, int);
	
		void buildTable (string);
	
		void buildDatabase ();
	
		node * getCell (int, int, int);
	
		string displayTable(string);
	
		bool dataFromFile (string);
	
		string solveDepth (int, int, int, int);
	
		node * depthFirstSearch (node *, int, int);
	
	private:
		//transition table
		char *** table;
	
		ofstream out;
	
		int jug1;
		
		int jug1Range;
	
		int jug2;
	
		int jug2Range;
	
		int max;
	
		int iSize;
	
		int jSize;
	
		int kSize;
};

#endif