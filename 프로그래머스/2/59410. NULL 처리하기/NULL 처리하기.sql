-- 코드를 입력하세요
SELECT animal_type,
    CASE
    WHEN name is NULL THEN "No name"
    ELSE name
    END AS NAME
    ,sex_upon_intake
FROM animal_ins;