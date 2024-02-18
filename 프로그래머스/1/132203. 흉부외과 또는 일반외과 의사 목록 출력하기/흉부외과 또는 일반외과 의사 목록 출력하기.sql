
SELECT DR_NAME, DR_ID, MCDP_CD, DATE_FORMAT(HIRE_YMD,"%Y-%m-%d") AS HIRE_YMD
FROM DOCTOR
WHERE MCDP_CD = "GS" or MCDP_CD = "CS"
ORDER BY HIRE_YMD DESC, DR_NAME ASC;