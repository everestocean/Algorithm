# -*- coding=utf-8 -*-

from __future__ import absolute_import, print_function, unicode_literals

import itertools

"""
Write a function that checks whether any permutation of an input string is a palindrome. For example,
1. "civic" should return True
2. "livci" should return False
3. "icvci" should return True
4. "civil" should return False
"""


def is_palindrome(input_str):

    for i in range((len(input_str) + 1)/2):
        if input_str[i] != input_str[-i-1]:
            return False
    return True


def is_palindrome_1(input_str):
    return input_str == input_str[::-1]


if __name__ == "__main__":
    word = "civic"

    for w in itertools.permutations(word):
        word = "".join(w)
        print("Is %s palindrome using is_palindrom function? %s"  %(word, is_palindrome(word)))
        print("Is %s palindrome using is_Palindrom_1 function? %s"  %(word, is_palindrome_1(word)))
