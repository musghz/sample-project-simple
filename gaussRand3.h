/// @file gaussRand3.h
///
/// @brief Generate random numbers with mean 0 and stdev 1
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
/// Created 10 Aug 2017
/// Modified 6 Jan 2018
/// -include file
///
/// @author Mustafa Ghazi

#ifdef _cplusplus
extern "C" {
#endif

#ifndef GAUSSRAND3_H
#define GAUSSRAND3_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// @brief Generate a Gaussian random number (mean 0, stdev 1).
double gaussRand3(void);

#endif

#ifdef _cplusplus
}
#endif

