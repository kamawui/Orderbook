#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include <queue>
#include <cstdint>
#include "Order.h"

// the order with the lowest price is on the top of sell list
class SellListComparator
{
public:
    bool operator()(const Order& o1, const Order& o2) const {
        if (o1.getPrice() != o2.getPrice())
            return o1.getPrice() > o2.getPrice();
        return o1.getOrderId() > o2.getOrderId();
    }
};

// the order with the highest price is on the top of buy list
class BuyListComparator
{
public:
    bool operator()(const Order& o1, const Order& o2) const {
        if (o1.getPrice() != o2.getPrice())
            return o1.getPrice() < o2.getPrice();
        return o1.getOrderId() > o2.getOrderId();
    }
};

class Orderbook
{
private:
    std::priority_queue<Order, std::vector<Order>, SellListComparator> sell_list;
    std::priority_queue<Order, std::vector<Order>, BuyListComparator> buy_list;

    // allows to find out which order was created earlier
    int64_t next_order_id = 0;
public:
    // adds order either to sell or buy list
    void addOrder(Order& order);

    // checks if there are matchable orders to complete
    void match();

    // stores balance changes after order complete using BalanceChange class instance, prints balance changes of both users
    void makeBalanceChange(int64_t user_id, int64_t uah, int64_t usd);
};

#endif