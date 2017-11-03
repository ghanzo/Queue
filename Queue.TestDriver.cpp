#include "Queue.h"
#include <cassert>

int main() {
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

	cout << "Testing Assignment Operator = \n";
	Queue<double> e;
	e.push(2);
	cout << ":Create New Object:\t\t\n";
	cout << "EXPECTED:\t2\n";
	cout << "ACTUAL:\t\t" << e.front() << endl;
	e = a;
	cout << ":After Assignment:\t\t\n";
	cout << "EXPECTED:\t2.2\n";
	cout << "ACTUAL:\t\t" << e.front();
	assert(2.2 == e.back());
	cout << "\nPass!\n\n";

	cout << "Testing Copy Constructor \n";
	Queue<double> alpha(e);
	cout << "EXPECTED:\t2.2\n";
	cout << "ACTUAL:\t\t" << e.front();
	assert(2.2 == e.back());
	cout << "\nPass!\n\n";

	cout << "Testing Size\n";
	cout << "EXPECTED:\t2\n";
	cout << "ACTUAL:\t\t" << e.size();
	assert(2 == e.size());
	cout << "\nPass!\n\n";

	cout << "Testing Empty\n";
	e.clear();
	cout << "EXPECTED:\t1\n";
	cout << "ACTUAL:\t\t" << e.empty();
	assert(e.empty() == 1);
	cout << "\nPass!\n\n";

	cout << "Testing Clear\n";
	cout << "EXPECTED:\t1\n";
	cout << "ACTUAL:\t\t" << e.empty();
	assert(e.empty() == 1);
	cout << "\nPass!\n\n";




	cout << "Testing Queue: String\n";
	cout << "------------------\n";
	Queue<string> aa;
	assert(0 == aa.size());
	cout << "EXPECTED:\t0\n";
	cout << "ACTUAL:\t\t" << a.size() << endl;
	cout << "Pass!\n\n";

	cout << "Testing Queue::push() \n";
	cout << "Testing Queue::front() \n";
	aa.push("1.1");
	cout << "EXPECTED:\t1.1\n";
	cout << "ACTUAL:\t\t" << aa.front() << endl;
	assert("1.1" == aa.front());
	cout << "Pass!\n\n";

	cout << "Testing Queue::pop() \n";
	aa.push("2.2");
	cout << ":Before Pop:\n";
	cout << "EXPECTED:\t1.1\n";
	cout << "ACTUAL:\t\t" << aa.front() << endl;
	aa.pop();
	cout << ":After Pop:\n";
	cout << "EXPECTED:\t2.2\n";
	cout << "ACTUAL:\t\t" << aa.front() << endl;
	assert("2.2" == aa.front());
	cout << "Pass!\n\n";

	cout << "Testing Queue::back() \n";
	aa.push("3.3");
	cout << "EXPECTED:\t3.3\n";
	cout << "ACTUAL:\t\t" << aa.back() << endl;
	assert("3.3" == aa.back());
	cout << "Pass!\n\n";

	cout << "Testing Assignment Operator = \n";
	Queue<string> ee;
	ee.push("2");
	cout << ":Create New Object:\t\t\n";
	cout << "EXPECTED:\t2\n";
	cout << "ACTUAL:\t\t" << ee.front() << endl;
	ee = aa;
	cout << ":After Assignment:\t\t\n";
	cout << "EXPECTED:\t2.2\n";
	cout << "ACTUAL:\t\t" << ee.front();
	assert("2.2" == ee.back());
	cout << "\nPass!\n\n";

	cout << "Testing Copy Constructor \n";
	Queue<string> alphaa(ee);
	cout << "EXPECTED:\t2.2\n";
	cout << "ACTUAL:\t\t" << ee.front();
	assert("2.2" == ee.back());
	cout << "\nPass!\n\n";

	cout << "Testing Size\n";
	cout << "EXPECTED:\t2\n";
	cout << "ACTUAL:\t\t" << ee.size();
	assert(2 == ee.size());
	cout << "\nPass!\n\n";

	cout << "Testing Empty\n";
	ee.clear();
	cout << "EXPECTED:\t1\n";
	cout << "ACTUAL:\t\t" << ee.empty();
	assert(ee.empty() == 1);
	cout << "\nPass!\n\n";

	cout << "Testing Clear\n";
	cout << "EXPECTED:\t1\n";
	cout << "ACTUAL:\t\t" << ee.empty();
	assert(ee.empty() == 1);
	cout << "\nPass!\n\n";

	return 0;
}


