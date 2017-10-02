#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
};

class list
{
	private:
		node *head, *tail;
	public:
		list()
		{
			head = nullptr;
			tail = nullptr;
		}
		void createNode(int value)
		{
			node *temp = new node;
			temp->data = value;
			temp->next = nullptr;
			if (head == nullptr)
			{
				head = temp;
				tail = temp;
				temp = nullptr;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}

		void display()
		{
			node *temp = new node;
			temp = head;
			while (temp != nullptr)
			{
				cout << temp->data << "\t";
				temp = temp->next;
			}
		}

		void delete_first()
		{
			node *temp = new node;
			temp = head;
			head = head->next;
			delete temp;
		}
		
		void delete_last()
		{
			node *current = new node;
			node *previous = new node;
			current = head;
			while (current->next != nullptr)
			{
				previous = current;
				current = current->next;
			}
			tail = previous;
			previous->next = nullptr;
			delete current;
		}

		void delete_pos(int pos)
		{
			node *current = new node;
			node *previous = new node;
			current = head;
			for (int i = 0; i < pos; i++)
			{
				previous = current;
				current = current->next;
			}
			previous->next = current->next;
		}
		
};


void main()
{
	list ll = list();
	for (int i = 1; i < 11; i++)
	{
		ll.createNode(i);
	}
	ll.display();
	ll.delete_first();
	ll.display(); //2,3,4,5,6,7,8,9,10
	ll.delete_last();
	ll.display(); //2,3,4,5,6,7,8,9
	ll.delete_pos(3);
	ll.display(); //2,3,5,6,7,8,9

}


