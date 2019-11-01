select dept.*,a.cut
from dept,
(SELECT deptno,count(*)as cut
from emp
group by deptno) as a
where dept.deptno=a.deptno;