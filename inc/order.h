#ifndef ORDER_H
#define ORDER_H

#include <cstdint>
#include "money_utils.h"

class Orderbook;

class Order
{
    friend class Orderbook;
private:
    int64_t user_id;
    int64_t amount; // UAH amount in kopiyka (1 UAH = 100 KOP)
    int64_t price;  // USD micro value (1 USD = 1 000 000 micro value)
    bool side;      // buy - true, sell - false
    int64_t order_id = -1; // allows to find out which order was created earlier
public:
    Order(int64_t user_id, double amount, double price, bool side)
        : user_id(user_id), amount(UAHtoKOP(amount)), price(USDtoMICRO(price)), side(side) {
    }

    int64_t getUserId() const { return user_id; }
    int64_t getAmount() const { return amount; }
    int64_t getPrice() const { return price; }
    bool getSide() const { return side; }
    int64_t getOrderId() const { return order_id; }

    void setAmount(double amount) { this->amount = UAHtoKOP(amount); }
    void setPrice(double price) { this->price = USDtoMICRO(price); }
};

#endif