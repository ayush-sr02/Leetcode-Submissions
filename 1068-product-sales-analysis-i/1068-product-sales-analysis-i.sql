# Write your MySQL query statement below
select pt.product_name, st.year, st.price FROM Sales st INNER JOIN Product pt
ON st.product_id = pt.product_id;