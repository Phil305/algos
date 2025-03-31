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

static int dist(int n1, int n2) { /* {{{ */
    return abs(n1 - n2);
}
/* }}} */
static void distinct_vertex_chains(int ret[][2], int ret_len, int const endpoints[], int endpoints_len) { /* {{{ */
    int offset = 0;
    for (int i = 0; i < endpoints_len && offset < ret_len; i++) {
        for (int j = i; j < endpoints_len - 1; j++) {
            ret[offset][0] = endpoints[i];
            ret[offset][1] = endpoints[j + 1];
            offset++;
        }
    }
}
/* }}} */
static void print_pairs(int pairs[][2], int const len) { /* {{{ */
    for (int i = 0; i < len; i++) {
        printf("(%d, %d)\n", pairs[i][0], pairs[i][1]);
    }
}
static int triangular_number(int height) {
    return (height * (height + 1)) / 2;
}
/* }}} */
int main(void) {
    int P[] = {0, -21, 11, -5, 3, -1, 1};
    int n = sizeof(P) / sizeof(int);

    int longest_row_len = n - 1;
    int num_uniq_pairs=triangular_number(/*height=*/longest_row_len);
    int pairs[num_uniq_pairs][2];

    distinct_vertex_chains(/*ret=*/pairs, /*ret_len=*/triangular_number(/*height=*/longest_row_len), /*endpoints=*/P, /*endpoints_len=*/n);
    print_pairs(pairs, /*len=*/num_uniq_pairs);

    for (unsigned long i = 1; i < n; i++) {
         int d = INT_MAX;
        int s;
        int t;
        int sm;
        int tm;
         for (int j=0; j < num_uniq_pairs; j++) {
             s = pairs[j][0];
             t = pairs[j][1];
            if (dist(s, t) <= d) {
                d = dist(s,t);
                sm = s;
                tm = t;
            }
         }
         int edge[2] = {sm, tm};
         printf("(%d, %d)\n", edge[0], edge[1]);
    }
    //         int s_ = pairs[i][0];
    //         int t_ = pairs[j][1];
    //         if (dist(s_, t_) <= d) {
    //             s = s_;
    //             t = t_;
    //             d = dist(s_, t_);
    //         }
    //         printf("j=%lu; (%d, %d); d=%d\n", j, s, t, d);
    //     }
    // }

    return 0;
}
