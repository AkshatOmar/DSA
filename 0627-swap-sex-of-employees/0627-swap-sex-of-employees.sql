# Write your MySQL query statement below
update Salary
SET sex = CASE 
        WHEN sex = 'm' THEN 'f'
        ELSE 'm'
END;