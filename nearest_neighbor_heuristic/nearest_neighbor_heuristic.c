#include <signal.h>
#include <stdbool.h>

#include "unity.h"

void setUp(void)/* {{{ */
{}
/* }}} */
void tearDown(void)/* {{{ */
{}
/* }}} */

static void test_GivenXYZ_DoABC(void) {
    int expected[] = {-21,-5,-1,0,1, 3, 11};

    //  NearestNeighbor($P$)
    //      Pick and visit an initial point `$p_0$` from $P$
    int points[] = {0,1,-21,-5, 11,-1, 3};
    int init_point = points[0];
    int i = 0;
    //      While there are still unvisited points
    //          $i = i + 1$
    while (unvisited_points(points)) {
    //          Select `$p_i$` to be the closest unvisited point to `$p_i−1$`
    //          Visit `$p_i$`
    //      Return to `$p_0$` from `$p_n−1$`
    // (The Algorithm Design Manual; Chapter 1 Introduction to Algorithm Design; pp. 5-6; Steven S. Skiena; 2020)
    }

    // [Unity Assertions Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
    TEST_ASSERT_EQUAL_INT_ARRAY(/*expected=*/expected, /*actual=*/array, /*num_elements=*/sizeof(expected)/sizeof(int));
}

int main(void) {
    // [Unity - Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/v2.6.1/docs/UnityGettingStartedGuide.md)
    UNITY_BEGIN();
    RUN_TEST(/*UnityDefaultTestRun=*/test_GivenXYZ_DoABC);
    return UNITY_END();
}
