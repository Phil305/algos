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


def configure_logging() -> None:  # {{{
    logging.basicConfig(
        format="%(asctime)s,%(msecs)03d %(levelname)-8s [%(filename)s:%(lineno)d] %(message)s",
        datefmt="%Y-%m-%d:%H:%M:%S",
        level=logging.DEBUG,
        handlers=[logging.StreamHandler()],
    )


# }}}


def uniq_pairs(P: typing.Sequence[int]) -> list[tuple[int, int]]:  # {{{
    n = len(P)
    ret: list[tuple[int, int]] = []
    for i in range(1, n):
        for j in range(i, n):
            ret.append((P[i - 1], P[j]))
    return ret


# }}}


def dist(s: int, t: int) -> int:  # {{{
    return abs(s - t)


# }}}


def closest_pairs(P: typing.Sequence[int], n: int):  # {{{
    ret: list[tuple[int, int]] = []
    connected_nodes: set[int] = set()

    for _ in range(1, n):

        d = float("inf")
        sm = 0
        tm = 0

        for pair in uniq_pairs(P):

            if pair[0] in connected_nodes and pair[1] in connected_nodes:
                continue

            s = pair[0]
            t = pair[1]

            if dist(s, t) <= d:
                sm = s
                tm = t
                d = dist(s, t)

        connected_nodes.update((sm, tm))
        ret.append((min(sm, tm), max(sm, tm)))

    return ret


# }}}


def print_cycle(edges: typing.Sequence[tuple[int, int]]):  # {{{
    cycle: list[int] = []

    for pair in sorted(edges):

        if not cycle:
            cycle.extend(pair)
            continue

        assert cycle[-1] == pair[0]

        cycle.append(pair[1])

    cycle.append(cycle[0])

    print(cycle)


# }}}


def main():
    configure_logging()
    P: list[int] = [0, -21, 11, -5, 3, -1, 1]
    print_cycle(edges=closest_pairs(P, n=len(P)))


if __name__ == "__main__":
    main()
