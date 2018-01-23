# -*- coding: utf-8 -*-

def  time_to_deliver(num_packages, delivery_sequence):
    g2h = {}
    s = set()
    for i in range(num_packages):
        g, h = delivery_sequence[i].split("-")
        s.add(g)
        if g not in g2h:
            g2h[g] = []
        g2h[g].append(int(h))
    s = list(s)
    res = 0
    if len(s) > 1:
        i = 1
        j = 1
        idle_i = 0
        idle_j = 0
        for index in range(num_packages):
            g, h = delivery_sequence[index].split("-")
            h = int(h)
            if g == s[0]:
                if abs(h - i) <= idle_i:
                    res += 1  # deliver here
                    idle_j += 1
                else:
                    res += abs(h - i) - idle_i + 1
                    idle_j += abs(h - i) - idle_i + 1
                idle_i = 0
                i = h
            else:
                if abs(h - j) <= idle_j:
                    res += 1
                    idle_i += 1
                else:
                    res += abs(h - j) - idle_j + 1
                    idle_i += abs(h - j) - idle_j + 1
                idle_j = 0
                j = h
        return res
    else:
        i = 1
        for g_h in delivery_sequence:
            g, h = g_h.split("-")
            h = int(h)
            res += abs(h - i) + 1
            i = h
        return res

if __name__ == '__main__':
    l = ["111-1", "222-1", "222-3", "111-2"]
    print(time_to_deliver(4, l))


