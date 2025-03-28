/*
1. Fazer uma cópia das tabelas emp e dept, criando tabelas empregado e
departamento.
2. Mostrar o nome, cargo salário e nome do departamento dos
funcionários com salário maior que 2500,00.
3. Mostrar o nome do funcionário, salário, nome do departamento e o
salário com aumento de 10%.
4. Mostrar o nome do funcionário, nome do departamento, comissão e
gerente dos funcionários cujo gerente for 7698
5. Mostrar o nome do funcionário, salário, local do departamento e cargo
dos funcionários cujo cargo for atendente (clerk), por ordem de nome.
*/

CREATE DATABASE IF NOT EXISTS Exercicio_3;

USE Exercicio_3;

-- 1)
CREATE TABLE empregado AS (SELECT * FROM scott.emp);

CREATE TABLE departamentos AS (SELECT * FROM scott.dept);

-- 2)
SELECT
    e.ename "Nome",
    e.job "Cargo",
    e.sal "Salário",
    e.deptno
FROM
    empregado e 
WHERE
    sal > 2500;

-- 3)
SELECT
    e.ename "Nome",
    e.job "Cargo",
    e.sal "Salário",
    e.sal * 1.10 "Sal + 10%",
    e.deptno "Dep",
    d.loc "Loc"
FROM
    empregado e 
JOIN 
    departamentos d
ON 
    d.deptno = e.deptno;

-- 4)
SELECT
    e.ename "Nome",
    e.job "Cargo",
    e.comm "Comissão",
    g.ename "Gerente"
FROM
    empregado e 
JOIN
    empregado g
ON
    e.mgr = g.empno
WHERE
    e.mgr = 7698;

-- 5)
SELECT
    e.ename "Nome",
    e.job "Cargo",
    e.sal "Salário",
    e.ename "job",
    d.loc "Local"
FROM 
    empregado e 
JOIN
    departamentos d
ON
    e.deptno = d.deptno
WHERE
    e.job = "CLERK";