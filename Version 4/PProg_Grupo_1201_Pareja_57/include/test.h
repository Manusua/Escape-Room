/**
 * @brief Define constantes para las pruebas
 *
 * @file test.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 13-11-2018
 * 
 */
#ifndef _TEST_H
#define _TEST_H

#pragma GCC diagnostic ignored "-Wpedantic"

#ifndef NOCOLOR
#define KRED  "\x1B[31m" /*!< KRED */
#define KGRN  "\x1B[32m"/*!< KGRN */
#define KYEL  "\x1B[33m"/*!< KYEL */
#define KCYN  "\x1B[36m"/*!< KCYN */
#define RESET "\033[0m"/*!< RESET */
#else
#define KRED/*!< KRED */
#define KGRN/*!< KGRN */
#define KYEL/*!< KYEL */
#define KCYN/*!< KCYN */
#define RESET/*!< RESET */
#endif

#define PRINT_TEST_RESULT(x) do{\
    __test_counter++;\
    __pass = (x);\
    __test_passed = (__pass)? __test_passed + 1 : __test_passed;\
    printf(KYEL "%s" RESET " line "  "%d " KCYN "%s" RESET ": %s\n", \
           __FILE__, __LINE__ , __FUNCTION__, \
           ((!__pass) ? KRED "NOT PASS" RESET : KGRN "PASS" RESET)); \
  } while (0) /*!< PRINT_TEST_RESULT */

#define PRINT_PASSED_PERCENTAGE printf("Tests passed %d%%\n", ((__test_passed * 100) / __test_counter)) /*!< PRINT_PASSED_PERCENTAGE */

static int __test_counter = 0;
static int __test_passed = 0;
static int __pass = 0;

#endif
