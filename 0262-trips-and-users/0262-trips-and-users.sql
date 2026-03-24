# Write your MySQL query statement below
WITH Trip_details AS 
(
    SELECT t.* , CASE WHEN c.banned = 'Yes' 
                    OR d.banned = 'Yes' 
                    THEN 'Yes' 
                    ELSE 'No' END AS banned
    FROM Trips t
    JOIN Users c
    ON t.client_id = c.users_id
    JOIN Users d
    ON t.driver_id = d.users_id

)
SELECT request_at AS Day,
    
        ROUND(
            (SELECT COUNT(*)
        FROM Trip_details t1
        WHERE t.request_at = t1.request_at 
        AND (t1.status = 'cancelled_by_driver' OR
        t1.status = 'cancelled_by_client')
        AND t1.banned != 'Yes'
        AND t1.request_at BETWEEN '2013-10-01' AND '2013-10-03'
        ) * 1.0
         /

        (SELECT COUNT(*)
        FROM Trip_details t2
        WHERE t.request_at = t2.request_at 
        AND t2.banned != 'Yes'
        AND t2.request_at BETWEEN '2013-10-01' AND '2013-10-03'
        ),2)
        
    AS `Cancellation Rate`

FROM Trip_details t
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
    AND t.banned = 'No'
GROUP BY t.request_at
ORDER BY t.request_at ASC;
