
#include "Table.h"
#include "DataBase.h"
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

int main() {
    DataBase db;
    std::string command;

    while (std::getline(std::cin, command)) {
        std::istringstream iss(command);
        std::string keyword;
        iss >> keyword;

        if (keyword == "CREATE") {
            std::string tableName;
            std::vector<Column> columns;
            iss >> tableName;

            std::string column;
            while (iss >> column) {
//                columns.push_back(Column(columnName));
                  size_t pos = column.find(':');
                  std::string colName = column.substr(0, pos);
                  std::string colType = column.substr(pos + 1);
                  columns.push_back({colName, colType});
            }

            db.createTable(tableName, columns);
        }else if (keyword == "DROP"){

            std::string tableName;
            iss >> tableName;
            db.dropTable(tableName);

        }else if (keyword == "SELECT"){

            std::string  tableName;
            iss >> tableName;
            std::string whereClause, orderByClause;
            if (iss >> keyword && keyword == "WHERE"){
                std::getline(iss, whereClause);
            }
            if (iss >> keyword && keyword == "ORDER BY"){
                std::getline(iss, whereClause);
            }

            db.selectFromTable(tableName, whereClause, orderByClause);


        }else if (keyword == "INSERT"){

            std::string tableName;
            std::unordered_map <std::string, std::string> rowData;
            iss >> tableName;
            std::string columnData;
            while(iss >> columnData){
                size_t pos = columnData.find(':');
                std::string colName = columnData.substr(0, pos);
                std::string colValue = columnData.substr(pos + 1);
                rowData[colName] = colValue;
            }
            db.insertIntoTable(tableName, rowData);


        }else if (keyword == "UPDATE"){
            std::string tableName;
            iss >> tableName;
            std::unordered_map <std::string, std::string> updateData;
            std::string columnData;
            while(iss >> columnData && columnData != "WHERE"){
                size_t pos = columnData.find(':');
                std::string colName = columnData.substr(0, pos);
                std::string colValue = columnData.substr(pos + 1);
                updateData[colName] = colValue;
            }
            std::string whereClause;
            std::getline(iss, whereClause);
            db.updateTable(tableName, updateData, whereClause);

        }else if(keyword == "SHOW" && iss >> keyword && keyword == "TABLES"){
            db.showTable();

        }else if(keyword == "DELETE"){
            std::string tableName;
            iss >> tableName;
            std::string whereClause;
            if (iss >> keyword && keyword == "WHERE"){
                std::getline(iss, whereClause);
            }
            db.deleteFromTable(tableName, whereClause);

        }else if (keyword == "QUIT"){

            break;

        }else {
            std::cout << "Unknown Command " << keyword << std::endl;
        }
    }

    return 0;
}