# -*- coding=utf-8 -*-

from __future__ import absolute_import, print_function, unicode_literals


def prefix_suffix_table(text):

    """
    build prefix—suffix-table
    >>> prefix_suffix_table('ananasy')
    [-1, 0, 0, 1, 2, 3, 0, 0]
    """

    t = -1
    p = [t]

    for x in text:
        while t >= 0 and x != text[t]:
            t = p[t]
        t += 1
        p.append(t)

    return p


def KMP(needle, haystack, pst_f):
    """
    
    :param needle: 
    :param haystack: 
    :param pst_f: 
    :return: 
    """
    p = pst_f(needle)

    n_len = len(needle)
    i = 0

    pos = i - n_len

    for sym in haystack:
        while i >= 0 and needle[i] != sym:
            i = p[i]
        i += 1
        if i == n_len:
            yield pos + 1
            i = p[n_len]
        pos += 1

if __name__ == "__main__":
    for item in KMP('ana', 'ananasy', prefix_suffix_table):
        print(item)
