# Write your MySQL query statement below
select t.user_id as user_id,round(sum(t.rate)/count(t.user_id),2) as confirmation_rate
from (
select s.user_id as user_id,s.time_stamp as time_stamp,
case when c.action='confirmed' then 1 else 0 end as rate
from Signups as s
left join Confirmations as c
on s.user_id=c.user_id
) as t
group by t.user_id