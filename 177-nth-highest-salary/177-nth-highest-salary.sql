CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct e.Salary from Employee e order by e.Salary desc limit 1 offset M
  );
END