#ifndef MONEY_UTILS_H
#define MONEY_UTILS_H

#include <cstdint>
#include <cmath>

#define MICRO 1000000

inline int64_t UAHtoKOP(double uah) {
    return static_cast<int64_t>(round(uah * 100));
}

inline int64_t USDtoMICRO(double usd) {
    return static_cast<int64_t>(round(usd * MICRO));
}

inline double KOPtoUAH(int64_t kop) {
    return kop / 100.0;
}

inline double MICROtoUSD(int64_t micro_usd) {
    return micro_usd / static_cast<double>(MICRO);
}

#endif