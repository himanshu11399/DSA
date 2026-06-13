select
q.person_name
from Queue as q
join (
    select turn,person_name,sum(weight) over(
    order by turn
    ) as rsum
    from Queue
) as t
on q.person_name=t.person_name
where t.rsum<=1000
order by t.rsum desc
limit 1



