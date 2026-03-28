# Write your MySQL query statement below
WITH delivery_details AS
(
    SELECT * , 
    ROW_NUMBER() OVER(PARTITION BY customer_id ORDER BY order_date)
    AS row_num
    FROM Delivery
),
 deli AS
(
    SELECT *
    FROM delivery_details
    WHERE  
    row_num = 1
    GROUP BY customer_id
)

SELECT ROUND(
            SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 
            ELSE 0 END) *100.0
            /
            (SELECT COUNT(*) FROM deli) 
        ,2) AS immediate_percentage

FROM deli;