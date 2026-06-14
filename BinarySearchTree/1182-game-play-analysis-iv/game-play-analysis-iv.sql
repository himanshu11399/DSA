# Write your MySQL query statement below

select 
round
(sum(date_add(t.first_date,interval 1 day)=a.event_date)/count(distinct a.player_id),2) 
as fraction
from Activity as a
join (
select player_id,
min(event_date) as first_date
from Activity
group by player_id
) as t
on a.player_id=t.player_id


