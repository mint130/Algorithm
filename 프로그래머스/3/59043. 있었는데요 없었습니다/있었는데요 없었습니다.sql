select ins.animal_id as animal_id, ins.name as name
from animal_ins ins join animal_outs outs on ins.animal_id = outs.animal_id
where outs.datetime<ins.datetime
order by ins.datetime
