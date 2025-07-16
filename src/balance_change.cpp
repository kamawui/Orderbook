#include <iostream>
#include "balance_change.h"
#include "money_utils.h"

void BalanceChange::printBalanceChange() {
	std::cout << "Balance change of user " << user_id << ":\n";
	std::cout << (value > -1 ? "+" : "");
	if (currency == "UAH") {
		std::cout << KOPtoUAH(value);
	}
	else if (currency == "USD") {
		std::cout << MICROtoUSD(value);
	}
	std::cout << " " << currency << std::endl;
}