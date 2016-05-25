#include <ctest.h>
#include <root.h>

#define UNUSED(x) (void)(x)

CTEST(quadratic_equation_suite, discriminant_test) {

    // Given

    const float a = 1;
    const float b = 4;
    const float c = 4;
    
    // When

    Roots reply;
    int stat;   
    reply = proc(a, b, c, &stat);

    // Then

    const Roots expected_reply = {-2, -2, 0};
    const int expected_stat = ONE_ROOT;

    ASSERT_DBL_NEAR(expected_reply.x1, reply.x1);
    ASSERT_DBL_NEAR(expected_reply.discriminant, reply.discriminant);
    ASSERT_DBL_NEAR(expected_stat, stat);
}

CTEST(quadratic_equation_suite, two_roots_test) {

    // Given

    const float a = 1;
    const float b = 5;
    const float c = 4;

    // When

    Roots reply;
    int stat;
    reply = proc(a, b, c, &stat);

    // Then

    const int expected_stat = TWO_ROOTS;
    const Roots expected_reply = {-1, -4, 9};

    ASSERT_DBL_NEAR(expected_reply.discriminant, reply.discriminant);
    ASSERT_DBL_NEAR(expected_stat, stat);
    ASSERT_DBL_NEAR(expected_reply.x1, reply.x1);
    ASSERT_DBL_NEAR(expected_reply.x2, reply.x2);
}

CTEST(quadratic_equation_suite, negative_discriminant_test) {

    // Given

    const float a = 1;
    const float b = 2;
    const float c = 3;

    // When

    Roots reply;
    int stat;
    reply = proc(a, b, c, &stat);


    // Then
    
    const int expected_stat = NO_ROOTS;
    const Roots expected_reply = {.discriminant = -8};

    ASSERT_DBL_NEAR(expected_reply.discriminant, reply.discriminant);
    ASSERT_DBL_NEAR(expected_stat, stat);    
}

CTEST(quadratic_equation_suite, non_quadratic_test) {

    // Given

    const float a = 0;
    const float b = 1;
    const float c = 4;

    // When

    Roots reply;
    int stat;
    reply = proc(a, b, c, &stat);
    UNUSED(reply);
    
    // Then
    const int expected_stat = INVALID_INPUT;

    ASSERT_DBL_NEAR(expected_stat, stat);
}
