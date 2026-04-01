# Write your MySQL query statement below
WITH CTE AS
(
    SELECT employee_id, department_id, primary_flag,
    COUNT(*) OVER (PARTITION BY employee_id) AS cnt
    FROM Employee
    
)
SELECT employee_id, department_id
FROM CTE 
WHERE cnt = 1 OR primary_flag = 'Y';
