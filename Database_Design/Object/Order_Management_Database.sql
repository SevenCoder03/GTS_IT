create table category(
categoryid varchar(3) primary key,
categoryname text
)

insert into category
values
('C01', 'Household'),
('C02', 'Stationery'),
('C03', 'Food');

create table product(
productid varchar(3) primary key,
productname text,
unitprice int,
categoryid varchar(3)
)

insert into product
values
('P01', 'Bowl', 1, 'C01'),
('P02', 'Paper', 2, 'C02'),
('P03', 'Beverage', 3, 'C03'),
('P04', 'Spoon', 55, 'C01'),
('P05', 'Vegetables', 12, 'C03'),
('P06', 'Pen', 11, 'C02'),
('P07', 'Pencil', 8, 'C02'),
('P08', 'Sofa', 14, 'C01'),
('P09', 'Fish', 15, 'C03'),
('P10', 'Chopsticks', 55, 'C01'),
('P11', 'Noodle', 120, 'C03'),
('P12', 'Ruler', 7, 'C02'),
('P13', 'Chicken', 12, 'C03'),
('P14', 'Eraser', 110, 'C02'),
('P15', 'Pan', 100, 'C01'),
('P16', 'Sticker', 1, 'C02'),
('P17', 'Rice', 7, 'C03'),
('P18', 'Pot', 85, 'C01'),
('P19', 'Calculator', 13, 'C02'),
('P20', 'Garbage', 12, 'C01');

create table customer(
customerid varchar(3) primary key,
customername text,
customeraddress text
)

insert into customer
values
('H01', 'Messi', 'Ho Chi Minh City'),
('H02', 'Alex', 'Ho Chi Minh City'),
('H03', 'Fukuda', 'Long An'),
('H04', 'Dieu', 'Vinh Long'),
('H05', 'Hung', 'Tra Vinh'),
('H06', 'Thiep', 'An Giang'),
('H07', 'Mush', 'Ca Mau'),
('H08', 'Messi LA', 'Long An'),
('H09', 'Henry', 'Long An'),
('H10', 'John', 'Kien Giang');

create table orders(
orderid varchar(3) primary key,
orderdate date,
requireddate date,
customerid varchar(3)
)

insert into orders
values
('O01', '2022-05-20', '2022-06-01', 'H04'),
('O02', '2022-05-03','2022-06-28', 'H05'),
('O03', '2022-02-15','2022-02-16', 'H06'),
('O04', '2022-03-20','2022-03-23', 'H06'),
('O05', '2022-01-31','2022-10-21', 'H07');

create table orderdetail(
orderid varchar(3),
productid varchar(3),
orderquantity int,
primary key(orderid, productid)
)

insert into orderdetail
values
('O01', 'P12', 4),
('O01', 'P09', 4),
('O01', 'P11', 30),
('O01', 'P13', 50),
('O02', 'P15', 10000),
('O02', 'P18', 2000),
('O02', 'P19', 3000),
('O03', 'P01', 10),
('O03', 'P02', 30),
('O03', 'P03', 30),
('O03', 'P04', 20),
('O03', 'P05', 15),
('O03', 'P06', 25),
('O04', 'P08', 100),
('O05', 'P20', 100000);

create table delivery(
deliveryid varchar(3) primary key,
deliverydate date,
orderid varchar(3)
)

insert into delivery
values
('D01', '2022-06-02', 'O01'),
('D02', '2022-06-22', 'O02'),
('D03', '2022-06-28', 'O02'),
('D04', '2022-06-29', 'O02'),
('D05', '2022-06-30', 'O02'),
('D06', '2022-02-16', 'O03'),
('D07', '2022-02-16', 'O03'),
('D08', '2022-03-23', 'O04'),
('D09', '2022-10-15', 'O05'),
('D10', '2022-10-20', 'O05');

create table deliverydetail(
deliveryid varchar(3),
productid varchar(3),
deliveryquantity int,
primary key(deliveryid, productid)
)

insert into deliverydetail
values
('D01', 'P12', 3),
('D01', 'P09', 2),
('D01', 'P11', 1),
('D01', 'P13', 1),
('D02', 'P17', 1),
('D03', 'P18', 1),
('D04', 'P19', 1),
('D05', 'P17', 1),
('D02', 'P18', 1),
('D03', 'P19', 2),
('D06', 'P01', 1),
('D06', 'P02', 1),
('D06', 'P03', 1),
('D06', 'P04', 1),
('D07', 'P05', 1),
('D07', 'P06', 1),
('D08', 'P08', 5),
('D09', 'P20', 1),
('D10', '20', 2);

5.1. All the products of category ID = "C02".
SELECT * 
FROM Product
WHERE CategoryID = 'C02'

5.2. List of customers who took order with date from d1 to d2.
SELECT CustomerID
FROM Orders
WHERE OrderDate >= '2022-02-03' AND OrderDate <= '2022-05-20'

