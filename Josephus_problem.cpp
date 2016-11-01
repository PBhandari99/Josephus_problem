// Josephus_problem implemented in linked list
// check the link for more info:
//  https://en.wikipedia.org/wiki/Josephus_problem

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

// node struct of the circular linked list:
// alphebate will hold the date which will only be a characher long
// next will me the next node pointer of NodeType.
struct NodeType    
{
	char alphebate;
	NodeType* next;	
};

class make_circular
{
public:
	int user_input() const;     // take the user input for the no. of node to skip
	void list_populator();
	int generate_no_of_node() const;
	void set_no_of_node_skip();
	int get_no_of_node_skip() const;
	void start_the_elemination(NodeType*, int);
private:
	int no_of_node_skip;  
};

// generates random number between 11 and 26 which is to be used as the no. of 
// node in the circular lisked list
int make_circular::generate_no_of_node() const  
{
	srand (time(NULL));
	return rand() % 11 + 15;
}

// takes user input as an integer which is set the number of nodes to be skipped
// during one rotation.
int make_circular::user_input() const
{
	int user_input_integer;
	cout << "Enter the number of node you want to skip: ";
	cin >> user_input_integer;

	return user_input_integer;
}

// set private variable equal to the user input
void make_circular::set_no_of_node_skip ()
{
	no_of_node_skip = user_input();
	return;
}


// creates and populates the circular linked list.
void make_circular::list_populator()
{
	string all_alphabate = "abcdefghijklmnopqrstuvwxyzhjgh";
	NodeType* head;
	head = new NodeType;
	NodeType* current;
	head->alphebate = all_alphabate[0];
	head->next = new NodeType;
	int counter = 1;
	for(current = head; counter < generate_no_of_node(); current->next = new NodeType)
	{
		current = current->next;
		current->alphebate = all_alphabate[counter];
		counter++;
	}
	current->next = head;  // makes the last node's next pointer to point to the head node.
	start_the_elemination(head, no_of_node_skip);
	return;
}

// start the elemination process where it starts deleting the nodes after
// skipping certain no. of nodes

void make_circular::start_the_elemination(NodeType* head, int no_of_node_skip)
{
	NodeType* temp = head;
	while(temp->next != temp){  // this process will continue untill only one node is left
		// will skip the node as specified in the class variable no_of_node_skip.
		for(int skip = 0; skip < no_of_node_skip; skip++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;  // eleminated the next node
		cout << temp->alphebate << endl;	
	}
	char last_one_standing = temp->alphebate;
	printf("%c\n", last_one_standing);
}

int main()
{	
	make_circular game_1;    //class instance decleration
	game_1.set_no_of_node_skip();
	game_1.list_populator();
	return 0;
}