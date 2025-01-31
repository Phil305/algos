// [Unity Assertions Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
//
// acts like a breakpoint when hit by GDB
//raise(SIGINT);

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unity.h>

static void insertion_sort(char * ret, unsigned long len) {
    for (unsigned long i=1; i < len; i ++) {
        unsigned long j = i-1;
        while (j > 0) {
            // continue if prev char in array not earlier in alphabet
            if (ret[j] >= ret[j-1]) {
                break;
            }
            char tmp = ret[j];
            ret[j] = ret[j-1];
            ret[j-1] = tmp;
            j--;
        }
    }
}

void setUp(void)/* {{{ */
{}
/* }}} */
void tearDown(void)/* {{{ */
{}
/* }}} */
static void test_GivenUnsortedString_SortAlphabetically(void) {
    // [Unity Assertions Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
    char str[] = "INSERTIONSORT";
    char expected[] = "EIINNOORRSSTT";
    insertion_sort(str, strlen(str));
    TEST_ASSERT_EQUAL_STRING(/*expected=*/expected, /*actual=*/str);
}

int main(void) {
    // [Unity - Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/v2.6.1/docs/UnityGettingStartedGuide.md)
    UNITY_BEGIN();
    RUN_TEST(/*UnityDefaultTestRun=*/test_GivenUnsortedString_SortAlphabetically);
    return UNITY_END();
}

