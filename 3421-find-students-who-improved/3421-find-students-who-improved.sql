# Write your MySQL query statement below
WITH CTE AS (
    select *, FIRST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date) AS first_score,
    LAST_VALUE(score) OVER(PARTITION BY student_id, subject ORDER BY exam_date ROWS BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING) AS latest_score
    FROM Scores
)
select DISTINCT student_id, subject, first_score, latest_score
FROM CTE
where first_score  < latest_score
;
