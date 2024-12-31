select b.TITLE, b.BOARD_ID, r.REPLY_ID, r.WRITER_ID, r.CONTENTS, 
date_format(r.created_date, "%Y-%m-%d") CREATED_DATE
from used_goods_board b join used_goods_reply r
on b.board_id = r.board_id
where b.created_date between '2022-10-01' and '2022-10-31'
order by r.created_date, b.title