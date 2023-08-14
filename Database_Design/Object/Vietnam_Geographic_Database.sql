create table country(
countryid varchar(3) primary key,
countryname text
)

insert into country
values
('C01', 'North'),
('C02', 'Central'),
('C03', 'South');

create table province(
provinceid varchar(2) primary key,
provincename text,
population int,
area float,
countryid varchar(3)
)

insert into province
values
	('01', 'TP Ha Noi', 8418883, 3358.9, 'C01'),
	('02', 'TP Ho Chi Minh', 9411805, 2061, 'C03'), 
	('03', 'TP Hai Phong', 2069110, 1561.8, 'C01'),
	('04', 'TP Da Nang', 1191381, 1284.9, 'C02'),
	('05', 'Ha Giang', 883388, 7929.5, 'C01'),
	('06', 'Cao Bang', 535098, 6700.3, 'C01'),
	('07', 'Lai Chau', 480588, 9068.8, 'C01'),
	('08', 'Lao Cai', 756083, 6364, 'C01'),
	('09', 'Tuyen Quang', 797392, 5867.9, 'C01'),
	('10', 'Lang Son', 791872, 8310.2, 'C01'),
	('11', 'Bac Kan', 318083, 4860, 'C01'),
	('12', 'Thai Nguyen', 1322235, 3536.4, 'C01'),
	('13', 'Yen Bai', 838181, 6887.7, 'C01'),
	('14', 'Son La', 1286068, 14123.5, 'C01'),
	('15', 'Phu Tho', 1495116, 3534.6, 'C01'),
	('16', 'Vinh Phuc', 1184074, 1235.2, 'C01'),
	('17', 'Quang Ninh', 1358490, 6177.7, 'C01'),
	('18', 'Bac Giang', 1858540, 3851.4, 'C01'),
	('19', 'Bac Ninh', 1450518, 822.7, 'C01'),
	('21', 'Hai Duong', 2069110, 1561.8, 'C01'),
	('22', 'Hung Yen', 1279308, 930.2, 'C01'),
	('23', 'Hoa Binh', 868623, 4591, 'C01'),
	('24', 'Ha Nam', 867258, 860.9, 'C01'),
	('25', 'Nam Dinh', 1771000, 1668, 'C01'),
	('26', 'Thai Binh', 1876579, 1570.5, 'C01'),
	('27', 'Ninh Binh', 1000093, 1387, 'C01'),
	('28', 'Thanh Hoa', 3690022, 11114.7, 'C02'),
	('29', 'Nghe An', 3417809, 16493.7, 'C02'),
	('30', 'Ha Tinh', 1301601, 5990.7, 'C02'),
	('31', 'Quang Binh', 905895, 8065.3, 'C02'),
	('32', 'Quang Tri', 639414, 4739.8, 'C02'),
	('33', 'Thua Thien Hue', 1137045, 5048.2, 'C02'),
	('34', 'Quang Nam', 1510960, 10574.7, 'C02'),
	('35', 'Quang Ngai', 1234704, 5135.2, 'C02'),
	('36', 'Kon Tum', 565685, 9674.2, 'C02'),
	('37', 'Binh Dinh', 1487009, 6066.2, 'C02'),
	('38', 'Gia Lai', 1566882, 15510.8, 'C02'),
	('39', 'Phu Yen', 875127, 5023.4, 'C02'),
	('40', 'Dak Lak', 1897710, 13030.5, 'C02'),
	('41', 'Khanh Hoa', 1246358, 5137.8, 'C02'),
	('42', 'Lam Dong', 1319952, 9783.2, 'C02'),
	('43', 'Binh Phuoc', 1020839, 687.7, 'C03'),
	('44', 'Binh Duong', 2678220, 2694.7, 'C03'),
	('45', 'Ninh Thuan', 595698, 3355.3, 'C02'),
	('46', 'Tay Ninh', 1190852, 4041.4, 'C03'),
	('47', 'Binh Thuan', 1243977, 7812.8, 'C02'),
	('48', 'Dong Nai', 3236248, 5905.7, 'C03'),
	('49', 'Long An', 1744138, 4490.2, 'C03'),
	('50', 'Dong Thap', 1586438, 3383.8, 'C03'),
	('51', 'An Giang', 1864651, 3536.7, 'C03'),
	('52', 'Ba Ria-Vung Tau', 1181302, 1980.8, 'C03'),
	('53', 'Tien Giang', 1783165, 2510.5, 'C03'),
	('54', 'Kien Giang', 1730117, 6348.8, 'C03'),
	('55', 'TP Can Tho', 1244736, 1439.2, 'C03'),
	('56', 'Ben Tre', 1295067, 2394.6, 'C03'),
	('57', 'Vinh Long', 1022408, 147.5, 'C03'),
	('58', 'Tra Vinh', 1010404, 2358.2, 'C03'),
	('59', 'Soc Trang', 1181835, 3311.8, 'C03'),
	('60', 'Bac Lieu', 917734, 266.9, 'C03'),
	('61', 'Ca Mau', 1191999, 5294.8, 'C03'),
	('62', 'Dien Bien', 623295, 954.1, 'C01'),
	('63', 'Dak Nong', 652766, 6509.3, 'C02'),
	('64', 'Hau Giang', 728255, 1621.8, 'C03');
	
