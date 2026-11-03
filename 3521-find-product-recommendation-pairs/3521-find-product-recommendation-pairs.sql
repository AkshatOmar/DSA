# Write your MySQL query statement below
WITH CTE AS (
                SELECT p1.user_id, p1.product_id AS product1_id,
                
                p2.product_id AS product2_id,
                pi1.category AS product1_category,
                pi2.category AS product2_category
                FROM ProductPurchases p1
                JOIN 
                ProductPurchases p2
                ON p1.user_id = p2.user_id 
                AND p1.product_id < p2.product_id
                LEFT JOIN 
                ProductInfo pi1
                ON p1.product_id = pi1.product_id
                LEFT JOIN 
                ProductInfo pi2
                ON p2.product_id = pi2.product_id
)

SELECT product1_id, product2_id, product1_category, product2_category,
COUNT(user_id) AS customer_count
FROM CTE 
GROUP BY product1_id, product2_id
HAVING COUNT(product1_id) >= 3
ORDER BY customer_count DESC, product1_id, product2_id
;