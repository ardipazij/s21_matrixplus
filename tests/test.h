#ifndef CPP_S21_MATRIXPLUS_SRC_TESTS_TEST_H
#define CPP_S21_MATRIXPLUS_SRC_TESTS_TEST_H

#include <gtest/gtest.h>
#include "../s21_matrix_oop.h"

void setMatrix3x3(S21Matrix &matrix, double expected[3][3]);

void setMatrix3x4(S21Matrix &matrix, double expected[3][4]);

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
static double mulMatrixFirstValue[3][3] = {{3, 4, 55},
                                           {6, 7, 8},
                                           {9, 3, 4}};
static double mulMatrixSecondValue[3][4] = {{1, 2, 3, 4},
                                            {4, 5, 6, 5},
                                            {6, 7, 8, 9}};
static double mulMatrixResult[3][4] = {
        {349, 411, 473, 527},
        {82,  103, 124, 131},
        {45,  61,  77,  87}};
static double transposeResult[3][3] =
        {{1, 0, 0},
         {2, 4, 0},
         {3, 5, 6}};
static double determinantResult[] = {24, 0, -6, -40, -1};
static double val1[5][3][3] = {{{1, 2, 3}, {0, 4, 5}, {0, 0, 6}},
                               {{1, 0, 0}, {2, 0, 0}, {3, 4, 1}},
                               {{1, 2, 3}, {0, 4, 2}, {2, 3, 4}},
                               {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}},
                               {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}}};
#endif