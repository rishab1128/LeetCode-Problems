DELETE from Person where id not in (SELECT * from (SELECT min(id) FROM Person GROUP BY email) as tmp);
