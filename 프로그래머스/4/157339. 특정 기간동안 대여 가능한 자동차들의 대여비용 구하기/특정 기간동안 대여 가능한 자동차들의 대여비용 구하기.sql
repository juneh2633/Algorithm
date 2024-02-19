-- 코드를 입력하세요
# 자동차 종류가 '세단' 또는 'SUV'
#2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고 
#30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차

SELECT car_id, car_table.car_type, 
    ROUND(daily_fee*discount_rate/100*30,0) as FEE
FROM (
    SELECT crcc.car_id, car_type, daily_fee
    FROM CAR_RENTAL_COMPANY_CAR crcc
    LEFT JOIN(
        SELECT distinct(car_id)
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE start_date<="2022-11-30"
        AND end_date >= "2022-11-01"
    ) pci
    ON crcc.CAR_ID = pci.CAR_ID
    WHERE (car_type = "SUV" or car_type = "세단")
    AND pci.car_id is  NULL
) car_table
JOIN (
    SELECT car_type,(100-discount_rate) AS discount_rate
    FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN
    WHERE (car_type = "SUV" or car_type = "세단")
    AND duration_type="30일 이상"
) discount_table
ON discount_table.car_type = car_table.car_type
WHERE daily_fee*discount_rate/100*30 >=500000
AND daily_fee*discount_rate/100*30 <2000000
ORDER BY FEE DESC, car_type ASC, car_id DESC;

# SELECT *
# FROM CAR_RENTAL_COMPANY_CAR
# WHERE car_id = 3
# or car_id = 23