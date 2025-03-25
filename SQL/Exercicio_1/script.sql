/*
Exercćio Aula 9

Criar as seguintes tabelas:
    • Departamento (cod_dept e nome_dept)
    • Empregado (cod_func, nome_func, sal, cod_dept)

• Incluir 5 registros para departamento e 10 registros para empregado.

• Fazer as seguintes consultas:
    • Todos os funcionários que trabalham no departamento de código 10.
    • Todos os funcionários que ganham menos de 1000,00.
    • Todos os departamentos por ordem de nome.
    • Todos os funcionários com o código entre 10 e 50.
*/


-- Cria Database se já não existe
CREATE DATABASE IF NOT EXISTS Exercicio_1;

-- Abre a DataBase
USE Exercicio_1;


-- Criação de tabelas ------------------------------------------
CREATE TABLE Departamentos (
    cod_dept INT(4) PRIMARY KEY,
    nome_dept VARCHAR(50) NOT NULL
);

CREATE TABLE Funcionarios (
    cod_func INT(4) PRIMARY KEY,
    nome_func VARCHAR(50) NOT NULL,
    salario INT(6) NOT NULL,
    cod_dept INT(4) REFERENCES Departamentos (cod_dept)
);

-- Preenchendo tabelas com Dados -------------------------------

-- Destaivando FOREIGN KEY para permitir inserir dados em qualquer ordem
SET FOREIGN_KEY_CHECKS = 0;

-- Departamentos <<

INSERT INTO Departamentos VALUES (10, 'Fiscal'); -- Podemos usar inline syntax

INSERT INTO Departamentos (cod_dept, nome_dept)
VALUES
(20, 'Fabrica'),
(30, 'Contabilidade'),
(40, 'Recursos Humanos'),
(50, 'Estoque');

-- Funcionarios <<
INSERT INTO Funcionarios (cod_func, nome_func, salario, cod_dept)
VALUES
(10, 'José da Silva', 1500, 10),
(20, 'Antonio de Souza', 1900, 10),
(30, 'Maria José', 3000, 20),
(40, 'João Camargo', 4000, 20),
(50, 'Amarildo Silva', 500, 10),
(60, 'Anita Ferreira', 1500, 30),
(70, 'Bafael Penha', 400, 40),
(80, 'Samuel Souza', 700, 50),
(90, 'José da Silva Jr.', 2500, 50),
(100, 'João da Silva', 3500, 40);

-- Reabilitando FOREIGN KEY
SET FOREIGN_KEY_CHECKS = 0;

-- Recuperando os dados

-- Procura por funcionários que trabalham no departamento de código 10 
SELECT cod_func "Codigo Func", nome_func "Nome", salario "Salário" 
FROM Funcionarios WHERE cod_dept=10;

SELECT cod_func "Codigo func", nome_func "Nome", salario "Salários < 10.000"
FROM Funcionarios WHERE salario < 10000;

SELECT cod_func "Codigo Func", nome_func "Nome", salario "Salário" 
FROM Funcionarios WHERE cod_func IN (10,30);

-- Seleciona todas linhas e colunas de funcionarios e limita output em 5 linhas
SELECT * FROM Funcionarios
LIMIT 5;

-- Busca todos departamentos e classifica por nome em ordem alfabetica
SELECT cod_dept "Cod Dep", nome_dept "Departamento"
FROM Departamentos ORDER BY nome_dept;

-- Podemos fazer de outra forma:

-- Query 1: Funcionários no departamento 10 e salários < 10.000
SELECT 
    cod_func AS "Codigo Func", 
    nome_func AS "Nome", 
    salario AS "Salário",
    CASE 
        WHEN salario < 10000 THEN 'Salário < 10.000' 
        ELSE 'Salário >= 10.000' 
    END AS "Status Salário"
FROM Funcionarios 
WHERE cod_dept = 10;

-- Query 2: Funcionários com códigos 10 e 30
SELECT 
    cod_func AS "Codigo Func", 
    nome_func AS "Nome", 
    salario AS "Salário"
FROM Funcionarios 
WHERE cod_func IN (10, 30);

-- Query 3: Limita a 5 linhas
SELECT * 
FROM Funcionarios
LIMIT 5;

-- Query 4: Departamentos ordenados alfabeticamente
SELECT 
    cod_dept AS "Cod Dep", 
    nome_dept AS "Departamento"
FROM Departamentos 
ORDER BY nome_dept;