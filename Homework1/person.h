/*
 * Name:		Elaine Del Rosario
 * Section:		6777
 * Assignment:	1
 * Due Date:	February 7, 2014
 *
 * Header file
 */

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
using namespace std;

class Person
{
public:
	Person (string first, string last, int age, int friendCap);

	~Person();

	bool add(Person* p);
	string toSimpleString();
	string toFullString();
	string getFirstName();
	string getLastName();
	int getAge();
	int getFriendCap();
	Person** getFriendList(int &size);
	bool isCapped();
	Person** getUncappedFriends(int &size);

private:
	string first; // person's first name
	string last; // person's last name
	int age; // person's age
	int friendCap; // friendship capacity
	Person** list; // friends list array
	int amount; // counter
};

#endif /* PERSON_H_ */
