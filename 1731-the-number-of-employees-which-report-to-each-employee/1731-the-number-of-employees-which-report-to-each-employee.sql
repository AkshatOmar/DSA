# Write your MySQL query statement below
SELECT e.employee_id, e.name, COUNT(*) AS reports_count,
ROUND(AVG(emp.age)) AS average_age
FROM Employees e
JOIN Employees emp
ON e.employee_id = emp.reports_to
GROUP BY e.employee_id
ORDER BY e.employee_id;