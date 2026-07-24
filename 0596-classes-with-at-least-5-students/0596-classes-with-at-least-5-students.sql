# Write your MySQL query statement below
select class
FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5