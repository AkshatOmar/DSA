# Write your MySQL query statement below
WITH Sales_details AS 
(
    SELECT product_id, `year` AS first_year, quantity, price, 
    DENSE_RANK() OVER(PARTITION BY product_id ORDER BY `year` ASC) AS rnk
    FROM Sales
)
SELECT product_id, first_year, quantity, price 
FROM Sales_details
WHERE rnk = 1;