use study
go

select *
from companyinfo

select name, city, IncInCtryCode from companyinfo

select distinct IncInCtryCode from companyinfo 

select * from companyinfo where IncInCtryCode = 'kor' 

select * from companyinfo where Employees >= 100000 

select * from companyinfo where Employees >= 50000 and IncInCtryCode = 'kor' 

select  IncInCtryCode, Employees, name
from companyinfo
order by IncInCtryCode 

select  IncInCtryCode, Employees, name
from companyinfo
where not IncInCtryCode = 'NULL' 
