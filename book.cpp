/*Guy Golpur 308353523
Bar Azouri 205785124*/

#include "book.h"
/*press 1*/
void print_all_books() {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		/* Fetch in reverse = descending order! */
		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "book: " << i << endl << "id: " << res->getString("id") << endl << "book name: " << res->getString("book_name") << endl << "book author: " << res->getString("book_author") << endl << "book type: " << res->getString("book_type") << endl << "book price: " << res->getString("book_price") << endl << "book stock: " << res->getString("book_stock") << endl << endl;            i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}


/*press 2*/
void print_all_open_reservation() {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM purchase LIMIT 5  OFFSET ? ");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM purchase LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "purchase: " << i << endl << "purchase id: " << res->getString("purchase_id") << endl << "amount_to_pay: " << res->getString("amount_to_pay") << endl << "amount paid: " << res->getString("amount_paid") << endl << "purchase date: " << res->getString("purchase_date") << endl << "status purchase: " << res->getString("status_purchase") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}

}



/*press 3*/
void print_all_costumers() {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM costumer LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM costumer LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "costumer: " << i << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "user mobile: " << res->getString("user_mobile") << endl << "user email: " << res->getString("user_email") << "user address: " << res->getString("user_address") << endl << "join date: " << res->getString("join_date") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}

/*press 4*/
void print_all_suppliers() {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM supplier LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		/* Fetch in reverse = descending order! */
		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM supplier LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "supplier: " << i << endl << "supplier id: " << res->getString("supplier_id") << endl << "supplier name: " << res->getString("supplier_name") << endl << "supplier phone: " << res->getString("supplier_phone") << endl << "supplier email: " << res->getString("supplier_email") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}



/*press 5*/
void print_deal_between_dates(const string &start, const string &end) {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM purchase_record WHERE record_date between ? and ? LIMIT 5  OFFSET ? ");
		pstmt->setString(1, start);
		pstmt->setString(2, end);
		pstmt->setInt(3, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM purchase_record WHERE record_date between ? and ? LIMIT 5  OFFSET ? ");
			pstmt->setString(1, start);
			pstmt->setString(2, end);
			pstmt->setInt(3, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "purchase: " << i << endl << "purchase id: " << res->getString("purchase_id") << endl << "amount to pay: " << res->getString("amount_to_pay") << endl << "price: " << res->getString("price") << endl << "saller name: " << res->getString("saller_name") << "user id: " << res->getString("user_id") << endl << "book id: " << res->getString("book_id") << endl << "date: " << res->getString("record_date") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}

}


/*press 6*/
void print_all_books_dicounts() {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM sales_and_discount LIMIT 5 OFFSET ?");
		pstmt->setInt(1, n);
		ResultSet *res = pstmt->executeQuery();
		/* Fetch in reverse = descending order! */
		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM sales_and_discount LIMIT 5 OFFSET ?");
			pstmt->setInt(1, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "book: " << i << endl << "sale id: " << res->getString("sales_id") << endl << "book id: " << res->getString("book_id") << endl << "book discount: " << res->getString("discount") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}





/*press 7- book name*/
void check_if_onstock(string checkStock) {
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book WHERE book_name = ? AND book_stock = ? ");
	pstmt->setString(1, checkStock);
	pstmt->setString(2, "1");
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "book is not exist" << endl;
	}
	else {
		cout << "book exist" << endl;
	}
}


/*press 7- author name*/
void check_if_onstock_author(string checkStock, string author_name) {
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book WHERE book_name = ? AND book_stock = ? AND book_author = ? ");
	pstmt->setString(1, checkStock);
	pstmt->setString(2, "1");
	pstmt->setString(3, author_name);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next()) {
		cout << "book is not exist" << endl;
	}
	else {
		cout << "book exist" << endl;
	}
}

/*press 8 book name*/

