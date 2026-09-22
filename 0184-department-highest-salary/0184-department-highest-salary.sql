# Write your MySQL query statement below
with cte AS (
    select e.salary as Salary, e.name as Employee, d.name as Department, dense_rank() over(partition by d.name Order by salary desc) as rnk
    from Employee e
    LEFT JOIN Department d
    ON e.departmentId = d.id

)
select Department, Employee, Salary 
FROM cte 
where rnk = 1;