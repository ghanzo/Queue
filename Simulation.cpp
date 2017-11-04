// Programmer: Max Goshay
// Programmer's ID: 252053
#include <iostream>
using namespace std;
#include "Queue.h"
#include "DynamicArray.h"
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>

//main customer struct
struct Customer {
	char ID;
	int arrivalTime = 0;
	int endTime = 0;
	Customer() {};
	Customer(char a, int at, int et) { ID = a; arrivalTime = at; endTime = et; };
};
//id generator
char getID(int& theCustomerIDNum) {
	if (theCustomerIDNum == 91) theCustomerIDNum -= 26;
	char ID = theCustomerIDNum;
	theCustomerIDNum++;
	return ID;
};
//service time generator
int serviceTime(int theTime, int maxService)
{
	int randomNumber = (1 + (rand() % maxService)) + theTime;
	return randomNumber;
};
//servers available? 
void availableServers(DynamicArray<Customer>& nowServing, DynamicArray<bool>& isOpen, int &numServers, int& theTime) {
	for (int i = 0; i < numServers; i++)
	{ 
		if (nowServing[i].endTime < theTime) {
			isOpen[i] = true;
			nowServing[i].ID = ' ';
			nowServing[i].endTime = 0;
		}
		else {
			isOpen[i] = false;
		}
	}
}
//for main loop break  
bool allOpen(DynamicArray<bool>& isOpen, int &numServers) {
	int all = 0;
	for (int i = 0; i < numServers; i++) {
		if (isOpen[i] == true)all++;
	}
	if (all == numServers) {
		return true;
	}
	return false;
}
//serve the customers  
void ServeCustomers(int& numServers, DynamicArray<bool>& isOpen, Queue<Customer>& line, DynamicArray<Customer>& nowServing, int & theTime, int& maxService) {
	//servers available get customers - line gets freed
	for (int i = 0; i < numServers; i++)
	{
		if (isOpen[i])
		{
			//move dude to server that is open if someone in line
			if (line.size() != 0) {
				nowServing[i] = line.front();
				line.pop();
				//give dude an end time
				nowServing[i].endTime = serviceTime(theTime, maxService);
			}
		}
		if (line.size() == 0)break;
	}
}
//the queue output
void queueOutput(const Queue<Customer>& line) {
	Queue<Customer> line2(line);
	cout << "Queue:Front<->Back\n";
	for (int i = 0; i < line.size(); i++) {
		cout << line2.front().ID;
		line2.pop();
		if (line.size() == 10 && i == 9)cout << " FULL";
	}
	cout << endl;
}
//output  
void output(int& theTime, int& numServers, DynamicArray<Customer>& nowServing, const Queue<Customer>& line)
{
	cout << "\nTime: " << theTime << "\n";
	cout << "Server:\tCustomer: EndTime:\n";
	for (int i = 0; i < numServers; i++) {
		cout << i + 1 << ": \t";
		cout << nowServing[i].ID << "\t  " << nowServing[i].endTime << endl;
	}
	queueOutput(line);
}
// requires cmath and cstdlib
int getRandomNumberOfArrivals(double averageArrivalRate)
{
	int arrivals = 0;
	double probOfnArrivals = exp(-averageArrivalRate);
	for (double randomValue = (double)rand() / RAND_MAX;
		(randomValue -= probOfnArrivals) > 0.0;
		probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
	return arrivals;
}

int main() {
	cout << endl;
	Queue<Customer> line;
	DynamicArray<bool> isOpen;
	DynamicArray<Customer> nowServing;
	int theTime = 1;
	int maxQueue = 0;
	int numServers = 0;
	int minService = 0;
	int maxService = 0;
	int programEnd = 0;
	int theCustomerIDNum = 65;
	double averageArrivalRate = 0.0;

	getRandomNumberOfArrivals(averageArrivalRate);
	
	// open the input file
	ifstream fin;
	fin.open("Simulation.txt");
	if (!fin.good()) throw "I/O error";
    char buf[100];
	int ww = 0;
	while (fin.good())
	{
		string line;
		getline(fin, line);
		strcpy(buf, line.c_str());
		if (buf[0] == 0) continue;
		double jj = stof(buf);
		ww++;
		if (ww == 1) { numServers = jj;continue; };
		if (ww == 2) { averageArrivalRate = jj;continue;};
		if (ww == 3) { maxQueue   = jj;continue;};
		if (ww == 4) { minService = jj;continue;};
		if (ww == 5) { maxService = jj;continue;};
		if (ww == 6) { programEnd = jj;fin.close();};
	}

    //Output the initial values
	cout << "number of servers:\t" << numServers << "\ncustomer arrival rate:\t" << averageArrivalRate << "per minute, for " << programEnd << " minutes\n" << "maximum queue length:\t" << maxQueue << "\nminimum service time:\t" << minService << " minutes\n" <<
		"maximum service time:\t" << maxService << " minutes \n";
	//Main Loop
	for (theTime; theTime; theTime++) {
		//find available servers  
		availableServers(nowServing, isOpen, numServers, theTime);
		//break out of main loop check
		if (theTime > programEnd && line.size() == 0) {
			if (allOpen(isOpen, numServers)) { break; }
		}
		//Add customers

		if (line.size() <= maxQueue && theTime <= programEnd) {
			//customer gets put in line
			int showedUp = getRandomNumberOfArrivals(averageArrivalRate);
			for (int x = 0; x < showedUp; x++)
			{
				if (line.size() <= maxQueue)
				{
					Customer theDude(getID(theCustomerIDNum), theTime, 0);
					line.push(theDude);
				}
			}
		}
		ServeCustomers(numServers, isOpen, line, nowServing, theTime, maxService);
		output(theTime, numServers, nowServing, line);
		cin.ignore();
	}
	//output of finished day
	cout << "\n:Now Closed:\n";
	cout << "Time is: " << theTime << "\n";
	cout << "Server:\tCustomer: EndTime:\n";
	for (int i = 0; i < numServers; i++) {
		cout << i + 1 << ": \t";
		cout << nowServing[i].ID << "\t  " << nowServing[i].endTime << endl;
	}
	cout << "work day finished\n";
	return 0;
}