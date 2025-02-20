#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wunsafe-buffer-usage"
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic pop

#include <signal.h>
#include <stdbool.h>

#include "unity.h"

void setUp(void)
{}

void tearDown(void)
{}

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
static void test_GivenXYZ_DoABC(void) {
    // acts like a breakpoint when hit by GDB
    //raise(SIGINT);

    // [Unity Assertions Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
    TEST_ASSERT_EQUAL_INT(/*expected=*/true, /*actual=*/false);
}

int main(void) {
    // [Unity - Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/v2.6.1/docs/UnityGettingStartedGuide.md)
    UNITY_BEGIN();
    RUN_TEST(/*UnityDefaultTestRun=*/test_GivenXYZ_DoABC);
    return UNITY_END();
}
