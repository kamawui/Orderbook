#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include "order.h"
#include "orderbook.h"

Order getOrder(const std::string& input) {
    std::istringstream iss(input);
    int64_t user_id;
    double amount;
    double price;
    int side_input;
    bool side;

    if (!(iss >> user_id)) {
        throw std::invalid_argument("Invalid user_id");
    }

    if (!(iss >> amount) || amount <= 0) {
        throw std::invalid_argument("Invalid amount");
    }

    if (!(iss >> price) || price <= 0) {
        throw std::invalid_argument("Invalid price");
    }

    if (!(iss >> side_input) || (side_input != 0 && side_input != 1)) {
        throw std::invalid_argument("Invalid side (must be 0 or 1)");
    }
    side = static_cast<bool>(side_input);

    return Order(user_id, amount, price, side);
}


int main()
{
    Orderbook orderbook;
    std::string input;

    std::cout << "Waiting for orders...\n";

    while (true) {
        std::cout << "Enter order in format {user_id, uah_amount, usd_price, side (1 - buy, 0 - sell)} or q to exit:\n";

        std::getline(std::cin, input);
        if (input == "q" || input == "Q") {
            std::cout << "Exiting...\n";
            break;
        }

        try {
            Order new_order = getOrder(input);
            std::cout << std::endl;
            orderbook.addOrder(new_order);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Input error: " << e.what() << '\n';
        }

        std::cout << std::endl;
    }
}