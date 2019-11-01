/*select ename,dname
from emp left join dept on 
emp.deptno=dept.deptno
where job=(select job from emp
where ename='庞统')*/
create view profit_view
as
select a.*,
concat((a.zz-b.zz)/b.zz*100,'%')
as '年度利润比'
from yrprofit as a left join yrprofit as b
on a.year=b.year+1;