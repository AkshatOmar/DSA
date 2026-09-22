# Write your MySQL query statement below
with cte AS (
    select *, lead(num,1) over() as lead1,
    lead(num,2) over() as lead2
    FROM Logs
    
)
select distinct num as ConsecutiveNums 
from cte 
where num = lead1 AND num = lead2
;