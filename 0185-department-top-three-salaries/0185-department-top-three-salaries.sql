# Write your MySQL query statement below
WITH employee_department AS 
    (
    SELECT d.name AS Department,
            e.name AS Employee,
            e.salary AS Salary, 
            DENSE_RANK() OVER(PARTITION BY e.departmentId ORDER BY salary DESC) AS rnk
            FROM Employee e
            JOIN Department d
            ON d.id = e.departmentId


    )
SELECT Department,Employee,Salary 
FROM employee_department
WHERE rnk <=3;