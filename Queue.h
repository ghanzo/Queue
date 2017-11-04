// Programmer: Max Goshay
// Programmer's ID: 252053
#ifndef Queue_d
#define Queue_d
#include <string>

template <typename V>
class Queue
{
	struct node
	{
		V     value = V();
		node* next = nullptr;
	};
	node *head = nullptr;
	node *tail = nullptr;
	node *temp = nullptr;
	int siz = 0;
public:
	Queue() {};
	Queue(const Queue<V>& other) { *this = other; };
	Queue<V>& operator=(const Queue<V>&);
	void push(const V&);
	void pop();
	V& front() { return head->value; };
	V& back() { return tail->value; };
	int size() const { return siz; };
	bool empty() const { if (siz == 0)return true; else return false; };
	void clear();
	~Queue() { clear(); };
};
//Assignment Operator =
template <typename V>
Queue<V>& Queue<V>::operator=(const Queue<V> & original)
{
	if (this != &original)
	{
		//Deallocate existing list
		while (head)
		{
			node* p = head->next;
			delete head;
			head = p;
		}
		//Build new Queue
		node* tail = 0; //temporary tail
		for (node* p = original.head; p; p = p->next)
		{
			node* temp = new node;
			temp->value = p->value;
			temp->next = 0;
			//confused here
			if (tail) tail->next = temp;
			else head = temp;
			tail = temp;
		}
		siz = original.siz;
	}
	return *this;
}
//Push
template <typename V>
void Queue<V>::push(const V& e)
{
	temp = new node;
	temp->value = e;
	if (head == nullptr) {
		head = temp;
		tail = temp;
	}
	else
		tail->next = temp;
	tail = temp;
	siz++;
}
//Pop
template <typename V>
void Queue<V>::pop()
{
	if (tail != head) {
		temp = head->next;
		delete head;
		head = temp;
	}
	else {
		tail = nullptr;
		head = nullptr;
	}
	siz--;
}
//Clear
template <typename V>
void Queue<V>::clear() {
	while (head != nullptr)
	{
		node* p = head->next;
		delete head;
		head = p;
	}
	if (head == nullptr) tail = nullptr;
	siz = 0;
}
#endif;