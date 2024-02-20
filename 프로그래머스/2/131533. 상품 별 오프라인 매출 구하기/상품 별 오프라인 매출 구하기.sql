SELECT product.PRODUCT_CODE, (product_sale.sales_amount * product.price) AS SALES
FROM product 
JOIN(
    SELECT product_id, SUM(sales_amount) AS sales_amount
    FROM offline_sale
    GROUP BY product_id
) product_sale
ON product.product_id = product_sale.product_id
ORDER BY SALES DESC, product.PRODUCT_CODE;