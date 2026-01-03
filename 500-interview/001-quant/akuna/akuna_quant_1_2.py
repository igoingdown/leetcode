# -*- coding: utf-8 -*-

import sys
import os
import re

clear_expression = ''
fa = {}
son = {}
opsort = {'+': 0, '-': 0, '*': 1, '/': 1, '^': 2}

def calc(now):
    if now not in son:
        return clear_expression[now], 4
    L, Lop = calc(son[now][0])
    R, Rop = calc(son[now][1])
    if Lop < opsort[clear_expression[now]]:
        L = '(' + L + ')'
    if Rop < opsort[clear_expression[now]]:
        R = '(' + R + ')'
    return L + clear_expression[now] + R, opsort[clear_expression[now]]

def postfix_to_infix(expression):
    mystack = []
    global clear_expression
    clear_expression = expression.replace(' ', '')
    now = 0
    for ch in clear_expression:
        mystack.append(now)
        now += 1
        if ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '^':
            try:
                op = mystack[-1]
                rchild = mystack[-2]
                lchild = mystack[-3]
                fa[lchild] = op
                fa[rchild] = op
                son[op] = (lchild, rchild)
                mystack = mystack[:-3]
                mystack.append(op)
            except:
                return 'invalid'
    if len(mystack) != 1:
        return 'invalid'
    ret, _ = calc(now-1)
    return ret



if __name__ == '__main__':
    expression = 'ab+c/'
    print(postfix_to_infix(expression))