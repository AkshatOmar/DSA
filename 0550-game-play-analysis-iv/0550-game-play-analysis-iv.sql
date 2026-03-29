# Write your MySQL query statement below
WITH Activity_details AS
(
    SELECT * ,
    RANK()
     OVER(partition BY player_id ORDER BY event_date) AS rnk,
     LEAD(event_date, 1)
     OVER(PARTITION BY player_id ORDER BY event_date) AS next_date
    FROM Activity
)

SELECT ROUND(
    IFNULL(SUM(DATEDIFF(next_date, event_date) = 1),0) / 
    (SELECT COUNT(DISTINCT player_id)
    FROM Activity)
    ,2)
     AS fraction
FROM Activity_details
WHERE rnk = 1
;
