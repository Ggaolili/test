select emp.deptno,emp.ename as'销售部'
from emp
where emp.deptno=
(select deptno from dept where dname='销售部');



