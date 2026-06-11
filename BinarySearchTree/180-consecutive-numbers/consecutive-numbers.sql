# Write your MySQL query statement below
select Distinct num as ConsecutiveNums
from (
select 
num,
LAG(num,1) over (order by id) as prev1,
LEAD(num,1) over (order by id) as next1
from Logs
) as t
where num=prev1 && num=next1;

