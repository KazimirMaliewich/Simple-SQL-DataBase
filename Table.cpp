#include "Table.h"
#include <algorithm>
#include <sstream>

bool Table::evaluateCondition(const Row& row, const std::string& condition) const {
    std::istringstream iss(condition);
    std::string column, op, value;
    iss >> column >> op >> value;

    auto it = row.data.find(column);
    if (it == row.data.end()) {
        return false;
    }

    const std::string& rowValue = it->second;

    if (op == "=") {
        return rowValue == value;
    } else if (op == ">") {
        return std::stoi(rowValue) > std::stoi(value);
    } else if (op == "<") {
        return std::stoi(rowValue) > std::stoi(value);
    }

        std::cout << "Unknown command" << std::endl;
    return false;
}

void Table::updateRow(const std::unordered_map<std::string, std::string>& rowData, const std::string& whereClause) {
    std::vector<std::pair<Row*, std::unordered_map<std::string, std::string>>> changes;

    for (auto& row : rows) {
        if (evaluateCondition(row, whereClause)) {
            std::unordered_map<std::string, std::string> rowChanges;
            for (const auto& [colName, colValue] : rowData) {
                rowChanges[colName] = colValue;
            }
            changes.emplace_back(&row, std::move(rowChanges));
        }
    }

    for (auto& [row, rowChanges] : changes) {
        for (const auto& [colName, colValue] : rowChanges) {
            row->data[colName] = colValue;
        }
    }
}


void Table::deleteRows(const std::string& whereClause) {
    auto it = std::remove_if(rows.begin(), rows.end(), [&](const Row& row) {
        return evaluateCondition(row, whereClause);
    });

    int rowsDeleted = std::distance(it, rows.end());
    rows.erase(it, rows.end());

    std::cout << rowsDeleted << " rows deleted." << std::endl;
}