void check_book_supplier(string checkSupplier) {
	int n = 0;
	int i = 1;
	int j = 0;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select book.supplier_id, supplier.supplier_id, supplier.supplier_name, supplier.supplier_phone, supplier.supplier_email from book inner JOIN  supplier on book.supplier_id = supplier.supplier_id  where book_name= ? ;");
	pstmt->setString(1, checkSupplier);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next() && n>0)                            //if there is no next
	{
		cout << endl << "there is no next data!" << endl;
		n -= 5;
		i -= j;
		j = 0;
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select book.supplier_id, supplier.supplier_id, supplier.supplier_name, supplier.supplier_phone, supplier.supplier_email from book inner JOIN  supplier on book.supplier_id = supplier.supplier_id  where book_name='arthur' ;");
		pstmt->setString(1, checkSupplier);
		res = pstmt->executeQuery();
	}
	else {
		j = 0;
	}
	res->beforeFirst();
	
		while (res->next())
		{
				cout << "supplier: " << i << endl << "supplier id: " << res->getString("supplier_id") << endl << "supplier name: " << res->getString("supplier_name") << endl << "supplier mobile: " << res->getString("supplier_phone") << endl << "supplier email: " << res->getString("supplier_email") << endl << endl;
				i++;
				j++;
		}

	cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
	{
		system("cls");
		n += 5;
		break;
	}
	case 2:
	{
		if (n >= 5)
		{
			system("cls");
			n -= 5;
			i -= j + 5;
		}
		else
		{
			system("cls");
			i -= j;
			j = 0;
			cout << endl << "there is no prev data!" << endl;
		}
		break;
	}
	default:
	{
		return;
	}
	}
	delete res;
	delete con;
	delete pstmt;
}

/*press 8 author name*/

void check_book_supplier_author(string checkSupplier) {
	int n = 0;
	int i = 1;
	int j = 0;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select book.supplier_id, supplier.supplier_id, supplier.supplier_name, supplier.supplier_phone, supplier.supplier_email from book inner JOIN  supplier on book.supplier_id = supplier.supplier_id  where book_author= ? ;");
	pstmt->setString(1, checkSupplier);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next() && n>0)                            //if there is no next
	{
		cout << endl << "there is no next data!" << endl;
		n -= 5;
		i -= j;
		j = 0;
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select book.supplier_id, supplier.supplier_id, supplier.supplier_name, supplier.supplier_phone, supplier.supplier_email from book inner JOIN  supplier on book.supplier_id = supplier.supplier_id  where book_author= ? ;");
		pstmt->setString(1, checkSupplier);
		res = pstmt->executeQuery();
	}
	else {
		j = 0;
	}
	res->beforeFirst();

	while (res->next())
	{
		cout << "supplier: " << i << endl << "supplier id: " << res->getString("supplier_id") << endl << "supplier name: " << res->getString("supplier_name") << endl << "supplier mobile: " << res->getString("supplier_phone") << endl << "supplier email: " << res->getString("supplier_email") << endl << endl;
		i++;
		j++;
	}

	cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
	{
		system("cls");
		n += 5;
		break;
	}
	case 2:
	{
		if (n >= 5)
		{
			system("cls");
			n -= 5;
			i -= j + 5;
		}
		else
		{
			system("cls");
			i -= j;
			j = 0;
			cout << endl << "there is no prev data!" << endl;
		}
		break;
	}
	default:
	{
		return;
	}
	}
	delete res;
	delete con;
	delete pstmt;
}


/*press 8 book name and author name*/

