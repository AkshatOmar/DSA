# Write your MySQL query statement below
with cte as (
    select d.name as Department,
e.name as Employee, e.salary as Salary, 
DENSE_RANK() OVER(partition BY e.departmentId ORDER BY e.salary DESC) as rnk
FROM Employee e
LEFT JOIN Department d
ON e.departmentId=d.id


)
select Department,Employee,Salary 
FROM CTE 
where rnk = 1;