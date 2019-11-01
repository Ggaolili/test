/*select a.ename,b.ename
from emp as a,emp as b
where a.mjr=b.empno*/
/*select a.ename,b.ename 
from emp as a left join emp as b
on a.mjr=b.empno;
select a.ename,
ifnull(b.ename,'老板')
from emp as a left join emp b
on a.mjr=b.empno;*/
/*select a.empno,a.ename,a.deptno,c.dname
from emp as a,emp as b,dept as c
where a.mjr=b.empno and b.deptno=c.deptno and
a.hiredate<b.hiredate;*/
/*select *
from emp right join dept
on emp.deptno=dept.deptno;*/
/*select job,count(*)
from emp 
where sal>15000
group by job ;*/
select emp.deptno,emp.ename as'销售部'
from emp
where emp.deptno=
(select deptno from dept where dname='销售部');