create table border(
provinceid varchar(2),
nationid text,
primary key(provinceid, nationid)
)

insert into border
values
	('05', '+86'),
	('06', '+86'),
	('07', '+86'),
	('08', '+86'),
	('10', '+86'),
	('14', '+856'),
	('17', '+86'),
	('28', '+856'),
	('29', '+856'),
	('30', '+856'),
	('31', '+856'),
	('32', '+856'),
	('33', '+856'),
	('34', '+856'),
	('36', '+855'),
	('36', '+856'),
	('38', '+855'),
	('40', '+855'),
	('43', '+855'),
	('46', '+855'),
	('49', '+855'),
	('50', '+855'),
	('51', '+855'),
	('54', '+855'),
	('62', '+86'),
	('62', '+856'),
	('63', '+855');

create table neighbor(
provinceid varchar(2),
neighborid varchar(2),
primary key(provinceid, neighborid)
)

insert into neighbor
values
	('01', '12'),
	('01', '15'),
	('01', '16'),
	('01', '18'),
	('01', '19'),
	('01', '22'),
	('01', '23'),
	('01', '24'),
	('02', '44'),
	('02', '46'),
	('02', '48'),
	('02', '49'),
	('02', '52'),
	('02', '53'),
	('03', '17'),
	('03', '21'),
	('03', '26'),
	('04', '33'),
	('04', '34'),
	('05', '06'),
	('05', '08'),
	('05', '09'),
	('05', '13'),
	('06', '05'),
	('06', '10'),
	('06', '11'),
	('07', '08'),
	('07', '13'),
	('07', '14'),
	('07', '62'),
	('08', '05'),
	('08', '07'),
	('08', '13'),
	('09', '05'),
	('09', '06'),
	('09', '11'),
	('09', '12'),
	('09', '13'),
	('09', '15'),
	('09', '16'),
	('10', '06'),
	('10', '11'),
	('10', '12'),
	('10', '21'),
	('10', '31'),
	('11', '06'),
	('11', '09'),
	('11', '10'),
	('11', '12'),
	('12', '01'),
	('12', '09'),
	('12', '11'),
	('12', '15'),
	('12', '16'),
	('12', '21'),
	('13', '05'),
	('13', '07'),
	('13', '08'),
	('13', '09'),
	('13', '14'),
	('13', '15'),
	('14', '07'),
	('14', '08'),
	('14', '13'),
	('14', '15'),
	('14', '23'),
	('14', '28'),
	('14', '62'),
	('15', '01'),
	('15', '09'),
	('15', '13'),
	('15', '14'),
	('15', '16'),
	('15', '23'),
	('16', '01'),
	('16', '09'),
	('16', '12'),
	('16', '15'),
	('17', '03'),
	('17', '10'),
	('17', '18'),
	('17', '21'),
	('18', '01'),
	('18', '10'),
	('18', '12'),
	('18', '17'),
	('18', '19'),
	('18', '21'),
	('19', '01'),
	('19', '18'),
	('19', '21'),
	('19', '22'),
	('21', '03'),
	('21', '17'),
	('21', '18'),
	('21', '19'),
	('21', '22'),
	('21', '26'),
	('22', '01'),
	('22', '21'),
	('22', '24'),
	('22', '26'),
	('22', '19'),
	('23', '15'),
	('23', '24'),
	('23', '27'),
	('23', '01'),
	('23', '14'),
	('23', '28'),
	('24', '01'),
	('24', '22'),
	('24', '26'),
	('24', '25'),
	('24', '27'),
	('25', '26'),
	('25', '27'),
	('25', '24'),
	('26', '21'),
	('26', '22'),
	('26', '03'),
	('26', '24'),
	('26', '25'),
	('27', '24'),
	('27', '25'),
	('27', '23'),
	('27', '28'),
	('28', '14'),
	('28', '23'),
	('28', '27'),
	('28', '29'),
	('29', '30'),
	('29', '28'),
	('30', '29'),
	('30', '31'),
	('31', '30'),
	('31', '32'),
	('32', '31'),
	('32', '33'),
	('33', '32'),
	('33', '34'),
	('34', '33'),
	('34', '35'),
	('34', '36'),
	('35', '34'),
	('36', '34'),
	('36', '38'),
	('36', '35'),
	('37', '35'),
	('37', '39'),
	('37', '38'),
	('38', '39'),
	('38', '37'),
	('38', '40'),
	('38', '36'),
	('39', '37'),
	('39', '41'),
	('39', '40'),
	('39', '38'),
	('40', '38'),
	('40', '39'),
	('40', '41'),
	('40', '42'),
	('40', '63'),
	('41', '39'),
	('41', '40'),
	('41', '45'),
	('42', '45'),
	('42', '63'),
	('42', '48'),
	('42', '43'),
	('42', '47'),
	('42', '40'),
	('43', '42'),
	('43', '48'),
	('43', '46'),
	('43', '44'),
	('44', '46'),
	('44', '02'),
	('45', '41'),
	('45', '47'),
	('45', '42'),
	('46', '44'),
	('46', '02'),
	('46', '43'),
	('47', '42'),
	('47', '45'),
	('47', '48'),
	('47', '52'),
	('48', '42'),
	('48', '44'),
	('48', '43'),
	('49', '02'),
	('49', '46'),
	('49', '50'),
	('49', '53'),
	('50', '49'),
	('50', '53'),
	('50', '51'),
	('50', '57'),
	('50', '55'),
	('51', '02'),
	('51', '50'),
	('51', '54'),
	('51', '55'),
	('52', '48'),
	('52', '02'),
	('52', '47'),
	('53', '02'),
	('53', '50'),
	('53', '56'),
	('53', '57'),
	('53', '49'),
	('54', '61'),
	('54', '55'),
	('54', '51'),
	('54', '64'),
	('54', '60'),
	('55', '51'),
	('55', '50'),
	('55', '57'),
	('55', '64'),
	('55', '54'),
	('56', '53'),
	('56', '57'),
	('56', '58'),
	('57', '50'),
	('57', '53'),
	('57', '56'),
	('57', '58'),
	('57', '59'),
	('57', '64'),
	('57', '55'),
	('58', '56'),
	('58', '57'),
	('58', '59'),
	('59', '57'),
	('59', '58'),
	('59', '64'),
	('59', '60'),
	('60', '54'),
	('60', '59'),
	('60', '61'),
	('60', '64'),
	('61', '54'),
	('61', '60'),
	('62', '07'),
	('62', '14'),
	('63', '40'),
	('63', '42'),
	('63', '43'),
	('64', '54'),
	('64', '55'),
	('64', '57'),
	('64', '59'),
	('64', '60');


