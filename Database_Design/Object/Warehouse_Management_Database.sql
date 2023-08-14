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

create table warehouse(
warehouseid varchar(3) primary key,
warehouseaddress text,
categoryid varchar(3)
)

insert into warehouse
values
('W05', 'An Giang', 'C01'),
('W03', 'Ben Tre', 'C03'),
('W02', 'Long An', 'C02'),
('W01', 'Ho Chi Minh City', 'C01'),
('W04', 'Tien Giang', 'C02');

create table instock(
warehouseid varchar(3),
productid varchar(3),
quantity int,
primary key(warehouseid, productid)
)

insert into instock
values 
('W01', 'P01', 500),
('W01', 'P10', 1000),
('W01', 'P20', 25),
('W02', 'P02', 10),
('W02', 'P06', 100),
('W02', 'P07', 3600),
('W03', 'P03', 60),
('W03', 'P05', 6),
('W03', 'P09', 100),
('W03', 'P11', 100),
('W03', 'P13', 4),
('W04', 'P16', 540),
('W05', 'P18', 500);

5.1. All the products of category ID = "C02"
SELECT *
FROM Product
WHERE CategoryID = 'C02'

5.2. All the warehouses (*) that store category ID = "C01".
SELECT *
FROM Warehouse 
WHERE CategoryID = 'C01'

5.3. All the warehouses (*) in now store product name = "beverage"
SELECT *
FROM Warehouse A, Product B
WHERE A.CategoryID = B.CategoryID AND ProductName = 'Beverage'

5.4. All the products, it can be store in warehouse ID = "W01".
SELECT ProductID
FROM Instock
WHERE WarehouseID = 'W01'

5.5. Calculating sum of quantity for each warehouses.
SELECT WarehouseID, Sum(Quantity)
FROM Instock
GROUP BY WarehouseID

5.6. Find warehouse have the largest total quantities
SELECT WarehouseID, Sum(Quantity) as "Largest Total"
FROM Instock
GROUP BY WarehouseID
HAVING Sum(Quantity) >= ALL(SELECT Sum(Quantity)
							FROM Instock
							GROUP BY WarehouseID)
							 
5.7. Calculating count of product for each warehouse
SELECT WarehouseID, Count(ProductID) as "Count"
FROM Instock
GROUP BY WarehouseID

5.8. Find warehouses have the largest number of product
SELECT WarehouseID, Count(ProductID) as "Largest Count"
FROM Instock
GROUP BY WarehouseID
HAVING Count(ProductID) >= ALL(SELECT Count(ProductID)
							   FROM Instock
							   GROUP BY WarehouseID)

5.9. Calculating sum of quantity for each product.
SELECT ProductID, Sum(Quantity)
FROM Instock
GROUP BY ProductID
						 
5.10. Show products have the largest total of quantities
SELECT ProductID, Sum(Quantity)
FROM Instock
GROUP BY ProductID
HAVING Sum(Quantity) >= ALL(SELECT Sum(Quantity)
						FROM Instock
						GROUP BY ProductID)