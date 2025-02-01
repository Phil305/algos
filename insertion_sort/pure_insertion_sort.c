// [Unity Assertions Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
//
// acts like a breakpoint when hit by GDB
//raise(SIGINT);

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unity.h>

// [Immutable structs in C](https://shitpoet.cc/immutable-structs-in-c.html)
struct String {/* {{{ */
    // +1 for null-terminator
    char const chars[13+1];
    unsigned long const len;
};
/* }}} */

static struct String insertion_sort2(char const * const str, unsigned long const len) {/* {{{ */
    char sorted[len];
    memmove(/*dest=*/sorted, /*src=*/str, /*n=*/len);
    for (unsigned long i=1; i < len; i ++) {
        unsigned long j = i-1;
        while (j > 0) {
            // continue if prev char in array not earlier in alphabet
            if (sorted[j] >= sorted[j-1]) {
                break;
            }
            char tmp = sorted[j];
            sorted[j] = sorted[j-1];
            sorted[j-1] = tmp;
            j--;
        }
    }
    struct String const str_obj;
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wcast-qual"
    memmove(/*dest=*/(char* const)str_obj.chars, /*src=*/sorted, /*n=*/len);
    #pragma clang diagnostic pop
    return str_obj;
}
/* }}} */

void setUp(void)/* {{{ */
{}
/* }}} */
void tearDown(void)/* {{{ */
{}
/* }}} */
static void test_GivenUnsortedString_SortAlphabetically(void) {
    // [Unity Assertions Reference](https://github.com/ThrowTheSwitch/Unity/tree/v2.6.1/docs/UnityAssertionsReference.md)
    char const str[] = "INSERTIONSORT";
    char const expected[] = "EIINNOORRSSTT";
    struct String const str_obj = insertion_sort2(/*str=*/str,/*len=*/strlen(expected));
    TEST_ASSERT_EQUAL_STRING(expected, /*actual=*/str_obj.chars);
    TEST_ASSERT_EQUAL_STRING(/*expected=*/"INSERTIONSORT", /*actual=*/str);
}

int main(void) {
    // [Unity - Getting Started](https://github.com/ThrowTheSwitch/Unity/blob/v2.6.1/docs/UnityGettingStartedGuide.md)
    UNITY_BEGIN();
    RUN_TEST(/*UnityDefaultTestRun=*/test_GivenUnsortedString_SortAlphabetically);
    return UNITY_END();
}

