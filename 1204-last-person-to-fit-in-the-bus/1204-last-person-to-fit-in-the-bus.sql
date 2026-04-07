# Write your MySQL query statement below
WITH CTE AS
(
    SELECT *, 
    SUM(weight) OVER(ORDER BY turn) AS rolling_sum
    FROM Queue

)

SELECT person_name
FROM CTE
WHERE rolling_sum<=1000
ORDER BY rolling_sum DESC
LIMIT 1;

