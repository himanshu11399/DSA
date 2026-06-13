# Write your MySQL query statement below
select t.category,ifnull(c.category_count,0) as accounts_count
from (
    select "Low Salary" as category
    union all
    select "Average Salary"
    union all
    select "High Salary"
) as t
left join
(
select
case
when income<20000 then 'Low Salary'
when income>=20000 and income<=50000 then 'Average Salary'
else 'High Salary'
end as category,
count(*) as category_count
from Accounts
group by category
) as c
on t.category=c.category

