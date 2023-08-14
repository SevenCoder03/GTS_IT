--CREATE TABLES/INSERT--
CREATE TABLE R
(
	A int,
	B int,
	C int
);
DROP TABLE R

CREATE TABLE R1
(
	A int,
	B int,
	C int
);
DROP TABLE R1

CREATE TABLE R2
(
	C int,
	D int,
	E int
);
DROP TABLE R2


INSERT INTO R
VALUES
(1,4,1),
(2,4,2),
(3,4,1);

--TRIGGERS--
do
$$
declare
	x integer;
	y date := '2022-11-11';
	z timestamp;
begin
	x := 1;
	z := now();
	raise notice 'var: x = %, y = %, z = %', x,y,z;
end
$$
----------------------------------------------------
create or replace function sumxy(integer, integer)
returns integer
language plpgsql
as
$$
declare 
	ret integer;
	--x alias $1;
	--y alias $2;
begin
	ret := ($1 + $2)*2;
	--ret := (x+y)*2;
	return ret;
end
$$
-----------------------------------------------
do
$$
declare
	x int;
begin
	select A into x
	from R
	WHERE B = 4;
	raise notice 'x=%',x;
end;
$$

call:
	select sumxy(2,3);
-----------------------------------------------
--PTB2--
create or replace function solve(float, float, float)
returns void
language plpgsql
as
$$
declare 
	del float;
	x1 float;
	x2 float;
	a alias for $1;
	b alias for $2;
	c alias for $3;
begin
	del:=b*b-4*a*c;
	if (del < 0 ) then 
		raise notice 'Vo nghiem';
	elsif (del = 0) then
		x1 = -b/(2*a);
		raise notice 'Nghiem kep x1 = x2 = %', x1;
	else
		x1 = (-b + sqrt(del))/(2*a);
		x2 = (-b - sqrt(del))/(2*a);
		raise notice '2 nghiem phan biet x1 = %; x2 = %;',x1,x2;
	end if;
end;
$$
DROP FUNCTION solve 

call:
	select * from solve(2,-7,3)