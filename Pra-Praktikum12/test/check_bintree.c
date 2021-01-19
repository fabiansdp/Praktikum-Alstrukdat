#include <check.h>
#include "stdio.h"
#include "stdlib.h"
#include "../src/listrek.h"
#include "../src/bintree.h"

/****************** Konstruktor ******************/
START_TEST(Tree_T) {
  BinTree P;
  boolean a;
  P = Tree(1, Nil, Nil);
  a = (P == Nil);
  ck_assert_int_eq(a, 0);
} END_TEST

START_TEST(MakeTree_T) {
  BinTree P;
  boolean a;
  MakeTree(1,Nil, Nil, &P);
  a = (P == Nil);
  ck_assert_int_eq(a, 0);
} END_TEST

/* Manajemen Memory */
START_TEST(AlokNode_T) {
  BinTree P;
  boolean a;
  P = AlokNode(1);
  a = (Left(P) == Nil);
  ck_assert_int_eq(a, 1);
} END_TEST

START_TEST(DealokNode_T) {
  BinTree P;
  P = AlokNode(1);
  DealokNode(P);
} END_TEST
/****************** Predikat Penting ******************/
START_TEST(IsTreeEmpty_T) {
  BinTree P;
  boolean a;
  P = Tree(1, Nil, Nil);
  a = IsTreeEmpty(P);
  ck_assert_int_eq(a, 0);
} END_TEST

START_TEST(IsTreeOneElmt_T) {
  BinTree P;
  boolean a;
  P = Tree(1, Nil, Nil);
  a = IsTreeOneElmt(P);
  ck_assert_int_eq(a, true);
} END_TEST

START_TEST(IsUnerLeft_T) {
  BinTree P, P1;
  boolean a;
  P1 = AlokNode(2);
  P = Tree(1, P1, Nil);
  a = IsUnerLeft(P);
  ck_assert_int_eq(a, true);
} END_TEST

START_TEST(IsUnerRight_T) {
  BinTree P, P1;
  boolean a;
  P1 = AlokNode(2);
  P = Tree(1, Nil, P1);
  a = IsUnerRight(P);
  ck_assert_int_eq(a, true);
} END_TEST

START_TEST(IsBiner_T) {
  BinTree P, P1, P2;
  boolean a;
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  a = IsBiner(P);
  ck_assert_int_eq(a, true);
} END_TEST

/* *** Traversal *** */
START_TEST(PrintPreorder_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  PrintPreorder(P);
  printf("\n");
} END_TEST

START_TEST(PrintInorder_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  PrintInorder(P);
  printf("\n");
} END_TEST

START_TEST(PrintPostorder_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  PrintPostorder(P);
  printf("\n");
} END_TEST

START_TEST(PrintTree_T) {
  BinTree P, P1, P2;

  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  PrintTree(P, 2);
} END_TEST

/* *** Searching *** */
START_TEST(SearchTree_T) {
  BinTree P, P1, P2;

  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  ck_assert_int_eq(SearchTree(P, 2), true);
} END_TEST

START_TEST(NbElmt_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  ck_assert_int_eq(NbElmt(P), 3);
} END_TEST

START_TEST(NbDaun_T) {
  BinTree P, P1, P2;
 
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  P = Tree(1, P2, P1);
  ck_assert_int_eq(NbDaun(P), 2);
} END_TEST

START_TEST(IsSkewLeft_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  Left(P2) = P1;
  P = Tree(1, P2, Nil);
  ck_assert_int_eq(IsSkewLeft(P), true);
} END_TEST

START_TEST(IsSkewRight_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(2);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  ck_assert_int_eq(IsSkewRight(P), true);
} END_TEST

START_TEST(Level_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  ck_assert_int_eq(Level(P, 3), 2);
} END_TEST

START_TEST(Tinggi_T) {
  BinTree P, P1, P2;
  
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  ck_assert_int_eq(Tinggi(P), 3);
} END_TEST

START_TEST(AddDaunTerkiri_T) {
  BinTree P, P1, P2;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  AddDaunTerkiri(&P, 4);
  ck_assert_int_eq(Akar(Left(P)), 4);
} END_TEST

START_TEST(AddDaun_T) {
  BinTree P, P1, P2;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;

  P = Tree(1, Nil, P2);
  AddDaun(&P, 4, 3, false);
  ck_assert_int_eq(Akar(Right(P)), 3);
} END_TEST

