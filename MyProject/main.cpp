#include <iostream>
#include <mysql.h>

using namespace std;

MYSQL* connectDB() {
    MYSQL* conn = mysql_init(nullptr);
    if (!conn) {
        cerr << "MySQL init failed\n";
        return nullptr;
    }

    // Change your password and user as needed
    conn = mysql_real_connect(conn, "localhost", "root", "Ycpait24", "payroll_db", 0, nullptr, 0);
    if (!conn) {
        cerr << "Connection Failed: " << mysql_error(conn) << "\n";
        return nullptr;
    }

    return conn;
}

void createEmployee(MYSQL* conn) {
    string name, position;
    double salary;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Position: ";
    getline(cin, position);
    cout << "Enter Salary: ";
    cin >> salary;

    char query[512];
    snprintf(query, sizeof(query),
             "INSERT INTO employee (name, position, salary) VALUES ('%s', '%s', %.2f)",
             name.c_str(), position.c_str(), salary);

    if (mysql_query(conn, query)) {
        cerr << "Insert Failed: " << mysql_error(conn) << "\n";
    } else {
        cout << "Employee added successfully.\n";
    }
}

void readEmployees(MYSQL* conn) {
    if (mysql_query(conn, "SELECT * FROM employee")) {
        cerr << "Select Failed: " << mysql_error(conn) << "\n";
        return;
    }

    MYSQL_RES* res = mysql_store_result(conn);
    if (!res) {
        cerr << "Store Result Failed: " << mysql_error(conn) << "\n";
        return;
    }

    MYSQL_ROW row;
    cout << "\n--- Employee List ---\n";
    while ((row = mysql_fetch_row(res))) {
        cout << "ID: " << row[0]
             << ", Name: " << row[1]
             << ", Position: " << row[2]
             << ", Salary: " << row[3] << "\n";
    }

    mysql_free_result(res);
}

void updateEmployee(MYSQL* conn) {
    int id;
    string name, position;
    double salary;

    cout << "Enter Employee ID to update: ";
    cin >> id;
    cout << "Enter new Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter new Position: ";
    getline(cin, position);
    cout << "Enter new Salary: ";
    cin >> salary;

    char query[512];
    snprintf(query, sizeof(query),
             "UPDATE employee SET name='%s', position='%s', salary=%.2f WHERE id=%d",
             name.c_str(), position.c_str(), salary, id);

    if (mysql_query(conn, query)) {
        cerr << "Update Failed: " << mysql_error(conn) << "\n";
    } else {
        cout << "Employee updated successfully.\n";
    }
}

void deleteEmployee(MYSQL* conn) {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    char query[256];
    snprintf(query, sizeof(query), "DELETE FROM employee WHERE id=%d", id);

    if (mysql_query(conn, query)) {
        cerr << "Delete Failed: " << mysql_error(conn) << "\n";
    } else {
        cout << "Employee deleted successfully.\n";
    }
}

int main() {
    MYSQL* conn = connectDB();
    if (!conn) return 1;

    int choice;
    do {
        cout << "\n--- Employee Payroll Management ---\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createEmployee(conn); break;
            case 2: readEmployees(conn); break;
            case 3: updateEmployee(conn); break;
            case 4: deleteEmployee(conn); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    mysql_close(conn);
    return 0;
}
