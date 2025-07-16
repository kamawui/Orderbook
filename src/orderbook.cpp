#include "balance_change.h"
#include "orderbook.h"

void Orderbook::addOrder(Order& order) {
    order.order_id = next_order_id++;

    if (order.side) {
        buy_list.push(order);
    }
    else {
        sell_list.push(order);
    }

    match();
}

void Orderbook::match() {
    while (!sell_list.empty() && !buy_list.empty() && sell_list.top().price <= buy_list.top().price) {
        Order top_sell_order = sell_list.top();
        Order top_buy_order = buy_list.top();

        sell_list.pop();
        buy_list.pop();

        // final price for both buy and sell order is set buy order which was created earlier
        int64_t final_price = top_sell_order.order_id < top_buy_order.order_id ? top_sell_order.price : top_buy_order.price;
        int64_t deal_amount = std::min(top_sell_order.amount, top_buy_order.amount);
        int64_t total_price = final_price * deal_amount / 100;


        makeBalanceChange(top_sell_order.user_id, -1 * deal_amount, total_price);
        makeBalanceChange(top_buy_order.user_id, deal_amount, -1 * total_price);

        top_sell_order.amount -= deal_amount;
        top_buy_order.amount -= deal_amount;
        if (top_sell_order.amount > 0)
            sell_list.push(top_sell_order);
        if (top_buy_order.amount > 0)
            buy_list.push(top_buy_order);
    }
}

void Orderbook::makeBalanceChange(int64_t user_id, int64_t uah, int64_t usd) {
    BalanceChange uah_balance_change(user_id, uah, "UAH");
    BalanceChange usd_balance_change(user_id, usd, "USD");
    uah_balance_change.printBalanceChange();
    usd_balance_change.printBalanceChange();
}