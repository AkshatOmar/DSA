# Write your MySQL query statement below
WITH CTE AS
(
    SELECT *, 
    DENSE_RANK() OVER(PARTITION BY player_id ORDER BY event_date) AS rnk
    FROM Activity
)
SELECT player_id, event_date AS first_login
FROM CTE 
WHERE rnk = 1 ;