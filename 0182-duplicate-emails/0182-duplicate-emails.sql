# Write your MySQL query statement below
select distinct email as Email 
from Person 
group by email
Having count(*) > 1;