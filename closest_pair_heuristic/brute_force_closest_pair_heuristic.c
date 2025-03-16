#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wmissing-prototypes"
void setUp(void)
{}

void tearDown(void)
{}
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

int main(void) {
    int P[] = {0, -21, 11, -5, 3, -1, 1};
    int d = INT_MAX;

    for (unsigned long i=0; i < sizeof(P) / sizeof(int); i++) {
        printf("%d\n", P[i]);
    }

    return 0;
}
