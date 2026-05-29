# Write your MySQL query statement below
WITH CTE AS (
    SELECT requester_id 
    FROM RequestAccepted 
    UNION ALL
    SELECT accepter_id
    FROM RequestAccepted

), 
CTE2 AS (
    SELECT requester_id AS id, COUNT(*) AS num
    FROM CTE 
    GROUP BY requester_id
)
SELECT id, num
FROM CTE2
WHERE num = (SELECT MAX(num) FROM CTE2);

