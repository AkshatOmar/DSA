# Write your MySQL query statement below
WITH CTE AS (
    SELECT salary AS SecondHighestSalary,
    DENSE_RANK() OVER(ORDER BY SALARY DESC) AS rnk
    FROM Employee
)
SELECT MAX(SecondHighestSalary) AS SecondHighestSalary
FROM CTE 
WHERE rnk = 2 
LIMIT 1;