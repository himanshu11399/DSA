# Write your MySQL query statement below
select s.product_id,t.first_year,s.quantity,s.price
from Sales as s
join (
select product_id,
min(year) as first_year
from Sales
group by product_id
) as t
where s.product_id=t.product_id and s.year=t.first_year