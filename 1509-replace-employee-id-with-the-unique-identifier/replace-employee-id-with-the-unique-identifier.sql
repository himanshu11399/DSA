# Write your MySQL query statement below
select emp.unique_id as unique_id , e.name as name
from Employees as e
left join EmployeeUNI as emp
on e.id=emp.id
