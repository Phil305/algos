#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-variable"

#include <signal.h>
#include <assert.h>
#include <stdbool.h>

#include "unity.h"

void setUp(void) /* {{{ */
{}
/* }}} */
void tearDown(void) /* {{{ */
{}
/* }}} */

static bool unvisited_points(int *points[], int num_points) { /* {{{ */
    for (int i = 0; i < num_points; i++) {
        if (points[i] == NULL) {
            return true;
        }
    }
    return false;
}
/* }}} */
static int closest_unvisited(int init_point_idx, int **points, int num_points){
    assert(points[init_point_idx]);
    int init_point = *points[init_point_idx];
    return 0;
}

static void test_GivenXYZ_DoABC(void) {
    int expected[] = {-21, -5, -1, 0, 1, 3, 11};
    int actual[] = {1, 2};

    int points[] = {0, 1, -21, -5, 11, -1, 3};
    int *P[sizeof(points) / sizeof(int)];
    for (unsigned long i = 0; i < sizeof(points) / sizeof(int); i++) {
        P[i] = &points[i];
    }
    //  NearestNeighbor($P$)
    //      Pick and visit an initial point `$p_0$` from $P$
    int init_point = *P[0];
    int i = 0;
    //      While there are still unvisited points
    while (unvisited_points(/*points=*/P, sizeof(points) / sizeof(int))) {
        //          $i = i + 1$
        i++;
        if (i == 7) {
            break;
        }
        //          Select `$p_i$` to be the closest unvisited point to
        closest_unvisited(/*init_point_idx=*/i, P,
                          /*num_points=*/sizeof(points) / sizeof(int));
        //          `$p_i−1$` Visit `$p_i$`
        //      Return to `$p_0$` from `$p_n−1$`
        // (The Algorithm Design Manual; Chapter 1 Introduction to
        // Algorithm Design; pp. 5-6; Steven S. Skiena; 2020)
    }

    // [Unity Assertions
    // Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
    TEST_ASSERT_EQUAL_INT_ARRAY(/*expected=*/expected, /*actual=*/actual,
                                /*num_elements=*/sizeof(expected) /
                                    sizeof(int));
}

int main(void) {
    // [Unity - Getting
    // Started](https://github.com/ThrowTheSwitch/Unity/blob/v2.6.1/docs/UnityGettingStartedGuide.md)
    UNITY_BEGIN();
    RUN_TEST(/*UnityDefaultTestRun=*/test_GivenXYZ_DoABC);
    return UNITY_END();
}
#pragma clang diagnostic pop
