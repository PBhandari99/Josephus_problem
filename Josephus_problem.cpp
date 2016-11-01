// Josephus_problem implemented in linked list

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct NodeType    // node struct of the circular linked list
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

int make_circular::generate_no_of_node() const
{
	srand (time(NULL));
	return rand() % 11 + 15;
}

int make_circular::user_input() const
{
	int user_input_integer;
	cout << "Enter the number of node you want to skip: ";
	cin >> user_input_integer;

	return user_input_integer;
}

void make_circular::set_no_of_node_skip ()
{
	no_of_node_skip = user_input();
	return;
}

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
	current->next = head;
	start_the_elemination(head, no_of_node_skip);
	return;
}

void make_circular::start_the_elemination(NodeType* head, int no_of_node_skip)
{
	NodeType* temp = head;
	while(temp->next != temp){
		for(int skip = 0; skip < no_of_node_skip; skip++)
		{
			temp = temp->next;
		}
		temp->next = temp->next->next;
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