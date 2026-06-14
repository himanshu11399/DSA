
select round(sum(t.first_date=c.customer_pref_delivery_date)*100/count(*),2) as immediate_percentage
from Delivery as c
join (
select customer_id,
min(order_date) as first_date
from Delivery
group by customer_id
) as t
on c.order_date=t.first_date AND c.customer_id=t.customer_id