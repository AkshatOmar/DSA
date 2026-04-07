# Write your MySQL query statement below
WITH catagories AS
(
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary' 
    UNION ALL 
    SELECT 'High Salary'
),
CTE AS 
(
    SELECT * , CASE WHEN income < 20000 THEN 'Low Salary'
                    WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
                    ELSE 'High Salary' END AS category
    FROM Accounts

)
SELECT c.category, COUNT(ct.account_id) AS accounts_count
FROM catagories c
LEFT JOIN CTE ct
ON ct.category = c.category
GROUP BY c.category 
;
