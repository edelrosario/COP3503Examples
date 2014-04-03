/*
 * Name:		Elaine Del Rosario
 * Section:		6777
 * Assignment:	1
 * Due Date:	February 7, 2014
 *
 * Person class file
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include "person.h"
using namespace std;


	// Default Constructor
	Person::Person(string first, string last, int age, int friendCap) {
		this->first = first;
		this->last = last;
		this->age = age;
		this->friendCap = friendCap;
		this->amount = 0; // counter/increment value
		this->list = new Person*[friendCap];// initializes a pointer to the current person to list their friends

		try {
			if (age < 0) { // tries and catches any negative age and returns an error
				throw invalid_argument("Age cannot be negative!");
			}
		}
		catch (invalid_argument & ex) {
			cerr << ex.what() << endl;
		}
	}

	// Destructor for class Person
	Person::~Person(){
		if (list != NULL) {
			delete[] list;
		}
	}

	// Getter methods
	string Person::getFirstName() {
		return first;
	}
	string Person::getLastName() {
		return last;
	}
	int Person::getAge() {
		return age;
	}
	int Person::getFriendCap() {
		return friendCap;
	}

	Person** Person::getFriendList(int &size) { // size == friendCap
		size = this->amount; // size is a pointer to amount increment
		Person** friendList = new Person*[size];
		int i;
		for (i = 0; i < amount; i++) {
			// at every i in friendList, it will point to the corresponding i in list[]
			friendList[i] = this->list[i];
		}
		return friendList;
		// returns the current person's friends list
	}

	Person** Person:: getUncappedFriends(int &size) {
		size = friendCap - amount; // the takes the max friendCap and subtracts out the empty spaces
		Person** uncappedList = new Person*[amount];
		int i;
		for (i = 0; i < amount; i++) {
			// at every i in uncappedList, it will point to the corresponding i in list[]
			uncappedList[i] = this->list[i];
		}
		return uncappedList;
		// returns list of friends with available friendship capacity
	}

	string Person::toSimpleString() {
		// changes the int value to a string that can be returned in this method
		int value = age;
		string s_age = to_string(value);
		// a simple string that returns only the person's name and age
		string data;
		data = first + " " + last + ", Age: " + s_age;
		return data; 		// First Last, Age: <age>
	}
	string Person::toFullString() {
		// a simple string that returns only the person's name and age
		string data;
		data = toSimpleString() + '\n' + "Friends: " + '\n';
		for (int i = 0; i < amount; i++) {
			// loops for every friend on the Person's friendList
			data += '\t' + list[i]->toSimpleString() + '\n';
		}
		return data;
		/* First Last, Age: <age>
		 * Friends:
		 * 		First Last, Age: <age>
		 * 		...
		 */
	}

	bool Person::add(Person* p) {
		int i;
		for (i = 0; i < friendCap; i++) {
			if(amount >= friendCap || this->list[i] == p) {
				return false; // returns false if amount of friends exceeds friendCap
								// or if p matches the friend on at i in the list[]
			}
		}
		list[amount++] = p;
		// adds p to each amount increment until amount == friendCap
		return true;

	}

	bool Person::isCapped() {
		// returns true if friend capacity is filled, i.e. when friendCap = 0
		// returns false if capacity has not been reached, i.e. when friendCap != amount
		return friendCap == amount;
	}
