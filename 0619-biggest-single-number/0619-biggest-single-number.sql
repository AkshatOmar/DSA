# Write your MySQL query statement below
WITH CTE AS 
(
    SELECT num, COUNT(num) AS cnt
    FROM MyNumbers
    GROUP BY num
    ORDER BY num DESC
)
SELECT MAX(num) AS num
FROM CTE 
WHERE cnt = 1
;