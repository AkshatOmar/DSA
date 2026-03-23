# Write your MySQL query statement below
WITH Customer_details AS
    (
        SELECT customer_id,
        COUNT(DISTINCT product_key) AS cnt
        FROM Customer 
        GROUP BY customer_id
    ) 
SELECT customer_id 
FROM Customer_details
WHERE  cnt = (SELECT COUNT(*) FROM Product);
