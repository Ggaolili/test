/*CREATE VIEW profit_view
as
SELECT a.*,
CONCAT((a.zz-b.zz)/b.zz*100,"%")
AS '年度利润比'
FROM yrprofit as a LEFT JOIN
yrprofit as b
ON a.year=b.year+1;*/


SELECT * FROM profit_view
WHERE year=2011;