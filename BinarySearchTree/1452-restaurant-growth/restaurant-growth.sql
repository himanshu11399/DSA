select 
  visited_on,
  SUM(amount) OVER(
    ORDER BY visited_on
    rows between 6 preceding and current row
  ) as amount,
  ROUND(
    avg(amount) over(
        order by visited_on
        rows between 6 preceding and current row
    ),2
  ) as average_amount
from (
    select
    visited_on,
    sum(amount) as amount
    from Customer
    group by visited_on
) as t
LIMIT 1000000 OFFSET 6;