void check_book_supplier_author_book(string checkSupplier, string author_name) {
	int n = 0;
	int i = 1;
	int j = 0;
	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select book.supplier_id, supplier.supplier_id, supplier.supplier_name, supplier.supplier_phone, supplier.supplier_email from book inner JOIN  supplier on book.supplier_id = supplier.supplier_id  where book_name= ? and book_author = ? ;");
	pstmt->setString(1, checkSupplier);
	pstmt->setString(2, author_name);
	ResultSet *res = pstmt->executeQuery();
	if (!res->next() && n>0)                            //if there is no next
	{
		cout << endl << "there is no next data!" << endl;
		n -= 5;
		i -= j;
		j = 0;
		delete res;
		delete pstmt;
		pstmt = con->prepareStatement("select book.supplier_id, supplier.supplier_id, supplier.supplier_name, supplier.supplier_phone, supplier.supplier_email from book inner JOIN  supplier on book.supplier_id = supplier.supplier_id  where book_author= ? ;");
		pstmt->setString(1, checkSupplier);
		res = pstmt->executeQuery();
	}
	else {
		j = 0;
	}
	res->beforeFirst();

	while (res->next())
	{
		cout << "supplier: " << i << endl << "supplier id: " << res->getString("supplier_id") << endl << "supplier name: " << res->getString("supplier_name") << endl << "supplier mobile: " << res->getString("supplier_phone") << endl << "supplier email: " << res->getString("supplier_email") << endl << endl;
		i++;
		j++;
	}

	cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
	int choose;
	cin >> choose;
	switch (choose) {
	case 1:
	{
		system("cls");
		n += 5;
		break;
	}
	case 2:
	{
		if (n >= 5)
		{
			system("cls");
			n -= 5;
			i -= j + 5;
		}
		else
		{
			system("cls");
			i -= j;
			j = 0;
			cout << endl << "there is no prev data!" << endl;
		}
		break;
	}
	default:
	{
		return;
	}
	}
	delete res;
	delete con;
	delete pstmt;
}






/*press 9 book name*/
void print_all_purchase_of_book_since_y(const string &book, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select book.id, purchase_record.record_date from book inner JOIN  purchase_record on id = book_id  where book_name= ?  and purchase_record.record_date >= ? ");
	pstmt->setString(1, book);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "no sells of this book" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " sells of this book" << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}

/*press 9 author name*/
void print_all_purchase_of_author_since_y(const string &author, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select book.id, purchase_record.record_date from book inner JOIN  purchase_record on id = book_id  where book_author= ?  and purchase_record.record_date >= ? ");
	pstmt->setString(1, author);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "no sells of this book" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " sells of this book" << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}



/*press 9 book and author name*/
void print_all_purchase_of_book_author_since_y(const string &book,const string &author, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select book.id, purchase_record.record_date from book inner JOIN  purchase_record on id = book_id  where book_name= ?  and purchase_record.record_date >= ? and book_author = ? ");
	pstmt->setString(1, book);
	pstmt->setString(2, date);
	pstmt->setString(3, author);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "no sells of this book" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " sells of this book" << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}





/*press 10 user name*/
void print_all_book_cost_z_buy_since_y(const string &user, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select costumer.user_id, purchase_record.record_date from costumer inner join purchase_record on costumer.user_id=purchase_record.user_id where user_name=? and purchase_record.record_date >= ?");
	pstmt->setString(1, user);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " purchases for this costumer " << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}

//10 by user id

void print_all_book_cost_userNumber_buy_since_y(const string &user, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select costumer.user_id, purchase_record.record_date from costumer inner join purchase_record on costumer.user_id=purchase_record.user_id where costumer.user_id= ? and purchase_record.record_date >= ?;");
	pstmt->setString(1, user);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " purchases for this costumer " << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}

//10 by user phone
void print_all_book_cost_userPhone_buy_since_y(const string &user, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select costumer.user_id, purchase_record.record_date from costumer inner join purchase_record on costumer.user_id=purchase_record.user_id where costumer.user_mobile= ? and purchase_record.record_date >= ?;");
	pstmt->setString(1, user);
	pstmt->setString(2, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " purchases for this costumer " << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}


//10 combine third
void print_all_book_cost_combineThird_buy_since_y(const string &name, const string &id, const string &phone, const string &date) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select costumer.user_id, purchase_record.record_date from costumer inner join purchase_record on costumer.user_id=purchase_record.user_id where user_name=? and costumer.user_id= ? and costumer.user_mobile= ? and purchase_record.record_date >= ?;");
	pstmt->setString(1, name);
	pstmt->setString(2, id);
	pstmt->setString(3, phone);
	pstmt->setString(4, date);

	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " purchases for this costumer " << " since " << date << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}




