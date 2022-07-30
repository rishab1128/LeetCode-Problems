SELECT Department.name as Department, Employee.name as Employee, Salary 
FROM Employee JOIN Department on (Employee.departmentId=Department.id) 
WHERE (departmentId , Salary) in (SELECT departmentId, Max(Salary) from Employee group by departmentId);