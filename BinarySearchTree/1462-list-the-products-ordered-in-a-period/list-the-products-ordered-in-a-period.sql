# Write your MySQL query statement below

select p.product_name,t.total_units as unit
from Products as p
inner join (
select product_id,sum(unit) as total_units
from Orders
where order_date between '2020-02-01' and '2020-02-29'
group by product_id
having sum(unit)>=100
) as t
on p.product_id=t.product_id