---------------------------------------  QUERIES LIST  ---------------------------------------
5.1. Provinces with an area larger than 15000 square kilometers.
SELECT *
FROM Province
WHERE Area > 15000

5.2. Provinces(*) it neighbored with province have area larger than 15000 square kilometers.
SELECT A.ProvinceID, ProvinceName, Population, Area, CountryID
FROM Province A, Neighbor B
WHERE A.ProvinceID = B.ProvinceID AND (SELECT Area 
								      FROM Province 
	                                  WHERE ProvinceID = B.NeighborID) > 15000

5.3. Provinces (*) in the country name = "North".
SELECT ProvinceID, ProvinceName, Population, Area, A.CountryID
FROM Country A, Province B
WHERE A.CountryID = B.CountryID AND CountryName = 'North'

5.4. Which Nation bordering the northern provinces.
SELECT DISTINCT NationID
FROM Province A, Border B, Country C
WHERE A.ProvinceID = B.ProvinceID AND A.CountryID = C.CountryID AND C.CountryName = 'North'

5.5. Average area of the southern provinces.
SELECT AVG(Area) as "Area of the southern provinces"
FROM Province A, Country B
WHERE A.CountryID = B.CountryID AND CountryName = 'South'

5.6. Population density of the central country.
SELECT Sum(Population)/Sum(Area) as "Population density of the central country"
FROM Province A, Country B
WHERE A.CountryID = B.CountryID AND CountryName = 'Central'

