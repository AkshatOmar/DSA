# Write your MySQL query statement below
SELECT d.name AS Department, rnk.name AS Employee, rnk.Salary
FROM 
(SELECT *,
    DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) as dense_rnk
    FROM Employee e ) AS rnk
 LEFT JOIN Department d
 ON d.id = rnk.departmentId
WHERE dense_rnk <=3;
 ;
 