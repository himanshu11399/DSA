# Write your MySQL query statement below

(select u.name as results
from Users as u
join (
select user_id,count(*) as total_rating
from MovieRating
group by user_id
) as t
on u.user_id=t.user_id
order by total_rating desc ,u.name asc
limit 1)
union all
(
select m.title
from Movies as m
join (
select movie_id,avg(rating) as avg_rating
from MovieRating 
where created_at between '2020-02-1' and '2020-02-29'
group by movie_id
) as tm
on m.movie_id=tm.movie_id
order by avg_rating desc,title asc limit 1
)

