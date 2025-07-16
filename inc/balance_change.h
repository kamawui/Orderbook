#ifndef BALANCE_CHANGE_H
#define BALANCE_CHANGE_H

#include <cstdint>
#include <string>

class Orderbook;

class BalanceChange
{
	friend class Orderbook;
private:
	int64_t user_id;
	int64_t value;
	std::string currency;
public:
	BalanceChange(int64_t user_id, int64_t value, std::string currency)
		: user_id(user_id), value(value), currency(currency) {
	}

	void printBalanceChange();
};

#endif