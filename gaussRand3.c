#include "gaussRand3.h"

/// @brief Generate a Gaussian random number (mean 0, stdev 1).
///
/// As is standard practice when generating random numbers,
/// need to seed the random number generator before first use.
///
/// Code adapted from:
/// - comp.lang.c FAQ List, Question 13.20
///   url: http://c-faq.com/lib/gaussian.html
///
/// Theory based on:
/// - Donald Knuth, The Art of Computer Programming, Vol 2
///   Section 3.4.1 Numerical Distributions,  pg. 117 (edition?)
/// - Marsaglia and Bray, "A Convenient Method for Generating Normal Variables"
///
/// @return random number
///
double gaussRand3(void) {
    static double V1, V2, S;
    static int phase = 0;
    double X;

    if (phase == 0) {
        do {
            double U1 = (double)rand() / RAND_MAX;
            double U2 = (double)rand() / RAND_MAX;

            V1 = 2*U1 - 1;
            V2 = 2*U2 - 1;
            S = V1*V1 + V2*V2;
        } while(S>=1 || S==0);

        X = V1*sqrt(-2*log(S)/S);
    } else {
        X = V2*sqrt(-2*log(S)/S);
    }
    phase = 1 - phase;

    return X;
}
