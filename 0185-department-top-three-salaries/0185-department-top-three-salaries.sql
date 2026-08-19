# Write your MySQL query statement below
WITH CTE AS (
    SELECT e.name AS Employee,d.name AS Department,e.salary AS salary, DENSE_RANK() OVER(PARTITION BY e.departmentId ORDER BY e.salary DESC) 
    AS rnk
    FROM Employee e
    LEFT JOIN Department d 
    ON e.departmentId = d.id

)
SELECT Department, Employee, Salary 
FROM CTE 
WHERE rnk < 4
ORDER BY Salary DESC;

