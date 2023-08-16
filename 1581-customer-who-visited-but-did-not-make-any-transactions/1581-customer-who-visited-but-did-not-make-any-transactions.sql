# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.visit_id) as count_no_trans 
from Visits v left join Transactions t ON 
v.visit_id = t.visit_id where t.visit_id IS NULL
GROUP BY customer_id;