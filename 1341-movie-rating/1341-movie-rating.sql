# Write your MySQL query statement below
(SELECT u.name as results
FROM MovieRating mr
 JOIN Users u
    ON u.user_id = mr.user_id

GROUP BY mr.user_id
ORDER BY COUNT(*) DESC, u.name ASC
LIMIT 1)

UNION ALL 

(SELECT m.title AS results
FROM Movies m
JOIN MovieRating mr
ON mr.movie_id = m.movie_id
WHERE mr.created_at BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY mr.movie_id
ORDER BY AVG(rating) DESC, m.title ASC
LIMIT 1)
;