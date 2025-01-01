-- 총 주문량이 3000보다 높고 주 성분이 과일 
select f.flavor
from first_half f JOIN icecream_info i ON f.flavor=i.flavor
where i.ingredient_type='fruit_based'
and f.total_order>3000
order by f.total_order desc
