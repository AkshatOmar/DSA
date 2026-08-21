# Write your MySQL query statement below
WITH CTE AS (
    SELECT id, salary AS SecondHighestSalary,
    DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk
    FROM Employee
)
SELECT MAX(SecondHighestSalary) AS SecondHighestSalary
FROM CTE 
WHERE rnk = 2 