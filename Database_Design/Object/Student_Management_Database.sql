CREATE TABLE Subject(
	SubjectID varchar(3) PRIMARY KEY, 
	SubjectName char(30), 
	Units int
);

CREATE TABLE Class(
	ClassID varchar(3) PRIMARY KEY, 
	ClassName char(30), 
	ClassYear text
);

CREATE TABLE Student(
	StudentID varchar(3) PRIMARY KEY,
	StudentName char(50), 
	StudentAddress varchar(50),
	ClassID varchar(3)
);

CREATE TABLE StudentGrades(
	StudentID varchar(3),
	SubjectID varchar(3),  
	Grades float,
	PRIMARY Key (SubjectID, StudentID)
);

INSERT INTO Subject
VALUES
	('S01', 'Analytics', 3),
	('S02', 'Database Design', 3),
	('S03', 'Computer Architecture', 3),
	('S04', 'Algebra', 2),
	('S05', 'Athletics', 1);

INSERT INTO Class
VALUES
('C01', 'Computer Science', '2022'),
('C02', 'Database', '2021'),
('C03', 'C++', '2020');

INSERT INTO Student
VALUES
('T01', 'Nguyen Van A', 'Binh Thanh, Ho Chi Minh City', 'C01'),
('T02', 'Nguyen Van B', 'Go Vap, Ho Chi Minh City', 'C02'),
('T03', 'Nguyen Van C', 'Thu Đuc, Ho Chi Minh City', 'C02'),
('T04', 'Nguyen Van D', 'Binh Thanh, Ho Chi Minh City', 'C01'),
('T05', 'Nguyen Van E', 'Go Vap, Ho Chi Minh City', 'C03'),
('T06', 'Nguyen Van F', 'Binh Thanh, Ho Chi Minh City', 'C01'),
('T07', 'Nguyen Van G', 'District 7, Ho Chi Minh City', 'C03'),
('T08', 'Nguyen Van H', 'District 8, Ho Chi Minh City', 'C01'),
('T09', 'Nguyen Van Y', 'Binh Thanh, Ho Chi Minh City', 'C02'),
('T10', 'Nguyen Van K', 'Thu Đuc, Ho Chi Minh City', 'C01'),
('T11', 'Nguyen Van L', 'Binh Thanh, Ho Chi Minh City', 'C03'),
('T12', 'Nguyen Van M', 'Go Vap, Ho Chi Minh City', 'C02'),
('T13', 'Nguyen Van N', 'District 7, Ho Chi Minh City', 'C03'),
('T14', 'Nguyen Van U', 'Binh Thanh, Ho Chi Minh City', 'C02'),
('T15', 'Nguyen Van O', 'District 8, Ho Chi Minh City', 'C01'),
('T16', 'Nguyen Van Z', 'Binh Thanh, Ho Chi Minh City', 'C03'),
('T17', 'Nguyen Van W', 'District 5, Ho Chi Minh City', 'C01'),
('T18', 'Nguyen Van X', 'District 7, Ho Chi Minh City', 'C02'),
('T19', 'Nguyen Van Y', 'Thu Đuc, Ho Chi Minh City', 'C02'),
('T20', 'Nguyen Van T', 'Binh Thanh, Ho Chi Minh City', 'C01');	

INSERT INTO StudentGrades
VALUES
('T01', 'S01', 10.0),
('T01', 'S02', 8.7),
('T02', 'S05', 9.5),
('T02', 'S04', 7.5),
('T03', 'S03', 7.9),
('T03', 'S04', 9.3),
('T04', 'S02', 8.9),
('T04', 'S03', 7.7),
('T05', 'S04', 8.9),
('T06', 'S03', 9.3),
('T06', 'S04', 6.9),
('T07', 'S05', 9.6),
('T08', 'S05', 5.3),
('T08', 'S01', 9.7),
('T08', 'S03', 7.0),
('T09', 'S01', 6.7),
('T10', 'S02', 5.0),
('T13', 'S03', 4.5),
('T15', 'S02', 3.7),
('T16', 'S01', 4.0),
('T16', 'S02', 4.0),
('T16', 'S03', 10.0),
('T18', 'S01', 7.5),
('T19', 'S02', 4.0),
('T20', 'S01', 7.0),
('T20', 'S02', 8.0);
		   
5.1. Show Students of class ID = "C02".
SELECT *
FROM Student
WHERE ClassID = 'C02'

5.2. Show Students of class name = "Computer Science".
SELECT StudentID, StudentName
FROM Class A, Student B
WHERE ClassName = 'Computer Science' AND A.ClassID = B.ClassID

