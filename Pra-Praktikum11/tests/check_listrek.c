#include "check.h"
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"

address AlokasiAsisten (infotype X);
List KonsoAsisten(infotype e, List L);
int NbElmtListAsisten (List L);

START_TEST(IsEmpty_TC1) {
  List L = NULL;
  ck_assert_int_eq(1, IsEmpty(L));
} END_TEST

START_TEST(IsOneElmt_TC1) {
  List L = NULL;
  ck_assert_int_eq(0, IsOneElmt(L));
} END_TEST

START_TEST(IsOneElmt_TC2) {
  infotype X = 2;
  List L = AlokasiAsisten(X);
  ck_assert_int_eq(1, IsOneElmt(L));
} END_TEST

START_TEST(IsOneElmt_TC3) {
  List L = AlokasiAsisten(2);
  address P = AlokasiAsisten(3);
  Next(L) = P;
  ck_assert_int_eq(0, IsOneElmt(L));
} END_TEST

START_TEST(Alokasi_TC1) {
  infotype X = 2;
  address P = Alokasi(X);
  ck_assert_int_eq(Info(P), X);
  ck_assert_ptr_eq(Next(P), Nil);
} END_TEST

START_TEST(Dealokasi_TC1) {
  infotype X = 2;
  address P = AlokasiAsisten(X);
  Dealokasi(P);
} END_TEST

START_TEST(Search_T1) {
  List L = NULL;
  infotype search = 2;
  L = KonsoAsisten(4, L);
  L = KonsoAsisten(3, L);
  L = KonsoAsisten(1, L);
  ck_assert_int_eq(0, Search(L, search));
} END_TEST

START_TEST(Search_T2) {
  List L = NULL;
  infotype search = 2;
  L = KonsoAsisten(3, L);
  L = KonsoAsisten(2, L);
  L = KonsoAsisten(1, L);
  ck_assert_int_eq(1, Search(L, search));
} END_TEST

START_TEST(FirstElmt_T1) {
  infotype first = 1;
  List L = AlokasiAsisten(first);
  ck_assert_int_eq(FirstElmt(L), 1);
} END_TEST

START_TEST(Tail_T1) {
  List L = AlokasiAsisten(1);
  ck_assert_int_eq(NbElmtListAsisten(Tail(L)),0);
} END_TEST

START_TEST(Tail_T2) {
  List L = NULL;
  L = KonsoAsisten(3, L);
  L = KonsoAsisten(2, L);
  L = KonsoAsisten(1, L);
  
  for (int i=2; i<4; i++) {
    L = Tail(L);
    ck_assert_int_eq(FirstElmt(L), i);
  }
} END_TEST

START_TEST(Konso_T1) {
  List L = Alokasi(2);
  L = Konso(1, L);
  ck_assert_int_eq(FirstElmt(L), 1);
  ck_assert_int_eq(NbElmtListAsisten(L),2);
} END_TEST

START_TEST(KonsB_T1) {
  List L = Alokasi(1);
  L = KonsB(L, 2);
  ck_assert_int_eq(NbElmtListAsisten(L),2);

  for (int i=1; i<3; i++) {
    ck_assert_int_eq(FirstElmt(L), i);
    L = Tail(L);
  }
} END_TEST

START_TEST(Copy_T1) {
  List L = Alokasi(3);
  L = Konso(2,L);
  L = Konso(1,L);
  List LTemp = Copy(L);

  ck_assert_int_eq(FirstElmt(L), FirstElmt(LTemp));
  for (int i=2; i<4; i++) {
    L = Tail(L);
    LTemp = Tail(LTemp);
    ck_assert_int_eq(FirstElmt(L), FirstElmt(LTemp));
  }
} END_TEST

START_TEST(Copy_T2) {
  List L = NULL;
  List LCopy = Copy(L);

  ck_assert_ptr_eq(LCopy, NULL);
} END_TEST

START_TEST(MCopy_T1) {
  List Lin = NULL;
  List Lout;

  MCopy(Lin, &Lout);

  ck_assert_ptr_eq(Lout, NULL);
} END_TEST

START_TEST(MCopy_T2) {
  List Lout;
  List L = Alokasi(3);
  L = Konso(2,L);
  L = Konso(1,L);

  MCopy(L, &Lout);

  for (int i=1; i<4; i++) {
    ck_assert_int_eq(FirstElmt(L), FirstElmt(Lout));
    L = Tail(L);
    Lout = Tail(Lout);
  }
} END_TEST

START_TEST(Concat_T1) {
  List L1 = NULL;
  List L2 = Alokasi(3);
  L2 = Konso(2,L2);
  L2 = Konso(1,L2);

  List L3 = Concat(L1, L2);

  for (int i=1; i<4; i++) {
    ck_assert_int_eq(FirstElmt(L3), i);
    L3 = Tail(L3);
  }
} END_TEST

