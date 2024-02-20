SELECT item_info.item_id, item_info.item_name, item_info.rarity
FROM item_info
LEFT JOIN (
    SELECT DISTINCT parent_item_id
    FROM item_tree
) no_parent
ON item_info.item_id = no_parent.parent_item_id
WHERE no_parent.parent_item_id IS NULL
ORDER BY item_info.item_id DESC;