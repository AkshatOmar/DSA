CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        with cte AS (
            select salary
            , dense_rank() over(order by salary desc) as rnk
            from Employee

        )
        select salary
        FROM cte 
        where rnk = n
        LIMIT 1
  );
END