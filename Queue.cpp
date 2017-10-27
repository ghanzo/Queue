#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

template <typename V>
class Queue
{
  struct node
  {
    V     value = V();
    node* next  = nullptr;
  };
  node *head;
  node *tail;
  node *temp;
  int siz = 0;

public:
  Queue( ); // may have a defaulted parameter
  Queue(const Queue<V>&); // copy constructor
  ~Queue();
  Queue<V>& operator=(const Queue<V>&);
  void push(const V&);
  V& front( ); // return a mutable reference to the oldest node
  V& back( ); // return a mutable reference to the newest node
  void pop( ); // remove the oldest node
  int size( ) const;
  bool empty( ) const{if (siz == 0) return true;};
  void clear( );
}; 

//Default Constructor
template <typename V>
Queue<V>::Queue(){
  head = nullptr;
  tail = nullptr;
  temp = nullptr;
  int siz = 0;
}

//Destructor
template <typename V>
Queue<V>::~Queue()
{
  while(tail)
  {
  node* temp = tail;
  tail = tail->next;
  delete temp;    
  }
}

//Copy Constructor
template <typename V>
Queue<V>::Queue(const Queue<V>& original)
{
  head = 0;
  node* tail = 0; //temporary tail
  siz = original.siz;
  for (  node* p = original.head; p; p = p->next)
  {
    node* temp  = new node;
    temp->value = p->value;
    temp->next  = 0;
    
    if (tail) tail->next = temp;
    else head   = temp;
    tail = temp;
  }
}

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
    for (node* p = original.head; p; p= p->next)
    {
      node* temp  = new node;
      temp->value = p->value;
      temp->next  = 0;
      
      if (tail) tail->next = temp;
      else head   = temp;
      tail    = temp;
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
  temp-> value = e;
  if (head == nullptr){
      head =  temp;
      tail =  temp;
  }
  else 
  head-> next = temp;
  head = temp;
  siz++;
}

//Front Value
template <typename V>
V& Queue<V>::front( ){
 return tail->value; 
}

//Back Value
template <typename V>
V& Queue<V>::back( ){
 return head->value; 
}

//Pop
template <typename V>
void Queue<V>::pop()
{
  if   (tail!= head)    
        tail = tail->next;
  else {tail = nullptr;
        head = nullptr;}
  siz--;      
}

//Size
template <typename V>
int Queue<V>::size() const{
  return siz;
}

//Clear
template <typename V>
void Queue<V>::clear(){
  head = nullptr;
  tail = nullptr;
}

  
int main (){
  cout << "Testing Queue: double\n";
  cout << "------------------\n";
	Queue<double> a;
	assert(0 == a.size());
	cout << "EXPECTED:\t0\n";
	cout << "ACTUAL:\t\t" << a.size() << endl;
	cout << "Pass!\n\n";

  cout << "Testing Queue::push() \n";
  cout << "Testing Queue::front() \n";
  a.push(1.1);
	cout << "EXPECTED:\t1.1\n";
	cout << "ACTUAL:\t\t" << a.front() << endl;
	assert(1.1 == a.front());
	cout << "Pass!\n\n";
	
	cout << "Testing Queue::pop() \n";
  a.push(2.2);
  cout << ":Before Pop:\n";
	cout << "EXPECTED:\t1.1\n";
	cout << "ACTUAL:\t\t" << a.front() << endl;
	a.pop();
	cout << ":After Pop:\n";
	cout << "EXPECTED:\t2.2\n";
	cout << "ACTUAL:\t\t" << a.front() << endl;
	assert(2.2 == a.front());
	cout << "Pass!\n\n";
	
	cout << "Testing Queue::back() \n";
  a.push(3.3);
	cout << "EXPECTED:\t3.3\n";
	cout << "ACTUAL:\t\t" << a.back() << endl;
	assert(3.3 == a.back());
	cout << "Pass!\n\n";
	
	Queue<double> e;
  
  return 0;
}


