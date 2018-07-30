# -*- coding=utf-8 -*-

from __future__ import absolute_import, print_function, unicode_literals

"""
Write a function that outputs a list of tuples [(an opening parenthesis, the corresponding closing parenthesis), () ...]. 
The tuple should be an index of the position of parenthesis. For example, "(())()", the list should be [(0,3),(1,2),(4,5)]

using stack to solve this problem
"""


def parenthesis(input_str):
    op = []
    cp = []
    pair = []

    for i in range(len(input_str)):
        if s[i] == "(":
            op.append(i)
        elif s[i] == ")":
            cp.append(i)
            pair.append((op.pop(), cp.pop()))
        else:
            pass

    return pair



if __name__ == "__main__":
    s = "You know parentheses()? (Those little crescent-shaped thingies()?) Well, sometimes they drive me crazy " \
        "(overusing(), even nested ones(()), lack of clarity, fuzzy writing)"

    pair = parenthesis(s)
    print(pair)
