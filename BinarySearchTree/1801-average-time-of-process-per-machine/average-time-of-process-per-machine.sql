# Write your MySQL query statement below
select a.machine_id,Round(avg(b.timestamp-a.timestamp),3) as processing_time
from Activity as a
join Activity as b
on a.machine_id=b.machine_id AND a.process_id=b.process_id
where a.activity_type='start' AND b.activity_type='end'
group by a.machine_id;