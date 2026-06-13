-- # Write your MySQL query statement below
-- select c.user_id,
-- ifnull(b.confirmation,0) as confirmation_rate
-- from (
--     select distinct user_id
--     from Confirmations
-- ) as c
-- left join(

select s.user_id,
ifnull(t.confirmation,0) as confirmation_rate
from Signups as s
 left join(
select user_id,round(sum(action='confirmed')/count(*),2) as confirmation
from Confirmations
group by user_id
 ) as t
 on s.user_id=t.user_id

-- ) as b
-- on c.user_id=b.user_id