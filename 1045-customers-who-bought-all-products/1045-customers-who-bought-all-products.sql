# Write your MySQL query statement below
SELECT c.customer_id
FROM Customer c
LEFT JOIN Product p
ON p.product_key = c.product_key
GROUP BY customer_id
HAVING COUNT(DISTINCT p.product_key) = (SELECT COUNT(*) FROM Product);