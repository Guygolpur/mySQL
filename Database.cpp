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
			stmt->execute("CREATE DATABASE IF NOT EXISTS book_store");
			con->setSchema("book_store");
			stmt->execute("create table if not exists costumer("
				"user_id char(50) primary key, "
				"user_name char(50), "
				"user_mobile char(50), "
				"user_email char(50), "
				"user_address char(50), "
				"join_date date "
				");");
			stmt->execute("create table if not exists discount ("
				"discount_id int auto_increment primary key,"
				"user_id char(50),"
				"foreign key(user_id) references costumer(user_id),"
				"discount float(7,2));");
			stmt->execute("create table if not exists supplier("
				"supplier_name varchar(50), "
				"supplier_id varchar(50) primary key, "
				"supplier_phone char(50), "
				"supplier_email varchar(50) "
				");");
			stmt->execute("create table if not exists book ("
				"id varchar(50) primary key, "
				"book_name varchar(50), "
				"book_author varchar(50), "
				"book_type varchar(50), "
				"book_price float(7,2), "
				"book_stock bool, "
				"supplier_id char(50),"
				"foreign key(supplier_id) references supplier(supplier_id)"
				");");
			stmt->execute("create table if not exists purchase("
				"purchase_id char(50) primary key, "
				"amount_to_pay float(7,2),"
				"amount_paid float(7,2), "
				"status_purchase ENUM('invited','arrived','massage'), "
				"purchase_date date,"
				"book_id varchar(50),"
				"foreign key(book_id) references book(id)"
				");");
			stmt->execute("create table if not exists sales_and_discount("
				"sales_id char(50) primary key, "
				"discount char(50),"
				"book_id char(50),"
				"foreign key(book_id) references book(id)"
				");");
			stmt->execute("CREATE TABLE IF NOT EXISTS purchase_record ( "
				"purchase_id varchar(50), "
				"amount_to_pay float(7,2), "
				"primary key(purchase_id), "
				"price float(7,2), "
				"saller_name varchar(50), "
				"user_id char(50),"
				"foreign key(user_id) references costumer(user_id),"
				"book_id char(50),"
				"foreign key(book_id) references book(id),"
				"record_date date,"
				"purchase_from enum('shop','ordered')"
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