5.7. Provinces with the largest population density.
SELECT ProvinceID, ProvinceName, Sum(Population)/Sum(Area) as "Provinces with the largest population density"
FROM Province 
GROUP BY ProvinceID, ProvinceName
HAVING Sum(Population)/Sum(Area) >= ALL(SELECT Sum(Population)/Sum(Area)
									FROM Province 
									GROUP BY ProvinceID, ProvinceName)

5.8. Provinces with the largest area.
SELECT ProvinceID, ProvinceName, Area
FROM Province
GROUP BY ProvinceID, ProvinceName
HAVING Area = (SELECT Max(Area)
			  FROM Province)

5.9. In southern country, provinces with the largest area.
SELECT ProvinceID, ProvinceName, Area
FROM Province A, Country B
WHERE A.CountryID = B.CountryID AND CountryName = 'South'
GROUP BY ProvinceID, ProvinceName
HAVING Area = (SELECT Max(Area)
			  FROM Province A, Country B
			  WHERE A.CountryID = B.CountryID AND CountryName = 'South')

5.10. Provinces that have borders with two or more nations.
SELECT A.ProvinceID, ProvinceName, Count(NationID) as "Number Nation"
FROM Province A, Border B
WHERE A.ProvinceID = B.ProvinceID 
GROUP BY A.ProvinceID, ProvinceName
HAVING Count(NationID) >= 2

5.11. List of Countries with the number of its provinces.
SELECT A.CountryID, CountryName, Count(ProvinceID) as "Number Province"
FROM Province A, Country B
WHERE A.CountryID = B.CountryID 
GROUP BY A.CountryID, CountryName

5.12. Provinces with the largest total neighbor.
SELECT A.ProvinceID, ProvinceName, Count(NeighborID) "The largest total neighbor"
FROM Province A, Neighbor B
WHERE A.ProvinceID = B.ProvinceID 
GROUP BY A.ProvinceID, ProvinceName
HAVING Count(NeighborID) >= ALL(SELECT Count(NeighborID)
							FROM Province A, Neighbor B
							WHERE A.ProvinceID = B.ProvinceID 
							GROUP BY A.ProvinceID, ProvinceName)
							
