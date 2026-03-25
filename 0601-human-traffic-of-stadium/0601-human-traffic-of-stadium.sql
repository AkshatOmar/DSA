WITH Stadium_details AS 
(
    SELECT *,
    LAG(id,1) OVER(ORDER BY id) AS prev,
    LAG(id,2) OVER(ORDER BY id) AS second_prev,
    LEAD(id,1) OVER(ORDER BY id) AS next,
    LEAD(id,2) OVER(ORDER BY id) AS second_next
    FROM Stadium
    WHERE people >= 100
)
SELECT id,visit_date,people 
FROM Stadium_details 
WHERE (prev = id-1 AND second_prev = id-2) 
        OR (prev = id-1 AND next = id+1)
        OR (next = id+1 AND second_next= id+2)
ORDER BY visit_date;
