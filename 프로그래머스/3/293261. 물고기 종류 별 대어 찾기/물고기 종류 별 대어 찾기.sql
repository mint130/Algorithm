select f.id, n.fish_name, f.length
from fish_info f
join fish_name_info n 
on f.fish_type = n.fish_type
where (f.fish_type, f.length) in (select f1.fish_type, max(f1.length)
                   from fish_info f1
                   group by f1.fish_type)