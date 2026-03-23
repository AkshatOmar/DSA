# Write your MySQL query statement below
SELECT d.name AS Department, e1.name AS Employee, e1.salary AS Salary
FROM Employee e1
JOIN Department d
ON d.id = e1.departmentId
WHERE 3 > (SELECT COUNT(DISTINCT e2.salary) 
            FROM employee e2 
            WHERE e2.salary > e1.salary AND e2.departmentId = e1.DepartmentId)

;