# Write your MySQL query statement below
WITH CTE AS (
    SELECT u.user_id,u.name,COUNT(m.movie_id) AS cnt
    FROM MovieRating AS m
    LEFT JOIN 
    users u 
    ON u.user_id = m.user_id
    GROUP BY m.user_id,u.name
    ORDER BY cnt DESC,u.name ASC
    LIMIT 1
),

 CTE2 AS (
    SELECT m.title, AVG(rating) as avg_rating
    FROM Movies m
    RIGHT JOIN MovieRating mr
    ON m.movie_id = mr.movie_id
    WHERE mr.created_at LIKE '2020-02%'
    GROUP BY mr.movie_id,m.title
    ORDER BY avg_rating DESC, m.title ASC
    LIMIT 1
)
SELECT name  AS results
FROM CTE 
UNION ALL
SELECT title FROM CTE2;



