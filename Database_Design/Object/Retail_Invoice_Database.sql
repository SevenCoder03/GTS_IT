create table category(
categoryid varchar(3) primary key, 
categoryname char(30)
)

insert into category
values
('C01', 'Household'),
('C02', 'Stationery'),
('C03', 'Furniture'),
('C04', 'Clothes'),
('C05', 'Footwear');

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
('P03', 'Bench',	3, 'C03'),
('P04', 'T shirt', 55, 'C04'),
('P05', 'Slippers', 12, 'C05'),
('P06', 'Boots', 11, 'C05'),
('P07', 'Coat', 8, 'C04'),
('P08', 'Sofa', 14, 'C03'),
('P09', 'Scissors', 15, 'C02'),
('P10', 'Chopsticks', 55, 'C01'),
('P11', 'Spoon', 120, 'C01'),
('P12', 'Ruler', 7, 'C02'),
('P13', 'Table', 12, 'C03'),
('P14', 'Jeans', 110, 'C04'),
('P15', 'Athletic shoes', 100, 'C05'),
('P16', 'Clog', 1, 'C05'),
('P17', 'Pyjamas', 7, 'C04'),
('P18',	'Flower vase', 85, 'C03'),
('P19', 'Document', 13, 'C02'),
('P20', 'Basket', 12, 'C01'),
('P21', 'Pot', 250, 'C01'),
('P22', 'Cover bag', 25, 'C02'),
('P23', 'Couch', 2, 'C03'),
('P24', 'Shorts', 2, 'C04'),
('P25', 'Sandals', 2, 'C05'),
('P26', 'Loafers', 57, 'C05'),
('P27', 'Sweater', 55, 'C04'),
('P28', 'Bed', 500, 'C03'),
('P29', 'Glue', 9, 'C02'),
('P30', 'Pan', 100, 'C01');

create table invoice(
invoiceid varchar(3) primary key,
invoicedate date,
description text
)

insert into invoice
values
('I01', '2022-05-13', 'Fragile goods! Do not step on!'),
('I02', '2021-08-24', 'Flammable goods! Avoid direct sunlight!'),
('I03', '2020-08-06', 'Hot goods! Do not touch!'),
('I04', '2022-04-15', 'Fragile goods! Do not step on!'),
('I05', '2021-07-24', 'Flammable goods! Avoid direct sunlight!'),
('I06', '2020-09-02', 'Hot goods! Do not touch!'),
('I07', '2022-04-30', 'Fragile goods! Do not step on!'),
('I08', '2021-04-05', 'Flammable goods! Avoid direct sunlight!'),
('I09', '2020-02-03', 'Hot goods! Do not touch!'),
('I10', '2022-03-13', 'Fragile goods! Do not step on!');

create table invoicedetail(
invoiceid varchar(3),
productid varchar(3),
quantity int,
primary key(invoiceid, productid)
)

insert into invoicedetail
values
('I01', 'P03', 55),
('I01', 'P04', 5),
('I01', 'P28', 10),
('I01', 'P30', 2),
('I02', 'P15', 4),
('I02', 'P23', 65),
('I02', 'P16', 100),
('I03', 'P23', 1),
('I03', 'P28', 17),
('I04', 'P21', 56),
('I05', 'P20', 6),
('I05', 'P30', 60),
('I06', 'P20', 60),
('I06', 'P30', 63),
('I07', 'P13', 54),
('I07', 'P27', 44),
('I08', 'P05', 56),
('I08', 'P11', 580),
('I09', 'P05', 5),
('I10', 'P16', 65),
('I10', 'P02', 5);

5.1. Find products of the category ID = "CO1"
SELECT *
FROM Product
WHERE CategoryID = 'C01'

5.2. Find products (ID, name and price) of the category ID = "CO2"
SELECT ProductID, ProductName, UnitPrice
FROM Product
WHERE CategoryID = 'C02'

