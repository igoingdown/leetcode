# -*- coding: utf-8 -*-

def min_cost(num_days, demands, max_capacity, shipping_cost, price, overnight_cost):
    l = [0]
    last = 0
    for d in demands:
        l.append(last + d)
        last += d
    f = [10000000 for _ in range(num_days + 1)]
    f[0] = 0
    for i in range(1, num_days + 1):
        for j in range(i):
            ss = l[i] - l[j]
            if ss > max_capacity:
                continue
            cost = 0
            for k in range(j + 1, i + 1):
                cost += (l[i] - l[k]) * overnight_cost
            f[i] = min(f[i], f[j] + cost + shipping_cost)
    return f[num_days] + sum(demands) * price

