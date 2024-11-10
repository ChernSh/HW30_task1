#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
protected:
    string title;
    string address;
    string number;
public:
    Contact(string title, string address, string number) {
        this->title = title;
        this->address = address;
        this->number = number;
    };
    virtual void show() const {};
};

class Person : public Contact {
public:
    Person(string surname, string address, string number)
        : Contact(surname, address, number) {};

    void show() const {
        cout << "Person:\n";
        cout << "Surname: " << title << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << number << "\n";
    }
};

class Colleague : public Contact {
    string fax;
    string contact_person;

public:
    Colleague(string organization, string address, string phone, string fax, string contact_person)
        : Contact(organization, address, phone)
    {
        this->fax = fax;
        this->contact_person = contact_person;
    };

    void show() const {
        cout << "Colleague:\n";
        cout << "Organization: " << title << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone: " << number << "\n";
        cout << "Fax: " << fax << "\n";
        cout << "Contact Person: " << contact_person << "\n";
    }
};

class Friend : public Contact {
    string bDate;

public:
    Friend(string surname, string address, string phone, string bDate)
        : Contact(surname, address, phone)
    {
        this->bDate = bDate;
    };
    void show() const {
        cout << "Friend:\n";
        cout << "Surname: " << title << "\n";
        cout << "Address: " << address << "\n";
        cout << "Phone Number: " << number << "\n";
        cout << "Birth Date: " << bDate << "\n";
    }
};

//class ContactContainer {
//    vector<Contact*> contacts;
//
//public:
//    void addContact(Contact* contact) {
//        contacts.push_back(contact);
//    }
//
//    void deleteContact(int index) {
//        if (index >= 0 && index < contacts.size()) {
//            contacts.erase(contacts.begin() + index);
//        }
//        else {
//            cout << "Invalid index!\n";
//        }
//    }
//
//    void showAll() const {
//        for (int i = 0; i < contacts.size(); i++) {
//            contacts[i]->show();
//            cout << "-------------------\n";
//        }
//    }
//};
