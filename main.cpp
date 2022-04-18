/*
 * Program to implement binary search tree.
 * By: Max Shi
 * 4/4/2022
 */

#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
using namespace::std;

struct node
{
  int data;
  node* child1;
  node* child2;
};

bool isNum(char input[]);
int charToInt(char input[]);
void print(node* root, int count);
void add(node* &root, int value);
void remove();
bool search();

int main()
{
  node* tree = NULL;
  while (true) {
    cout << "Instructions:\nEnter a number or file name or SEARCH, REMOVE, PRINT, or QUIT\n";
		char input[80];
		cin.getline(input, 80, '\n');

    if(strcmp(input, "SEARCH") == 0)
    {
      cout << "Enter value to search: ";
    }
    else if(strcmp(input, "REMOVE") == 0)
    {
      cout << "Enter value to remove: ";
    }
    else if(strcmp(input, "PRINT") == 0)
    {
      print(tree, 0);
    }
    else if(strcmp(input, "QUIT") == 0)
    {
      break;
    }
    else
    {
      if (isNum(input) == true) { //if input is a number
  			add(tree, charToInt(input));
        cout << "Inserted " << input << ".\n\n";
  		} 
      else { //try to find file name
  			fstream file;
  			file.open(input);
  			if (file.is_open()) {
  				int num;
  				while (file >> num) { //read in numbers from file
  					add(tree, num);
            cout << "Inserted " << num << ".\n\n";

  				}
  			} else {
  				cout << "Error opening file.\n";
  			}
  		}
    }
    
    
    }
}

//checks if a char array contains only numbers. Source: heap project.
bool isNum(char input[]) {
	int index = 0;
	int nonDigitCount = 0;
	while (true) {
		if (input[index] == '\0') { //break at end of cstring
			break;
		} else if (isdigit(input[index]) == 0) { //count number of non digits
			nonDigitCount++;
		}
		index++;
	}

	if (nonDigitCount > 0) { //not a number if there are any non digits
		return false;
	} else {
		return true;
	}
}

//converts char array to int. Source: heap project
int charToInt(char input[]) {
	int index = 0;
	int intArr[80];
	while (true) { //finds length of input and converts each char to int
		if (input[index] == '\0') {
			break;
		} else {
			intArr[index] = input[index] - '0';
		}
		index++;
	}

	int num = 0;
	for (int i = 0; i < index; i++) { //multiplies each int in array by the appropriate power of 10 and sums
		num = num + intArr[i] * pow(10, (index - 1 - i));
	}
	return num;
}

void print(node* root, int count)
{
  if(root != NULL) 
  {
    print(root->child2, count+1);
    for(int i = 0; i < count; i++)
      {
        cout << "    ";
      }
    cout << root->data << endl;
    print(root->child1, count+1);
  }
}

void add(node* &root, int value)
{
  if(root == NULL)
  {
    node* n = new node();
    n->data = value;
    n->child1 = NULL;
    n->child2 = NULL; 
    root = n;
  }
  else if(value > root->data)
  {
    add(root->child2, value);
  }
  else
  {
    add(root->child1, value);
  }
}