5.13. Provinces that are area larger than area of their neighboring provinces.
SELECT  A.ProvinceID, ProvinceName, Area
FROM Province A, Neighbor B
WHERE A.ProvinceID = B.ProvinceID 
GROUP BY A.ProvinceID, ProvinceName, Area
HAVING Area > (SELECT Max(Area)
			   FROM Province C, Neighbor D
			   WHERE C.ProvinceID = D.NeighborID)
											 										  
5.14. For each country, list the provinces with largest area.
SELECT CountryID, ProvinceID, ProvinceName, Area 
FROM Province A
WHERE Area = (SELECT MAX(Area)
			FROM Province
			WHERE CountryID = A.CountryID)
			ORDER BY CountryID

5.15. For each country, list the provinces with population larger than the average population of that country.
SELECT A.CountryID, CountryName, ProvinceID, ProvinceName, Area
FROM Province A, Country B
WHERE A.CountryID = B.CountryID AND Area > (SELECT Avg(Area)
											FROM Province 
											WHERE CountryID = A.CountryID)
											

5.16. Countries with the largest total area.
SELECT A.CountryID, CountryName, Sum(Area) as "The largest total area"
FROM Province A, Country B
WHERE A.CountryID = B.CountryID
GROUP BY A.CountryID, CountryName
HAVING Sum(Area) >= ALL(SELECT Sum(Area) as "A"
					  FROM Province A, Country B
                      WHERE A.CountryID = B.CountryID
                      GROUP BY A.CountryID, CountryName)

5.17. Countries with the largest total population
SELECT A.CountryID, CountryName, Sum(Population) as "The largest total population"
FROM Province A, Country B
WHERE A.CountryID = B.CountryID
GROUP BY A.CountryID, CountryName
HAVING Sum(Population) >= ALL(SELECT Sum(Population) as "P"
					  FROM Province A, Country B
                      WHERE A.CountryID = B.CountryID
                      GROUP BY A.CountryID, CountryName)


-------------------------------------  EXTRA EXERCISES  ---------------------------------------
Q1: Số tỉnh của mỗi miền
SELECT CountryID, count(*) as "Number of provinces per country"
FROM Province
Group by CountryID

Q2: Miền nào có nhiều tỉnh nhất?
SELECT A.CountryID, CountryName, count(ProvinceID) as "Number of provinces"
FROM Country A, Province B
WHERE A.CountryID = B.CountryID
Group by CountryName
HAVING count(ProvinceID) = (SELECT Max(TotalProvince)
						   FROM (SELECT count(ProvinceID) as "TotalProvince"
								 FROM Country A, Province B
								 WHERE A.CountryID = B.CountryID
								 Group by CountryName))
								 
Q3: Miền nào rộng lớn nhất?
SELECT A.CountryID, CountryName, sum(Area) as "Total area"
FROM Country A, Province B
WHERE A.CountryID = B.CountryID
Group by A.CountryName
HAVING sum(Area) = (SELECT Max(TotalArea)
						   FROM (SELECT sum(Area) as "TotalArea"
								 FROM Country A, Province B
								 WHERE A.CountryID = B.CountryID
								 Group by A.CountryName))
								 
Q4: Miền nào đông dân nhất?
SELECT A.CountryID, CountryName, sum(Population) as "Total Population"
FROM Country A, Province B
WHERE A.CountryID = B.CountryID
Group by CountryName
HAVING sum(Population) = (SELECT Max(TotalPopulation)
						   FROM (SELECT sum(Population) as "TotalPopulation"
								 FROM Country A, Province B
								 WHERE A.CountryID = B.CountryID
								 Group by CountryName))
								 
Q5: Miền nào có mật độ dân cư lớn nhất?
SELECT A.CountryID, CountryName, sum(Population)/sum(Area) as "Population Density"
FROM Country A, Province B
WHERE A.CountryID = B.CountryID
Group by CountryName, A.countryid
HAVING sum(Population)/sum(Area) >= all(SELECT sum(Population)/sum(Area)
								 FROM Country A, Province B
								 WHERE A.CountryID = B.CountryID
								 Group by CountryName)