#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-prototypes"
void setUp(void) {}

void tearDown(void) {}
#pragma clang diagnostic pop

/* ClosestPair(P)
 *      Let n be the number of points in set P.
 *      For i = 1 to n − 1 do
 *          d=∞
 *          For each pair of endpoints (s, t) from distinct vertex chains
 *              if dist(s, t) ≤ d then sm = s, tm = t, and d = dist(s, t)
 *          Connect (sm, tm) by an edge
 *      Connect the two endpoints by an edge
 *
 * [source: algo design manual, p.7]
 */

static int dist(int n1, int n2) {
    return abs(n1 - n2);
}

static void endpoint_pairs(int ret[][2], int const endpoints[], int len) {
    for (int i = 0; i < len; i++) {
        int j = i;
        if (i == 0) {
            j = len;
        }
        ret[i][0] = endpoints[j - 1];
        ret[i][1] = endpoints[i];
    }
}

static void print_pairs(int pairs[][2], int const len) {
    for (int i = 0; i < len; i++) {
        printf("(%d, %d)\n", pairs[i][0], pairs[i][1]);
    }
}

int main(void) {
    int P[] = {0, -21, 11, -5, 3, -1, 1};
    int pairs[sizeof(P) / sizeof(int)][2] = {0};
    /// int ordered_pairs[sizeof(P)/sizeof(int)] = {0};

    endpoint_pairs(/*ret=*/pairs, /*endpoints=*/P, /*len=*/sizeof(P) / sizeof(int));
    print_pairs(pairs, /*len=*/sizeof(P) / sizeof(int));

    for (unsigned long i = 0; i < sizeof(P) / sizeof(int); i++) {
        int d = INT_MAX;
        int s = 0;
        int t = 0;
        for (unsigned long j = i; j < sizeof(P) / sizeof(int); j++) {
            int s_ = pairs[j][0];
            int t_ = pairs[j][1];
            if (dist(s_, t_) <= d) {
                s = s_;
                t = t_;
                d = dist(s_, t_);
            } else {
                continue;
            }
        }
        printf("i=%lu; (%d, %d); d=%d\n",i, s, t, d);
    }

    return 0;
}
