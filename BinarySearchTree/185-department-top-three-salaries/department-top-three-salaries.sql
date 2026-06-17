
select
 d.name as Department,
 e.name as Employee,
 e.salary as Salary
from (
select *,
dense_rank() over(
    partition by departmentId
    order by salary desc
) as rnk
from Employee
) as e
join department d
on e.departmentId=d.id
where e.rnk<=3

