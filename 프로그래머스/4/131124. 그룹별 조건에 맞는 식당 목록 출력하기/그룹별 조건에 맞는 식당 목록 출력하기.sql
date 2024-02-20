SELECT member_profile.member_name, rest_review.review_text, 
        DATE_FORMAT(rest_review.review_date,"%Y-%m-%d") AS review_date
FROM rest_review
JOIN member_profile
ON rest_review.member_id = member_profile.member_id
WHERE rest_review.member_id =(

    SELECT member_id
    FROM rest_review
    GROUP BY member_id
    ORDER BY COUNT(*) DESC
    LIMIT 1
)
ORDER BY rest_review.review_date, rest_review.review_text ;