5.3. List of customers (ID, name, address) who took order in year = 2021.
SELECT A.CustomerID, CustomerName, CustomerAddress
FROM Orders A, Customer B
WHERE A.CustomerID = B.CustomerID AND date_part('year', OrderDate::Date) = '2022'

5.4. List of products (ID) ordered in order ID = "O01".
SELECT ProductID
FROM OrderDetail
WHERE OrderID = 'O01'

5.5. List of products (*) ordered in order ID = "O01".
SELECT A.ProductID, ProductName, UnitPrice, CategoryID
FROM OrderDetail A, Product B
WHERE A.ProductID = B.ProductID AND OrderID = 'O01'	

5.6. List of products (*) ordered in order date = d.
SELECT A.ProductID, ProductName, UnitPrice, CategoryID
FROM OrderDetail A, Product B, Orders C
WHERE A.ProductID = B.ProductID AND A.OrderID = C.OrderID AND OrderDate = '2022-05-03'	

5.7. Calculating total of quantities for each order (ID).
SELECT OrderID, Sum(OrderQuantity) as "Total Quantity"
FROM OrderDetail
GROUP BY OrderID

5.8. Calculating total of quantities for each order (ID), it took in year = 2021.
SELECT A.OrderID, Sum(OrderQuantity) as "Total Quantity"
FROM OrderDetail A, Orders B
WHERE A.OrderID = B.OrderID AND date_part('year', OrderDate) = '2022'
GROUP BY A.OrderID

5.9. With orders (ID) have the largest total cost.
SELECT OrderID, Sum(OrderQuantity) as "Total Quantity"
FROM OrderDetail
GROUP BY OrderID
HAVING Sum(OrderQuantity) >= ALL(SELECT Sum(OrderQuantity) 
							 FROM OrderDetail
							 GROUP BY OrderID)
							 
5.10. In year = 2021, with orders (ID) have the most total cost.
SELECT A.OrderID, Sum(OrderQuantity) as "Total Quantity 2022"
FROM Orders A, OrderDetail B
WHERE A.OrderID = B.OrderID AND date_part('year', OrderDate) = '2022'
GROUP BY A.OrderID
HAVING Sum(OrderQuantity) >= ALL(SELECT Sum(OrderQuantity)
							 FROM Orders A, OrderDetail B
							 WHERE A.OrderID = B.OrderID AND date_part('year', OrderDate) = '2022'
							 GROUP BY A.OrderID )

5.11. Calculating total cost of orders for each customer.
SELECT CustomerID, Sum(OrderQuantity) as "Total Quantity Customer"
FROM OrderDetail A, Orders B
WHERE A.OrderID = B.OrderID 
GROUP BY CustomerID

5.12. With customers (ID) have the largest total cost.
SELECT B.CustomerID, Sum(OrderQuantity) as "Total Quantity Customer"
FROM OrderDetail A, Customer B, Orders C
WHERE A.OrderID = C.OrderID AND B.CustomerID = C.CustomerID
GROUP BY B.CustomerID
HAVING Sum(OrderQuantity) >= ALL(SELECT Sum(OrderQuantity) as "S"
							 FROM OrderDetail A, Customer B, Orders C
							 WHERE A.OrderID = C.OrderID AND B.CustomerID = C.CustomerID
							 GROUP BY B.CustomerID)
							
5.13. Calculating total cost of orders for each customer (ID, name).
SELECT B.CustomerID, CustomerName, Sum(OrderQuantity) as "Total Quantity Customer"
FROM OrderDetail A, Customer B, Orders C
WHERE A.OrderID = C.OrderID AND B.CustomerID = C.CustomerID
GROUP BY B.CustomerID

5.14. In year = 2021, Calculating total cost of orders for each customer (ID, name).
SELECT B.CustomerID, CustomerName, Sum(OrderQuantity) as "Total Quantity Customer"
FROM OrderDetail A, Customer B, Orders C
WHERE A.OrderID = C.OrderID AND B.CustomerID = C.CustomerID AND date_part('year', OrderDate) = '2022'
GROUP BY B.CustomerID, CustomerName

5.15. In year = 2021, customers (ID, name, address) with the largest total cost.
SELECT B.CustomerID, CustomerName, Sum(OrderQuantity) as "Total Quantity Customer"
FROM OrderDetail A, Customer B, Orders C
WHERE A.OrderID = C.OrderID AND B.CustomerID = C.CustomerID AND date_part('year', OrderDate) = '2022'
GROUP BY B.CustomerID, CustomerName, CustomerAddress
HAVING Sum(OrderQuantity) >= ALL(SELECT Sum(OrderQuantity) 
							 FROM OrderDetail A, Customer B, Orders C
							 WHERE A.OrderID = C.OrderID AND B.CustomerID = C.CustomerID AND date_part('year', OrderDate) = '2022'
							 GROUP BY B.CustomerID, CustomerName, CustomerAddress)
