#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"
#include <iostream>
#include <string>
#include <unordered_map>

class DataBase {
public:
    std::unordered_map<std::string, Table> tables;

    void createTable(const std::string& tableName, const std::vector<Column>& columns) {
        tables[tableName] = Table(tableName);
        for (const auto& column : columns) {
            tables[tableName].addColumn(column.name, column.type);
        }
        std::cout << "Table '" << tableName << "' created." << std::endl;
    }

    void dropTable(const std::string& tableName) {
        tables.erase(tableName);
        std::cout << "Table '" << tableName << "' dropped." << std::endl;
    }

    void insertIntoTable(const std::string& tableName, const std::unordered_map<std::string, std::string>& rowData) {
        if (tables.find(tableName) != tables.end()) {
            tables[tableName].addRow(rowData);
            std::cout << "Row inserted into table '" << tableName << "'." << std::endl;
        } else {
            std::cout << "Table '" << tableName << "' does not exist." << std::endl;
        }
    }

    void selectFromTable(const std::string& tableName, const std::string& whereClause, const std::string& orderByClause) const {
        if (tables.find(tableName) != tables.end()) {
            tables.at(tableName).print();
        } else {
            std::cout << "Table '" << tableName << "' does not exist." << std::endl;
        }
    }

    void updateTable(const std::string& tableName, const std::unordered_map <std::string, std::string>& updateData, const std::string& whereClause){
        if (tables.find(tableName) != tables.end()){
            std::cout << tableName << std::endl;
            tables[tableName].updateRow(updateData, whereClause);
        }else {
            std::cout << "Table '" << tableName << "' does not exist." << std::endl;
        }
    }
    void showTable(){
        for (const auto &table: tables){
            std::cout << table.first << std::endl;
        }
    }
    void deleteFromTable(const std::string& tableName, const std::string& whereClause){
        if (tables.find(tableName) != tables.end()){
            tables[tableName].deleteRows(whereClause);
        }else {
            std::cout << "Table '" << tableName << "' does not exist." << std::endl;
        }
    }
};

#endif