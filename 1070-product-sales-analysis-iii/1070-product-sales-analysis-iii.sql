# Write your MySQL query statement below
WITH Sales_details AS
(
    SELECT *, 
    RANK() OVER(PARTITION BY product_id ORDER BY year) AS rnk
    FROM Sales
)
SELECT product_id, year AS first_year, quantity, price
FROM Sales_details
WHERE rnk = 1 
;