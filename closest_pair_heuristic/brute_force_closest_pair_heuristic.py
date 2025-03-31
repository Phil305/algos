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


def uniq_pairs(P):
    n = len(P)
    ret = []
    for i in range(1, n):
        for j in range(i, n):
            ret.append((P[i - 1], P[j]))


for pair in uniq_pairs(P=[0, -21, 11, -5, 3, -1, 1]):
    d = float("inf")
    # for k
