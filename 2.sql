/*select * from student 
left join college on
student.collegeId=college.collegeId
where college.collegeId is null
union
select * from college 
right join student on
student.collegeId=college.collegeId
where college.collegeId is  null;*/

select *from profit_view
where year=2011;