START_TEST(Concat_T2) {
  List L1 = Alokasi(3);
  L1 = Konso(2,L1);
  L1 = Konso(1,L1);

  List L2 = Alokasi(6);
  L2 = Konso(5,L2);
  L2 = Konso(4,L2);

  List L3 = Concat(L1, L2);

  for (int i=1; i<7; i++) {
    ck_assert_int_eq(FirstElmt(L3), i);
    L3 = Tail(L3);
  }
} END_TEST

START_TEST(MConcat_T1) {
  List LHsl;
  List L1 = NULL;
  List L2 = Alokasi(3);
  L2 = Konso(2,L2);
  L2 = Konso(1,L2);

  MConcat(L1, L2, &LHsl);
  for (int i=1; i<4; i++) {
    ck_assert_int_eq(FirstElmt(LHsl), i);
    LHsl = Tail(LHsl);
  }
} END_TEST

START_TEST(MConcat_T2) {
  List LHsl;
  List L1 = Alokasi(3);
  L1 = Konso(2,L1);
  L1 = Konso(1,L1);

  List L2 = Alokasi(6);
  L2 = Konso(5,L2);
  L2 = Konso(4,L2);

  MConcat(L1, L2, &LHsl);
  for (int i=1; i<7; i++) {
    ck_assert_int_eq(FirstElmt(LHsl), i);
    LHsl = Tail(LHsl);
  }
} END_TEST

START_TEST(PrintList_T1) {
  List L = Alokasi(3);
  L = Konso(2,L);
  L = Konso(1,L);
  PrintList(L);
} END_TEST

START_TEST(NbElmtList_T1) {
  List L = NULL;
  ck_assert_int_eq(NbElmtListAsisten(L),0);
} END_TEST

START_TEST(NbElmtList_T2) {
  List L = Alokasi(3);
  L = Konso(2,L);
  L = Konso(1,L);
  ck_assert_int_eq(NbElmtListAsisten(L),3);
} END_TEST

address AlokasiAsisten (infotype X) {
  address P = (address) malloc (sizeof(ElmtList));
  if (P != NULL) {
    Info(P) = X;
    Next(P) = Nil;
  }

  return P;
}

List KonsoAsisten(infotype e, List L)
{
  address P = Alokasi(e);

  if (P == Nil) {
    return L;
  } else {
    Next(P) = L;
    return P;
  }
}

int NbElmtListAsisten (List L)
{
  if (IsEmpty(L)) {
    return 0;
  } else {
    return (1 + NbElmtListAsisten(Tail(L)));
  }
}

/* ********** SUITE DAN EKSEKUSI ********** */
Suite *listrek_suite(void) { 
  Suite *s;
  TCase *tc_prototype, *tc_memory, *tc_search, *tc_primitif, *tc_proses;
  s = suite_create("List Rekursif");

  tc_prototype = tcase_create("Prototype");
  tcase_add_test(tc_prototype, IsEmpty_TC1);
  tcase_add_test(tc_prototype, IsOneElmt_TC1);
  tcase_add_test(tc_prototype, IsOneElmt_TC2);
  tcase_add_test(tc_prototype, IsOneElmt_TC3);
  suite_add_tcase(s, tc_prototype);

  tc_memory = tcase_create("Memory");
  tcase_add_test(tc_memory, Alokasi_TC1);
  tcase_add_test(tc_memory, Dealokasi_TC1);
  suite_add_tcase(s, tc_memory);

  tc_search = tcase_create("Search");
  tcase_add_test(tc_search, Search_T1);
  tcase_add_test(tc_search, Search_T2);
  suite_add_tcase(s, tc_search);

  tc_primitif = tcase_create("Primitif");
  tcase_add_test(tc_primitif, FirstElmt_T1);
  tcase_add_test(tc_primitif, Tail_T1);
  tcase_add_test(tc_primitif, Tail_T2);
  tcase_add_test(tc_primitif, Konso_T1);
  tcase_add_test(tc_primitif, KonsB_T1);
  suite_add_tcase(s, tc_primitif);

  tc_proses = tcase_create("Proses");
  tcase_add_test(tc_proses, Copy_T1);
  tcase_add_test(tc_proses, Copy_T2);
  tcase_add_test(tc_proses, MCopy_T1);
  tcase_add_test(tc_proses, MCopy_T2);
  tcase_add_test(tc_proses, Concat_T1);
  tcase_add_test(tc_proses, Concat_T2);
  tcase_add_test(tc_proses, MConcat_T1);
  tcase_add_test(tc_proses, MConcat_T2);
  tcase_add_test(tc_proses, PrintList_T1);
  tcase_add_test(tc_proses, NbElmtList_T1);
  tcase_add_test(tc_proses, NbElmtList_T2);
  suite_add_tcase(s, tc_proses);

  return s;
} 

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = listrek_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}