# -*- coding=utf-8 -*-

from __future__ import absolute_import, print_function, unicode_literals


class LRUCache(object):

    def __init__(self, max_items=100):
        self.cache = dict()
        self.key_order = list()
        self.max_items = max_items

    def __setitem__(self, key, value):
        self.cache[key] = value
        self._mark(key)

    def __getitem__(self, key):
        try:
            value = self.cache[key]
        except KeyError as e:
            raise KeyError, key
        self._mark(key)
        return value

    def _mark(self, key):
        if key in self.key_order:
            self.key_order.remove(key)

        self.key_order.insert(0, key)

        if len(self.key_order) > self.max_items:
            remove = self.key_order[self.max_items]
            del self.cache[remove]
            self.key_order.remove(remove)


if __name__ == "__main__":
    cache = LRUCache(2)
    cache['foo'] = 1
    cache['bar'] = 100
    cache['brz'] = 10

    try:
        cache['foo']
    except KeyError as e:
        print("{} is not exist!".format(e.message))
