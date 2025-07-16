#include <iostream>
#include <cstdint>
#include "order.h"
#include "orderbook.h"

Order getOrder() {
    int64_t user_id;
    double amount;
    double price;
    int side_input;
    bool side;
    
    if (!(std::cin >> user_id)) {
        throw std::invalid_argument("Invalid user_id");
    }

    if (!(std::cin >> amount) || amount <= 0) {
        throw std::invalid_argument("Invalid amount");
    }

    if (!(std::cin >> price) || price <= 0) {
        throw std::invalid_argument("Invalid price");
    }

    if (!(std::cin >> side_input) || (side_input != 0 && side_input != 1)) {
        throw std::invalid_argument("Invalid side (must be 0 or 1)");
    }
    side = static_cast<bool>(side_input);

    return Order(user_id, amount, price, side);
}

int main()
{
    Orderbook orderbook;

    while (true) {
        std::cout << "Waiting for orders {user_id, uah_amount, usd_price, side (1 - buy, 0 - sell)}... \n";

        try {
            Order new_order = getOrder();
            std::cout << std::endl;
            orderbook.addOrder(new_order);
        }
        catch (const std::invalid_argument& e) {
            std::cout << std::endl;
            std::cout << "Input error: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << std::endl;
    }
}