/*press 11*/
void print_costumer_buy_most(string &date) {
	int i = 1;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select * from costumer inner join (select user_id ,  count(user_id) c from purchase_record where purchase_record.record_date >= ?  group by user_id   order by c  desc limit 1) multi_purchase on costumer.user_id=multi_purchase.user_id  limit 1;");
	pstmt->setString(1, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no costumer";
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "costumer: " << i << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "user mobile: " << res->getString("user_mobile") << endl << "user email: " << res->getString("user_email") << endl << "user address: " << res->getString("user_address") << endl << "join date: " << res->getString("join_date") << endl << "number of book: " << res->getString("c") << endl << endl;		i++;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;

	delete res;
	delete con;
	delete pstmt;

}


/*press 12*/
void print_supplier_order_most(string &date) {
	int i = 1;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select * from supplier inner join (select supplier_id ,  count(supplier_id) c from book inner join (select book_id from purchase where purchase_date >= ?) pur on book.id=pur.book_id group by supplier_id   order by c  desc limit 1) sup on supplier.supplier_id=sup.supplier_id;");
	pstmt->setString(1, date);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no supplier";
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "suppleier: " << i << endl << "supplier id: " << res->getString("supplier_id") << endl << "supplier name " << res->getString("supplier_name") << endl << "supplier mobile: " << res->getString("supplier_phone") << endl << "supplier email: " << res->getString("supplier_email") << endl << "number of book order: " << res->getString("c") << endl << endl;
		i++;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;

	delete res;
	delete con;
	delete pstmt;

}







/*press 13*/
void print_invited_between(string start_order, string end_order) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM purchase WHERE purchase_date between ? and ?");
	pstmt->setString(1, start_order);
	pstmt->setString(2, end_order);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "no sells of this book" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " books reservation between those dates" << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;

}

/*press 14*/
void order_became_sell_between(string start_become, string end_become) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM purchase_record WHERE record_date between ? and ? and purchase_from = 'ordered'");
	pstmt->setString(1, start_become);
	pstmt->setString(2, end_become);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "no sells of this book" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		i++;
	}
	cout << "there is " << i << " orders that eventually sold between those dates" << endl << endl;
	cout << "press any number to main menu" << endl;
	cin >> i;
	delete res;
	delete con;
	delete pstmt;



}

/*press 15 user name*/
void total_discount_costumer_since(const string &user, const string &date) {


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT x.user_id, x.user_name,sum(price - amount_to_pay ) as total from (select purchase_record.user_id, purchase_record.amount_to_pay,purchase_record.price,purchase_record.record_date, cos.user_name from purchase_record inner join (select * from costumer WHERE user_name = ?) cos on purchase_record.user_id = cos.user_id) x where x.record_date >= ? and x.user_name = ? group by user_id;");
	pstmt->setString(1, user);
	pstmt->setString(2, date);
	pstmt->setString(3, user);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "total: " << res->getString("total") << endl << endl;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;
	delete res;
	delete con;
	delete pstmt;

}
//15 by id
void total_discount_costumer_since_by_id(const string &user, const string &date) {


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT x.user_id, x.user_name,sum(price - amount_to_pay ) as total from (select purchase_record.user_id, purchase_record.amount_to_pay,purchase_record.price,purchase_record.record_date, cos.user_name from purchase_record inner join (select * from costumer WHERE user_id = ?) cos on purchase_record.user_id = cos.user_id) x where x.record_date >= ? and x.user_id = ? group by user_id;");
	pstmt->setString(1, user);
	pstmt->setString(2, date);
	pstmt->setString(3, user);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "total: " << res->getString("total") << endl << endl;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;
	delete res;
	delete con;
	delete pstmt;

}

