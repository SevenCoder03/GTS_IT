--TRIGGERS--
create or replace function st_gpa()
returns table (stid varchar(3), GPA float)
language plpgsql 
as
$$
begin
	return query
	select studentid stid, avg(grades) GPA
	from "studentgrades"
	group by studentid
	order by studentid;
end;
$$
call:
	select * from st_gpa()
DROP FUNCTION st_gpa

------------------------------
create or replace function st_gpaname()
returns table (stname char, GPA float)
language plpgsql 
as
$$
begin
	return query
	select studentname stname, avg(grades) GPA
	from "studentgrades" A, "student" B
	WHERE A.studentid = B.studentID 
	GROUP BY B.studentid
	HAVING B.studentname = 'Nguyen Van A';
end;
$$

call:
	select * from st_gpaname()
	
DROP FUNCTION st_gpaname
---------------------------------
