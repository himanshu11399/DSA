# Write your MySQL query statement below
select emp.name from (
select e.name as name, e.id as id,count(e.id) as cnt
from Employee as e
join Employee as e2
on e.id=e2.managerId
group by e.id,e.name
) as emp where emp.cnt>=5
