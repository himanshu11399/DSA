# Write your MySQL query statement below
select e.employee_id,e.department_id
from Employee as e
where e.primary_flag='Y' 
or e.employee_Id in
(select employee_id
from employee 
group by employee_id
having count(*)=1)

