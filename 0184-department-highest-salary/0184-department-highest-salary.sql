# Write your MySQL query statement below
-- WITH employee_details AS 
-- (
--     SELECT e.name AS Employee, e.salary AS Salary, d.name AS Department, 
--     DENSE_RANK() OVER(PARTITION BY d.name ORDER BY salary DESC) AS rnk
--     FROM Employee e 
--     LEFT JOIN Department d 
--     ON e.departmentId = d.id
    
-- )

-- SELECT Department, Employee, Salary 
-- FROM employee_details
-- WHERE rnk = 1 
-- ;
SELECT d.name AS Department,e.name AS Employee, e.salary AS Salary
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
WHERE 
    e.salary = (
                SELECT MAX(salary)
                FROM Employee
                WHERE  departmentId = e.departmentId
                )
