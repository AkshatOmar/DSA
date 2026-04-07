# Write your MySQL query statement below
WITH CTE AS
(
    SELECT *, 
    SUM(weight) OVER(ORDER BY turn) AS rolling_sum
    FROM Queue

), 
cte2 AS 
(
    SELECT * 
    FROM CTE
    WHERE rolling_sum <= 1000
)
SELECT person_name 
FROM cte2
ORDER BY rolling_sum DESC
LIMIT 1;

