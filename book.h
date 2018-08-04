/*Guy Golpur 308353523
Bar Azouri 205785124*/

#ifndef book_h
#define book_h

#include <stdio.h>
#include <iostream>
#include "Database.h"
#include <boost/date_time/posix_time/posix_time.hpp>

#include "mysql_connection.h"

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;

/*1*/void print_all_books();
/*2*/void print_all_open_reservation();
/*3*/void print_all_costumers();
/*4*/void print_all_suppliers();
/*5*/void print_deal_between_dates(const string &start, const string &end);
/*6*/void print_all_books_dicounts();
/*7 book name*/void check_if_onstock(string checkStock);
/*7 author name*/void check_if_onstock_author(string checkStock, string author_name);
/*8 book name*/void check_book_supplier(string checkSupplier);
/*8 author name*/void check_book_supplier_author(string checkSupplier);
/*8 author and book name*/void check_book_supplier_author_book(string checkSupplier, string author_name);
/*9 book name*/void print_all_purchase_of_book_since_y(const string &book, const string &date);
/*9 book authur*/void print_all_purchase_of_author_since_y(const string &author_name, const string &date);
/*9 author and book name*/void print_all_purchase_of_book_author_since_y(const string &book, const string &author_name, const string &date);
/*10 user name*/void print_all_book_cost_z_buy_since_y(const string &user, const string &date);
/*10 user id*/void print_all_book_cost_userNumber_buy_since_y(const string &user, const string &date);
/*10 phone*/void print_all_book_cost_userPhone_buy_since_y(const string &user, const string &date);
/*10 combine*/void print_all_book_cost_combineThird_buy_since_y(const string &name, const string &id, const string &phone, const string &date);
/*11*/void print_costumer_buy_most(string &date);
/*12*/void print_supplier_order_most(string &date);
/*13*/void print_invited_between(string start_order, string end_order);
/*14*/void order_became_sell_between(string start_become, string end_become);
/*15 user name*/void total_discount_costumer_since(const string &user, const string &date);
/*15 by id*/void total_discount_costumer_since_by_id(const string &user, const string &date);
/*15 phone*/void total_discount_costumer_since_by_mobile(const string &user, const string &date);
/*15 combine*/void total_discount_costumer_since_by_third_combine(const string &user_name, const string &user_id, const string &user_mobile, const string &date);
/*16*/void print_sum_quarter(const string &year);
/*17*/void print_costumer_since_y(const string &date);
/*18*/ void total_purchase_from_supplier_between(string suplier_id, string start_supplier, string end_supplier);
/*19*/void saller_sold_most_between(string start_saller, string end_saller, string saller_name);
/*20*/void print_most_sells_book_between_years(const string &start, const string &end);
#endif