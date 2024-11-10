#include <iostream>
#include "Contacts.h"

int main()
{
    vector<Contact*> phoneBook;
    int i;

    do {
        cout << "++++++++++++++++++++++++++++++++++\n";
        cout << "Menu:\n";
        cout << "++++++++++++++++++++++++++++++++++\n";
        cout << "\t1. Add Person\n";
        cout << "\t2. Add Colleague\n";
        cout << "\t3. Add Friend\n";
        cout << "\t4. Show All Contacts\n";
        cout << "\t5. Delete Contact\n";
        cout << "\t0. Exit\n";
        cout << "++++++++++++++++++++++++++++++++++\n";

        cout << "Your choice: ";
        cin >> i;

        switch (i) {
        case 1: {
            string surname, address, phone;
            cout << "Enter surname: ";cin >> surname;
            cout << "Enter address: ";cin >> address;
            cout << "Enter phone: ";cin >> phone;
            phoneBook.push_back(new Person(surname, address, phone));
            break;
        }
        case 2: {
            string organization, address, phone, fax, contact_person;
            cout << "Enter organization: ";cin >> organization;
            cout << "Enter address: ";cin >> address;
            cout << "Enter phone: ";cin >> phone;
            cout << "Enter Fax: ";cin >> fax;
            cout << "Enter contact person: ";cin >> contact_person;
            phoneBook.push_back(new Colleague(organization, address, phone, fax, contact_person));
            break;
        }
        case 3: {
            string surname, address, phone, birth_date;
            cout << "Enter Surname: ";cin >> surname;
            cout << "Enter Address: ";cin >> address;
            cout << "Enter Phone Number: ";cin >> phone;
            cout << "Enter Birth Date: ";
            cin >> birth_date;
            phoneBook.push_back(new Friend(surname, address, phone, birth_date));
            break;
        }
        case 4:
            for (int i = 0; i < phoneBook.size(); i++) {
                cout << "\t#" << (i + 1) << endl;
                phoneBook[i]->show();
                cout << "-------------------\n";
            }
            break;
        case 5: {
            int index;
            cout << "Enter index of contact to delete: ";  cin >> index;
            index--;
            if (index >= 0 && index < phoneBook.size()) {
                phoneBook.erase(phoneBook.begin() + index);
            }
            else {
                cout << "Invalid index!\n";
            }
            break;
        }
        case 0:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (i != 0);

    return 0;
}
