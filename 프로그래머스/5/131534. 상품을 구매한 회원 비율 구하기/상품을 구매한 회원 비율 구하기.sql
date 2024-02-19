SELECT  "2022" AS YEAR, D.MONTH, AMOUNT AS PUCHASED_USERS, ROUND( AMOUNT/(
    SELECT COUNT(user_id)
    FROM USER_INFO UI
    WHERE DATE_FORMAT(UI.JOINED,"%Y") = "2021"
),1) AS PUCHASED_RATIO

FROM (
    SELECT COUNT(C.AMOUNT) AS AMOUNT, C.MONTH
    FROM(
        SELECT A.user_id, A.amount, A.MONTH
        FROM (
            SELECT user_id, COUNT(sales_amount) AS amount,MONTH(SALES_DATE) AS MONTH
            FROM ONLINE_SALE
            GROUP BY user_id, MONTH(SALES_DATE)
            ORDER BY user_id
        ) A
        LEFT JOIN (
            SELECT user_id
            FROM USER_INFO UI
            WHERE DATE_FORMAT(UI.JOINED,"%Y") = "2021"
        ) B
        ON A.user_id = B.user_id
        WHERE B.user_id IS NOT NULL

    ) C
    GROUP BY C.MONTH
) D
ORDER BY YEAR, D.MONTH;