//15 by mobile
void total_discount_costumer_since_by_mobile(const string &user, const string &date) {


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT x.user_id , x.user_name,sum(price - amount_to_pay ) as total from (select purchase_record.user_id, purchase_record.amount_to_pay,purchase_record.price,purchase_record.record_date, cos.user_name,cos.user_mobile from purchase_record inner join (select * from costumer WHERE user_mobile = ?) cos on purchase_record.user_id = cos.user_id) x where x.record_date >= ? and x.user_mobile = ? group by user_id;");
	pstmt->setString(1, user);
	pstmt->setString(2, date);
	pstmt->setString(3, user);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "total: " << res->getString("total") << endl << endl;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;
	delete res;
	delete con;
	delete pstmt;

}


//15 by third combine
void total_discount_costumer_since_by_third_combine(const string &user_name, const string &user_id, const string &user_mobile, const string &date) {


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT x.user_id , x.user_name,sum(price - amount_to_pay ) as total from (select purchase_record.user_id, purchase_record.amount_to_pay,purchase_record.price,purchase_record.record_date, cos.user_name,cos.user_mobile from purchase_record inner join (select * from costumer WHERE user_name = ? and user_id= ? and user_mobile = ? ) cos on purchase_record.user_id = cos.user_id) x where x.record_date >= ? and x.user_name=? and x.user_id= ? and x.user_mobile = ? group by user_id;");
	pstmt->setString(1, user_name);
	pstmt->setString(2, user_id);
	pstmt->setString(3, user_mobile);
	pstmt->setString(4, date);
	pstmt->setString(5, user_name);
	pstmt->setString(6, user_id);
	pstmt->setString(7, user_mobile);

	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase of this costumer" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "total: " << res->getString("total") << endl << endl;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;
	delete res;
	delete con;
	delete pstmt;

}

/*press 16*/

void print_sum_quarter(const string &year) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("select  sum(amount_to_pay) _sum, quarter(record_date)  as _quarter from purchase_record where year(record_date) = ? group by _quarter;");
	pstmt->setString(1, year);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                 
	{
		cout << "no income" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << "quarter : " << res->getString("_quarter") << endl << "sum: " << res->getString("_sum") << endl << endl;
	}
	cout << "press any number to main menu" << endl;
	cin >> i;

	delete res;
	delete con;
	delete pstmt;

}



