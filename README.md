🚀 Overview

The Employee Payroll Management System is a console-based application built using C++ and MySQL C API (mysql.h).
This project demonstrates how a native C++ program can connect to and interact with a MySQL database without relying on high-level libraries or external frameworks such as cppconn.

It provides a simple yet effective platform for managing employee data — allowing the user to add, view, update, and delete records — and serves as a foundational learning project for understanding database-driven application development in C++.

🎯 Objectives

1.To demonstrate C++ and MySQL database connectivity using the MySQL C API.

2.To perform basic CRUD operations (Create, Read, Update, Delete) on employee records.

3.To understand query construction, error handling, and resource management in a database-connected environment.

4.To offer a lightweight and educational example for students and developers learning database integration at a low level.

🏗️ System Architecture

1. Database Layer

Database Name: payroll_db

Table Name: employee

Schema:

| Field      | Type                              | Description        |
| ---------- | --------------------------------- | ------------------ |
| `id`       | INT (Primary Key, Auto Increment) | Unique Employee ID |
| `name`     | VARCHAR(100)                      | Employee Name      |
| `position` | VARCHAR(100)                      | Employee Job Title |
| `salary`   | DECIMAL(10,2)                     | Employee Salary    |



2. Application Layer

The application uses the following MySQL C functions for database communication:

1.mysql_init() – Initializes a MySQL object.

2.mysql_real_connect() – Connects the C++ program to the MySQL server.

3.mysql_query() – Executes SQL statements.

4.mysql_store_result() – Retrieves query results.

5.mysql_fetch_row() – Iterates through rows of results.

These APIs allow low-level control over database operations while maintaining efficient performance.

⚙️ Features

✅ Add New Employee
✅ View All Employees
✅ Update Employee Details
✅ Delete Employee Records
✅ Error Handling for SQL and Connection Failures
✅ Clean Console Interface for User Interaction

💻 Technologies Used
| Component                | Technology                         |
| ------------------------ | ---------------------------------- |
| **Programming Language** | C++                                |
| **Database**             | MySQL (via MySQL Workbench)        |
| **Connector**            | MySQL C API (`mysql.h`)            |
| **IDE/Compiler**         | Code::Blocks / Visual Studio / g++ |
| **OS Compatibility**     | Windows / Linux                    |

📂 Project Structure
EmployeePayrollManagement/
│
├── main.cpp                # Entry point of the application
├── database_connection.cpp # Contains MySQL connection and CRUD logic
├── database_connection.h   # Header file with function declarations
├── README.md               # Project documentation
└── payroll_db.sql          # SQL script for creating database and table

🧠 Learning Outcomes

Understanding of database connectivity in native C++.

Hands-on practice with MySQL C API functions.

Implementation of CRUD operations without external libraries.

Reinforcement of C-style string manipulation, error handling, and query execution.

Foundation for developing advanced systems such as payroll automation, attendance tracking, or HR management tools.

🪄 How to Run the Project
Step 1: Set Up Database

Open MySQL Workbench.

Create a new database:

CREATE DATABASE payroll_db;
USE payroll_db;


Create the employee table:

CREATE TABLE employee (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    position VARCHAR(100),
    salary DECIMAL(10,2)
);

Step 2: Configure C++ Environment

Install MySQL server and ensure libmysql is accessible.

Link MySQL library while compiling:

g++ main.cpp -o payroll -lmysqlclient

Step 3: Run the Application
./payroll


Follow the on-screen console menu to manage employee records.

🧩 Example Menu
1. Add New Employee
2. View All Employees
3. Update Employee Information
4. Delete Employee
5. Exit
Enter your choice:

📘 Future Enhancements

Add Login Authentication for admin access.

Implement Salary Calculation and Slip Generation.

Add Export to CSV / PDF functionality.

Upgrade to a GUI interface using Qt or wxWidgets.

Integrate stored procedures for complex database operations.

✍️ Author

Swapnil Rathod
💼 C++ Developer | CDAC Student | Passionate about System Programming and AI
📧 [swapnilrathod5444@gmail.com]
