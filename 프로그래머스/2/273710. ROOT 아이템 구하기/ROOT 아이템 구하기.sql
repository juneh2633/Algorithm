SELECT item_info.item_id,item_info.item_name
FROM item_info
JOIN item_tree
ON item_info.item_id = item_tree.item_id
WHERE item_tree.parent_item_id is NULL
;