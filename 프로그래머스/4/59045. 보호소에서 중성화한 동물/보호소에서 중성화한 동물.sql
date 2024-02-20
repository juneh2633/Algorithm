SELECT ai.animal_id, ai.animal_type, ai.name
FROM animal_ins ai
LEFT JOIN animal_outs ao
ON ai.animal_id = ao.animal_id 
WHERE ao.animal_id IS NOT NULL
AND ai.sex_upon_intake IN ("Intact Male", "Intact Female")
AND ao.sex_upon_outcome NOT LIKE "Intact%"
ORDER BY ai.animal_id;