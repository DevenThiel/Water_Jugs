/*************
*
* Deven Thiel
*
* Christopher Look
*
* 04.11.2015
*
* Water Jug Problem 
*
*************/

#include "waterJugs.h"

//default construtor
WaterJugs::WaterJugs ()
{
	jug1 = 0;
	jug1Range = 0;
	jug2 = 0;
	jug2Range = 0;
	max = 0;
	iSize = 0;
	jSize = 0;
	kSize = 0;
	table = NULL;
}

//build a problem from a file.
WaterJugs::WaterJugs(string fileName)
{
	jug1Range = 0;
	jug2Range = 0;
	table = NULL;
	dataFromFile(fileName);
}

//default destructor
WaterJugs::~WaterJugs ()
{
	//delete the whole table
	for(int i= 0; i < iSize; i++)
	{
		for(int j = 0; j < jSize; j++)
		{
			delete[] table[i][j];
		}
	}
}

template <typename T>
string WaterJugs::toString(T in)
{
	string c;
    stringstream s;
    s << in;
	c = s.str();
	return c;
}

string WaterJugs::stringChar (string in, int num)
{
       string c = "";
       for (int i = 0; i < num; i++)
       {
           c += in[i];
       }
     
     return c;
}

string WaterJugs::padSpace(int in)
{
	//make dynamically wide by size
    string c = "";
    
	//find how many significant digits
	int temp = in;
	int size = 0;
	
	while (temp > 0)
	{
		temp = (int)(temp / 10);
		size ++;
	}
	
	if (size < 1)
	{
		size = 1;
	}
	
	//add forward spaces
	size = max - size;
	for (int i = 0; i < size; i++)
	{
		c += " ";
	}
	
	size = max - size;
	c += stringChar(toString(in),size);
    
	return c;
}

void WaterJugs::fillCell(int A, int B, int j, int k)
{
	string answer;
	
	//create string for a
	if (A < 0)
	{
		answer = "";
		for (int a = 0; a < max; a++)
		{
			answer += " ";
		}
	}
	else
	{
	answer = padSpace(A);
	}
	
	//write string for a
	for(int a = 0; a < answer.length(); a++)
	{
		table [a][j][k] = answer[a];
	}

	//write comma
	table [max][j][k] = ',';

	//create string for b
	if (B < 0)
	{
		answer = "";
		for (int a = 0; a < max; a++)
		{
			answer += " ";
		}
	}
	else
	{
		answer = padSpace(B);
	}
	
	//write string for b
	for(int a = 0; a < answer.length(); a++)
	{
		table [max+1+a][j][k] = answer[a];
	}
}

