# -- 코드를 입력하세요

SELECT  D.YEAR, D.MONTH, AMOUNT AS PUCHASED_USERS, ROUND( AMOUNT/(
    SELECT COUNT(user_id)
    FROM USER_INFO UI
    WHERE DATE_FORMAT(UI.JOINED,"%Y") = "2021"
),1) AS PUCHASED_RATIO

FROM (
    SELECT COUNT(C.AMOUNT) AS AMOUNT, C.YEAR, C.MONTH
    FROM(
        SELECT A.user_id, A.amount, A.YEAR, A.MONTH
        FROM (
            SELECT user_id, COUNT(sales_amount) AS AMOUNT,YEAR(SALES_DATE) AS YEAR, MONTH(SALES_DATE) AS MONTH
            FROM ONLINE_SALE
            GROUP BY user_id, YEAR(SALES_DATE), MONTH(SALES_DATE)
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
ORDER BY  D.YEAR, D.MONTH;

# 2021가입자 중 물건을 구입한 user_id, sale_amount, month
# SELECT A.user_id, A.amount, A.MONTH
# FROM (
#     SELECT user_id, COUNT(sales_amount) AS amount,DATE_FORMAT(SALES_DATE,"%m") AS MONTH
#     FROM ONLINE_SALE
#     GROUP BY user_id, DATE_FORMAT(SALES_DATE,"%m")
#     ORDER BY user_id
# ) A
# LEFT JOIN (
#     SELECT user_id
#     FROM USER_INFO UI
#     WHERE DATE_FORMAT(UI.JOINED,"%Y") = "2021"
# ) B
# ON A.user_id = B.user_id
# WHERE B.user_id IS NOT NULL





# 2021에 가입한 전체 회원 수
    # SELECT COUNT(user_id)
    # FROM USER_INFO UI
    # WHERE DATE_FORMAT(UI.JOINED,"%Y") = "2021"