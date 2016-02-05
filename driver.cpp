/*************
*
* Deven Thiel
*
* Christopher Look
*
* 04.11.2015
*
* Water Jug Problem driver 
*
*************/

#include "waterJugs.h"

bool menu (WaterJugs *buildJugs, WaterJugs *solveJugs)
{
	int menu = 0;
	while (menu < 1 || menu > 4)
	{
		cout << "What would you like to do?" << endl;
		cout << "\t1. build a database" << endl;
		cout << "\t2. display a table" << endl;
		cout << "\t3. find a solution from existing data" << endl;
		cout << "\t4. Exit" << endl;
		cout << "\t?: ";
		cin >> menu;
		
		if (menu < 1 || menu > 4)
		{
			cout << "\n\nInvalid Input, please try again.\n\n";
		}
	}
	
	string fileName = "";
	string input = "";
	
	switch (menu)
	{
		case 1:
			buildJugs->buildDatabase();
			menu = 0;
			break;
		case 2:
			int a;
			int b;
			fileName = "data/a";
			cout << "Please input the size of the jugs:" << endl;
			cout << "first jug: ";
			cin >> a;
			fileName += solveJugs->toString(a);
			fileName += "b";
			cout << "second jug: ";
			cin >> b;
			fileName += solveJugs->toString(b);
			fileName += ".txt";
		
			cout <<"\n\nTable for Jug 1: " << a << " Jug 2: " << b << endl;
				
			cout << solveJugs->displayTable(fileName);
			break;
		case 3:
			fileName = "data/a";
			cout << "Please input the size of the jugs:" << endl;
			cout << "first jug: ";
			cin >> input;
			fileName += input;
			fileName += "b";
			cout << "second jug: ";
			cin >> input;
			fileName += input;
			fileName += ".txt";
				
			if (solveJugs->dataFromFile(fileName))
			{
				int startA, startB, endA, endB;

				cout << endl;
				cout << "Loaded data.\n\n";
				cout << "Please enter the start state:" << endl;
				cout << "first jug: ";
				cin >> startA;
				cout << "second jug: ";
				cin >> startB;
				
				endA = 0;
				cout << endl;
				cout << "Please enter the goal measurement:" << endl;
				cout << "?: ";
				cin >> endB;
				cout << endl;
				
				cout << solveJugs->solveDepth(startA, startB, endA, endB);
			}
			else
			{
				cout << "That data does not yet exist in the database.\n";
			}
			menu = 0;
			break;		
		case 4:
			cout << "Exiting ...\n";
			return false;
			break;
	}
		return true;
}

int main ()
{
	WaterJugs buildJugs;
	WaterJugs solveJugs;
	
	while(menu (&buildJugs, &solveJugs));
	
	return 0;     
}