# Write your MySQL query statement below
SELECT EU.unique_id, E.name
FROM EmployeeUNI AS EU
RIGHT JOIN Employees AS E
ON EU.id = E.id; #RIGHT JOIN keeps all records from the right table (Employees).
#If a match is found, it brings the value from the left table (EmployeeUNI).
#If there's no match, SQL fills it with NULL for missing values.

