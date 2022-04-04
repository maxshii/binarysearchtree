/*
 * Program to implement binary search tree.
 * By: Max Shi
 * 4/4/2022
 */

#include <iostream>
using namespace::std

struct node
{
  int data;
  node* child1;
  node* child2;
};

bool isNum(char input[]);
int charToInt(char input[]);
void print(node tree);
void add();
void remove();
bool search();

int main()
{
  while (true) {
		char input[80];
		cin.getline(input, 80, '\n');

		if (isNum(input) == true) { //if input is a number
			add(heap, count, charToInt(input));
			count++;
		} else { //try to find file name
			fstream file;
			file.open(input);
			if (file.is_open()) {
				int num;
				while (file >> num) { //read in numbers from file
					add(heap, count, num);
					count++;
				}
			} else {
				cout << "Error opening file.\n";
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

void print(node root, int count)
{
  if(root != NULL) 
  {
    print(root.child2, count+1);
    for(int i = 0; i < count; i++)
      {
        cout << "    ";
      }
    cout << root.data;
    print(root.child1, count+1);
  }
}