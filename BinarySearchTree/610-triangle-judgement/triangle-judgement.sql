# Write your MySQL query statement below
select 
x,y,z,
case 
when
t.x+t.y>t.z
&& t.y+t.z>t.x
&& t.x+t.z>t.y 
then 'Yes'
else 'No'
end as triangle
from Triangle as t;