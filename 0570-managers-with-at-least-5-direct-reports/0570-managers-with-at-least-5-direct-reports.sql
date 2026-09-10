# Write your MySQL query statement below
select e.name from Employee e
LEFT JOIN Employee em
ON e.id = em.managerId
group by em.managerId 
Having count(em.managerId)>=5;