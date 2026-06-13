# Write your MySQL query statement below

SELECT DATE_FORMAT(t.trans_date,'%Y-%m') as month,
       t.country,
       count(trans_date) as trans_count,
       sum(state='approved') as approved_count,
       sum(amount) as trans_total_amount,
       sum(case when state='approved' then amount else 0 end) as approved_total_amount
FROM Transactions as t
GROUP BY DATE_FORMAT(t.trans_date,'%Y-%m'),t.country