5.3. Find products (*) with unit price from 10 to 50
SELECT *
FROM Product
WHERE UnitPrice BETWEEN 10 AND 50

5.4. Show invoices, it created at date = '2022-04-15'
SELECT *
FROM Invoice 
WHERE InvoiceDate = '2022-04-15'

5.5. Show invoices, it created on year = 2021
SELECT *
FROM Invoice
WHERE date_part('year', InvoiceDate::date) = 2021

5.6. Find products (ID, name, unit price and quantity), it belong to the invoice at date = d.
SELECT A.ProductID, ProductName, UnitPrice, Quantity
FROM Product A, InvoiceDetail B, Invoice C
WHERE A.ProductID = B.ProductID AND B.InvoiceID = C.InvoiceID AND date_part('day', InvoiceDate::date) = 13

5.7. Total quantity of each invoice
SELECT InvoiceID, SUM(Quantity) AS "Total Quantity"
FROM InvoiceDetail 
Group by InvoiceID

5.8. Total quantity of each invoice in date = d.
SELECT A.InvoiceID, SUM(Quantity) AS "Total Quantity"
FROM Invoice A, InvoiceDetail B
WHERE A.InvoiceID = B.InvoiceID AND date_part('month', InvoiceDate::date) = 8
GROUP BY A.InvoiceID

5.9. Total cost (= quantity times to unit price) of each invoice
SELECT B.InvoiceID, SUM(Quantity * UnitPrice) AS "Cost"
FROM  InvoiceDetail B, Product C
WHERE  B.ProductID = C.ProductID
GROUP BY B.InvoiceID

5.10. With invoices have the largest total quantity
SELECT InvoiceID, SUM(Quantity) AS "MAX"
FROM InvoiceDetail 
Group by InvoiceID
Having SUM(Quantity) >= ALL(SELECT SUM(Quantity) 
						FROM InvoiceDetail
						GROUP BY InvoiceID)

2.11. In date = '2022-05-13', with invoices have the largest total quantity.
select a.invoiceid, sum(quantity) as "total quantity"
from invoice a, invoicedetail b
where a.invoiceid = b.invoiceid and invoicedate = '2022-05-13'
group by a.invoiceid
having sum(quantity) >= all(select sum(quantity)
					        from invoice a, invoicedetail b
                            where a.invoiceid = b.invoiceid and invoicedate = '2022-05-13'
                            group by a.invoiceid)

2.12. With invoices have the largest total cost.
select invoiceid, sum(quantity * unitprice) as "cost"
from product a, invoicedetail b
where a.productid = b.productid
group by invoiceid
having  sum(quantity * unitprice) >= all(select sum(quantity * unitprice)
                  					     from product a, invoicedetail b
                                         where a.productid = b.productid
						                 group by invoiceid)

2.13. in date = '2022-05-13', with invoices have the largest total cost.
select b.invoiceid, invoicedate, sum(quantity * unitprice) as "total cost"
from product a, invoicedetail b, invoice c
where a.productid = b.productid and b.invoiceid = c.invoiceid and invoicedate = '2022-05-13'
group by b.invoiceid, invoicedate
having  sum(quantity * unitprice) >= all(select sum(quantity * unitprice)
					                     from product a, invoicedetail b, invoice c
                                         where a.productid = b.productid and b.invoiceid = c.invoiceid and invoicedate = '2022-05-13'
                                         group by b.invoiceid, invoicedate)

2.14. Find years have the largest total cost.
select date_part('year', invoicedate::date) as "year", sum(quantity * unitprice) as "totalcost"
from product a, invoicedetail b, invoice c
where a.productid = b.productid and b.invoiceid = c.invoiceid 
group by date_part('year', invoicedate::date)
having  sum(quantity*unitprice) >= all(select sum(quantity * unitprice)
					   	               from product a, invoicedetail b, invoice c
                                       where a.productid = b.productid and b.invoiceid = c.invoiceid 
                                       group by date_part('year', invoicedate::date))