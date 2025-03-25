-- Script to create MySQL's "scott" schema with tables
-- EMP, DEPT, BONUS, SALGRADE, DUMMY. Adapted from Oracle's demobld.sql.

CREATE DATABASE IF NOT EXISTS scott;

USE scott;

-- Create tables
CREATE TABLE dept (
  deptno   INT(2) NOT NULL,
  dname    VARCHAR(14),
  loc      VARCHAR(13),
  PRIMARY KEY (deptno)
);

CREATE TABLE emp (
  empno    INT(4) NOT NULL,
  ename    VARCHAR(10),
  job      VARCHAR(9),
  mgr      INT(4),
  hiredate DATE,
  sal      DECIMAL(7,2),
  comm     DECIMAL(7,2),
  deptno   INT(2) NOT NULL,
  PRIMARY KEY (empno),
  FOREIGN KEY (deptno) REFERENCES dept(deptno)
);

CREATE TABLE bonus (
  ename    VARCHAR(10),
  job      VARCHAR(9),
  sal      DECIMAL(7,2),
  comm     DECIMAL(7,2)
);

CREATE TABLE salgrade (
  grade    INT,
  losal    DECIMAL(7,2),
  hisal    DECIMAL(7,2)
);

CREATE TABLE dummy (
  dummy    INT
);

-- Insert data into dummy table
INSERT INTO dummy VALUES (0);

-- Insert data into DEPT table
INSERT INTO dept (deptno, dname, loc)
VALUES
(10, 'ACCOUNTING', 'NEW YORK'),
(20, 'RESEARCH', 'DALLAS'),
(30, 'SALES', 'CHICAGO'),
(40, 'OPERATIONS', 'BOSTON');

-- Insert data into EMP table
INSERT INTO emp (empno, ename, job, mgr, hiredate, sal, comm, deptno)
VALUES
(7839, 'KING', 'PRESIDENT', NULL, '1981-11-17', 5000, NULL, 10),
(7698, 'BLAKE', 'MANAGER', 7839, '1981-05-01', 2850, NULL, 30),
(7782, 'CLARK', 'MANAGER', 7839, '1981-06-09', 2450, NULL, 10),
(7566, 'JONES', 'MANAGER', 7839, '1981-04-02', 2975, NULL, 20),
(7788, 'scott', 'ANALYST', 7566, '1987-07-13', 3000, NULL, 20),
(7902, 'FORD', 'ANALYST', 7566, '1981-12-03', 3000, NULL, 20),
(7369, 'SMITH', 'CLERK', 7902, '1980-12-17', 800, NULL, 20),
(7499, 'ALLEN', 'SALESMAN', 7698, '1981-02-20', 1600, 300, 30),
(7521, 'WARD', 'SALESMAN', 7698, '1981-02-22', 1250, 500, 30),
(7654, 'MARTIN', 'SALESMAN', 7698, '1981-09-28', 1250, 1400, 30),
(7844, 'TURNER', 'SALESMAN', 7698, '1981-09-08', 1500, 0, 30),
(7876, 'ADAMS', 'CLERK', 7788, '1987-07-13', 1100, NULL, 20),
(7900, 'JAMES', 'CLERK', 7698, '1981-12-03', 950, NULL, 30),
(7934, 'MILLER', 'CLERK', 7782, '1982-01-23', 1300, NULL, 10);

-- Insert data into SALGRADE table
INSERT INTO salgrade (grade, losal, hisal)
VALUES
(1, 700, 1200),
(2, 1201, 1400),
(3, 1401, 2000),
(4, 2001, 3000),
(5, 3001, 9999);

-- Commit the transaction (not necessary in MySQL as each statement is auto-committed)
-- COMMIT;