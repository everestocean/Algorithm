# -*- coding=utf-8 -*-

from __future__ import absolute_import, print_function


def topological_sort(graph):

    in_degrees = dict((u, 0) for u in graph)

    for u in graph:
        for v in graph[u]:
            in_degrees[v] += 1

    Q = [u for u in graph if in_degrees[u] == 0]

    S = []

    while Q:

        u = Q.pop()
        S.append(u)
        for v in graph[u]:
            in_degrees[v] -= 1

            if in_degrees[v] == 0:
                Q.append(v)
    return S


if __name__ == "__main__":
    graph = {
        'a':'bf',
        'b':'cdf',
        'c':'d',
        'd':'ef',
        'e':'f',
        'f':''
    }

    print(topological_sort(graph))
