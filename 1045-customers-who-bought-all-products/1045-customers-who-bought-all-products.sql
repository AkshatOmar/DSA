# Write your MySQL query statement below
SELECT c.customer_id
FROM Customer c
LEFT JOIN Product p
ON p.product_key = c.customer_id

GROUP BY c.customer_id 
HAVING COUNT(DISTINCT c.product_key) = (SELECT COUNT(*) FROM Product)
;