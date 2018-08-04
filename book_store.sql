/*Guy Golpur 308353523
Bar Azouri 205785124*/


create database if not exists book_store;
use book_store;

create table if not exists costumer(
	user_id char(50) primary key, 
	user_name char(50), 
	user_mobile char(50), 
	user_email char(50),
	user_address char(50),
    join_date date
);
create table if not exists discount (
	discount_id int auto_increment primary key,
	user_id char(50),
    foreign key(user_id) references costumer(user_id),
    discount float(7,2)
);

create table if not exists supplier(
	supplier_name varchar(50),
    supplier_id varchar(50) primary key,
	supplier_phone char(50),
    supplier_email varchar(50)
);

create table if not exists book (
	id varchar(50) primary key,
    book_name varchar(50),
    book_author varchar(50),
    book_type varchar(50),
    book_price float(7,2),
    book_stock bool,
    supplier_id char(50),
	foreign key(supplier_id) references supplier(supplier_id)
);



create table if not exists purchase(
	purchase_id char(50) primary key,
	amount_to_pay float(7,2),
	amount_paid float(7,2),
    status_purchase ENUM('invited','arrived','massage'),
    purchase_date date,
    book_id varchar(50),
    foreign key(book_id) references book(id)
);

create table if not exists sales_and_discount(
	sales_id char(50) primary key,
	discount char(50),
	book_id char(50),
	foreign key(book_id) references book(id)
);

create table if not exists purchase_record(
	purchase_id varchar(50),
    amount_to_pay float(7,2),
    primary key(purchase_id),
	price float(7,2),
    saller_name varchar(50),
    user_id char(50),
	foreign key(user_id) references costumer(user_id),
	book_id char(50),
	foreign key(book_id) references book(id),
    record_date date,
    purchase_from enum('shop','ordered')
);




INSERT INTO  costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('01', 'bar', '0525287103', 'barazouri@gmail.com', 'emil zula', '2018-01-01');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('02', 'guy', '0527349472', 'guy@gmail.com', 'artglas', '2016-01-01');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('03', 'david', '0525293847', 'david@gmail.com', 'igal mosinon', '2015-01-05');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('04', 'shir', '0554478832', 'shir@gmail.com', 'brodeski', '1995-01-01');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('05', 'karin', '0536785321', 'karin@gmail.com', 'hofyen', '1996-01-01');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('06', 'tibor', '0567849382', 'tibor@gmail.com', 'dizi', '1998-05-04');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('07', 'aviad', '0554736271', 'aviad@gmail.com', 'ben gurion', '2016-08-07');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('08', 'idan', '0576453627', 'idan@gmail.com', 'eben gabirol', '2014-07-07');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('09', 'shani', '0564738291', 'shani@gmail.com', 'shosho', '2017-08-08');
INSERT INTO costumer (`user_id`, `user_name`, `user_mobile`, `user_email`, `user_address`, `join_date`) VALUES ('010', 'yoni', '0567348593', 'yoni@gmail.com', 'yehuda', '2018-01-01');





INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('dror', '001', '054333333', 'd@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('yossi', '002', '054111111', 'y@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('kobi', '003', '054222222', 'k@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('nahum', '004', '054555555', 'n@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('shlomo', '005', '054666666', 's@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('shlomi', '006', '054777777', 'si@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('jojo', '007', '054888888', 'j@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('ben', '008', '054999999', 'b@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('efraim', '009', '55111111', 'e@gmail.com');
INSERT INTO supplier (`supplier_name`, `supplier_id`, `supplier_phone`, `supplier_email`) VALUES ('drorit', '0010', '55222222', 'drorit@gmail.com');






INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('1', 'arthur', 'chris', 'drama', '20.4', '1', '001');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('2', 'harry potter', 'jk', 'horror', '30.5', '1', '002');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('3', 'tom and jerry', 'jhon', 'history', '40.6', '1', '003');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('4', 'cliford', 'dror', 'kids', '20.4', '1', '004');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('5', 'harry potter 2', 'jk', 'horror', '40.5', '1', '002');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('6', 'narnia', 'klil', 'drama', '30.4', '1', '005');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('7', 'peter pen', 'amy', 'history', '10.3', '1', '006');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('8', 'prince', 'yali', 'history', '14.5', '1', '007');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('9', 'shosho', 'tomi', 'drama', '55.6', '1', '008');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('11', 'princess', 'klil', 'deama', '55.70', '1', '009');
INSERT INTO book (`id`, `book_name`, `book_author`, `book_type`, `book_price`, `book_stock`, `supplier_id`) VALUES ('10', 'arthur', 'chris', 'drama', '20.40', '1', '001');




INSERT INTO discount (`user_id`, `discount`) VALUES ('01', '20');
INSERT INTO discount (`user_id`, `discount`) VALUES ('02', '30');
INSERT INTO discount (`user_id`, `discount`) VALUES ('03', '40');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('4', '04', '50.00');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('5', '05', '60.00');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('6', '06', '70.00');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('7', '07', '80.00');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('8', '08', '90.00');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('9', '09', '10.00');
INSERT INTO discount (`discount_id`, `user_id`, `discount`) VALUES ('10', '010', '11.00');





INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id` , `record_date`) VALUES ('0001', '10', '20', 'avi', '01', '1','2016-03-03');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`) VALUES ('0002', '20', '20', 'dolev', '02', '2','2017-03-02');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`) VALUES ('0003', '30', '30', 'idan', '03', '3','2015-03-03');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`) VALUES ('0004', '40', '50', 'tibor', '01', '6','2013-02-02');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`) VALUES ('0005', '50', '60', 'saar', '03', '8','2018-01-01');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`) VALUES ('0006', '60', '70', 'irit', '03', '6','2017-01-01');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`) VALUES ('0007', '70', '70', 'ganot', '02', '4','2000-05-24');
UPDATE purchase_record SET `purchase_id`='00001', `purchase_from`='ordered' WHERE `purchase_id`='0001';
UPDATE purchase_record SET `purchase_id`='00002', `purchase_from`='ordered' WHERE `purchase_id`='0002';
UPDATE purchase_record SET `purchase_id`='00003', `purchase_from`='ordered' WHERE `purchase_id`='0003';
UPDATE purchase_record SET `purchase_id`='00004', `purchase_from`='ordered' WHERE `purchase_id`='0004';
UPDATE purchase_record SET `purchase_id`='00005', `purchase_from`='ordered' WHERE `purchase_id`='0005';
UPDATE purchase_record SET `purchase_id`='00006', `purchase_from`='ordered' WHERE `purchase_id`='0006';
UPDATE purchase_record SET `purchase_id`='00007', `purchase_from`='ordered' WHERE `purchase_id`='0007';
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`, `purchase_from`) VALUES ('00008', '65.00', '65.00', 'dolev', '01', '5', '2001-04-04', 'ordered');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`, `purchase_from`) VALUES ('00009', '65.00', '65.00', 'saar', '02', '7', '1995-01-01', 'ordered');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`, `purchase_from`) VALUES ('00010', '70.00', '72.00', 'ganor', '01', '9', '2013-01-01', 'shop');
INSERT INTO purchase_record (`purchase_id`, `amount_to_pay`, `price`, `saller_name`, `user_id`, `book_id`, `record_date`, `purchase_from`) VALUES ('00011', '60', '60', 'idan', '01', '6', '2017-12-12', 'shop');







INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00001', '20%', '1');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00002', '30%', '2');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00003', '40%', '3');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00004', '15%', '4');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00005', '20%', '5');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00006', '33%', '6');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00007', '12%', '7');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00008', '10%', '8');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('00009', '12%', '9');
INSERT INTO sales_and_discount (`sales_id`, `discount`, `book_id`) VALUES ('000010', '13%', '10');





INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0001', '10', '10', 'invited', '2018-01-01');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0002', '20', '10', 'arrived', '2016-02-02');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0003', '30', '20', 'arrived', '2015-02-05');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0004', '10', '10', 'massage', '2017-02-07');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0005', '20', '20', 'invited', '2017-03-03');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0006', '20', '20', 'arrived', '2015-01-01');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`) VALUES ('0007', '20', '20', 'arrived', '2016-01-01');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`, `book_id`) VALUES ('0008', '65.00', '65.00', 'arrived', '2001-04-04', '5');
INSERT INTO purchase (`purchase_id`, `amount_to_pay`, `amount_paid`, `status_purchase`, `purchase_date`, `book_id`) VALUES ('0009', '65.00', '65.00', 'arrived', '1995-01-01', '6');
UPDATE purchase SET `book_id`='1' WHERE `purchase_id`='0001';
UPDATE purchase SET `book_id`='2' WHERE `purchase_id`='0002';
UPDATE purchase SET `book_id`='3' WHERE `purchase_id`='0003';
UPDATE purchase SET `book_id`='6' WHERE `purchase_id`='0004';
UPDATE purchase SET `book_id`='8' WHERE `purchase_id`='0005';
UPDATE purchase SET `book_id`='6' WHERE `purchase_id`='0006';
UPDATE purchase SET `book_id`='4' WHERE `purchase_id`='0007';