void WaterJugs::buildTable(string fileName)
{
	out.open(fileName.c_str());
	
	table = new char**[iSize];
	for (int i = 0; i < iSize; i++)
	{
		table[i] = new char*[jSize];
		for (int j = 0; j < jSize; j++)
		{
			table[i][j] = new char[kSize];
		}
	}
	
	//zero the array
    for (int j = 0; j < jSize; j++)
	{
		for (int k = 0; k < kSize; k++)
		{
			for (int i = 0; i < iSize; i++)
			{
				table [i][j][k] = '0';
			}
		}
	}
	
	//calculate and fill the whole table
	int a = 0;
	int b = 0;
	for (int j = 0; j < jSize; j++)
	{
		for (int k = 0; k < kSize; k++)
		{
			switch (j)
			{
				case 0:
					//touple column
				
					//calculate a and b
					a = 0;
					b = 0;
				
					for (int z = 0; z < k; z++)
					{
						if (b <= jug2)
						{
							b++;
						}

						if (b > jug2)
						{
							a++;
							b = 0;
						}
					}
				
					//write cell
					fillCell(a,b,j,k);
				
					break;
				case 1:
					//column a
				
					//calculate a
					a = jug1;
				
					//calculate b
					b = 0;
					for (int c = 0; c < max; c++)
					{
						b += (table[max+1+c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//write cell
					fillCell(a,b,j,k);
					
					break;
				case 2:
					//column b
				
					//calculate a
					a = 0;
					for (int c = 0; c < max; c++)
					{
						a += (table[c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//calculate b
					b = jug2;
				
					//write cell
					fillCell(a,b,j,k);
				
					break;					
				case 3:
					//colmn c
				
					//calculate a
					a = 0;
				
					//calculate b
					b = 0;
					for (int c = 0; c < max; c++)
					{
						b += (table[max+1+c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//write cell
					fillCell(a,b,j,k);
				
					break;
				case 4:
					//column d
				
					//calculate a
					a = 0;
					for (int c = 0; c < max; c++)
					{
						a += (table[c][0][k] - '0')*pow(10,(max-1-c));
					}
					
					//calculate b
					b = 0;
				
					//write cell
					fillCell(a,b,j,k);
					
					break;
				case 5:
					//column e
				
					//calculate a and b
					a = 0;
					for (int c = 0; c < max; c++)
					{
						a += (table[c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					b = 0;
					for (int c = 0; c < max; c++)
					{
						b += (table[max+1+c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//is it legal?
                    if ( a + b >= jug2) 
                    {
                    	while (b < jug2 && a > 0)
                        {
                        	a--;
                        	b++;
                        }                    
                    }
                    else 
                    {
                	    a = -1;
						b = -1;
                    }
				
					//write cell
					fillCell(a,b,j,k);
				
					break;					
				case 6:
					//column f
				
					//calculate a and b
					a = 0;
					for (int c = 0; c < max; c++)
					{
						a += (table[c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					b = 0;
					for (int c = 0; c < max; c++)
					{
						b += (table[max+1+c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//is it legal?
					if (a + b < jug2)
					{
						a = 0;
						b = a + b;
					}
					else
					{
						a = -1;
						b = -1;
					}
				
					//write cell
					fillCell(a,b,j,k);
				
					break;							
				case 7:
					//column g
				
					//calculate a and b
					a = 0;
					for (int c = 0; c < max; c++)
					{
						a += (table[c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					b = 0;
					for (int c = 0; c < max; c++)
					{
						b += (table[max+1+c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//is it legal?
					if (a + b >= jug1)
					{
						while (a < jug1 && b > 0)
						{
							a++;
							b--;
						}
					}
					else
					{
						a = -1;
						b = -1;
					}
				
					//write cell
					fillCell(a,b,j,k);
				
					break;
				case 8:
					//column h
				
					//calculate a and b
					a = 0;
					for (int c = 0; c < max; c++)
					{
						a += (table[c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					b = 0;
					for (int c = 0; c < max; c++)
					{
						b += (table[max+1+c][0][k] - '0')*pow(10,(max-1-c));
					}
				
					//is it legal?
					if (a + b < jug1)
					{
						a = a + b;
						b = 0;
					}
					else
					{
						a = -1;
						b = -1;
					}
				
					//write cell
					fillCell(a,b,j,k);
				
					break;					
				default:
					cout << "Something went wrong with the switch!\n";
			}
		}
	}
	
	//write table to file
	//header for file only	Tree solutionTree;
	out << jug1 << ","
		<< jug2 << ","
		<< max << ","
		<< iSize << ","
		<< jSize << ","
		<< kSize << endl;
	//calculate total rows of output
	int R = ((kSize + 1) * 2) + 1;
	int k = 0;
	//each row of output
	for (int r = 0; r < R; r++)
	{
		//non-data rows
		if ( r % 2 == 0)
		{
			//write non-data line
			for (int j = 0; j < jSize; j++)
			{
				//cout << "+";
				out << "+";

				for (int i = 0; i < iSize; i++)
				{
					//cout << "-";
					out << "-";
				}
			}
			//cout << "+" <<endl;
			out << "+" << endl;
		}
		//title row
		else if (r == 1)
		{
			//cout << "|";
			out << "|";
			if (iSize < 8)
			{
				//cout << " t";
				out << " t";
				for (int i = 2; i < iSize; i++)
				{
					//cout << " ";
					out << " ";
				}
			}
			else
			{
				//cout << " touple";
				out << " touple";
				for (int i = 7; i < iSize; i++)
				{
					//cout << " ";
					out << " ";
				}
			}
			
			for (int j = 1; j < jSize; j++)
			{
				//cout << "|";
				out << "|";
				
				//cout << " " << (char)(j + 96);
				out << " " << (char)(j + 96);
				for (int i = 2; i < iSize; i++)
				{
					//cout << " ";
					out << " ";
				}
			}
			//cout << "|" << endl;
			out << "|" << endl;
			
		}
		//data rows
		else
		{
			for (int j = 0; j < jSize; j++)
			{
				//cout << "|";
				out << "|";
				
				for (int i = 0; i < iSize; i++)
				{
					//cout << table[i][j][k];
					out << table[i][j][k];
				}
			}
			//cout << "|" << endl;
			out << "|" << endl;
			k++;
		}
	}
	
	//delete the whole table
	for(int i= 0; i < iSize; i++)
	{
		for(int j = 0; j < jSize; j++)
		{
			delete[] table[i][j];
		}
	}
	
	out.close();
}

void WaterJugs::buildDatabase ()
{	
	cout << "Please input the maximum size (range of 1 to this size) you would like to build the data base for:" << endl;
	cout << "Jug 1:";
	cin >> jug1Range;
	
	cout << "Jug 2:";
	cin >> jug2Range;
	
	for (int a = 1; a <= jug1Range; a ++)
	{
		for (int b = 1; b <= jug2Range; b++)
		{
			cout << "building " << a << "x" << b << "...\n";
			
			int temp = 0;
			
			jug1 = a;
			jug2 = b;
			
			max = 0;			
			temp = a;
			if (b > temp)
			{
				temp = b;
			}
			//find number of digits in temp
			while (temp > 0)
			{
				temp = temp / 10;
				max ++;
			}
			
			jSize = 9;
			kSize = (a+1)*(b+1);
			iSize = (max*2) + 1;
			
			string name = "data/";
			name += "a";
			name += toString(a);
			name += "b";
			name += toString(b);
			name += ".txt";
			
			buildTable(name);
		}
	}
	
	cout << "\nDone.\n\n";
}

node * WaterJugs::getCell(int jug1In, int jug2In, int transIn)
{
	cout << "1: " << jug1In << " 2: " << jug2In << endl;
	if (jug1In > jug1 || jug2In > jug2)
	{
		//no transition
		cout << "out of bounds" << endl;
		return NULL;
	}
	else
	{
		int k = jug1In*(jug2+1)+jug2In;
		int j = transIn;
		
		int a = 0;
		for (int c = 0; c < max; c++)
		{
			a += (table[c][j][k] - '0')*pow(10,(max-1-c));
		}

		int b = 0;
		for (int c = 0; c < max; c++)
		{
			b += (table[max+1+c][j][k] - '0')*pow(10,(max-1-c));
		}

		node * result;
		
		result = new node;
		
		result->jug1 = a;
		result->jug2 = b;
		result->input = (char)(transIn + 96);
		
		cout << "a: " << a << " b: " << b << endl;
		
		if (a < 0 || b < 0)
		{
			return NULL;
		}
		else
		{
			return result;
		}
	}
}

string WaterJugs::displayTable(string fileName)
{
	ifstream in;
	
	in.open(fileName.c_str());
	
	if (in.is_open())
	{
		char c;
		string out = "";
		
		//skip header
		while( c != '+')
		{
			c = in.get();
		}
		
		while(((int)c >= 32 && (int)c <= 126) || c == '\n')
		{
			out += c;
			c = in.get();
		}
		
		out += "\n\n";
		
		return out;
	}
	else
	{
		return "Error opening file.";
	}
}

bool WaterJugs::dataFromFile(string fileName)
{
	ifstream in;
	
	in.open(fileName.c_str());
	
	if (in.is_open())
	{
		char temp;
		double scratch;
		int count;
		
		//header
		
		temp = in.get();
		
		for (int z = 0; z < 6; z++)
		{
			scratch = 0.0;
			count = 0;
			
			while(temp != ',' && temp != '\n')
			{
				scratch += ((int)(temp - 48))/(pow(10,count));
				count ++;
				temp = in.get();
			}
			scratch = scratch*pow(10,count-1);
			//eat ,
			temp = in.get();
				
			switch (z)
			{
				case 0:
					//jug1
					jug1 = (int)scratch;
					break;
				case 1:
					//jug2
					jug2 = (int)scratch;
					break;
				case 2:
					//max
					max = (int)scratch;
					break;
				case 3:
					//iSize
					iSize = (int)scratch;
					break;
				case 4:
					//jSize
					jSize = (int)scratch;
					break;
				case 5:
					//kSize
					kSize = (int)scratch;
					break;
			}
		}
		
		//create array			
		table = new char**[iSize];
		for (int i = 0; i < iSize; i++)
		{
			table[i] = new char*[jSize];
			for (int j = 0; j < jSize; j++)
			{
				table[i][j] = new char[kSize];
			}
		}

		//zero the array
		for (int j = 0; j < jSize; j++)
		{
			for (int k = 0; k < kSize; k++)
			{
				for (int i = 0; i < iSize; i++)
				{
					table [i][j][k] = '0';
				}
			}
		}
		
		//eat title crap
		for (int z = 0; z < 2; z++)
		{
			while (temp != '\n')
			{
				temp = in.get();
			}
			temp = in.get();
		}
					
		//actual data
		
		for (int k = 0; k < kSize; k++)
		{
			//remove non-data line
			while(temp == '+' || temp == '-' || temp == '\n')
			{
				temp = in.get();
			}
			
			for (int j = 0; j < jSize; j++)
			{
				int a = 0;
				int b = 0;
				bool dataFlag = false;
				count = 0;
				scratch = 0;			
				
				//eat |
				temp = in.get();
					
				//eat spaces
				while (temp == ' ')
				{
					temp = in.get();
				}
					
				//read in first number
				while (temp > 47 && temp < 58)
				{
					dataFlag = true;
					scratch += ((int)(temp - 48))/(pow(10,count));
					count ++;
					temp = in.get();
				}
				a = scratch*pow(10,count-1);
					
				//eat ,
				temp = in.get();
				//reset
				scratch = 0;
				count = 0;
				
				//eat spaces
				while (temp == ' ')
				{
					temp = in.get();
				}
				
				//read in second number
				while (temp > 47 && temp < 58)
				{
					dataFlag = true;
					scratch += ((int)(temp - 48))/(pow(10,count));
					count ++;
					temp = in.get();
				}
				b = scratch*pow(10,count-1);
				
				if (dataFlag)
				{
					fillCell(a,b,j,k);
				}
				else
				{
					fillCell(-1,-1,j,k);
				}
			}
			//eat end | and '\n'
			temp = in.get();
			temp = in.get();
		}		
		return true;
	}
	else
	{
		return false;
	}
}

string WaterJugs::solveDepth (int startJug1, int startJug2, int tarJug1, int tarJug2)
{
	string answer = "Depth First Solution:\n";
	node * current;
	node * next;
	
	current = new node;
	current->jug1 = startJug1;
	current->jug2 = startJug2;
	
	depthFirstSearch(current, tarJug1, tarJug2);
	next = current->child;
	
	if (next == NULL)
	{
		answer += "[";
		answer += toString(current->jug1);
		answer += ",";
		answer += toString(current->jug2);
		answer += "] Target is unreachable\n";
	}
	
	while (next != NULL)
	{
		answer += "[";
		answer += toString(current->jug1);
		answer += ",";
		answer += toString(current->jug2);
		answer += "] --";
		answer += next->input;
		answer += "--> [";
		answer += toString(next->jug1);
		answer += ",";
		answer += toString(next->jug2);
		answer += "]\n";
		current = current->child;
		next = next->child;
	}
	
	return answer;
}
	
node * WaterJugs::depthFirstSearch (node * current, int tarJug1, int tarJug2)
{
	node * optionsList;
	node * newTemp;
	node * temp;
	
	optionsList = NULL;
	newTemp = NULL;
	temp = NULL;
	
	//new linked list of possible nodes (new node)
	bool add = false;
	for (int i = 1; i < 9; i++)
	{
		add = true;
		//get the node possibility
		newTemp = getCell(current->jug1, current->jug2, i);
					
		//if it's not null
		if (newTemp == NULL)
		{
			add = false;
		}
		else
		{
			//check all the previous nodes
			temp = current;
			while (temp != NULL)
			{
				if (newTemp->jug1 == temp->jug1 && newTemp->jug2 == temp->jug2)
				{
					add = false;
				}
				temp = temp->parent;
			}
			
			//if add true, add to options list
			if (add)
			{
				if (optionsList == NULL)
				{
					//if it's the first element
					optionsList = newTemp;
				}
				else
				{
					temp = optionsList;
					//find the end of the linked list
					while (temp->child != NULL) //seg fault
					{
						temp = temp->child;
					}
					//add the new node
					temp->child = newTemp;
					newTemp->parent = temp;
				}
			}
			
		}
	}
	
	//while optionsList is not empty
	while (optionsList != NULL)
	{
		//remove the first one from the list.
		newTemp = optionsList;
		optionsList = optionsList->child;
		if (optionsList != NULL)
		{
			optionsList->parent = NULL;
		}
		newTemp->child = NULL;
		
		//add it to the path list
		current->child = newTemp;
		newTemp->parent = current;
		
		//if this option is the target
		if (newTemp->jug1 == tarJug1 && newTemp->jug2 == tarJug2)
		{
			return newTemp;
		}
		//recursive call with current option added to list
		temp = depthFirstSearch (newTemp, tarJug1, tarJug2);
		//if the recursive call returns a pointer
		if (temp != NULL)
		{
			//return the pointer we got.
			return temp;
		}
		
		//remove new node from end of list
		delete newTemp;
		current->child = NULL;
	}
		
	//none of the options on this path lead to the target, return a null to move to the next option 1 level up
	return NULL;
}

/*
string WaterJugs::solveBreadth (int startJug1, int startJug2, int tarJug1, int tarJug2)
{
	string answer = "Breadth First Solution:\n";
	node * current;
	node * next;
	
	current = new node;
	current->jug1 = startJug1;
	current->jug2 = startJug2;
	
	breadthFirstSearch(current, tarJug1, tarJug2);
	next = current->child;
	
	if (next == NULL)
	{
		answer += "[";
		answer += toString(current->jug1);
		answer += ",";
		answer += toString(current->jug2);
		answer += "] Target is unreachable\n";
	}
	
	while (next != NULL)
	{
		answer += "[";
		answer += toString(current->jug1);
		answer += ",";
		answer += toString(current->jug2);
		answer += "] --";
		answer += next->input;
		answer += "--> [";
		answer += toString(next->jug1);
		answer += ",";
		answer += toString(next->jug2);
		answer += "]\n";
		current = current->child;
		next = next->child;
	}
	
	return answer;
}
	
int WaterJugs::breadthFirstSearch (node * current, int tarJug1, int tarJug2)
{
	node * optionsList;
	node * newTemp;
	node * temp;
	
	optionsList = NULL;
	newTemp = NULL;
	temp = NULL;
	
	//very similar to depth, if target found return 1, else recurse every possible node, 
	// and choose lowest return value > 0; return 1+ that value after discrding rest of options.

	
	//new tree of possible nodes (new node)
	bool add = false;
	for (int i = 1; i < 9; i++)
	{
		add = true;
		//get the node possibility
		newTemp = getCell(current->jug1, current->jug2, i);
					
		//if it's not null
		if (newTemp == NULL)
		{
			add = false;
		}
		else
		{
			//check all the previous nodes
			temp = current;
			while (temp != NULL)
			{
				if (newTemp->jug1 == temp->jug1 && newTemp->jug2 == temp->jug2)
				{
					add = false;
				}
				temp = temp->parent;
			}
			
			//if add true, add to options list
			if (add)
			{
				if (optionsList == NULL)
				{
					//if it's the first element
					optionsList = newTemp;
				}
				else
				{
					temp = optionsList;
					//find the end of the linked list
					while (temp->child != NULL) //seg fault
					{
						temp = temp->child;
					}
					//add the new node
					temp->child = newTemp;
					newTemp->parent = temp;
				}
			}
			
		}
	}
	
	//now we have a list of all the possible nodes.
	
	//check if any are the target.
	temp = optionsList;
	while (temp != NULL)
	{
		if (temp->jug1 == tarJug1 && temp->jug2 == tarJug2)
		{
			//add to list
			current->child = temp;
			temp->parent = current;
			
			//delete rest of options
			while(optionsList != NULL)
			{
				temp = optionsList;
				optionsList = optionsList->child;
				delete temp;
			}
			
			return 1;
		}
		temp = temp->child;
	}
	
	//if target is not on this level, recurse on each option, and return the lowest value > 0 + 1
	temp = optionsList;
	while (temp != NULL)
	{
		temp->distance = breadthFirstSearch(temp, tarJug1, tarJug2);
		//next option
		temp = temp->child;
	}
	
	//find the lowest, add it, and return lowest + 1
	int lowest = 999999999;
	temp = optionsList;
	while (temp != NULL)
	{
		if (temp->distance > 0 && temp->distance < lowest)
		{
			lowest = temp->distance;
		}
	}
	temp = optionsList;
	while (temp != NULL)
	{
		if (temp->distance == lowest)
		{
			//add to list
			current->child = temp;
			temp->parent = current;
			
			//delete rest of options
			while(optionsList != NULL)
			{
				temp = optionsList;
				optionsList = optionsList->child;
				delete temp;
			}
			
			return lowest + 1;
		}
	}
		
	//if none of the options lead to the target, return 0;
	//delete rest of options
	while(optionsList != NULL)
	{
		temp = optionsList;
		optionsList = optionsList->child;
		delete temp;
	}
	
	return 0;
}
*/