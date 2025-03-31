# pyright: strict

import logging
import typing

# ClosestPair(P)
#      Let n be the number of points in set P.
#      For i = 1 to n − 1 do
#          d=∞
#          For each pair of endpoints (s, t) from distinct vertex chains
#              if dist(s, t) ≤ d then sm = s, tm = t, and d = dist(s, t)
#          Connect (sm, tm) by an edge
#      Connect the two endpoints by an edge
#
# [source: algo design manual, p.7]


def configure_logging() -> None:# {{{
    logging.basicConfig(
        format="%(asctime)s,%(msecs)03d %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s",
        datefmt="%Y-%m-%d:%H:%M:%S",
        level=logging.DEBUG,
        handlers=[logging.StreamHandler()],
    )
# }}}

def uniq_pairs(P: typing.Sequence[int]) -> list[tuple[int, int]]:# {{{
    n = len(P)
    ret: list[tuple[int,int]] = []
    for i in range(1, n):
        for j in range(i, n):
            ret.append((P[i - 1], P[j]))
    return ret
# }}}

def dist(s:int, t:int)->int:# {{{
    return abs(s - t)
# }}}

configure_logging()

P: list[int] = [0, -21, 11, -5, 3, -1, 1]
n = len(P)

closest_pairs: list[tuple[int,int]] = []
connected_pairs: set[tuple[int,int]] = set()
for i in range(1, n):
    d = float("inf")
    sm = 0
    tm = 0
    for pair in uniq_pairs(P):
        if pair in connected_pairs:
            continue

        s = pair[0]
        t = pair[1]
        if dist(s, t) <= d:
            sm = s
            tm = t
            d = dist(s, t)
    closest_pairs.append((sm, tm))
    connected_pairs.add((sm,tm))
    breakpoint()

#path: list[int] = []

# path_from_endpoints
#for pair in connected_pairs:


breakpoint()
