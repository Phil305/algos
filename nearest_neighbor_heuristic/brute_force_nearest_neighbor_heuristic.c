#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
#pragma clang diagnostic ignored "-Wunused-variable"

#include <assert.h>
#include <sys/param.h>
#include <signal.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#include "unity.h"

void setUp(void) /* {{{ */
{}
/* }}} */
void tearDown(void) /* {{{ */
{}
/* }}} */

static bool unvisited_points(int *points[], int num_points) { /* {{{ */
    for (int i = 0; i < num_points; i++) {
        // visited points are set to NULL
        if (points[i] != NULL) {
            return true;
        }
    }
    return false;
}
/* }}} */
static int closest_unvisited_point_idx(int visited_point, int **points, int num_points) {
    int dist = 0;
    int min_dist = INT_MAX;
    int closest_unvisited_idx = 0;
    for (int i = 0; i < num_points; i++) {
        if (!points[i]) {
            continue;
        }
        if (*points[i] == visited_point) {
            continue;
        }
        dist = abs(visited_point - *points[i]);
        if (dist < min_dist) {
            min_dist = dist;
            closest_unvisited_idx = i;
        }
        printf("closest_unvisited_point=%d, point_idx=%d, min_dist=%d\n", *points[i], closest_unvisited_idx, min_dist);
    }
    assert(dist > 0);
    assert(closest_unvisited_idx > 0);
    return closest_unvisited_idx;
}

/*
 *  NearestNeighbor($P$)
 *      Pick and visit an initial point `$p_0$` from $P$
 *      `$p = p_0$`
 *      $i = 0$
 *      While there are still unvisited points
 *          $i = i + 1$
 *          Select `$p_i$` to be the closest unvisited point to `$p_i−1$`
 *          Visit `$p_i$`
 *      Return to `$p_0$` from `$p_n−1$`
 * (The Algorithm Design Manual; Chapter 1 Introduction to Algorithm Design; pp.
 * 5-6; Steven S. Skiena; 2020)
 */
static void test_GivenXYZ_DoABC(void) {
    int expected[] = {0, 1, -1, 3, -5, 11, -21};
    int result[sizeof(expected) / sizeof(int)];

    int points[] = {0, -21, 1, 3, -5, 11, -1};
    int *P[sizeof(points) / sizeof(int)];
    for (unsigned long i = 0; i < sizeof(points) / sizeof(int); i++) {
        P[i] = &points[i];
    }
    // Pick and visit an initial point `$p_0$` from $P$
    result[0] = *P[0];
    P[0] = NULL;
    int i = 0;
    // While there are still unvisited points
    while (unvisited_points(/*points=*/P, sizeof(points) / sizeof(int))) {
        // $i = i + 1$
        i++;
        // Select `$p_i$` to be the closest unvisited point to `$p_i−1$`
        // we're assuming all points are unique
        int closest_point_idx = closest_unvisited_point_idx(/*visited_point=*/result[i - 1], P,
                                   /*num_points=*/sizeof(points) / sizeof(int));
        result[i] = *P[closest_point_idx];
        P[closest_point_idx] = NULL;
        //          `$p_i−1$` Visit `$p_i$`
        //      Return to `$p_0$` from `$p_n−1$`
        // (The Algorithm Design Manual; Chapter 1 Introduction to
        // Algorithm Design; pp. 5-6; Steven S. Skiena; 2020)
    }

    // [Unity Assertions
    // Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
    TEST_ASSERT_EQUAL_INT_ARRAY(/*expected=*/expected, /*actual=*/result,
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
