#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

class PhoneBook {
private:
    vector<Contact> contacts;

public:
    void addContact(const string& name, const string& phone, const string& email);

    bool deleteContact(const string& name);

    Contact* findContact(const string& name);

    bool editContact(const string& oldName, const string& newName,
        const string& newPhone, const string& newEmail);

    vector<Contact> getAllContacts() const;
};

#endif
#include <algorithm>

void PhoneBook::addContact(const string& name, const string& phone, const string& email) {
    contacts.push_back({ name, phone, email });
}

bool PhoneBook::deleteContact(const string& name) {
    auto it = remove_if(contacts.begin(), contacts.end(),
        [&name](const Contact& c) { return c.name == name; });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        return true;
    }
    return false;
}

Contact* PhoneBook::findContact(const string& name) {
    for (auto& contact : contacts) {
        if (contact.name == name) {
            return &contact;
        }
    }
    return nullptr;
}

bool PhoneBook::editContact(const string& oldName, const string& newName,
    const string& newPhone, const string& newEmail) {
    Contact* contact = findContact(oldName);
    if (contact) {
        contact->name = newName;
        contact->phone = newPhone;
        contact->email = newEmail;
        return true;
    }
    return false;
}

vector<Contact> PhoneBook::getAllContacts() const {
    return contacts;
}

void displayMenu() {
    cout << "\nPhone Book Menu:\n";
    cout << "1. Add Contact\n";
    cout << "2. Delete Contact\n";
    cout << "3. Find Contact\n";
    cout << "4. Edit Contact\n";
    cout << "5. Display All Contacts\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

void addContactUI(PhoneBook& phoneBook) {
    string name, phone, email;
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter phone: ";
    getline(cin, phone);

    cout << "Enter email: ";
    getline(cin, email);

    phoneBook.addContact(name, phone, email);
    cout << "Contact added successfully!\n";
}

void deleteContactUI(PhoneBook& phoneBook) {
    string name;
    cout << "Enter name to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    if (phoneBook.deleteContact(name)) {
        cout << "Contact deleted successfully!\n";
    }
    else {
        cout << "Contact not found!\n";
    }
}

void findContactUI(PhoneBook& phoneBook) {
    string name;
    cout << "Enter name to find: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    Contact* contact = phoneBook.findContact(name);
    if (contact) {
        cout << "Name: " << contact->name << "\n";
        cout << "Phone: " << contact->phone << "\n";
        cout << "Email: " << contact->email << "\n";
    }
    else {
        cout << "Contact not found!\n";
    }
}

void editContactUI(PhoneBook& phoneBook) {
    string oldName, newName, newPhone, newEmail;
    cout << "Enter name of contact to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, oldName);

    cout << "Enter new name: ";
    getline(cin, newName);

    cout << "Enter new phone: ";
    getline(cin, newPhone);

    cout << "Enter new email: ";
    getline(cin, newEmail);

    if (phoneBook.editContact(oldName, newName, newPhone, newEmail)) {
        cout << "Contact updated successfully!\n";
    }
    else {
        cout << "Contact not found!\n";
    }
}

void displayAllContactsUI(PhoneBook& phoneBook) {
    auto contacts = phoneBook.getAllContacts();
    if (contacts.empty()) {
        cout << "No contacts in the phone book!\n";
        return;
    }

    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << "\n";
        cout << "Phone: " << contact.phone << "\n";
        cout << "Email: " << contact.email << "\n";
        cout << "-----------------\n";
    }
}

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: addContactUI(phoneBook); break;
        case 2: deleteContactUI(phoneBook); break;
        case 3: findContactUI(phoneBook); break;
        case 4: editContactUI(phoneBook); break;
        case 5: displayAllContactsUI(phoneBook); break;
        case 6: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}