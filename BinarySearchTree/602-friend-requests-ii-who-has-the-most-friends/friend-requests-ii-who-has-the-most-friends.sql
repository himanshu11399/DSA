# Write your MySQL query statement below
select t.accepter_id as id,sum(t.acount) as num
from (
select
accepter_id,count(*) as acount
from RequestAccepted
group by accepter_id
union all
select requester_id,count(*) as rcount
from RequestAccepted
group by requester_id
) as t
group by t.accepter_id
order by num desc
limit 1

