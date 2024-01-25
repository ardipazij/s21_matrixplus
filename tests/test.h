#ifndef CPP_S21_MATRIXPLUS_SRC_TESTS_TEST_H
#define CPP_S21_MATRIXPLUS_SRC_TESTS_TEST_H

#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

void SetMatrix3x3(S21Matrix &matrix, double expected[3][3]);

void SetMatrix3x4(S21Matrix &matrix, double expected[3][4]);

void SetMatrix10x10(S21Matrix &matrix, double expected[10][10]);

void CompareForInverse(S21Matrix matrix, double result[3][3]);

static double summandFirst[2][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                                       {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}}};

static double summandSecond[2][3][3] = {{{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                                        {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}}};
static bool compareSumResult[2] = {true, false};
static double sumResult[2][3][3] = {{{2, 2, 3}, {2, 4, 5}, {3, 4, 7}},
                                    {{2, 5, 3}, {2, 4, 5}, {3, 4, 7}}};

static double minuend[2][3][3] = {{{2, 2, 3}, {2, 4, 5}, {3, 4, 7}},
                                  {{2, 5, 3}, {2, 4, 5}, {3, 4, 7}}};

static double subtrahend[2][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                                     {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}}};
static bool compareSubResult[2] = {true, false};
static double subResult[2][3][3] = {{{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                                    {{1, 2, 3}, {0, 4, 5}, {0, 0, 6}}};
static double mulMatrixFirstValue[3][3] = {{3, 4, 55}, {6, 7, 8}, {9, 3, 4}};
static double mulMatrixSecondValue[3][4] = {
    {1, 2, 3, 4}, {4, 5, 6, 5}, {6, 7, 8, 9}};
static double mulMatrixResult[3][4] = {
    {349, 411, 473, 527}, {82, 103, 124, 131}, {45, 61, 77, 87}};
static double transposeResult[3][3] = {{1, 0, 0}, {2, 4, 0}, {3, 5, 6}};
static double determinantResult[] = {24, 0, -6, -40, -1};
static double val1[5][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                               {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                               {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}},
                               {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}},
                               {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}}};

static double valDeterminant[10][10] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20},
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 20}};
static double calcComplementsResults[5][3][3] = {
    {{24, -0, 0}, {-12, 6, -0}, {-2, -5, 4}},
    {{0, -2, 8}, {-0, 1, -4}, {0, -0, 0}},
    {{10, 4, -8}, {1, -2, 1}, {-8, -2, 4}},
    {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}},
    {{-1, 38, -27}, {1, -41, 29}, {-1, 34, -24}}};

static double inverseResults[5][3][3] = {
    {{1, -0.5, -0.0833333}, {-0, 0.25, -0.208333}, {0, -0, 0.166667}},
    {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
    {{-1.66667, -0.166667, 1.33333},
     {-0.666667, 0.333333, 0.333333},
     {1.33333, -0.166667, -0.666667}},
    {{-0, -0.1, 0.2}, {-0.25, 0.35, 0.05}, {0.5, -0.2, -0.1}},
    {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}}};
#endif