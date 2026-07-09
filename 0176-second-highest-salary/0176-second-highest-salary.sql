# Write your MySQL query statement below
WITH CTE AS (
    SELECT salary, 
    DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk
    FROM Employee
    
)
SELECT (SELECT DISTINCT salary 
FROM CTE
WHERE rnk = 2) AS SecondHighestSalary