START_TEST(DelDaunTerkiri_T) {
  BinTree P, P1, P2;
  infotype X;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  AddDaunTerkiri(&P, 4);
  DelDaunTerkiri(&P,&X);
  ck_assert_int_eq(X, 4);
} END_TEST

START_TEST(DelDaun_T) {
  BinTree P, P1, P2;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  DelDaun(&P,3);
  ck_assert_int_eq(Akar(P),1);
} END_TEST

START_TEST(MakeListDaun_T) {
  BinTree P, P1, P2;
  List L;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  L = MakeListDaun(P);
} END_TEST

START_TEST(MakeListPreorder_T) {
  BinTree P, P1, P2;
  List L;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  L = MakeListPreorder(P);
} END_TEST

START_TEST(MakeListLevel_T) {
  BinTree P, P1, P2;
  List L;
  P1 = AlokNode(2);
  P2 = AlokNode(3);
  Right(P2) = P1;
  P = Tree(1, Nil, P2);
  L = MakeListLevel(P,1);
} END_TEST

START_TEST(BSearch_T) {
  BinTree P;
  P = Tree(1, Nil, Nil);
  InsSearch(&P,2);
  InsSearch(&P,3);
  ck_assert_int_eq(BSearch(P, 2), true);
} END_TEST

START_TEST(InsSearch_T) {
  BinTree P;
  P = Tree(1, Nil, Nil);
  InsSearch(&P,2);
  InsSearch(&P,3);
} END_TEST

START_TEST(DelBtree_T) {
  BinTree P;
  P = Tree(1, Nil, Nil);
  InsSearch(&P,2);
  DelBtree(&P,2);
  ck_assert_int_eq(IsTreeOneElmt(P), true);
} END_TEST

/* *** Fungsi-Fungsi Lain *** */

Suite *bintree_suite(void) { 
  Suite *s;
  TCase *tc_all;
  s = suite_create("Binary Tree");

  tc_all = tcase_create("Tests");
  tcase_add_test(tc_all, Tree_T);
  tcase_add_test(tc_all, MakeTree_T);
  tcase_add_test(tc_all, AlokNode_T);
  tcase_add_test(tc_all, DealokNode_T);
  tcase_add_test(tc_all, IsTreeEmpty_T);
  tcase_add_test(tc_all, IsTreeOneElmt_T);
  tcase_add_test(tc_all, IsUnerLeft_T);
  tcase_add_test(tc_all, IsUnerRight_T);
  tcase_add_test(tc_all, IsBiner_T);
  tcase_add_test(tc_all, PrintPreorder_T);
  tcase_add_test(tc_all, PrintInorder_T);
  tcase_add_test(tc_all, PrintPostorder_T);
  tcase_add_test(tc_all, PrintTree_T);
  tcase_add_test(tc_all, SearchTree_T);
  tcase_add_test(tc_all, NbElmt_T);
  tcase_add_test(tc_all, NbDaun_T);
  tcase_add_test(tc_all, IsSkewLeft_T);
  tcase_add_test(tc_all, IsSkewRight_T);
  tcase_add_test(tc_all, Level_T);
  tcase_add_test(tc_all, Tinggi_T);
  tcase_add_test(tc_all, AddDaunTerkiri_T);
  tcase_add_test(tc_all, AddDaun_T);
  tcase_add_test(tc_all, DelDaunTerkiri_T);
  tcase_add_test(tc_all, DelDaun_T);
  tcase_add_test(tc_all, MakeListDaun_T);
  tcase_add_test(tc_all, MakeListPreorder_T);
  tcase_add_test(tc_all, MakeListLevel_T);
  tcase_add_test(tc_all, BSearch_T);
  tcase_add_test(tc_all, InsSearch_T);
  tcase_add_test(tc_all, DelBtree_T);
  suite_add_tcase(s, tc_all);
 
  return s;
} 

// void DelDaunTerkiri(BinTree *P, infotype *X)
// void DelDaun(BinTree *P, infotype X)
// List MakeListDaun(BinTree P)
// List MakeListPreorder(BinTree P)
// List MakeListLevel(BinTree P, int N)
// boolean BSearch(BinTree P, infotype X)
// void InsSearch(BinTree *P, infotype X)
// void DelBtree(BinTree *P, infotype X)

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = bintree_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL); 
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}