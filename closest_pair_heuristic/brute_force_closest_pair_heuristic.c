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

// static int dist(int n1, int n2) {
//     return abs(n1 - n2);
// }

static void endpoint_pairs(int ret[][2], int const endpoints[], int len) {
    for (int i = 1; i < len; i++) {
        ret[i - 1][0] = endpoints[i - 1];
        ret[i - 1][1] = endpoints[i];
    }
}

int main(void) {
    int P[] = {0, -21, 11, -5, 3, -1, 1};
    int pairs[sizeof(P) / sizeof(int)][2] = {0};
    endpoint_pairs(/*ret=*/pairs, /*endpoints=*/P, /*len=*/sizeof(P) / sizeof(int));

    for (unsigned long i = 0; i < (sizeof(P) / sizeof(int)) - 1; i++) {
        printf("(%d, %d)\n", pairs[i][0], pairs[i][1]);
    }
    // int s = 0;
    // int t = 0;

    // for (unsigned long i = 1; i < sizeof(P) / sizeof(int); i++) {
    //     int d = INT_MAX;
    //     s = P[i - 1];
    //     t = P[i];
    //     if (dist(s, t) <= d) {

    return 0;
}
