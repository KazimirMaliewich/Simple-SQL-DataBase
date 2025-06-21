#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

struct Column {
    std::string name;
    std::string type;
};

struct Row {
    std::unordered_map<std::string, std::string> data;
};

class Table {
public:
    Table() : name("") {}
    Table(const std::string& name) : name(name) {}

    std::string name;
    std::vector<Column> columns;
    std::vector<Row> rows;

    void addColumn(const std::string& columnName, const std::string& columnType) {
        columns.push_back({columnName, columnType});
    }

    void addRow(const std::unordered_map<std::string, std::string>& rowData) {
        rows.push_back({rowData});
    }

    void print() const {
        for (const auto& column : columns) {
            std::cout << column.name << "\t";
        }
        std::cout << std::endl;
        for (const auto& row : rows) {
            for (const auto& column : columns) {
                std::cout << row.data.at(column.name) << "\t";
            }
            std::cout << std::endl;
        }
    }

    void updateRow(const std::unordered_map<std::string, std::string>& rowData, const std::string& whereClause);
    void deleteRows(const std::string& whereClause);

private:
    bool evaluateCondition(const Row& row, const std::string& condition) const;
};

#endif
