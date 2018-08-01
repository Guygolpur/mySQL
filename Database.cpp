/*Guy Golpur*/

#include "Database.h"


Database *Database::instance = 0;

Database::Database() : driver(get_driver_instance()) {
	connection_properties["hostName"] = DB_HOST;
	connection_properties["port"] = DB_PORT;
	connection_properties["userName"] = DB_USER;
	connection_properties["password"] = DB_PASS;
	connection_properties["OPT_RECONNECT"] = true;

	// use database
	try {
		Connection *con = driver->connect(connection_properties);
		try {
			con->setSchema("book_store");
		}
		catch (SQLException &e) {
			Statement *stmt = con->createStatement();
			stmt->execute(
				"CREATE DATABASE IF NOT EXISTS book_store");
			con->setSchema("book_store"); // switch database
			stmt->execute("create table if not exists costumer("
				"user_id char(50) primary key, "
				"user_name char(50), "
				"user_mobile char(50), "
				"user_email char(50), "
				"user_address char(50), "
				"join_date date "
				");");
			stmt->execute("create table if not exists book ("
				"id varchar(50) primary key, "
				"book_name varchar(50), "
				"book_author varchar(50), "
				"book_type varchar(50), "
				"book_price float(7,2), "
				"book_stock bool "
				");");
			stmt->execute("create table if not exists supplier("
				"supplier_name varchar(50), "
				"supplier_id varchar(50) primary key, "
				"supplier_phone int(50), "
				"supplier_email varchar(50) "
				");");

			stmt->execute("create table if not exists books_suppliers("
				"book_id varchar(50), "
				"supplier_id varchar(50), "
				"primary key(book_id, supplier_id), "
				"foreign key(book_id) references book(id), "
				"foreign key(supplier_id) references supplier(supplier_id) "
				");");

			stmt->execute("create table if not exists purchase("
				"purchase_id char(50) primary key, "
				"amount_to_paid float(7,2), "
				"price float(7,2), "
				"book_ISBN char(50), "
				"date_purchase date, "
				"status_purchase ENUM('invited','arrived','massage'), "
				"seller_name char(50) "
				");");
			stmt->execute("create table if not exists sales_and_discount("
				"sales_id char(50) primary key, "
				"amount_to_pay float(7,2), "
				"amount_paid float(7,2), "
				"balance  float(7,2) "
				");");

			stmt->execute("CREATE TABLE IF NOT EXISTS purchase record ( "
				"purchase_id varchar(50), "
				"amount_to_pay float(7,2), "
				"primary key(purchase_id), "
				"price float(7,2), "
				"book_ISBN varchar(50), "
				"date_purchase_record date, "
				"saller_name varchar(50) "
				")");

			delete stmt;
		}

		delete con;
	}
	catch (SQLException &e) {
		cout << e.getErrorCode() << " " << e.what() << " " << e.getSQLState();
	}
}

Database & Database::getInstance() {
	if (Database::instance == 0) {
		instance = new Database();
	}
	return *instance;
}

Connection * Database::getConnection() {
	try {
		Connection *con = driver->connect(connection_properties);
		con->setSchema(DB_NAME);
		return con;
	}
	catch (SQLException &e) {
		cout << e.what();
	}
	return 0;
}