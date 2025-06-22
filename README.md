# DataBase2_0

A simple in-memory database system written in C++. This project provides a command-line interface for basic SQL-like operations such as creating tables, inserting, updating, selecting, and deleting rows, as well as dropping tables and listing all tables.

## Features
- Create and drop tables with custom columns and types
- Insert, update, select, and delete rows
- List all tables
- Simple SQL-like command syntax
- In-memory storage (data is not persisted)

## Build Instructions

This project uses CMake and requires a C++20 compatible compiler (e.g., GCC, Clang, MSVC).

```sh
git clone git@github.com:KazimirMaliewich/Simple-SQL-DataBase.git
 cd DataBase2_0
```

```bash
git clone https://github.com/KazimirMaliewich/Simple-SQL-DataBase.git
```
# Create a build directory
mkdir build
cd build

# Generate build files with CMake
cmake ..

# Build the project
cmake --build .
```

The resulting executable will be named `DataBase2_0` or `DataBase2_0.exe` (on Windows).

## Usage
Run the executable and enter commands in the terminal. Supported commands:

### Create a Table
```
CREATE <table_name> <col1:type1> <col2:type2> ...
```
Example:
```
CREATE users id:int name:string age:int
```

### Drop a Table
```
DROP <table_name>
```

### Insert a Row
```
INSERT <table_name> <col1:val1> <col2:val2> ...
```
Example:
```
INSERT users id:1 name:Alice age:30
```

### Select Rows
```
SELECT <table_name> [WHERE <col> <op> <val>]
```
Example:
```
SELECT users WHERE age > 25
```

### Update Rows
```
UPDATE <table_name> <col1:val1> ... WHERE <col> <op> <val>
```
Example:
```
UPDATE users age:31 WHERE name = Alice
```

### Delete Rows
```
DELETE <table_name> WHERE <col> <op> <val>
```
Example:
```
DELETE users WHERE id = 1
```

### Show All Tables
```
SHOW TABLES
```

### Quit
```
QUIT
```

## Notes
- All data is stored in memory and will be lost when the program exits.
- Only basic condition evaluation is supported in WHERE clauses (e.g., `=`, `>`, `<`).
- Column types are not strictly enforced beyond string/integer parsing for conditions.