/*press 17*/
void print_costumer_since_y(const string &date) {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM costumer WHERE join_date >= ? LIMIT 5  OFFSET ? ");
		pstmt->setString(1, date);
		pstmt->setInt(2, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM costumer WHERE join_date >= ? LIMIT 5  OFFSET ?");
			pstmt->setString(1, date);
			pstmt->setInt(2, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "costumer: " << i << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "user mobile: " << res->getString("user_mobile") << endl << "user email: " << res->getString("user_email") << "user address: " << res->getString("user_address") << endl << "join date: " << res->getString("join_date") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}

}


/*press 18 now*/
void total_purchase_from_supplier_between(string suplier_id, string start_supplier, string end_supplier) {
	int i = 0;


	Database &db = Database::getInstance();
	Connection *con = db.getConnection();
	PreparedStatement *pstmt = con->prepareStatement("SELECT x.supplier_id, x.amount_to_pay , sum(amount_to_pay) as total from (SELECT amount_to_pay, book_id, record_date, book.supplier_id from purchase_record INNER JOIN book on purchase_record.book_id = book.id ) x where x.supplier_id = ? and x.record_date between ? and ?;");
	pstmt->setString(1, suplier_id);
	pstmt->setString(2, start_supplier);
	pstmt->setString(3, end_supplier);
	ResultSet *res = pstmt->executeQuery();

	if (!res->next())                            //if there is no next
	{
		cout << "there is no purchase from this supplier" << endl;
	}
	res->beforeFirst();
	while (res->next())
	{
		cout << endl << "id: " << res->getString("supplier_id") << endl << "amount: " << res->getString("total") << endl << endl;
	}

	cout << "press any number to main menu" << endl;
	int choose;
	cin >> choose;
	delete res;
	delete con;
	delete pstmt;



}



/*press 19*/
void saller_sold_most_between(string start_saller, string end_saller, string saller_name) {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM purchase_record WHERE saller_name = ? and record_date between ? and ? LIMIT 5  OFFSET ? ");
		pstmt->setString(1, saller_name);
		pstmt->setString(2, start_saller);
		pstmt->setString(3, end_saller);
		pstmt->setInt(4, n);
		ResultSet *res = pstmt->executeQuery();

		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("SELECT * FROM purchase_record WHERE saller_name = ? and record_date between ? and ? LIMIT 5  OFFSET ?");
			pstmt->setString(1, saller_name);
			pstmt->setString(2, start_saller);
			pstmt->setString(3, end_saller);
			pstmt->setInt(4, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "purchase: " << i << endl << "purchase id: " << res->getString("purchase_id") << endl << "amount to pay: " << res->getString("amount_to_pay") << endl << "price: " << res->getString("price") << endl << "saller name: " << res->getString("saller_name") << "user id: " << res->getString("user_id") << endl << "book id: " << res->getString("book_id") << endl << "date: " << res->getString("record_date") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}

}

/*press 20*/
void print_most_sells_book_between_years(const string &start, const string &end) {
	int n = 0;
	int i = 1;
	int j = 0;

	while (1)
	{
		Database &db = Database::getInstance();
		Connection *con = db.getConnection();
		PreparedStatement *pstmt = con->prepareStatement("select * from book inner join (select book_id ,  count(book_id) c from purchase_record where purchase_record.record_date >= ?  and purchase_record.record_date < ?  group by book_id   order by c  desc limit 10) multi_purchase on book.id=multi_purchase.book_id  limit 5 OFFSET ?;");
		pstmt->setString(1, start);
		pstmt->setString(2, end);
		pstmt->setInt(3, n);
		ResultSet *res = pstmt->executeQuery();
		/* Fetch in reverse = descending order! */
		if (!res->next() && n>0)                            //if there is no next
		{
			cout << endl << "there is no next data!" << endl;
			n -= 5;
			i -= j;
			j = 0;
			delete res;
			delete pstmt;
			pstmt = con->prepareStatement("select * from book inner join (select book_id ,  count(book_id) c from purchase_record where purchase_record.record_date >= ?  and purchase_record.record_date < ?  group by book_id   order by c  desc limit 10) multi_purchase on book.id=multi_purchase.book_id  limit 5 OFFSET ?;");
			pstmt->setString(1, start);
			pstmt->setString(2, end);
			pstmt->setInt(3, n);
			res = pstmt->executeQuery();
		}
		else {
			j = 0;
		}
		res->beforeFirst();
		while (res->next())
		{
			cout << "book: " << i << endl << "id: " << res->getString("id") << endl << "book name: " << res->getString("book_name") << endl << "book author: " << res->getString("book_author") << endl << "book type: " << res->getString("book_type") << endl << "book price: " << res->getString("book_price") << endl << "book stock: " << res->getString("book_stock") << endl << "number of sells: " << res->getString("c") << endl << endl;
			i++;
			j++;
		}

		cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
		int choose;
		cin >> choose;
		switch (choose) {
		case 1:
		{
			system("cls");
			n += 5;
			break;
		}
		case 2:
		{
			if (n >= 5)
			{
				system("cls");
				n -= 5;
				i -= j + 5;
			}
			else
			{
				system("cls");
				i -= j;
				j = 0;
				cout << endl << "there is no prev data!" << endl;
			}
			break;
		}
		default:
		{
			return;
		}
		}
		delete res;
		delete con;
		delete pstmt;
	}
}