5.3. Show Students (All information) of class year = "2020-2024".
SELECT *
FROM Subject
WHERE Units = (SELECT max(Units) FROM Subject)

5.4. Show Subject name and units of the Subject ID = “S01”.
SELECT SubjectName, Units
FROM Subject
WHERE SubjectID = 'S01'

5.5. Grades of Subject ID = "S02" of Student ID = "T02".
SELECT Grades
FROM StudentGrades
WHERE SubjectID = 'S02' AND StudentID = 'T01'

5.6. Find Subject (ID, Name and Grades) that Student ID = "T15" fail.
SELECT A.SubjectID, SubjectName, Grades 
FROM Subject A, StudentGrades B
WHERE A.SubjectID = B.SubjectID AND StudentID = 'T15' AND Grades < 5

5.7. Show all the Subject (*) that Student ID = "T03" never took the exam.
SELECT *
FROM Subject
WHERE SubjectId NOT IN (SELECT SubjectId
					    FROM StudentGrades
					    WHERE StudentId = 'T03')

5.8. Number of Students for each class.
SELECT ClassID, count(StudentID) as "Total"
FROM Student 
GROUP BY ClassID

5.9. Find the classes with the largest number of students.
SELECT ClassID, count(StudentID) as "Total"
FROM Student 
GROUP BY ClassID
Having count(StudentID) >= all(SELECT count(StudentID)
				           FROM Student 
						   GROUP BY ClassID)

5.10. GPA (grade point average) of student ID = "T02".
SELECT avg(Grades) as "GPA"
FROM Studentgrades 
WHERE StudentID = 'T02'

5.11. GPA for each student.
SELECT StudentID, avg(Grades) as "GPA"
FROM Studentgrades 
GROUP BY StudentID

5.12. GPA of class ID = "C02".
SELECT avg(Grades) as "GPA"
FROM Student A, Studentgrades B
WHERE A.StudentID = B.StudentID AND ClassID = 'C02'

5.13. GPA for each class.
SELECT ClassID, avg(Grades) as "GPA"
FROM Student A, Studentgrades B
WHERE A.StudentID = B.StudentID
GROUP BY ClassID

5.14. Find students have the largest GPA.
SELECT StudentID, avg(Grades) as "GPA"
FROM Studentgrades
GROUP BY StudentID
HAVING avg(Grades) >= all(SELECT Avg(Grades)
			              FROM StudentGrades
			              GROUP BY StudentID)

5.15. Find students (ID and Name) have the largest GPA.
SELECT A.StudentID, StudentName, avg(Grades) as "GPA"
FROM Student A, Studentgrades B
WHERE A.StudentID = B.StudentID
GROUP BY A.StudentID, StudentName
HAVING avg(Grades) >= all(SELECT Avg(Grades)
				          FROM Studentgrades
				          GROUP BY StudentID)


5.16. Find classes (ID and Name) have the largest GPA.
SELECT A.ClassID, ClassName, avg(Grades) as "GPA"
FROM class A, Student B, Studentgrades C
WHERE A.ClassID = B.ClassID AND B.StudentID = C.StudentID
GROUP BY A.ClassID
HAVING avg(Grades) >= all(SELECT Avg(Grades)
				          FROM Class A, Student B, Studentgrades C
				          WHERE A.ClassID = B.ClassID AND B.StudentID = C.StudentID
			              GROUP BY A.ClassID)


5.17. GPA with weight for each student.
SELECT StudentID, sum(Grades*Units)/sum(Units) as "GPATS"
FROM Subject A, StudentGrades B
WHERE A.SubjectID = B.SubjectID
GROUP BY StudentID

5.18. GPA with weight for each student (ID and name).
SELECT B.StudentID, StudentName, sum(Grades*Units)/sum(Units) as "GPA"
FROM Subject A, StudentGrades B, Student C
WHERE A.SubjectID = B.SubjectID AND B.StudentID = C.StudentID
GROUP BY B.StudentID, StudentName

5.19. GPA with weight for each class.
SELECT D.ClassID, sum(Grades*Units)/sum(Units) as "GPA"
FROM Subject A, StudentGrades B, Student C, Class D
WHERE A.SubjectID = B.SubjectID AND B.StudentID = C.StudentID AND C.ClassID = D.ClassID
GROUP BY D.ClassID

Extra exercise:
SELECT B.*, C.*
FROM Student A, Studentgrades B, Subject C
WHERE ClassID = 'C01'
AND A.StudentID = B.StudentID AND B.SubjectID = C.SubjectID